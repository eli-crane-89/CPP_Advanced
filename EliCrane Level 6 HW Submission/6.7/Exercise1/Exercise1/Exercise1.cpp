#include <iostream>

#include "ConsoleShapeFactory.hpp"

int main()
{
	auto factory = ConsoleShapeFactory();

	auto p1 = factory.CreatePoint(3.3, 4.0);
	auto p2 = factory.CreatePoint(6.3, 75.0);

	auto l = factory.CreateLine(*p1.get(), *p2.get());

	auto c = factory.CreateCircle(*p1.get(), *l.get());

	std::cout << *p1.get() << std::endl;
	std::cout << *p2.get() << std::endl;
	std::cout << *l.get() << std::endl;
	std::cout << *c.get() << std::endl;


    return 0;
}

