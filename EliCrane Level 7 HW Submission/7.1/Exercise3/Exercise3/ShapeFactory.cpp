#ifndef SHAPEFACTORY_CPP
#define SHAPEFACTORY_CPP

#include "ShapeFactory.hpp"
#include "PolyLine.hpp"

std::shared_ptr<CAD::Line> ShapeFactory::CreateLine(double x1, double y1, double x2, double y2) {

	//Derived class institutes own form of CreatePoint 
	auto sp_p1 = CreatePoint(x1, y1);
	auto sp_p2 = CreatePoint(x2, y2);

	return std::make_shared<CAD::Line>(*sp_p1, *sp_p2);

};


#endif