#ifndef PRINTVISITOR_CPP
#define PRINTVISITOR_CPP

#include <iostream>

#include "PrintVisitor.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Shape.hpp"


void PrintVisitor::Visit(CAD::Point* point) {
	std::cout << *point << std::endl;
}

void PrintVisitor::Visit(CAD::Circle* circle) {
	std::cout << *circle << std::endl;
}

void PrintVisitor::Visit(CAD::Line* line) {
	std::cout << *line << std::endl;
}

void PrintVisitor::Visit(CAD::Shape* shape) {
	std::cout << *shape << std::endl;
}

#endif
