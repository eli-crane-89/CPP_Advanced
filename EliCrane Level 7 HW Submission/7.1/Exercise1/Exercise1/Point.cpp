#include "Point.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

namespace CAD {

	//Constructors
	Point::Point() : Shape(), m_x(0), m_y(0) {}

	Point::Point(double x, double y) : Shape(), m_x(x), m_y(y) {}

	Point::Point(const Point& point) : Shape(point), m_x(point.m_x), m_y(point.m_y) {}


	//Getters and Setters
	void Point::X(double X) {
		m_x = X;
	}

	double Point::X() const {
		return m_x;
	}

	void Point::Y(double Y) {
		m_y = Y;
	}

	double Point::Y() const {
		return m_y;
	}

	//Operator overloading
	Point& Point::operator = (const Point& source) {
		if (this != &source)
		{
			Shape::operator=(source);
			m_x = source.m_x;
			m_y = source.m_y;

			return *this;
		}
	}

	//Print
	void Point::print() {
		std::cout << "Point(" << m_x << "," << m_y << ")";
	}

	std::ostream& operator << (std::ostream& stream, const Point& point) {
		stream << "Point(" << point.m_x << "," << point.m_y << ")";
		return stream;
	}

	Point::~Point() {
	};
}
