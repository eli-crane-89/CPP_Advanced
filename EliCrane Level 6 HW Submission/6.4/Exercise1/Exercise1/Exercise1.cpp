#include <iostream>

#include "ShapeComposite.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Circle.hpp"


//Remove reference so Copy Constructor is called
auto lPrint = [](const ShapeComposite sc) {

	//Use const iterators
	for (auto iter = sc.cbegin(); iter != sc.cend(); ++iter) {
		std::cout << *iter->get() << std::endl;
	}
};

int main()
{

	//c)
	CAD::Point p;
	std::shared_ptr<CAD::Shape> clone_p = p.Clone();

	std::cout << "First Clone:\n";
	std::cout << *clone_p.get() << std::endl;

	//e)
	ShapeComposite sc;

	//Make shapes
	std::shared_ptr<CAD::Shape> sp_p1 = std::make_shared<CAD::Point>(4, 5);
	std::shared_ptr<CAD::Point> sp_p2 = std::make_shared<CAD::Point>(10, 12);
	std::shared_ptr<CAD::Line> sp_l = std::make_shared<CAD::Line>(CAD::Point(1, 4), CAD::Point(5, 7));
	std::shared_ptr<CAD::Circle> sp_c = std::make_shared<CAD::Circle>(CAD::Point(5, 7), CAD::Line(CAD::Point(5, 7), CAD::Point(11, 5)));

	//Add shapes
	sc.AddShape(sp_p1);
	sc.AddShape(sp_p2);
	sc.AddShape(sp_l);
	sc.AddShape(sp_c);

	//Copy Constructor called
	std::cout << "After copy:\n";
	lPrint(sc);

	//Assignment Operator Called
	ShapeComposite sc2;
	sc2 = sc;

	lPrint(sc);

	//Clone
	std::shared_ptr<CAD::Shape> sp_sc = sc.Clone();
	std::cout << "sc Clone:\n";
	std::cout << *sp_sc.get() << std::endl;



    return 0;
}

