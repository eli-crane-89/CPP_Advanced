#ifndef COMPILETIMEMATRIX_HPP
#define COMPILETIMEMATRIX_HPP

#include <array>

#include "CompileTimeVector.hpp"

template <typename V, int NR, int NC>
using VectorMatrix = Vector<Vector<V, NC>, NR>;

template <typename V, int NR, int NC>
class Matrix {
private:
	VectorMatrix<V, NR, NC> matrix;

public:
	//Constructor
	Matrix();
	Matrix(V);
	Matrix(const Matrix<V, NR, NC>&);

	//Get Non Const Array For Friend Function Operator Overload
	VectorMatrix<V, NR, NC>& GetMatrix();

	//Operator overload
	Matrix<V, NR, NC>& operator = (const Matrix<V, NR, NC>&);
	Vector<V, NC>& operator[](int);
	const Vector<V, NC>& operator[](int) const;
	Matrix<V, NR, NC> operator+(const Matrix<V, NR, NC>&);
	Matrix<V, NR, NC> operator-(const Matrix<V, NR, NC>&);
	Matrix<V, NR, NC> operator-(const V&);
	V& operator()(int, int);
	//Matrix<V, NR, NC> operator*(const V&);

	template<typename F>
	friend Matrix<V, NR, NC> operator * (const F&, const Matrix<V, NR, NC>&);

	//Transform
	void modify(const std::function<V(V&)>&);

	//Helper
	void Print();

};


#ifndef COMPILETIMEMATRIX_CPP // Must be the same name as in source file #define
#include "CompileTimeMatrix.cpp"
#endif


#endif
