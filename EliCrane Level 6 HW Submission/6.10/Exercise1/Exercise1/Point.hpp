#ifndef POINT_HPP
#define POINT_HPP

#include <string>


#include "Shape.hpp"

using namespace std;

//

namespace CAD {
	class Point;
}

class ShapeVisitor;

class CAD::Point : public Shape
{
private:
	double m_x;
	double m_y;

protected:
	void print(ostream&) const;
public:

	//Getters and Setters
	void X(double);
	double X() const;
	void Y(double);
	double Y() const;

	//Constructors
	Point();
	Point(double, double);
	Point(const Point&);

	//Operator Overloading Functions
	Point& operator = (const Point&);
	friend std::ostream& operator << (std::ostream&, const Point&);

	//Visitor
	void accept(ShapeVisitor&);

	//Helper Methods
	double Distance() const;
	double Distance(const Point&) const;

	//Destructor
	~Point();
};




#endif


