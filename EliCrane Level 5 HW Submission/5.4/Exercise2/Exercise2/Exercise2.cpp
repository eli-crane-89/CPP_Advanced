#include <iostream>
#include <list>
#include <functional>
#include <boost/functional/hash.hpp>

#include "Point.hpp"
#include "Line.hpp"

using namespace Eli::CAD;
int main()
{
	//a)
	Point p1 = Point(3, 4);
	Point p2 = Point(5, 6);
	std::cout << "p1 hash: " << hash_value(p1) << std::endl;
	std::cout << "p2 hash: " << hash_value(p2) << std::endl;

	Line l1 = Line(p1, p2);

	Line l2 = Line(p2, p1);

	//The same hash value is produced for both l1 and l2, but since they are the same line,
	//just with start and end points reversed, that makes sense
	std::cout << "l1 hash: " << hash_value(l1) << std::endl;
	std::cout << "l2 hash: " << hash_value(l2) << std::endl;

	//b)
	Point p3 = Point(3, 9);
	Point p4 = Point(10, 8);

	std::list<Point> lPoint;

	lPoint.push_back(p1);
	lPoint.push_back(p2);
	lPoint.push_back(p3);
	lPoint.push_back(p4);

	//Note that without a function hash_value defined for the class, hash_range cannot be called on it
	std::size_t hashRange = boost::hash_range(lPoint.begin(), lPoint.end());
	std::cout << "The hash range is: " << hashRange << std::endl;

	//c)
	auto f_ph = std::bind(PointHash(), p1);
	std::cout << "The function object produces for p1 the following hash: " << f_ph() << std::endl;

    return 0;
}

