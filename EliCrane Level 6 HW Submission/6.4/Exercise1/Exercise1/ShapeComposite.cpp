#ifndef SHAPECOMPOSITE_CPP
#define SHAPECOMPOSITE_CPP

#include <iostream>
#include <memory>

#include "ShapeComposite.hpp"
#include "Shape.hpp"

//Default constructor
ShapeComposite::ShapeComposite() {};

//Copy Constructor
ShapeComposite::ShapeComposite(const ShapeComposite& orig) {
	for (auto iter = orig.cbegin(); iter != orig.cend(); ++iter) {
		_shapePointers.push_back(*iter);
	}
}

//Add Shape
void ShapeComposite::AddShape(std::shared_ptr<CAD::Shape> shape) {
	_shapePointers.push_back(shape);
}

//Retrieve iterators
iterList ShapeComposite::begin() {
	return _shapePointers.begin();
}

iterList ShapeComposite::end() {
	return _shapePointers.end();
}

citerList ShapeComposite::cbegin() const {
	return _shapePointers.cbegin();
}

citerList ShapeComposite::cend() const{
	return _shapePointers.cend();
}

//Assignment Operator
ShapeComposite& ShapeComposite::operator = (const ShapeComposite& source) {
	if (this != &source)
	{
		Shape::operator=(source);
		for (auto iter = source.cbegin(); iter != source.cend(); ++iter) {
			_shapePointers.push_back(*iter);
		}
	}

	return *this;
}

//Clone
std::shared_ptr<CAD::Shape> ShapeComposite::Clone() {
	return std::make_shared<ShapeComposite>(*this);
}

//Count
long ShapeComposite::Count() {
	return _shapePointers.size();
}

//Print
void ShapeComposite::print(std::ostream& o) const {
	for (auto iter = _shapePointers.cbegin(); iter != _shapePointers.cend(); ++iter) {
		std::cout << *iter->get() << std::endl;
	}
}

#endif