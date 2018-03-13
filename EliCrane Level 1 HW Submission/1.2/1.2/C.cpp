#ifndef C_CPP
#define C_CPP

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

#include "C.hpp"

//Move Constructor
template<class T>
constexpr C<T>::C(C<T> &&source) {
	cout << "The move constructor has been called." << endl;

	m_vectorT = std::move(source.m_vectorT);
}

//Setter
template<class T>
constexpr void C<T>::VectorT(const vector<T> &v) noexcept{
	m_vectorT = v;
}

//Getter
template<class T>
vector<T> C<T>::VectorT() const noexcept{
	return m_vectorT;
}


//Move Assignment Operator
template<class T>
C<T>& C<T>::operator=(C<T> &&source) {
	cout << "The move assignment operator has been called." << endl;

	m_vectorT = std::move(source.m_vectorT);

	return *this;

}

//Destructor
template<class T>
C<T>::~C() {
	cout << "The destructor has been called." << endl;
}

#endif