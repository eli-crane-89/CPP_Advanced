#include <iostream>
#include <queue>

#include "Command.hpp"


double square(double num) {
	return num * num;
}

double sum(double num){
	return num + num;
}

double subtract(double num) {
	return num - num;
}

double divide(double num) {
	return num - num;
}

int main()
{
	const FunctionType ft = FunctionType(square);
	//b) Create instances
	Command c1 = Command(square, 7);
	Command c2 = Command(sum, 15);
	Command c3 = Command(subtract, 8);
	Command c4 = Command(divide, 4);
	Command c5 = Command(square, 22);

	//c) Create priority queue
	auto pq = std::priority_queue <Command, std::vector<Command>,CommandComparator>();
	pq.push(c1);
	pq.push(c2);
	pq.push(c3);
	pq.push(c4);
	pq.push(c5);

	//d) Execute
	while (pq.size() > 0) {
		pq.top().Execute(2.0);
		pq.pop();
	}

    return 0;
}

