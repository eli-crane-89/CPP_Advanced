#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

#include "ShapeVisitor.hpp"

class ShapeVisitor;

using namespace std;


namespace CAD {
	class Shape;
}

class CAD::Shape {

public:

	//Constructors
	Shape();
	Shape(const Shape&); //Copy constructor

	//Visitor Method
	virtual void accept(ShapeVisitor&) = 0;

	//Helper
	virtual void print(std::ostream&) const = 0;

	//Operator overload functions
	Shape& operator = (const Shape&);
	friend std::ostream& operator << (std::ostream&, const Shape&);


};
#endif
