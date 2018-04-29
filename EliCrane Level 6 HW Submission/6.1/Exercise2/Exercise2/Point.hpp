#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include "Shape.hpp"

using namespace std;

namespace CAD {
	class Point;
}

class CAD::Point : public Shape
{
private:
	double m_x;
	double m_y;
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

	//Helper Methods
	double Distance() const;
	double Distance(const Point&) const;

	//Destructor
	~Point();
};




#endif


