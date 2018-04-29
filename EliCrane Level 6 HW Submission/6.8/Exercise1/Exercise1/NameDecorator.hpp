#ifndef NAMEDECORATOR_HPP
#define NAMEDECORATOR_HPP

#include "ShapeDecorator.hpp"

#include <string>

class NameDecorator : public ShapeDecorator {
private:
	std::string Name;

protected:
	void print(ostream&) const;

public:
	//Constructors
	NameDecorator();
	NameDecorator(const std::shared_ptr<CAD::Shape>&, std::string);

	//Getters and Setters;
	std::string GetName() const;
	void SetName(std::string name);

	//helpers
	NameDecorator& operator = (const NameDecorator& source);
	std::shared_ptr<NameDecorator> Clone();
	friend std::ostream& operator << (std::ostream&, const NameDecorator&);
};

#endif