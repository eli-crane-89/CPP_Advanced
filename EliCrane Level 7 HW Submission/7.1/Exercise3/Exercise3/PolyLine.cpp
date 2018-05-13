#ifndef POLYLINE_CPP
#define POLYLINE_CPP

#include <iostream>

#include "PolyLine.hpp"
#include "Point.hpp"

//Constructor that takes size for number of points and distance to create PolyLine
template<template<typename,typename> class Container>
PolyLine<Container>::PolyLine(size_t size, double distance) : Shape(), _n_points(size) {
	for (int i = 0; i < _n_points; ++i) {
		_pline.push_back(CAD::Point(i+distance*i, i + distance*i));
	}
};

//Copy Constructor
template<template<typename, typename> class Container>
PolyLine<Container>::PolyLine(const PolyLine& pl) : Shape(), _n_points(pl._n_points), _pline(pl._pline) {};

//Assignment Operator
template<template<typename, typename> class Container>
PolyLine<Container>& PolyLine<Container>::operator=(const PolyLine& source) {

	if (this != &source) {
		Shape::operator=(source);
		_n_points = source._n_points;
		_pline = source._pline;
	}

	return *this;
}

//Print Function
template<template<typename, typename> class Container>
void PolyLine<Container>::print() {
	std::cout << "The PolyLine has: " << _n_points << "." << std::endl;
	for (auto point : _pline) {
		std::cout << point << std::endl;
	}
}


#endif