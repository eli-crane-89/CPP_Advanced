#ifndef COMPILETIMEMATRIX_CPP
#define COMPILETIMEMATRIX_CPP

#include <iostream>

#include "CompileTimeMatrix.hpp"
#include "CompileTimeVector.hpp"

//Constructors

//Default
template <typename V, int NR, int NC>
Matrix<V, NR, NC>::Matrix() : matrix(Vector<Vector<V, NC>, NR>()) {};

//With Value
template <typename V, int NR, int NC>
Matrix<V, NR, NC>::Matrix(V arg) : matrix(Vector<Vector<V, NC>, NR>()) {
	for (int i = 0; i < NR; i++) {
		for (int j = 0; j < NC; j++) {
			matrix[i][j] = arg;
		}
	}
};

//Copy Constructor
template <typename V, int NR, int NC>
Matrix<V, NR, NC>::Matrix(const Matrix<V, NR, NC>& orig) {
	matrix = orig.matrix;
}

//Get Matrix
template <typename V, int NR, int NC>
VectorMatrix<V, NR, NC>& Matrix<V, NR, NC>::GetMatrix() {
	return matrix;
}

//Assignment Operator
template <typename V, int NR, int NC>
Matrix<V, NR, NC>& Matrix<V, NR, NC>::operator=(const Matrix<V, NR, NC>& source) {

	if (this != &source)
	{
		matrix = source.matrix;
	}
	return *this;
}

//Access by index
template <typename V, int NR, int NC>
Vector<V, NC>& Matrix<V, NR, NC>::operator[](int index) {

	if (index < NR && index >= 0) {
		return matrix[index];
	}

	throw "Error Index is Out Of Bounds.\n";
}

//Access by index for const
template <typename V, int NR, int NC>
const Vector<V, NC>& Matrix<V, NR, NC>::operator[](int index) const{

	if (index < NR && index >= 0) {
		return matrix[index];
	}

	throw "Error Index is Out Of Bounds.\n";
}

//Addition
template <typename V, int NR, int NC>
Matrix<V, NR, NC> Matrix<V, NR, NC>::operator+(const Matrix<V, NR, NC>& v2) {

	//Assign return vector to *this
	Matrix<V, NR, NC> vRet = *this;

	for (int i = 0; i < NR; i++) {
		//Add via Compile Time Vector overload
		vRet[i] = vRet[i] + v2[i];
	}

	return vRet;

}

//Subtraction
template <typename V, int NR, int NC>
Matrix<V, NR, NC> Matrix<V, NR, NC>::operator-(const Matrix<V, NR, NC>& v2) {

	//Assign return vector to *this
	Matrix<V, NR, NC> vRet = *this;

	for (int i = 0; i < NR; i++) {
		//Subtract via Compile Time Vector overload
		vRet[i] = vRet[i] - v2[i];
	}

	return vRet;
}

//Unary Subtraction
template <typename V, int NR, int NC>
Matrix<V, NR, NC> Matrix<V, NR, NC>::operator-(const V& t) {

	//Assign return vector to *this
	Matrix<V, NR, NC> vRet = *this;

	//subtract single value
	for (int i = 0; i < NR; i++) {
		//Subtract unary via Compile Time Vector overload
		vRet[i] = vRet[i] - t;
	}

	return vRet;

}

//() operator overload
template <typename V, int NR, int NC>
V& Matrix<V, NR, NC>::operator()(int r, int c) {

	return matrix[r][c];
};


//Scalar Multiplication
//template <typename V, int NR, int NC>
//Matrix<V, NR, NC> Matrix<V, NR, NC>::operator*(const V& t) {
//
//	//Assign return vector to *this
//	Matrix<V, NR, NC> vRet = *this;
//
//	//multiply single value
//	for (int i = 0; i < NR; i++) {
//		vRet[i] = vRet[i] * t;
//	}
//
//	return vRet;
//
//}

//Friend multiplication
template <typename V, int NR, int NC, typename F>
Matrix<V, NR, NC> operator * (const F& a, const Matrix<V, NR, NC>& m) {
	//Assign matrix
	Matrix<V, NR, NC> vRet = m;

	for (int i = 0; i < NR; i++) {
		//subtract value
		vRet.GetMatrix()[i] = vRet.GetMatrix()[i] * a;
	}

	return vRet;
}

//Modify
template <typename V, int NR, int NC>
void Matrix<V, NR, NC>::modify(const std::function<V(V&)>& f) {

	for (int i = 0; i < NR; i++) {
		matrix[i].modify(f);
	}
}


//Print Matrix
template <typename V, int NR, int NC>
void Matrix<V, NR, NC>::Print() {
	for (int i = 0; i < NR; i++) {
		for (int j = 0; j < NC; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


#endif