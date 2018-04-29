#ifndef POINT_HPP
#define POINT_HPP

#include <string>
#include <memory>

#include "Shape.hpp"
#include "DistanceStrategy.hpp"

class DistanceStrategy;

using namespace std;

namespace CAD {
	class Point;
}

class CAD::Point : public CAD::Shape
{
private:
	double m_x;
	double m_y;
	static std::shared_ptr<DistanceStrategy> distStrat;


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

	//Helper Methods
	std::shared_ptr<CAD::Shape> Clone();
	double Distance() const;
	double Distance(const Point&) const;
	static void SetDistanceStrat(std::string);

	//Destructor
	~Point();
};




#endif


