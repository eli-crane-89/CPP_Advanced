#ifndef COMPILETIMEVECTOR_HPP
#define COMPILETIMEVECTOR_HPP

#include <array>
#include <functional>

//Forward declare
template<typename T, int N> class Vector;

template<typename T, int N>
class Vector {

private:
	std::array<T, N> arr; //Using std::array because it should be as performant as C style array and easier to work with

public:

	//Constructor
	Vector();
	Vector(T);
	Vector(const Vector<T, N>&);

	//Get Non Const Array For Friend Function Operator Overload
	std::array<T, N>& GetArr();
	const std::array<T, N>& GetArr() const;

	//Operator overload
	Vector<T, N>& operator = (const Vector<T, N>&);
	T& operator[](int);
	const T& operator[](int) const;
	const Vector<T, N> operator+(const Vector<T, N>&) const;
	const Vector<T, N> operator-(const Vector<T, N>&) const;
	const Vector<T, N> operator-(const T&) const;
	const Vector<T, N> operator*(const T&) const;

	template<typename F>
	friend Vector<T, N> operator * (const F&, const Vector<T, N>&);

	//Transform
	void modify(const std::function<T(T&)>&);

	//Helper
	void Print();



};



#ifndef COMPILETIMEVECTOR_CPP // Must be the same name as in source file #define
#include "CompileTimeVector.cpp"
#endif

#endif