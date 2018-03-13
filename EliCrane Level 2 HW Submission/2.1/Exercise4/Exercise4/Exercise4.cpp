#ifndef EXERCISE4_HPP
#define EXERCISE4_HPP

#include <iostream>

#include "AddCode.hpp"

using namespace std;

int main() {

	std::cout << std::endl << "Exercise4:" << std::endl;

	//a)
	cout << "Point2 has a virtual destructor: " << std::boolalpha << has_virtual_destructor<Point2>::value << endl; //false

																													//b)
	cout << "Point2 has a default constructor: " << std::boolalpha << is_default_constructible<Point2>::value << endl; //true
	cout << "Point2 has a copy constructor: " << std::boolalpha << is_copy_constructible<Point2>::value << endl; //true, even though not explicit
	cout << "Point2 has a move constructor: " << std::boolalpha << is_move_constructible<Point2>::value << endl; //true, even though not explicit

	//It appears constructors do not have to be explicit to still be capable of performing the construction operation

	//c)
	cout << "Point2 is copy assignable: " << std::boolalpha << is_copy_assignable<Point2>::value << endl; //true
	cout << "Point2 is move assignable: " << std::boolalpha << is_move_assignable<Point2>::value << endl; //true

	//d)
	cout << "Point3 has a default constructor: " << std::boolalpha << is_default_constructible<Point3>::value << endl; //still true
	cout << "Point3 has a copy constructor: " << std::boolalpha << is_copy_constructible<Point3>::value << endl; //false
	cout << "Point3 has a move constructor: " << std::boolalpha << is_move_constructible<Point3>::value << endl; //fals
	cout << "Point3 is copy assignable: " << std::boolalpha << is_copy_assignable<Point3>::value << endl; //false
	cout << "Point3 is move assignable: " << std::boolalpha << is_move_assignable<Point3>::value << endl; //false

	//Adding a deleted copy constructor makes Point3 not copy or move constructor, while adding a deleted assignment operator makes Point3
	//not copy or move assignable

	//e)
	cout << "Point4 has a default constructor: " << std::boolalpha << is_default_constructible<Point4>::value << endl; //true
	cout << "Point4 has a copy constructor: " << std::boolalpha << is_copy_constructible<Point4>::value << endl; //false
	cout << "Point4 has a move constructor: " << std::boolalpha << is_move_constructible<Point4>::value << endl; //true
	cout << "Point4 is copy assignable: " << std::boolalpha << is_copy_assignable<Point4>::value << endl; //false
	cout << "Point4 is move assignable: " << std::boolalpha << is_move_assignable<Point4>::value << endl; //true

	//Adding a move constructor makes Point4 move constructible and adding a move assignment operator makes it
	//move assignable

	return 0;

}

#endif