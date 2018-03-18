#include <queue>
#include <iostream>
#include <functional>

int main()
{
	//a) Test priority_queue with default
	auto pq_a = std::priority_queue<long long>();
	
	///Push values
	pq_a.push(66);
	pq_a.push(22);
	pq_a.push(44);

	//Print and Pop
	std::cout << "a)\ntop: " << pq_a.top() << std::endl;
	pq_a.pop(); //66

	///Push values
	pq_a.push(11);
	pq_a.push(22);
	pq_a.push(33);

	//Pop
	pq_a.pop(); //44

	//Print and Pop
	while (pq_a.size() > 0) {
		std::cout << "top: " << pq_a.top() << std::endl;
		pq_a.pop();
	}

	//With default parameters, top priority is given to the highest value based on the condition::less
	

	//b) Test priority_queue with greater
	auto pq_b = std::priority_queue<long long, std::vector<long long>, std::greater<long long>>();

	///Push values
	pq_b.push(66);
	pq_b.push(22);
	pq_b.push(44);

	//Print and Pop
	std::cout << "\nb)\ntop: " << pq_b.top() << std::endl;
	pq_b.pop(); //22

	//Push values
	pq_b.push(11);
	pq_b.push(22);
	pq_b.push(33);

	//Pop
	pq_b.pop(); //11

	//Print and Pop
	while (pq_b.size() > 0) {
		std::cout << "top: " << pq_b.top() << std::endl;
		pq_b.pop();
	}

	//Using greater reverses the priority so now the lowest value fall at the top of the queue. This feels
	//a little counterintuitive to me, since I would think std::less = lower values have higher priority
	//and std::greater = higher values have higher priority

	//c) Test priority queue with lambda

	auto l_greater = [](const long long& lhs, const long long &rhs) {
		return lhs > rhs;
	};

	//Make queue
	std::priority_queue<long long, std::vector<long long>, decltype(l_greater)> pq_c(l_greater);

	//Push values
	pq_c.push(66);
	pq_c.push(22);
	pq_c.push(44);

	//Print and Pop
	std::cout << "\nc)\ntop: " << pq_c.top() << std::endl;
	pq_c.pop(); //22

	//Push values
	pq_c.push(11);
	pq_c.push(22);
	pq_c.push(33);

	//Pop
	pq_c.pop(); //11

	//Print and Pop
	while (pq_c.size() > 0) {
		std::cout << "top: " << pq_c.top() << std::endl;
		pq_c.pop();
	}
	
	//Output is the same as std::greater



    return 0;
}

