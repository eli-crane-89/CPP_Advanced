//#include <boost/thread.hpp>
#include <thread>
#include <boost\thread.hpp>
#include <string>
#include <iostream>
#include <functional>
#include <chrono>
#include <mutex>

//Define mutex;
std::mutex mtx;
int lockFailCount = 0;

void IPrint(const std::string& s, int count) {


	//Prints string, count, and thread id

	//a) use lock and unlock
	//Processing time seems slightly faster with locks than without it
	//mtx.lock();

	//b) Try lock
	//The thread lock fails most of the time
	//The processing time is slightly shorter though the mutex.lock() time
	if (mtx.try_lock()) {
		std::cout << s << ": " << count << " from thread: " << std::this_thread::get_id() << std::endl;

		//c) Commenting out unlock leads to a runtime error of "mutex destroyed while busy"
		mtx.unlock();
	}
	else {
		lockFailCount++;
		std::cout << "Thread locking has failed: " << lockFailCount << "x" << std::endl;
	}
}

//Free Function
void FreeFunction() {

	std::string s = "Free Function";

	for (int i = 0; i < 5; i++) {
		IPrint(s, i);
	}
}

//Lambda
auto LambdaFunction = [&](std::string& s) {

	for (int i = 0; i < 5; i++) {
		IPrint(s, i);
	}
};

//Function Object
void ForFunctionObj(std::string& s) {

	for (int i = 0; i < 5; i++) {
		IPrint(s, i);
	}
}

std::function<void(std::string&)> ffo = ForFunctionObj;

//Bound Function Object
std::string s_bmf = "Bound Function Object";
auto bmf = std::bind(&ForFunctionObj, s_bmf);


//Static Function
static void StaticFunction() {
	std::string s = "Static Function";

	for (int i = 0; i < 5; i++) {
		IPrint(s, i);
	}
}

int main()
{

	
	//Create threads from those functions
	std::thread t_free(FreeFunction);

	std::string s_l = "Lambda Function";
	std::thread t_lambda{ LambdaFunction, s_l };

	auto storedlambda = LambdaFunction;
	std::string t_l = "Stored Lambda";
	std::thread t_stored{ storedlambda, t_l };

	std::string s_fo = "Function Object";
	std::thread t_functionobj(ffo, s_fo);

	std::thread t_bound(bmf);
	t_bound.detach();

	std::thread t_static{ StaticFunction };

	//Clock time to run
	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();

	// Do something heavy here
	// Introduce delay to simulate a heavy algorithm
	if (t_free.joinable()) {
		try {
			t_free.join();
		}
		catch (const std::system_error& e) {
			std::cout << "Error thrown on t_free" << std::endl;
		}
	}

	if (t_lambda.joinable()) {
		try {
			t_lambda.join();
		}
		catch (const std::system_error& e) {
			std::cout << "Error thrown on t_lambda" << std::endl;
		}
	}

	if (t_stored.joinable()) {
		try {
			t_stored.join();
		}
		catch (const std::system_error& e) {
			std::cout << "Error thrown on t_stored" << std::endl;
		}
	}

	if (t_functionobj.joinable()) {
		try {
			t_functionobj.join();
		}
		catch (const std::system_error& e) {
			std::cout << "Error thrown on t_functionobj" << std::endl;
		}
	}

	//Do not check for joinable
	try {
		t_bound.join();
	}
	catch (const std::system_error& e) {
		std::cout << "Error on t_bound" << std::endl;
	}

	if (t_static.joinable()) {
		try {
			t_static.join();
		}
		catch (const std::system_error& e) {
			std::cout << "Error thrown on t_static" << std::endl;
		}
	}

	//boost::this_thread::sleep(boost::posix_time::millisec(10000));

	end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "Finished computation at " << "elapsed time: " << elapsed_seconds.count() << "s\n";

	return 0;
}

