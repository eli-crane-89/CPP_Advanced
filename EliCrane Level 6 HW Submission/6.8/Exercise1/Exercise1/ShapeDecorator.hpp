#ifndef SHAPEDECORATOR_HPP
#define SHAPEDECORATOR_HPP

#include "Shape.hpp"

#include <memory>

class ShapeDecorator : public CAD::Shape {

private:
	std::shared_ptr<CAD::Shape> sp_shape;

protected:
	void print(ostream&) const;

public:

	//Constructors
	ShapeDecorator();
	ShapeDecorator(const std::shared_ptr<CAD::Shape>&);
	~ShapeDecorator();

	//Methods
	ShapeDecorator& operator = (const ShapeDecorator& source);
	std::shared_ptr<CAD::Shape> Clone();
	friend std::ostream& operator << (std::ostream&, const ShapeDecorator&);

	//Getters and Setters
	std::shared_ptr<CAD::Shape> GetShape() const;
	void SetShape(const std::shared_ptr<CAD::Shape>&);
};

#endif // !SHAPEDECORATOR_HPP
