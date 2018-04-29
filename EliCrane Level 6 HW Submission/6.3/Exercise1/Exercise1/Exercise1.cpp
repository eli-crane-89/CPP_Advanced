#include <iostream>
#include <memory>

#include "ShapeComposite.hpp"
#include "Shape.hpp"
#include "Line.hpp"
#include "Point.hpp"
#include "Circle.hpp"

auto lPrint = [](const ShapeComposite& sc) {

	//Use const iterators
	for (auto iter = sc.cbegin(); iter != sc.cend(); ++iter) {
		std::cout << *iter->get() << std::endl;
	}
};

int main()
{
	//h)
	ShapeComposite sc;

	//Make shapes
	std::shared_ptr<CAD::Shape> sp_p1 = std::make_shared<CAD::Point>(4, 5);
	std::shared_ptr<CAD::Point> sp_p2 = std::make_shared<CAD::Point>(10, 12);
	std::shared_ptr<CAD::Line> sp_l = std::make_shared<CAD::Line>(CAD::Point(1, 4), CAD::Point(5, 7));
	std::shared_ptr<CAD::Circle> sp_c = std::make_shared<CAD::Circle>(CAD::Point(5, 7), CAD::Line(CAD::Point(5,7), CAD::Point(11,5)));

	//Add shapes
	sc.AddShape(sp_p1);
	sc.AddShape(sp_p2);
	sc.AddShape(sp_l);
	sc.AddShape(sp_c);

	//Print
	lPrint(sc);

	//Second shape composite
	std::shared_ptr<ShapeComposite> sp_sc = std::make_shared<ShapeComposite>();
	sp_sc->AddShape(sp_p1);
	sp_sc->AddShape(sp_p2);
	sp_sc->AddShape(sp_l);
	sp_sc->AddShape(sp_c);

	//Add to first
	sc.AddShape(sp_sc);

	//Print
	std::cout << std::endl;
	lPrint(sc);

	//With the polymorphic print function, everything prints
	





    return 0;
}

