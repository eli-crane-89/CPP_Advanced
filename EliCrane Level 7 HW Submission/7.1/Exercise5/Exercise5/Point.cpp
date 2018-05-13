#ifndef POINT_CPP
#define POINT_CPP

#include "Point.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>



using namespace std;

namespace CAD {


	//Constructors
	Point::Point() : CAD::Shape(), m_x(0), m_y(0) {}

	Point::Point(double x, double y) : CAD::Shape(), m_x(x), m_y(y) {};
	
	Point::Point(double x, double y, DistanceStrategy strat) : CAD::Shape(), m_x(x), m_y(y), distStrat(strat) {};

	Point::Point(const Point& point) : CAD::Shape(point), m_x(point.m_x), m_y(point.m_y) {}

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

	//To Return Distance Strategy
	DistanceStrategy Point::ReturnDistanceStrategy() {
		return distStrat;
	}

	//Distance from origin
	//Function cannot be const to increment counter
	double Point::Distance(){
		Point orig(0, 0);
		counter++;
		return distStrat.Distance(*this, orig);
	}


	//Distance from provided point
	//Function cannot be const to increment counter
	double Point::Distance(const Point& point) {
		counter++;
		return distStrat.Distance(*this, point);

	}

	//Return counter
	int Point::ReturnCounter() const {
		return counter;
	}

	//Set distance strategy
	void Point::SetStatelessDistanceStrat(const DistanceStrategy& strat) {
		distStrat = strat;
	}

	//Operator overloading
	Point& Point::operator = (const Point& source) {
		if (this != &source)
		{
			Shape::operator=(source);
			m_x = source.m_x;
			m_y = source.m_y;
		}

		return *this;
	}

	std::ostream& operator << (std::ostream& stream, const Point& point) {
		stream << "Point(" << point.m_x << "," << point.m_y << ")";
		return stream;
	}

	//Clone
	std::shared_ptr<CAD::Shape> Point::Clone() {
		return std::make_shared<Point>(m_x, m_y);
	}

	void Point::print(std::ostream& o) const{
		o << "Point(" << m_x << "," << m_y << ")";
	}

	Point::~Point() {
	};
}


#endif // !POINT_CPP