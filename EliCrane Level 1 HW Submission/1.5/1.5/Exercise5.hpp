#ifndef EXERCISE5_HPP
#define EXERCISE5_HPP

#include "Exercise5_AddCode.hpp"

void Exercise5() {

	std::cout << std::endl << "Exercise5: " << std::endl;

	//a) Create display classes
	IODevice_A io_a = IODevice_A();

	IODevice_B io_b = IODevice_B();

	Circle c = Circle(5.1);

	Line l = Line(48.5);

	c.display(io_a);

	l.display(io_a);

	c.display(io_b);

	l.display(io_b);

	//b) use Build factories
	Builder_Circle_A bca;
	std::get<0>(bca.getProduct())->display(*std::get<1>(bca.getProduct()));

	Builder_Line_A bla;
	std::get<0>(bla.getProduct())->display(*get<1>(bla.getProduct()));

	Builder_Circle_B bcb;
	std::get<0>(bcb.getProduct())->display(*std::get<1>(bcb.getProduct()));

	Builder_Line_B blb;
	std::get<0>(blb.getProduct())->display(*std::get<1>(blb.getProduct()));
}

#endif