#ifndef CONSOLESHAPEFACTORY_HPP
#define CONSOLESHAPEFACTORY_HPP

#include "ShapeFactory.hpp"

class ConsoleShapeFactory : public ShapeFactory {

public:
	ConsoleShapeFactory();
	~ConsoleShapeFactory();

	//Functions for object creation
	std::shared_ptr<CAD::Point> CreatePoint(double, double);
	std::shared_ptr<CAD::Line> CreateLine(const CAD::Point&, const CAD::Point&);
	std::shared_ptr<CAD::Circle> CreateCircle(const CAD::Point&, const CAD::Line&);



};

#endif // !CONSOLESHAPEFACTORY_HPP
