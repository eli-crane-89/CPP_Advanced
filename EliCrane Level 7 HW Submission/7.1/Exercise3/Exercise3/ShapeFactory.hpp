#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <memory>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "PolyLine.hpp"




class ShapeFactory {

public:
	ShapeFactory() {};
	virtual ~ShapeFactory() {};

	//Functions for object creation
	virtual std::shared_ptr<CAD::Point> CreatePoint(double, double) = 0;
	virtual std::shared_ptr<CAD::Line> CreateLine(double, double, double, double) final;
	virtual std::shared_ptr<CAD::Circle> CreateCircle(const CAD::Point&, const CAD::Line&) = 0;

	//Create Polyline
	//Define in Header File to avoid linker error
	template<template<typename, typename> class Container>
	std::shared_ptr<PolyLine<Container>> CreatePolyLine(size_t size, double dist) {
		return std::make_shared<PolyLine<Container>>(size, dist);
	}

	

};



#endif // !SHAPEFACTORY_HPP
