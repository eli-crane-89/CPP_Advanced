#ifndef SHAPEDECORATOR_CPP
#define SHAPEDECORATOR_CPP

#include <iostream>

#include "ShapeDecorator.hpp"

//Constructors
ShapeDecorator::ShapeDecorator() : sp_shape(nullptr) {};
ShapeDecorator::ShapeDecorator(const std::shared_ptr<CAD::Shape>& sp) : sp_shape(sp) {};

//Destructor
ShapeDecorator::~ShapeDecorator() {};

//Print
void ShapeDecorator::print(std::ostream& o) const {
	o << *sp_shape.get();
}

//Assignment operator
ShapeDecorator& ShapeDecorator::operator = (const ShapeDecorator& source) {
	if (this != &source)
	{
		//Shape::operator=(source);
		sp_shape = source.sp_shape;
	}

	return *this;
}


//Stream
std::ostream& operator << (std::ostream& stream, const ShapeDecorator& shapeDec) {
	stream << shapeDec.sp_shape.get();
	return stream;
}

//Clone
std::shared_ptr<CAD::Shape> ShapeDecorator::Clone() {
	return std::make_shared<ShapeDecorator>(sp_shape);
};

//Getters and Setters
std::shared_ptr<CAD::Shape> ShapeDecorator::GetShape() const{
	return sp_shape;
};

void ShapeDecorator::SetShape(const std::shared_ptr<CAD::Shape>& sp) {
	sp_shape = sp;
}

#endif