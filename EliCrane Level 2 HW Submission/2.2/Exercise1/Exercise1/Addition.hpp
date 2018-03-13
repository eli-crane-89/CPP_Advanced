#ifndef ADDITION_HPP
#define ADDITION_HPP

#include <iostream>

using namespace std;


//a) Addition

//vector
template <typename T>
T Addition_impl(const T& t1, const T& t2, std::true_type) {
	T ret = t1; //Set return equal to t1

				//Add t2 to array
	auto iterT2 = t2.begin();

	for (auto iterRet = ret.begin(); iterRet != ret.end(); iterRet++) {
		*iterRet += *iterT2++; //post operation incrementation
	}

	return ret;
}

//For scalars
template<typename T>
T Addition_impl(const T& t1, const T& t2, std::false_type) {
	return t1 + t2;
}


//Bridge for addition
template <typename T>
T Addition(const T& t1, const T& t2)
{
	// Vector space addition
	// Best(?) approximation to testing for an array
	return Addition_impl(t1, t2, std::is_compound<T>());
}


//b) AdditiveInverse
//Vector
template <typename T>
T AdditiveInverse_impl(const T& t1, std::true_type) {
	T ret = t1; //Set return equal to t1

	for (auto iterRet = ret.begin(); iterRet != ret.end(); iterRet++) {
		(*iterRet) *= -1; //Set term equal to inverse
	}

	return ret;
}

//Scalar
template<typename T>
T AdditiveInverse_impl(const T& t1, std::false_type) {

	return t1*-1;

}

//Bridge for additive inverse
template <typename T>
T AdditiveInverse(T& val)
{
	return AdditiveInverse_impl(val, std::is_compound<T>());
}

//c) Multiply

//vector
template<typename Tbase, typename Tmult>
Tbase Multiply_impl(const Tbase& vBase, const Tmult& vMult, std::true_type) {
	Tbase ret = vBase; //set ret equal to vBase

					   //multiply ret by vmult
	auto iterMult = vMult.begin();

	for (auto iterRet = ret.begin(); iterRet != ret.end(); iterRet++) {
		*iterRet *= *iterMult++; //post operation incrementation
	}

	return ret;
}

//For scalars
template<typename Tbase, typename Tmult>
Tbase Multiply_impl(const Tbase& vBase, const Tmult& mult, std::false_type) {
	Tbase ret = vBase;

	for (auto iterRet = ret.begin(); iterRet != ret.end(); iterRet++) {
		*iterRet *= mult; //multiply by scalar
	}

	return ret;
}

//Brdige for multiply
template <typename Tbase, typename Tmult>
Tbase Multiply(const Tbase& vBase, const Tmult& mult)
{
	return Multiply_impl<Tbase, Tmult>(vBase, mult, std::is_compound<Tmult>());
}

#endif