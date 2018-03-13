#ifndef EXERCISE3_HPP
#define EXERCISE3_HPP

#include <iostream>

#include "Shapes.hpp"

using namespace std;


int main() {

	std::cout << "Exercise3:" << std::endl;

	//Only values of 'true' are commented

	//a)
	cout << "Shape is empty: " << std::boolalpha << is_empty<Shape>::value << endl;
	cout << "Base is empty: " << std::boolalpha << is_empty<Base>::value << endl;
	cout << "Point is empty: " << std::boolalpha << is_empty<Point>::value << endl;

	cout << "Shape is polymorphic: " << std::boolalpha << is_polymorphic<Shape>::value << endl; //true
	cout << "Base is polymorphic: " << std::boolalpha << is_polymorphic<Base>::value << endl;
	cout << "Point is polymorphic: " << std::boolalpha << is_polymorphic<Point>::value << endl; //true

	cout << "Shape is abstract: " << std::boolalpha << is_abstract<Shape>::value << endl; //true
	cout << "Base is abstract: " << std::boolalpha << is_abstract<Base>::value << endl;
	cout << "Point is abstract: " << std::boolalpha << is_abstract<Point>::value << endl;

	//b)
	cout << "Shape is same as Shape: " << std::boolalpha << is_same<Shape, Shape>::value << endl; //true
	cout << "Shape is same as Base: " << std::boolalpha << is_same<Shape, Base>::value << endl;
	cout << "Base is same as Point: " << std::boolalpha << is_same<Base, Point>::value << endl;
	cout << "Point is same as Shape: " << std::boolalpha << is_same<Point, Shape>::value << endl;
	cout << "Point is same as Base: " << std::boolalpha << is_same<Point, Base>::value << endl;

	//c) 
	cout << "Shape is base of Base: " << std::boolalpha << is_base_of<Shape, Base>::value << endl;
	cout << "Base is base of Point: " << std::boolalpha << is_base_of<Base, Point>::value << endl;
	cout << "Point is base of Shape: " << std::boolalpha << is_base_of<Point, Shape>::value << endl;
	cout << "Point is base of Base: " << std::boolalpha << is_base_of<Point, Base>::value << endl;
	cout << "Base is base of Shape: " << std::boolalpha << is_base_of<Base, Shape>::value << endl;
	cout << "Point is base of Base: " << std::boolalpha << is_base_of<Point, Base>::value << endl;
	cout << "Shape is base of Point: " << std::boolalpha << is_base_of<Shape, Point>::value << endl; //true
	cout << "Base is base of Point: " << std::boolalpha << is_base_of<Base, Point>::value << endl;

	//d)
	cout << "Shape is convertible to Base: " << std::boolalpha << is_convertible<Shape, Base>::value << endl;
	cout << "Base is convertible to Point: " << std::boolalpha << is_convertible<Base, Point>::value << endl;
	cout << "Point is convertible to Shape: " << std::boolalpha << is_convertible<Point, Shape>::value << endl; //true
	cout << "Point is convertible to Base: " << std::boolalpha << is_convertible<Point, Base>::value << endl;


	return 0;
}

#endif