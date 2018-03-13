#ifndef EXERCISE4_ADDCODE_HPP
#define EXERCISE4_ADDCODE_HPP

#include "Shapes.hpp" //To Get Shape

//Renaming Point2 to as not to conflict with Point
class Point2 : public Shape
{
public:
	Point2() {}
	virtual void draw() override {}
};

//For part d
class Point3 : public Shape
{
public:
	Point3() {}
	virtual void draw() override {}

	//Copy constructor
	Point3(const Point3&) = delete;

	//Assignment Operator
	Point3& operator = (const Point3&) = delete;

};

//For part e
class Point4 : public Shape
{
public:
	Point4() {}
	virtual void draw() override {}

	//Copy constructor
	Point4(const Point4&) = delete;

	//Assignment Operator
	Point4& operator = (const Point4&) = delete;

	//Move constructor
	Point4(Point4&&) {};

	//Move Assignment Operator
	Point4& operator = (const Point4&&);

};

#endif