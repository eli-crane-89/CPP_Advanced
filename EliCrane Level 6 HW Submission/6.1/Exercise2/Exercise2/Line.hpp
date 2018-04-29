#ifndef LINE_HPP
#define LINE_HPP


namespace CAD {
	class Line;
	//std::ostream& operator << (std::ostream&, const Line&);
}

#include "Point.hpp"
#include "Shape.hpp"
#include <string>

using namespace std;


class CAD::Line : public Shape
{
private:
	Point _p1;
	Point _p2;

public:
	void p1(Point);
	Point p1() const;
	void p2(Point);
	Point p2() const;

	//Constructors
	Line();
	Line(Point, Point);
	Line(const Line&);

	//Helper Methods
	double Length() const;

	//Operator Overloading Functions
	Line& operator = (const Line&);
	friend std::ostream& operator << (std::ostream&, const Line&);
	

	//Destructor
	~Line();
};




#endif
