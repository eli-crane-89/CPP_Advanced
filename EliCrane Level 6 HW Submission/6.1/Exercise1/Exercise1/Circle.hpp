
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"
#include "Line.hpp"
#include "Point.hpp"

using namespace std;

namespace CAD{

	class Circle;
}

class CAD::Circle : public Shape
{
private:
	Point centerPoint;
	Line radius;
public:
	//Getters and Setters
	void CenterPoint(Point);
	Point CenterPoint() const;
	void Radius(Line);
	Line Radius() const;

	//Constructor
	Circle();
	Circle(Point, Line);
	Circle(const Circle&);

	//Print
	void print();

	//Operator Overloading Functions
	Circle& operator = (const Circle&);
	friend std::ostream& operator << (std::ostream&, const Circle&);

	//Destructor
	~Circle();
};


#endif

