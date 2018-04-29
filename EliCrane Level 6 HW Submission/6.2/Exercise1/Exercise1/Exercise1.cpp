#include "OriginPoint.hpp"
#include "Point.hpp"
#include <iostream>


int main()
{
	CAD::Point p(2, 3);

	std::cout << p.Distance() << std::endl;

	//Change origin point
	OriginPoint::instance()->X(17);
	OriginPoint::instance()->Y(13.4);

	std::cout << p.Distance() << std::endl; //Distance changes
	

	

    return 0;
}

