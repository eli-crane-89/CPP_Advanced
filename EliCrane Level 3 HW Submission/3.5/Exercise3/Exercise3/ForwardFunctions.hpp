#ifndef FORWARDFUNCTIONS_HPP
#define FORWARDFUNCTIONS_HPP

#include <forward_list>
#include <vector>

auto printFL = [](const std::forward_list<int> fl) {
	std::cout << std::endl;
	for (auto item : fl) {
		std::cout << "Item: " << item << std::endl;
	}
};

//Size function
template<typename T>
long sizeFunction(const std::forward_list<T>& fl) {
	return std::distance(fl.begin(), fl.end());
}

//Erase function from iterator
template<typename T, class iter>
void eraseValues(std::forward_list<T>& fl, iter iterBegin) {
	
	//Determine iterator positions and 
	iter iterFL = fl.begin();
	int posCounter = 1;
	while (iterFL != iterBegin) {
		iterFL++;
		posCounter++;
	}

	//Use size to delete values
	const int size = sizeFunction(fl);
	while (size - posCounter > 0) {
		fl.erase_after(iterBegin);
		posCounter++;
	}


}

//Erase function from range of iterators
template<typename T, class iter>
void eraseValues(std::forward_list<T>& fl, iter iterBegin, iter iterEnd) {

	iter iterAfterEnd = std::next(iterEnd, 1);

	//Determine beginning iterator position
	iter iterFL = fl.begin();
	int posCounter = 1;
	while (iterFL != iterBegin) {
		iterFL++;
		posCounter++;
	}

	//Use size to delete values and stop at iterAfterEnd
	const int size = sizeFunction(fl);
	while (size - posCounter > 0 && std::next(iterBegin, 1) != iterAfterEnd) {
		fl.erase_after(iterBegin);
		posCounter++;
	}


}

#endif