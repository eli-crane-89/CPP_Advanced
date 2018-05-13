#include <iostream>
#include <functional>


#include "ConsoleShapeFactory.hpp"

using tupShapesT = std::tuple<std::shared_ptr<CAD::Point>, std::shared_ptr<CAD::Point>>;


int main()
{
	//Factory 1
	auto factory = ConsoleShapeFactory<std::shared_ptr<CAD::Point>, std::shared_ptr<CAD::Line>>();

	auto shapeTuple = factory.CreateShapeTuple();

	std::cout << *std::get<0>(shapeTuple) << std::endl;
	std::cout << typeid(*std::get<0>(shapeTuple)).name() << std::endl;
	std::cout << *std::get<1>(shapeTuple) << std::endl;
	std::cout << typeid(*std::get<1>(shapeTuple)).name() << std::endl;

	//Factory 2
	auto factory2 = ConsoleShapeFactory<std::shared_ptr<CAD::Circle>, std::shared_ptr<CAD::Line>, std::shared_ptr<CAD::Point>>();

	auto shapeTuple2 = factory2.CreateShapeTuple();

	std::cout << *std::get<0>(shapeTuple2) << std::endl;
	std::cout << typeid(*std::get<0>(shapeTuple2)).name() << std::endl;
	std::cout << *std::get<1>(shapeTuple2) << std::endl;
	std::cout << typeid(*std::get<1>(shapeTuple2)).name() << std::endl;
	std::cout << *std::get<2>(shapeTuple2) << std::endl;
	std::cout << typeid(*std::get<2>(shapeTuple2)).name() << std::endl;

	//The redesigned GOF pattern has an advantage in that it allows to the client
	//to create a variable list of shapes of any type. In fact, with the current design
	//there is no reason that the tuple needs to have only shapes. I can put any kind of
	//type in the tuple and then, as long as I provide a MakeShape() overload for the 
	//type in the factory, it will work. That is pretty powerful.

	//On the other hand, there is no good way to provide initial parameters to the shape.
	//The shapes would either require user input to be created (which could be time consuming)
	//Or they need to use some default value. This would make the factory redesign useful if
	//you wanted to create variable number of shapes with default values that the user may then
	//manipulate. If you wanted to create varied objects with different parameters, the standard
	//factory pattern would make more sense.

	//It is not that much easier to add a new shape such as rectangle either way. Both factories requires a new
	//CreateRectangle or MakepShape(std::shared_ptr<CAD::Rectangle>) method. 


    return 0;
}

