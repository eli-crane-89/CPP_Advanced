#include "Shape.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

namespace CAD {
	
	//Default Constructor
	Shape::Shape() {
	}

	//Copy Constructor
	Shape::Shape(const Shape& shp) {
	}

	//Assignment operator
	Shape& Shape::operator = (const Shape& source) {
		return *this;
	}

	//Stream Operator
	std::ostream& operator << (std::ostream& stream, const Shape& circle) {
		stream << "The shape has printed.";
		return stream;
	}


}