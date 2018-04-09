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
	Point startPoint;
	Point endPoint;

public:
	void StartPoint(Point);
	Point StartPoint() const;
	void EndPoint(Point);
	Point EndPoint() const;

	//Constructors
	Line();
	Line(Point, Point);
	Line(const Line&);

	//Helper methods
	virtual std::string ToString() const;
	double Length() const;
	virtual void Line::Draw() const;

	//Operator Overloading Functions
	Line& operator = (const Line&);
	friend std::ostream& operator << (std::ostream&, const Line&);

	//Hash Function
	friend std::size_t hash_value(const Line&);
	

	//Destructor
	~Line();
};




#endif
