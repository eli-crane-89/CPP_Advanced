#ifndef SHAPEVISITOR_HPP
#define SHAPEVISITOR_HPP


namespace CAD{
	class Shape;
	class Point;
	class Line;
	class Circle;
}

class ShapeVisitor {
public:

	//Visit Methods
	virtual void Visit(CAD::Point*) = 0;
	virtual void Visit(CAD::Line*) = 0;
	virtual void Visit(CAD::Circle*) = 0;
	virtual void Visit(CAD::Shape*) = 0;


};

#endif
