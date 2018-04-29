#ifndef SHAPEFACTORY_HPP
#define SHAPEFACTORY_HPP

#include <memory>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"


class ShapeFactory {

public:
	ShapeFactory() {};
	virtual ~ShapeFactory() {};

	//Functions for object creation
	virtual std::shared_ptr<CAD::Point> CreatePoint(double, double) = 0;
	virtual std::shared_ptr<CAD::Line> CreateLine(const CAD::Point&, const CAD::Point&) = 0;
	virtual std::shared_ptr<CAD::Circle> CreateCircle(const CAD::Point&, const CAD::Line&) = 0;



};

#endif // !SHAPEFACTORY_HPP
