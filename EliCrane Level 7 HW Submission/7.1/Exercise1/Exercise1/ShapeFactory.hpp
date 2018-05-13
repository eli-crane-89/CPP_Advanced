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
	//Create a Polymorphic function MakeShape that accepts a shared pointer reference
	//Overload MakeShape to route 
	virtual void MakeShape(std::shared_ptr<CAD::Point>&) = 0;
	virtual void MakeShape(std::shared_ptr<CAD::Line>&) = 0;
	virtual void MakeShape(std::shared_ptr<CAD::Circle>&) = 0;

};

#endif // !SHAPEFACTORY_HPP
