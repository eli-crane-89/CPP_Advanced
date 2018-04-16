#include <queue>
#include <iostream>
#include <functional>
#include <list>

int main()
{
	//a)
	std::priority_queue<int> pq;
	
	for (int n : { 10, 5, 20, 30, 25, 7, 40 }) {
		pq.push(n);
	}

	auto lPrint = [](const std::priority_queue<int>& pq) {
		//Create copy to print so as not to alter original priority queue
		auto pqCopy = pq;

		while (!pqCopy.empty()) {
			std::cout << pqCopy.top() << ",";
			pqCopy.pop();
		}
		std::cout << std::endl;
	};

	lPrint(pq);

	//Only the top element can be accessed at a time


	//b)
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq_greater;
	
	for (int n : { 10, 5, 20, 30, 25, 7, 40 }) {
		pq_greater.push(n);
	}

	//Print manually cause each priority q will require a different lambda
	while (!pq_greater.empty()) {
		std::cout << pq_greater.top() << ",";
		pq_greater.pop();
	}
	std::cout << std::endl;

	//c)
	auto cmp = [](int left, int right)->bool {
		return (left > right);
	};

	//Use std::function so lambda can be used as comparator
	std::priority_queue<int, std::vector<int>, std::function<bool(int,int)>> pq_cmp(cmp);

	for (int n : { 10, 5, 20, 30, 25, 7, 40 }) {
		pq_cmp.emplace(n);
	}

	while (!pq_cmp.empty()) {
		std::cout << pq_cmp.top() << ",";
		pq_cmp.pop();
	}
	std::cout << std::endl;

    return 0;
}

