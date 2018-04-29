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
	

	

protected:
	void print(std::ostream&) const;
	

public:

	//Default constructor;
	ShapeComposite();

	//Copy Constructor
	ShapeComposite(const ShapeComposite&);

	

	//iterators
	iterList begin();
	iterList end();
	citerList cbegin() const;
	citerList cend() const;

	//helper
	std::shared_ptr<CAD::Shape> Clone();
	void AddShape(std::shared_ptr<CAD::Shape> S);
	long Count();

	//Assignment Operator
	ShapeComposite& operator = (const ShapeComposite&);

};



#endif
