#ifndef SHAPECOMPOSITE_CPP
#define SHAPECOMPOSITE_CPP

#include <iostream>
#include <memory>

#include "ShapeComposite.hpp"
#include "Shape.hpp"

//Default constructor
ShapeComposite::ShapeComposite() {};

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