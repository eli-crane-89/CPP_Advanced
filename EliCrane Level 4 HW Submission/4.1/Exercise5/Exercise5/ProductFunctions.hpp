#ifndef PRODUCTFUNCTIONS_HPP
#define PRODUCTFUNCTIONS_HPP

#include <functional>
#include <numeric>
#include <complex>

#include "CompileTimeVector.hpp"
#include "CompileTimeMatrix.hpp"

template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue) {

	return std::inner_product(v1.GetArr().begin(), v1.GetArr().end(), v2.GetArr().begin(), initValue);

};

template <typename T>
using BinaryFunction = std::function < T(const T& t1, const T& t2)>;

template <typename T, int N>
T inner_product(const Vector<T, N>& v1, const Vector<T, N>& v2, T initValue, const BinaryFunction<T>& op1, const BinaryFunction<T>& op2) {
	
	return std::inner_product(v1.GetArr().begin(), v1.GetArr().end(), v2.GetArr().begin(), initValue, op1, op2);
};

//Return a matrix with rows equal to the size of v1 and columns equal to the size of v2
template <typename T, int N_V1, int N_V2>
Matrix<T, N_V1, N_V2> outerProduct(const Vector<T, N_V1>& v1, const Vector<T, N_V2>& v2) {
	Matrix<T, N_V1, N_V2> retMat;

	auto iter_v1 = v1.GetArr().begin();

	for (int i = 0; i < N_V1; i++) {
		auto iter_v2 = v2.GetArr().begin(); //Set during loop back to beginning for each row
		for (int j = 0; j < N_V2; j++) {
			retMat[i][j] = *iter_v1 * *iter_v2;
			iter_v2++; //increment iter_v2
		}
		iter_v1++; //increment iter_v1
	}

	return retMat;
	
}

template<typename T>
using Complex = std::complex<T>;

template <typename T, int N_V1, int N_V2>
Matrix<Complex<T>, N_V1, N_V2> outerProduct(const Vector<Complex<T>, N_V1>& v1, const Vector<Complex<T>, N_V2>& v2) {
	Matrix<Complex<T>, N_V1, N_V2> retMat;

	auto iter_v1 = v1.GetArr().begin();

	for (int i = 0; i < N_V1; i++) {
		auto iter_v2 = v2.GetArr().begin(); //Set during loop back to beginning for each row
		for (int j = 0; j < N_V2; j++) {
			//Get real part ((v1.real * v2.real) + (v1.imag * v2.image * i^2)
			auto real = iter_v1->real() * iter_v2->real() - (iter_v1->imag() * iter_v2->imag());

			//Get imaginary part ((v1.real * v2.image) + (v1.imag * v2.real)
			auto imag = iter_v1->real() * iter_v2->imag() + iter_v1->imag() * iter_v2->real();

			retMat[i][j] = Complex<T>(real, imag) ;
			iter_v2++;
		}
		iter_v1++;
	}

	return retMat;

}
 

#endif // !PRODUCTFUNCTIONS_HPP