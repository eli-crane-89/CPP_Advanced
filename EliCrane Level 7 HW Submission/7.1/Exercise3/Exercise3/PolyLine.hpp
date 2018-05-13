#ifndef POLYLINE_HPP
#define POLYLINE_HPP

#include "Shape.hpp"

namespace CAD {
	class Point;
}

//Create PolyLine with defaults for CAD::Point, so only container must be given
template<template<typename,typename> class Container>//, typename alloc = std::allocator<CAD::Point>
class PolyLine : public CAD::Shape {
private:
	size_t _n_points; //Number of points
	Container<CAD::Point, std::allocator<CAD::Point>> _pline;
public:

	//Constructors
	PolyLine(size_t, double);
	PolyLine(const PolyLine&); //Copy constructor

	//Print
	void print();

	//Operator overload functions
	PolyLine& operator = (const PolyLine&);

};

#ifndef POLYLINE_CPP
#include "PolyLine.cpp"
#endif

#endif // !POLYLINE_HPP
