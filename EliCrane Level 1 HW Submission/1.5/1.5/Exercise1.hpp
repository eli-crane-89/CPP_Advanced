#ifndef EXERCISE1_HPP
#define EXERCISE1_HPP

#include <tuple>
#include <vector>

#include "Exercise1_AddCode.hpp"

inline void Exercise1() {
	std::cout << "Exercise1: " << std::endl;

	//a) Create Person Tupples
	Person person1 = std::make_tuple("John", "Smith", greg::date(2004,3,4), "123 Fake Street");
	Person person2 = std::make_tuple("Sheila", "Henrod", greg::date(1987,6,24), "384 Unreal Avenue");
	Person person3 = std::make_tuple("Mitch", "LumpyLumps", greg::date(1981,12,31), "763 Falsified Lane");

	//c) Create vector of person
	std::vector<Person> vPerson = std::vector<Person>();
	vPerson.push_back(person1);
	vPerson.push_back(person2);
	vPerson.push_back(person3);

	//b) Print Person
	auto vPersonPrint = [](const std::vector<Person> &vPerson) {
		for (auto it = vPerson.begin(); it != vPerson.end(); it++) {
			printPerson(*it);
		}
	};

	vPersonPrint(vPerson);
	
	//d) Struct sort by date on index
	std::sort(vPerson.begin(), vPerson.end(), TupleLess<2>());

	vPersonPrint(vPerson);
}


#endif