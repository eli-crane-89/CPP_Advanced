#ifndef C_HPP
#define C_HPP

#include <vector>

using namespace std;

template <typename T>
class C
{
private:
	vector<T> m_vectorT;

	//Copy Constructor
	constexpr C(const C<T>&) noexcept = delete;

	//Assignment Operator
	C<T>& operator = (const C<T>&) noexcept = delete;

public:
	//Constructors
	explicit constexpr C() noexcept = default;
	constexpr C(C<T>&&);

	//Getters and Setters
	constexpr void VectorT(const vector<T>&) noexcept;
	vector<T> VectorT() const noexcept;

	//Move Assignment Operator
	C<T>& operator=(C<T>&&);

	//Destructor
	~C() noexcept;
};


#ifndef C_CPP // Must be the same name as in source file #define
#include "C.cpp"
#endif

#endif