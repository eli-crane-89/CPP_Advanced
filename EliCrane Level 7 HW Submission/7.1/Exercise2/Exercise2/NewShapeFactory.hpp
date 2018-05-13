#ifndef NEWSHAPEFACTORY_HPP
#define NEWSHAPEFACTORY_HPP

#include <functional>
#include <memory>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

//Define Types
using SP_Point = std::shared_ptr<CAD::Point>;
using F_Point = std::function<SP_Point()>;
using SP_Circle = std::shared_ptr<CAD::Circle>;
using F_Circle = std::function<SP_Circle()>;
using SP_Line = std::shared_ptr<CAD::Line>;
using F_Line = std::function<SP_Line()>;

class NewShapeFactory {
private:
	F_Point _f_point;
	F_Line _f_line;
	F_Circle _f_circle;

public:
	//Constructor
	NewShapeFactory(F_Point, F_Line, F_Circle);

	//Creat Shape Method
	SP_Point CreatePoint();
	SP_Line CreateLine();
	SP_Circle CreateCircle();


};


#endif