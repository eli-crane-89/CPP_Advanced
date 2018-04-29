#ifndef CONSOLESHAPEFACTORY_CPP
#define CONSOLESHAPEFACTORY_CPP

#include "ConsoleShapeFactory.hpp"

//Constructor
ConsoleShapeFactory::ConsoleShapeFactory() {};

//Destructor
ConsoleShapeFactory::~ConsoleShapeFactory(){};

//Functions for object creation
std::shared_ptr<CAD::Point> ConsoleShapeFactory::CreatePoint(double x, double y) {
	return std::make_shared<CAD::Point>(x, y);
};

std::shared_ptr<CAD::Line> ConsoleShapeFactory::CreateLine(const CAD::Point& p1, const CAD::Point& p2) {
	return std::make_shared<CAD::Line>(p1, p2);
};


std::shared_ptr<CAD::Circle> ConsoleShapeFactory::CreateCircle(const CAD::Point& p, const CAD::Line& radius) {
	return std::make_shared<CAD::Circle>(p, radius);
};





#endif // !CONSOLESHAPEFACTORY_CPP
