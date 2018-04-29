#ifndef NAMEDECORATOR_CPP
#define NAMEDECORATOR_CPP

#include "NameDecorator.hpp"
#include <iostream>

NameDecorator::NameDecorator() : Name(""), ShapeDecorator() {};
NameDecorator::NameDecorator(const std::shared_ptr<CAD::Shape>& shape, std::string name) : Name(name), ShapeDecorator(shape) {};

//Getters and Setters
std::string NameDecorator::GetName() const {
	return Name;
}

void NameDecorator::SetName(std::string name) {
	Name = name;
}


//print
void NameDecorator::print(std::ostream& o) const{
	o << "The name of the shape " << this->GetShape() << " is " << Name << std::endl;
}

//Clone
std::shared_ptr<NameDecorator> NameDecorator::Clone() {
	return std::make_shared<NameDecorator>(this->GetShape(), Name);
}

//Assignment Operator
NameDecorator& NameDecorator::operator = (const NameDecorator& source) {
	if (this != &source)
	{
		ShapeDecorator::operator=(source);
		Name = source.Name;
	}

	return *this;
}



//stream
std::ostream& operator << (std::ostream& os, const NameDecorator& nd) {
	os << "The name of the shape " << *nd.GetShape() << " is " << nd.GetName() << std::endl;
	return os;
};

#endif