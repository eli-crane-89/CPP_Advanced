#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
using namespace std;


namespace CAD {
	class Shape;
}

class CAD::Shape {

public:

	//Constructors
	Shape();
	Shape(const Shape&); //Copy constructor

	//Helper
	virtual void print(std::ostream&) const = 0;

	//Operator overload functions
	Shape& operator = (const Shape&);
	friend std::ostream& operator << (std::ostream&, const Shape&);


};
#endif
