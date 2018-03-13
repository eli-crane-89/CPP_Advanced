#ifndef ADDCODE_HPP
#define ADDCODE_HPP

#include <iostream>


//Convert from signed to unsigned
void convertSignedUnsigned_impl(int& val, std::true_type) {

	unsigned int valuSigned = val;

	std::cout << "The signed number has been converted to unsigned number: " << valuSigned << std::endl;
}

//Convert unsigned to signed
void convertSignedUnsigned_impl(unsigned int& val, std::false_type) {

	int valSigned = val;

	std::cout << "The signed number has been converted to signed number: " << valSigned << std::endl;
}


//Bridge for convert signed to unsined or visa versa
template<typename T>
void ConvertSignedUnsigned(T& val) {
	convertSignedUnsigned_impl(val, std::is_signed<T>());
}

//Convert from const to non const
template<typename T>
void convertConstNonConst_impl(T& val, std::true_type) {
	using nonconstT = std::remove_const<T>::type;

	nonconstT nonConstVal = val;

	std::cout << "The const object has been set to a non const type." << std::endl;
}

//Convert from non const to const
template<typename T>
void convertConstNonConst_impl(T& val, std::false_type) {

	const T constVal = val;

	std::cout << "The non const object has been set to a const type." << std::endl;
}

//Bridge to convert from const to non const or visa versa
template<typename T>
void ConvertConstNonConst(T& val) {
	convertConstNonConst_impl(val, std::is_const<T>());
}

//Convert from pointer to non pointer
template<typename T>
void convertPointerNonPointer_impl(T& val, std::true_type) {
	using nonPointerT = std::remove_pointer<T>::type;

	nonPointerT nonPointer = *val;

	std::cout << "The pointer has been set to a non pointer type." << std::endl;
}

//Convert from non pointer to pointer
template<typename T>
void convertPointerNonPointer_impl(T& val, std::false_type) {
	T * pointer = &val;

	std::cout << "The non pointer has been set to a pointer type." << std::endl;
}

//Bridge to convert from pointer to non pointer or visa versa
template<typename T>
void ConvertPointerNonPointer(T& val) {
	convertPointerNonPointer_impl(val, std::is_pointer<T>());
}

//Convert from volatile to non volatile
template<typename T>
void convertVolatileNonVolatile_impl(T& val, std::true_type) {
	using nonVolatileT = std::remove_volatile<T>::type;

	nonVolatileT nonVolatile = val;

	std::cout << "The volatile type has been set to a non volatile type." << std::endl;
}

//Convert from non volatile to volatile
template<typename T>
void convertVolatileNonVolatile_impl(T& val, std::false_type) {
	volatile T valVolatile = val;

	std::cout << "The non volatile type has been set to a volatile type." << std::endl;
}


//Brdige to convert from volatile to non volatile or visa versa
template<typename T>
void ConvertVolatileNonVolatile(T& val) {
	convertVolatileNonVolatile_impl(val, std::is_volatile<T>());
}



#endif