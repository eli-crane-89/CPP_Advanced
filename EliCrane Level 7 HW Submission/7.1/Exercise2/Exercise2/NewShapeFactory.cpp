#ifndef NEWSHAPEFACTORY_CPP
#define NEWSHAPEFACTORY_CPP

#include "NewShapeFactory.hpp"

//Constructor
NewShapeFactory::NewShapeFactory(F_Point f_point, F_Line f_line, F_Circle f_circle) : _f_point(f_point), _f_line(f_line), _f_circle(f_circle) {};

//Create Point Method
SP_Point NewShapeFactory::CreatePoint() {
	//Call Function
	return _f_point();
}

//Create Circle Method
SP_Circle NewShapeFactory::CreateCircle() {
	//Call Function
	return _f_circle();
}

//Create Line Method
SP_Line NewShapeFactory::CreateLine() {
	//Call Function
	return _f_line();
}

#endif