#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include "Shape.hpp"

using namespace std;

namespace Eli {
	namespace CAD {
		class Point;
	}
}



class Eli::CAD::Point : public Shape
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

	//Helper Methods
	virtual std::string ToString() const;
	virtual void Draw() const;

	//Distance Functions
	double Distance() const;
	double Distance(const Point& p) const;

	//Operator overloading functions
	Point operator - () const;
	Point operator * (double factor) const;
	Point operator + (const Point&) const;
	bool operator == (const Point&) const;
	Point& operator = (const Point&);
	Point& operator *= (double factor);

	friend std::ostream& operator << (std::ostream&, const Point&);

	//Hash Function - Permit default argument for seed = 0
	friend std::size_t hash_value(const Point&);

	//Constructors
	Point();
	explicit Point(double);
	Point(double, double);
	Point(const Point&);

	//Destructor
	~Point();
};


//Unary Function
using Point = Eli::CAD::Point;
struct PointHash :
	std::unary_function <Point, std::size_t>
{
	std::size_t operator () (const Point& pt) const {
		//returns a hash of double for pt.X + pt.Y
		return std::hash<double>()(pt.X()) + std::hash<double>()(pt.Y());
	}
};

#endif


