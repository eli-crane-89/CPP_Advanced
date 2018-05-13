#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <memory>

#include "Shape.hpp"
#include "DistanceStrategy.hpp"


using namespace std;

namespace CAD {
	class Point;
}

class CAD::Point : public CAD::Shape
{
private:
	double m_x;
	double m_y;
	DistanceStrategy distStrat;
	int counter = 0;


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
	Point(double, double, DistanceStrategy); //for stateful construction
	Point(const Point&);

	//Operator Overloading Functions
	Point& operator = (const Point&);
	friend std::ostream& operator << (std::ostream&, const Point&);

	//Helper Methods
	std::shared_ptr<CAD::Shape> Clone();
	DistanceStrategy ReturnDistanceStrategy();
	double Distance();
	double Distance(const Point&);
	int ReturnCounter() const;
	void SetStatelessDistanceStrat(const DistanceStrategy&);

	//Destructor
	~Point();
};




#endif


