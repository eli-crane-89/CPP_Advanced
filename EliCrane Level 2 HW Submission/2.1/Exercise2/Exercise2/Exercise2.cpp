#include <iostream>

#include "BridgeFunction.hpp"

using namespace std;

int main() {

	std::cout << "Exercise2:" << std::endl;

	int i = 4;
	int * ip = &i;
	PrintObjectBridge(ip);
	PrintObjectBridge(*ip);

	return 0;
}

