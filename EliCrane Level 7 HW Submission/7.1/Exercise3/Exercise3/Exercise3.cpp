#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include "ConsoleShapeFactory.hpp"
#include "PolyLine.hpp"


int main()
{
	//a)
	ConsoleShapeFactory cs_factory;
	auto sp_line = cs_factory.CreateLine(1.3, 4.5, 6.7, 7.99);
	std::cout << *sp_line << std::endl;

	//b)
	const size_t size = 5;
	//With vector
	std::shared_ptr<PolyLine<std::vector>> pline1 = cs_factory.CreatePolyLine<std::vector>(size, 4.5);
	//With list
	std::shared_ptr<PolyLine<std::list>> pline2 = cs_factory.CreatePolyLine<std::list>(size, 4.5);
	//With deque
	std::shared_ptr<PolyLine<std::deque>> pline3 = cs_factory.CreatePolyLine<std::deque>(size, 4.5);

	pline1.get()->print();
	pline2.get()->print();
	pline3.get()->print();

	//The Template Method Pattern allows for a lot of flexibility 

    return 0;
}


