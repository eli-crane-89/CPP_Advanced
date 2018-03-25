#include <iostream>
#include <functional>

#include "CompileTimeVector.hpp"

//Function
int modifyFunction(int& term) {
	term *= 2;

	return term;
}




int main()
{
	//b)
	//Default
	Vector<int, 5> vDef = Vector<int, 5>();
	vDef.Print();

	//With value
	Vector<int, 5> vec1(3);
	vec1.Print();

	//Assignment
	Vector<int, 5> vec2 = vec1;
	vec2.Print();

	//c)
	//Addition
	Vector<int, 5> vec3 = vec1 + vec2;
	vec3.Print();

	//Subtraction
	Vector<int, 5> vec4 = vec3 - vec2;
	vec4.Print();

	//Unary Subtraction
	Vector<int, 5> vec5 = vec4 - 2;
	vec5.Print();

	//Scalar Multiplication
	Vector<int, 5> vec6 = vec5 * 5; 
	vec6.Print();

	//d)

	//Multiplication with friend
	Vector<int, 5> vec7 = 17 * vec6 ;
	vec7.Print();
	
	//e) Use modify function
	std::function<int(int&)> f_mod = modifyFunction;
	vec7.modify(f_mod);
	vec7.Print();

    return 0;
}

