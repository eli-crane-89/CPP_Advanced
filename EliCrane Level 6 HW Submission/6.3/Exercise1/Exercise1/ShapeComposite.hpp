#ifndef SHAPECOMPOSITE_HPP
#define SHAPECOMPOSITE_HPP

#include <list>
#include <memory>

#include "Shape.hpp"

//e) typedefs
typedef std::list<std::shared_ptr<CAD::Shape>>::iterator iterList;
typedef std::list<std::shared_ptr<CAD::Shape>>::const_iterator citerList;

//a)
class ShapeComposite : public CAD::Shape {

private:

	//b)
	std::list<std::shared_ptr<CAD::Shape>> _shapePointers;

	//c)
	//Copy Constructor
	ShapeComposite(const ShapeComposite&);

	//Assignment Operator
	ShapeComposite& operator = (const ShapeComposite&);

protected:
	void print(std::ostream&) const;
	

public:

	//Default constructor;
	ShapeComposite();

	//d) Add Shape Method
	void AddShape(std::shared_ptr<CAD::Shape> S);

	//f) Iterator Return Functions
	iterList begin();
	iterList end();
	citerList cbegin() const;
	citerList cend() const;

	//g) Count
	long Count();


};



#endif
