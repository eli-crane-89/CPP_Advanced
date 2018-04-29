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

	CAD::Circle c1 = CAD::Circle(radStart, radius);

	std::cout << c1 << std::endl;


    return 0;
}

