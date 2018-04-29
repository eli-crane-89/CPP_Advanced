#include <iostream>

#include "Circle.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Shape.hpp"

int main()
{
	CAD::Point radStart = CAD::Point(1, 3);
	CAD::Point radEnd = CAD::Point(4, 5);

	CAD::Line radius = CAD::Line(radStart, radEnd);

	std::cout << "The radius has length: " << radius.Length() << std::endl;

	return 0;
}

