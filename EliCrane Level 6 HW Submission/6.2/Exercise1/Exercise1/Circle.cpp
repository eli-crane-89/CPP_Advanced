#define _USE_MATH_DEFINES

#include "Circle.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;


namespace CAD {

	Circle::Circle() : Shape(), centerPoint(Point(0, 0)), radius(Line(Point(0, 0), Point(0, 0))) {}

	Circle::Circle(Point point, Line line) : Shape(), centerPoint(point), radius(line) {}
		
	Circle::Circle(const Circle& circle) : Shape(circle), centerPoint(circle.centerPoint), radius (circle.radius) {

	}

	void Circle::CenterPoint(Point point) {
		centerPoint = point;
	}

	Point Circle::CenterPoint() const {
		return centerPoint;
	}

	void Circle::Radius(Line line) {
		radius = line;
	}

	Line Circle::Radius() const {
		return radius;
	}

	Circle& Circle::operator = (const Circle& source) {
		if (this != &source)
		{
			Shape::operator=(source);
			centerPoint = source.centerPoint;
			radius = source.radius;
		}

		return *this;
	}

	std::ostream& operator << (std::ostream& stream, const Circle& circle) {
		stream << "The circle is centered around : " << circle.centerPoint << " with a radius of : " << circle.radius;
		return stream;
	}

	Circle::~Circle()
	{
	}
}
