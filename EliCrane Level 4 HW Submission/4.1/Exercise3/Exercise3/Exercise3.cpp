#include <functional>

#include "CompileTimeMatrix.hpp"

int modifyFunction(int& term) {
	term *= 2;

	return term;
}



int main()
{

	//b)

	//Create and Print
	Matrix<int, 3, 4> m1 = Matrix<int, 3, 4>();
	m1.Print();

	Matrix<int, 3, 4> m2 = Matrix<int, 3, 4>(7);
	m2.Print();
	
	Matrix<int, 3, 4> m3 = m2;
	m3.Print();

	//Add
	Matrix<int, 3, 4> m4 = m2 + m3;
	m4.Print();

	//Subtract
	Matrix<int, 3, 4> m5 = m4 - m3;
	m5.Print();

	//Unary Subtract
	Matrix<int, 3, 4> m6 = m5 - 5;
	m6.Print();

	//Scalar/Friend Multiply
	Matrix<int, 3, 4> m7 = 12 * m6;
	m7.Print();

	//Modify
	std::function<int(int&)> f_mod = modifyFunction;
	m7.modify(f_mod);
	m7.Print();

	//Selects item via (,)
	std::cout << m7(1, 2) << std::endl;

    return 0;
}

