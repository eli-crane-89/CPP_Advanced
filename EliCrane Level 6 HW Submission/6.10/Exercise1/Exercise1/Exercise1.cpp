#include <iostream>

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "ShapeComposite.hpp"
#include "PrintVisitor.hpp"


int main()
{
	//Declare Print Visitor
	PrintVisitor pv = PrintVisitor();

	//Make Shape Pointers
	CAD::Point* p1(new CAD::Point);
	CAD::Point* p2(new CAD::Point(3,4));
	CAD::Line* l(new CAD::Line(*p1, *p2));
	CAD::Circle* c(new CAD::Circle(*p1, *l));

	//Make Shape Composite
	ShapeComposite sc;
	sc.AddShape(std::make_shared<CAD::Point>(2, 3));
	sc.AddShape(std::make_shared<CAD::Point>(7, 8));
	sc.AddShape(std::make_shared<CAD::Line>(*p1, *p2));
	sc.AddShape(std::make_shared<CAD::Circle>(*p1,*l));

	//Make Nested Shape Composite
	ShapeComposite sc2;
	sc2.AddShape(std::make_shared<CAD::Point>(999,999));
	std::shared_ptr<ShapeComposite> sp_sc = std::make_shared<ShapeComposite>();
	sp_sc->AddShape(std::make_shared<CAD::Point>(2, 4));
	sp_sc->AddShape(std::make_shared<CAD::Point>(6, 18));
	sp_sc->AddShape(std::make_shared<CAD::Line>(*p1, *p2));
	sp_sc->AddShape(std::make_shared<CAD::Circle>(*p1, *l));
	sc2.AddShape(sp_sc);


	//Visit Objects
	p1->accept(pv);
	p2->accept(pv);
	l->accept(pv);
	c->accept(pv);
	sc.accept(pv);
	sc2.accept(pv);

	//Nested composites print as expected

    return 0;
}

