#include "Line.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

namespace CAD {

	Line::Line() : Shape(), _p1(Point()), _p2(Point()) {}

	Line::Line(Point ps1, Point ps2) : Shape(), _p1(ps1), _p2(ps2) {}

	Line::Line(const Line& line) : Shape(line), _p1(line._p1), _p2(line._p2) {}

	void Line::p1(Point ps1) {
		_p1 = ps1;
	}

	Point Line::p1() const {
		return _p1;
	}

	void Line::p2(Point ps2) {
		_p2 = ps2;
	}

	Point Line::p2() const {
		return _p2;
	}


	Line& Line::operator = (const Line& source) {
		if (this != &source)
		{
			Shape::operator=(source);
			_p1 = source._p1;
			_p2 = source._p2;
		}

		return *this;
	}

	void Line::print() {
		std::cout << "This line has ps1 at " << _p1 << " and ps2 at " << _p2 << std::endl;
	}

	std::ostream& operator << (std::ostream& stream, const Line& line) {
		stream << "This line has ps1 at " << line._p1 << " and ps2 at " << line._p2 << std::endl;
		return stream;
	}


	Line::~Line() {
	}
}
