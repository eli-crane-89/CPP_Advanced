#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

int main()
{
	//a)
	std::vector<int> vec2{ 3,4,5,6,7,5,6,7,8,9,1,2,3,4 };

	//b)
	std::make_heap(vec2.begin(), vec2.end());

	auto lPrint = [](const std::vector<int>& v) {
		for (auto elem : v) {
			std::cout << elem << ",";
		}
		std::cout << std::endl;
	};

	lPrint(vec2);

	//see BinaryTree.png for drawing

	//c)
	std::pop_heap(vec2.begin(), vec2.end());
	lPrint(vec2);
	//Calling pop_heap on vec2 moves 9 to the back of heap and does not remove it.
	//The new tree structure does ignore the number 9 though

	vec2.pop_back();
	lPrint(vec2);
	//Pop back actually removes the element from the back of the vector

	//d)
	std::push_heap(vec2.begin(), vec2.end());
	lPrint(vec2);
	//Just calling push heap does nothing

	vec2.push_back(9);
	lPrint(vec2);
	std::push_heap(vec2.begin(), vec2.end());
	lPrint(vec2);
	//push_back actually adds a number to be added to the heap
	//push_heap then looks for the element at the back and adds it

	//e)
	//Put into sorted collection
	std::sort_heap(vec2.begin(), vec2.end());
	lPrint(vec2);
	//sorts ascending

	//f)
	//Find max by making heap then grabbing first elem
	std::make_heap(vec2.begin(), vec2.end());
	std::cout << "The max value is: " << vec2.front() << std::endl;


    return 0;
}

