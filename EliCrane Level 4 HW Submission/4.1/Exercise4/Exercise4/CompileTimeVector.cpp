#ifndef COMPILETIMEVECTOR_CPP
#define COMPILETIMEVECTOR_CPP

#include <iostream>
#include <array>

#include "CompileTimeVector.hpp"

//Constructors

//Default
template<typename T, int N>
Vector<T, N>::Vector() : arr(std::array<T, N>()) {};

//With Value
template<typename T, int N>
Vector<T, N>::Vector(T arg) : arr(std::array<T, N>()) {
	for (int i = 0; i < N; i++) {
		arr[i] = arg;
	}
};

//Copy Constructor
template <typename T, int N>
Vector<T, N>::Vector(const Vector<T, N>& orig) {
	//Directly copy r
	arr = orig.arr;

}

//Get Array
template <typename T, int N>
std::array<T, N>& Vector<T, N>::GetArr() {
	return arr;
}

//Assignment Operator
template <typename T, int N>
Vector<T, N>& Vector<T, N>::operator=(const Vector<T, N>& source) {

	if (this != &source)
	{
		arr = source.arr;
	}
	return *this;
}



//Access by index
template <typename T, int N>
T& Vector<T, N>::operator[](int index) {

	if (index < arr.size() && index >= 0) {
		return arr[index];
	}

	throw "Error Index is Out Of Bounds.\n";
}

//Access by index for const
template <typename T, int N>
const T& Vector<T, N>::operator[](int index) const {

	if (index < arr.size() && index >= 0) {
		return arr[index];
	}

	throw "Error Index is Out Of Bounds.\n";
}

//Addition
template <typename T, int N>
Vector<T, N> Vector<T, N>::operator+(const Vector<T, N>& v2) {

	//Assign return vector to *this
	Vector<T, N> vRet = *this;

	for (int i = 0; i < vRet.arr.size(); i++) {
		//Add vector array values
		vRet.arr[i] += v2.arr[i];
	}

	return vRet;

}

//Subtraction
template <typename T, int N>
Vector<T, N> Vector<T, N>::operator-(const Vector<T, N>& v2) {

	//Assign return vector to *this
	Vector<T, N> vRet = *this;

	for (int i = 0; i < vRet.arr.size(); i++) {
		//subtract vector array values
		vRet.arr[i] -= v2.arr[i];
	}
	return vRet;
}

//Unary Subtraction
template <typename T, int N>
Vector<T, N> Vector<T, N>::operator-(const T& t) {

	//Assign return vector to *this
	Vector<T, N> vRet = *this;

	//subtract single value
	for (int i = 0; i < vRet.arr.size(); i++) {
		//Add vector array values
		vRet.arr[i] -= t;
	}

	return vRet;

}

//Scalar Multiplication
template <typename T, int N>
Vector<T, N> Vector<T, N>::operator*(const T& t) {

	//Assign return vector to *this
	Vector<T, N> vRet = *this;

	//multiply elems by value
	for (int i = 0; i < vRet.arr.size(); i++) {
		//Add vector array values
		vRet.arr[i] *= t;
	}

	return vRet;

}

//Friend multiplication
template<typename Type, int N, typename F>
Vector<Type, N> operator * (const F& a, const Vector<Type, N>& v) {
	//Assign const vector
	Vector<Type, N> vRet = v;

	for (int i = 0; i < vRet.GetArr().size(); i++) {
		vRet[i] *= a;
	}

	return vRet;
}

//Modify
template<typename T, int N>
void Vector<T, N>::modify(const std::function<T(T&)>& f) {
	for (int i = 0; i < arr.size(); i++) {
 		arr[i] = f(arr[i]);
	}
}

//Print Vector
template <typename T, int N>
void Vector<T, N>::Print() {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}
}





#endif