#ifndef CONSOLESHAPEFACTORY_CPP
#define CONSOLESHAPEFACTORY_CPP

#include <iostream>

#include "ConsoleShapeFactory.hpp"

////Constructor
template<typename...Shapes>
ConsoleShapeFactory<Shapes...>::ConsoleShapeFactory() {};

//Destructor
template<typename...Shapes>
ConsoleShapeFactory<Shapes...>::~ConsoleShapeFactory(){};

//Functions for shape creation
template<typename...Shapes>
void ConsoleShapeFactory<Shapes...>::MakeShape(std::shared_ptr<CAD::Point>& sp_point) {

	double x, y;

	//Have user input coordinates
	std::cout << "Please insert x coordinate for point:\n";
	cin >> x;
	std::cout << "Please insert y coordinate for point:\n";
	cin >> y;

	sp_point = std::make_shared<CAD::Point>(x,y);
};

template<typename...Shapes>
void ConsoleShapeFactory<Shapes...>::MakeShape(std::shared_ptr<CAD::Line>& sp_point) {
	//Use Default values
	double x = 3, y = 4;
	auto p1 = CAD::Point(3, 4);
	auto p2 = CAD::Point(7, 8);

	sp_point = std::make_shared<CAD::Line>(p1, p2);
}

template<typename...Shapes>
void ConsoleShapeFactory<Shapes...>::MakeShape(std::shared_ptr<CAD::Circle>& sp_point) {
	//Use Default Values
	double x = 3, y = 4;
	auto p1 = CAD::Point(3, 4);
	auto p2 = CAD::Point(7, 8);

	CAD::Line radius(p1, p2);

	sp_point = std::make_shared<CAD::Circle>(p1, radius);
}

template<typename...Shapes>
std::tuple<Shapes...> ConsoleShapeFactory<Shapes...>::CreateShapeTuple() {
	return CreateShapeTuple(std::index_sequence_for<Shapes...>());
};








#endif // !CONSOLESHAPEFACTORY_CPP
