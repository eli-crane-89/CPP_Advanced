#ifndef PRINTVISITOR_HPP
#define PRINTVISITOR_HPP

#include "ShapeVisitor.hpp"

class PrintVisitor : public ShapeVisitor {

public:

	//Visit Methods
	void Visit(CAD::Point*);
	void Visit(CAD::Line*);
	void Visit(CAD::Circle*);
	void Visit(CAD::Shape*);

};

#endif
