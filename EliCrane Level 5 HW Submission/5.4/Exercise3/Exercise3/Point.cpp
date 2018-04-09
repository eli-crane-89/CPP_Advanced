#include "Point.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <boost/functional/hash.hpp>

using namespace std;
namespace Eli {
	namespace CAD {

		Point::Point() : Shape(), m_x(0), m_y(0) {}

		Point::Point(double xy) : Shape(), m_x(xy), m_y(xy) {}

		Point::Point(double x, double y) : Shape(), m_x(x), m_y(y) {}

		Point::Point(const Point& point) : Shape(point), m_x(point.m_x), m_y(point.m_y) {}

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

		std::string Point::ToString() const {

			std::string s = Shape::ToString();

			//Use a stringstream
			std::stringstream ss;
			ss << "Point(" << setprecision(5) << Point::m_x << "," << Point::m_y << ")";
			ss << ", " << s;

			//Convert to string
			return ss.str();
		}

		void Point::Draw() const {
			cout << "This draws " << Point::ToString() << endl;
		}

		//Distance from origin
		double Point::Distance() const {
			return sqrt(pow(X(), 2) + pow(Y(), 2));
		}


		//Distance from provided point
		double Point::Distance(const Point& point) const {

			//implement sqrt((y2 - y1)^2 + (x2 - x1)^2)
			return sqrt(pow(point.m_y - Point::Y(), 2) + pow(point.m_x - Point::X(), 2));

		}

		//Operator overloading

		Point Point::operator - () const {
			Point pointNeg;
			pointNeg.m_x = m_x * -1;
			pointNeg.m_y = m_y * -1;

			return pointNeg;
		}

		Point Point::operator * (double factor) const {
			Point pointFact;
			pointFact.m_x = m_x * factor;
			pointFact.m_y = m_y * factor;

			return pointFact;
		}

		Point Point::operator + (const Point& source) const {
			Point pointAdd;
			pointAdd.m_x = m_x + source.m_x;
			pointAdd.m_y = m_y + source.m_y;

			return pointAdd;
		}

		bool Point::operator == (const Point& source) const {
			return m_x != (source.m_x && m_y != source.m_y);
		}

		Point& Point::operator = (const Point& source) {
			if (this != &source)
			{
				Shape::operator=(source);
				m_x = source.m_x;
				m_y = source.m_y;

				return *this;
			}
		}

		Point& Point::operator *= (double factor) {
			m_x = m_x * factor;
			m_y = m_y * factor;

			return *this;
		}

		//Comparator for multiset
		bool Point::operator() (const Point& lhs, const Point& rhs) const {
			//determine if m_x is less or m_y
			return lhs.m_x < rhs.m_x || (lhs.m_x == rhs.m_x && lhs.m_y < rhs.m_y);
		}


		//With standard
		std::size_t Point::operator() (const Point& point) const{
			return std::hash<double>()(point.m_x) + std::hash<double>()(point.m_y);
		}


		//custom method
		//std::size_t Point::operator() (const Point& point) const {
		//	//Get max of double for first part and then multiply by m_x
		//	//Then add m_y
		//	return (std::numeric_limits<double>::max() * point.m_x) + point.m_y;
		//}

		std::ostream& operator << (std::ostream& stream, const Point& point) {
			stream << "Point(" << point.m_x << "," << point.m_y << ")";
			return stream;
		}


		Point::~Point() {
		};
	}
}

