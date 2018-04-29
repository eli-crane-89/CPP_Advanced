#include "Point.hpp"
#include "OriginPoint.hpp"
#include "ExactDistance.hpp"
#include "ApproximateDistance.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>



using namespace std;

namespace CAD {

	//Initialize static var
	std::shared_ptr<DistanceStrategy> Point::distStrat = std::make_shared<ExactDistance>();

	//Constructors
	Point::Point() : CAD::Shape(), m_x(0), m_y(0) {}

	Point::Point(double x, double y) : CAD::Shape(), m_x(x), m_y(y) {}

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

	//Distance from origin
	double Point::Distance() const {
		Point orig(0, 0);
		return distStrat.get()->Distance(*this, orig);
	}


	//Distance from provided point
	double Point::Distance(const Point& point) const {

		return distStrat.get()->Distance(*this, point);

	}

	//Set distance strategy
	void Point::SetDistanceStrat(std::string strat) {
		if (strat == "Exact"){
			Point::distStrat = std::make_shared<ExactDistance>();
		}
		else {
			Point::distStrat = std::make_shared<ApproximateDistance>();
		}
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
