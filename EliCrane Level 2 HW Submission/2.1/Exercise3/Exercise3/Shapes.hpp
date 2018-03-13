#ifndef SHAPES_HPP
#define SHAPES_HPP


class Shape
{
public:
	virtual void draw() = 0;
};

class Base
{
private:
	int y;
public:
	Base() {}
	void draw() {}
};

class Point : public Shape
{
public:
	Point() {}
	virtual void draw() override {}
};

#endif