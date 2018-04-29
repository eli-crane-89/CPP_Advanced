#include "ShapeDecorator.hpp"
#include "NameDecorator.hpp"
#include "Point.hpp"

#include <iostream>

int main()
{
	auto sp_p = std::make_shared<CAD::Point>(3, 4.8);
	NameDecorator nd(sp_p, "Point177");

	auto nd2 = nd.Clone();

	std::cout << *nd2.get() << std::endl;


    return 0;
}

