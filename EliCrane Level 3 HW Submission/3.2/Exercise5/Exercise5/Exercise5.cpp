
#include <string>
#include <vector>
#include <thread>

#include "SynchronizationDeQue.hpp"
#include "ClientArrivalConsumer.hpp"
#include "ClientLeaveConsumer.hpp"
#include "ServiceConsumer.hpp"
#include "ClientShopFullConsumer.hpp"
#include "BarberWaitingConsumer.hpp"
#include "ClientProducer.hpp"
#include "Client.hpp"

using namespace std;

//Create lambda to join std::vector<std::thread>
auto lambdaJoin = [&](std::vector<std::thread>&& vThreads) {
	for (auto iter = vThreads.begin(); iter != vThreads.end(); iter++) {
		(*iter).join();
	}
};

int main()
{

	//The shared queue
	SynchronizationDeque<Client> deque;

	//Shared mutex
	std::unique_ptr<std::mutex> mx_uptr(new std::mutex);
	std::condition_variable cv_share;

	//Create producers
	std::vector<std::thread> consumers;
	ClientArrivalConsumer c_ClientArrival(&deque, &cv_share);
	ClientShopFullConsumer c_ClientShopFull(1, &deque, &cv_share);
	ServiceConsumer c_Service("buzz cut",&deque, &cv_share);
	ClientLeaveConsumer c_Leave(&deque, &cv_share);
	BarberWaitingConsumer c_Wait(&deque, &cv_share);

	//Group consumers
	consumers.push_back(std::thread(c_ClientArrival));
	consumers.push_back(std::thread(c_ClientShopFull));
	consumers.push_back(std::thread(c_Service));
	consumers.push_back(std::thread(c_Leave));
	consumers.push_back(std::thread(c_Wait));

	//Create vector of names
	std::vector<std::string> vNames;
	vNames.push_back("Tim"); //He will get a hair cut
	vNames.push_back("Jerry"); //Will leave because barbershop is full

	//Create producers
	std::vector<std::thread> producers;
	ClientProducer p_client(vNames, &deque, &cv_share);
	producers.push_back(std::thread(p_client));

	//Join threads
	lambdaJoin(std::move(consumers));
	lambdaJoin(std::move(producers));

	return 0;
}