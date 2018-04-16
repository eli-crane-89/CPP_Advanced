#include <iostream>
#include <boost\signals2.hpp>


void CPrint(double x)
{
	std::cout << "C function: " << x << std::endl;
}

struct Print{
	void operator() (double x)
	{
		std::cout << "I am a printer " << x << std::endl;
	}
};

struct MathsWiz {
	double initialData;

	MathsWiz(double d) { initialData = d; }

	void operator()(double x) {
		initialData *= x;
		std::cout << "The initial data is now: " << initialData << std::endl;
	}
};

struct Database {

	void operator()(double x) {

		std::cout << x << " is now in the database.\n";
	}

};

//Define a Subject as a signal
typedef boost::signals2::signal<void(double)> Subject;

int main()
{
	//Signal
	Subject mySubject;

	//Make slots
	Print myPrint;
	MathsWiz myMaths(10.0);
	Database myDatabase;

	//Connect slots
	mySubject.connect(myPrint);
	mySubject.connect(myMaths);
	mySubject.connect(myDatabase);
	mySubject.connect(&CPrint);
	
	// Trigger the event
	std::cout << "Give the value: "; double val; std::cin >> val;
	mySubject(val);

	//Through functional programming, we can reduce total code needed to follow an Observer pattern;
	//No need to bind function objects or declare a vector, or define the Add Observer or ChangeEvent functions

    return 0;
}

