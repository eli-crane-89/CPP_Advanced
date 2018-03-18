#include <forward_list>
#include <iostream>

#include "ForwardFunctions.hpp"



int main()
{

	//a)
	std::forward_list<int> fl_1; //default

	//list of n elements
	std::forward_list<int> fl_2;
	for (int i = 0; i < 3; i++) {
		fl_2.push_front(i);
	}

	//List initialization
	std::forward_list<int> fl_3 = std::forward_list<int>({ 1,4,5,17,2,33 }); 
	std::forward_list<int> fl_4{ 11,111,1111 };

	//b)
	std::cout << "The size of fl_1: " << sizeFunction(fl_1) << std::endl;
	std::cout << "The size of fl_2: " << sizeFunction(fl_2) << std::endl;
	std::cout << "The size of fl_3: " << sizeFunction(fl_3) << std::endl;
	std::cout << "The size of fl_4: " << sizeFunction(fl_4) << std::endl;

	//c) Insert after
	fl_2.insert_after(fl_2.begin(), 35);
	printFL(fl_2);

	int iMove = 50;
	fl_2.insert_after(fl_2.begin(), std::move(iMove));
	printFL(fl_2);

	fl_2.insert_after(++fl_2.begin(), 2, 77);
	printFL(fl_2);
	
	fl_2.insert_after(fl_2.begin(), fl_4.begin(), fl_4.end());
	printFL(fl_2);

	fl_2.insert_after(fl_2.begin(), { 555,666,777 });
	printFL(fl_2);

	//d)
	std::cout << "\nd)\n";
	eraseValues(fl_2, std::next(fl_2.begin(), 6));
	printFL(fl_2);

	std::cout << "\nd)\n";
	eraseValues(fl_2, std::next(fl_2.begin(), 2), std::next(fl_2.begin(), 4));
	printFL(fl_2);

	//e)

	//Split will insert fl_3 after the third position
	fl_2.splice_after(std::next(fl_2.begin(), 2), fl_3);
	printFL(fl_2);

	//Will splice all but the first element into fl_2 from fl_4
	fl_2.splice_after(std::next(fl_2.begin(), 2), fl_4, fl_4.begin(), fl_4.end());
	printFL(fl_2);

	//Merge two sorted lists
	std::forward_list<int> fl_merge({ 1,2,3,4,5 });

	fl_2.sort();
	fl_merge.sort();
	fl_2.merge(fl_merge);
	printFL(fl_2);


    return 0;
}

