#ifndef EXERCISE1_ADDCODE_HPP
#define EXERCISE1_ADDCODE_HPP

#include <tuple>
#include <string>
#include <iostream>
#include <vector>
#include "boost/date_time/gregorian/gregorian.hpp"

namespace greg = boost::gregorian;
using Person = std::tuple<std::string, std::string, greg::date, std::string>;


//Function to print date
inline std::string dateToString(const greg::date& date)
{
	std::ostringstream os;
	os << date.month() << "-";
	os << date.day() << "-";
	os << date.year();
	return os.str();
}

template<int index> struct TupleLess
{
	template<typename Tuple>
	bool operator() (const Tuple& left, const Tuple& right) const
	{
		return std::get<index>(left) < std::get<index>(right);
	}
};


//Prints person
inline void printPerson(const Person& person) {
	std::cout << "First Name: " << std::get<0>(person) << ", Last Name: " << std::get<1>(person) << std::endl;
	std::cout << "Birthdate: " << dateToString(std::get<2>(person)) << std::endl;
	std::cout << "Address: " << std::get<3>(person) << std::endl;
}

#endif