#ifndef EXERCISE5_ADDCODE_HPP
#define EXERCISE5_ADDCODE_HPP

#include <iostream>
#include <tuple>

using namespace std;

//Forward Declarations
class Shape;
class Circle;
class Line;
class IODevice;

//Define types
using ShapePointer = std::shared_ptr<Shape>;
using IODevicePointer = std::shared_ptr<IODevice>;
using ConstructedTuple = tuple<ShapePointer, IODevicePointer>;

//IODevice
class IODevice
{
	// Interface for displaying CAD objects
public:
	virtual void operator << (const Circle& c) = 0;
	virtual void operator << (const Line& l) = 0;
};


// Class hierarchy
class Shape
{
public:
	virtual void display(IODevice& ioDevice) const = 0;
};

class Circle : public Shape
{
private:
	double _radius;

public:
	//Define radius
	Circle(double radius) : _radius(radius) {};

	void display(IODevice& ioDevice) const {
		ioDevice << *this;
	}

	double radius() const { return _radius; };
};

class Line : public Shape
{
private:
	double _length;

public:
	//Define length
	Line(double length) : _length(length) {};

	void display(IODevice& ioDevice) const {
		ioDevice << *this;
	}

	double length() const { return _length; };
};

class IODevice_A : public IODevice
{
private:
	int _resMultiplier;
public:

	//Set a default resolution multiplier
	IODevice_A() : _resMultiplier(300) {};

	void operator << (const Circle& c) {
		cout << "The circle is output with " << c.radius() * _resMultiplier << " pixels. " << endl;
	}

	void operator << (const Line& l) {
		cout << "The line is output with " << l.length() * _resMultiplier << " pixels. " << endl;
	}

	int resMutliplier() { return _resMultiplier; };

};

class IODevice_B : public IODevice
{
private:
	int _resMultiplier;
public:

	//Set a default resolution multiplier
	IODevice_B() : _resMultiplier(600) {};


	void operator << (const Circle& c) {
		cout << "The circle is output with " << c.radius() * _resMultiplier << " pixels. " << endl;
	}

	void operator << (const Line& l) {
		cout << "The line is output with " << l.length() * _resMultiplier << " pixels. " << endl;
	}

	int resMutliplier() { return _resMultiplier; };

};



class Builder
{
	// A Builder hierarchy that builds shapes and io devices
public:
	ConstructedTuple getProduct() {
		ConstructedTuple ct = make_tuple(getShape(), getIODevice());

		return ct;
	}

	// Hook functions that derived classes must implement
	virtual ShapePointer getShape() = 0;
	virtual IODevicePointer getIODevice() = 0;
};

class Builder_Circle_A : public Builder {
public:
	ShapePointer getShape() {
		ShapePointer sp(new Circle(4.5));

		return sp;
	}

	IODevicePointer getIODevice() {
		IODevicePointer io(new IODevice_A);

		return io;
	}
};

class Builder_Line_A : public Builder {
public:
	ShapePointer getShape() {
		ShapePointer sp(new Line(6.8));

		return sp;
	}

	IODevicePointer getIODevice() {
		IODevicePointer io(new IODevice_A);

		return io;
	}
};

class Builder_Circle_B : public Builder {
public:
	ShapePointer getShape() {
		ShapePointer sp(new Circle(4.5));

		return sp;
	}

	IODevicePointer getIODevice() {
		IODevicePointer io(new IODevice_B);

		return io;
	}
};

class Builder_Line_B : public Builder {
public:
	ShapePointer getShape() {
		ShapePointer sp(new Line(6.8));

		return sp;
	}

	IODevicePointer getIODevice() {
		IODevicePointer io(new IODevice_B);

		return io;
	}
};

#endif