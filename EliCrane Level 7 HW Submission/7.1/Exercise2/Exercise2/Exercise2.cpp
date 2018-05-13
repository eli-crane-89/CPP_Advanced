#include <iostream>

#include "NewShapeFactory.hpp"
#include "ConsoleShapeFactory.hpp"

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

//Global function to make Point
std::shared_ptr<CAD::Point> makePoint() {
	return std::make_shared<CAD::Point>(5, 6);
}

//Global lambda to make line
auto makeLine = []() {
	return std::make_shared<CAD::Line>(CAD::Point(0,0),CAD::Point(5,7));
};


//Function object to make circle
struct makeCircle {
private:
	CAD::Point center;
	CAD::Line radius;
public:
	//Can instantiate private variables and use in operator
	makeCircle(CAD::Point p, CAD::Line l) : center(p), radius(l) {};

	SP_Circle operator()() { 
		return std::make_shared<CAD::Circle>(center, radius); 
	}
};


int main()
{
	//b) 
	
	//create functions
	//global function
	F_Point func_makePoint = makePoint;
	//lambda
	F_Line func_makeLine = makeLine;
	//Use Functor
	CAD::Point p1;
	CAD::Point p2(3, 4);
	CAD::Line l1(p1, p2);
	makeCircle mc = makeCircle(p1, l1);
	F_Circle func_makeCircle = mc;

	//Instantiate factory
	auto ns_factory = NewShapeFactory(func_makePoint, func_makeLine, func_makeCircle);

	//Create Point
	SP_Point sp_point1 = ns_factory.CreatePoint();

	//Prints Point
	sp_point1.get()->print();
	std::cout << std::endl;

	//Create Line
	SP_Line sp_line1 = ns_factory.CreateLine();

	//Prints Line
	sp_line1.get()->print();
	std::cout << std::endl;

	//Create Circle
	SP_Circle sp_circle1 = ns_factory.CreateCircle();

	//Print Circle
	sp_circle1.get()->print();
	std::cout << std::endl;

	//Console Shape Factory
	ConsoleShapeFactory cs_fact;

	//Use lambdas with capture to allow for function overloading and binding
	auto callPoint = [&cs_fact](double x, double y) {
		return cs_fact.CreatePoint();
	};
	auto callLine = [&cs_fact](CAD::Point p1, CAD::Point p2) {
		return cs_fact.CreateLine(p1, p2);
	};
	auto callCircle = [&cs_fact](CAD::Point center, CAD::Line radius) {
		return cs_fact.CreateCircle(center, radius);
	};

	//Make function objects
	std::function<std::shared_ptr<CAD::Point>()> ft_point = std::bind(callPoint, 3.4, 5.6);
	std::function<std::shared_ptr<CAD::Line>()> ft_line = std::bind(callLine, p1, p2);
	std::function<std::shared_ptr<CAD::Circle>()> ft_circle = std::bind(callCircle, p1, l1);

	//Create Factory From GOF
	auto gof_factory = NewShapeFactory(ft_point, ft_line, ft_circle);

	std::cout << *gof_factory.CreatePoint() << std::endl;
	std::cout << *gof_factory.CreateLine() << std::endl;
	std::cout << *gof_factory.CreateCircle() << std::endl;
	

	//c)
	//This is different than a strategy pattern in that it allows the consumer to completely create
	//their own factory, as opposed to all the functions being defined in the strategy pattern. This
	//could be useful if consumers may want to directly build out their own factories and use the
	//NewShapeFactory as the blueprint, in a way making the NewShapeFactory behave somewhat like an
	//abstract factory class since it does not implement its own methods.

	//d)
	std::unique_ptr<ConsoleShapeFactory> sp_cs_factory(new ConsoleShapeFactory());

	short val = 3;

	auto facPoint = [&val, &sp_cs_factory]() {
		auto pt = sp_cs_factory->CreatePoint();
		pt->X(val);
		return pt;
	};

	//The factory 
	std::function<std::shared_ptr<CAD::Point>()> func_fac_point = facPoint;
	std::cout << *func_fac_point() << std::endl;

    return 0;
}

