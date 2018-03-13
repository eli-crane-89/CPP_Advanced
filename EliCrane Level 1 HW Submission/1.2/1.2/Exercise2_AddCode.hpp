#ifndef EXERCISE2_ADDCODE_HPP
#define EXERCISE2_ADDCODE_HPP

//For exercise 2.C
template < typename T >
void SwapCopyStyle(T& a, T& b)
{
	// Swap a and b in copying way; temporary object needed
	T tmp(a); // Copy constructor
	a = b; // Copy all elements from b to a
	b = tmp; // Copy all elements from tmp to b
}

template <typename T>
void SwapMoveStyle(T&& a, T&& b)
{
	//T tmp = std::move(a); // Copy constructor
	T tmp(a);
	a = std::move(b); // Copy all elements from b to a
	b = std::move(tmp); // Copy all elements from tmp to b
}

#endif