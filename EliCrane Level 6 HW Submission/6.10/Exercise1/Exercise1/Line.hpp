#ifndef LINE_HPP
#define LINE_HPP


namespace CAD {
	class Line;
	//std::ostream& operator << (std::ostream&, const Line&);
}

#include "Point.hpp"
//#include "Shape.hpp"
#include "ShapeVisitor.hpp"

class ShapeVisitor;


#include <string>

using namespace std;


class CAD::Line : public Shape
{
private:
	Point _p1;
	Point _p2;

protected:
	void print(std::ostream&) const;

public:
	void p1(Point);
	Point p1() const;
	void p2(Point);
	Point p2() const;

	//Constructors
	Line();
	Line(Point, Point);
	Line(const Line&);

	//Visitor
	void accept(ShapeVisitor&);

	//Helper Methods
	double Length() const;

	//Operator Overloading Functions
	Line& operator = (const Line&);
	friend std::ostream& operator << (std::ostream&, const Line&);
	

	//Destructor
	~Line();
};




#endif
