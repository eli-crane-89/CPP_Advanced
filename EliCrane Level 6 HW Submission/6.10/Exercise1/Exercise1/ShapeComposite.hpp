#ifndef SHAPECOMPOSITE_HPP
#define SHAPECOMPOSITE_HPP

#include <list>
#include <memory>

#include "Shape.hpp"
#include "ShapeVisitor.hpp"

//typedefs
typedef std::list<std::shared_ptr<CAD::Shape>>::iterator iterList;
typedef std::list<std::shared_ptr<CAD::Shape>>::const_iterator citerList;

class ShapeComposite : public CAD::Shape {

private:

	std::list<std::shared_ptr<CAD::Shape>> _shapePointers;

	//Copy Constructor
	ShapeComposite(const ShapeComposite&);

	//Assignment Operator
	ShapeComposite& operator = (const ShapeComposite&);

protected:
	void print(std::ostream&) const;
	

public:

	//Default constructor;
	ShapeComposite();

	//Add Shape
	void AddShape(std::shared_ptr<CAD::Shape> S);

	//Visitor
	void accept(ShapeVisitor&);

	//Iterators
	iterList begin();
	iterList end();
	citerList cbegin() const;
	citerList cend() const;

	//Count
	long Count();


};



#endif
