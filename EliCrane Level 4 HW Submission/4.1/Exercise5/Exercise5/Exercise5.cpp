#include <iostream>
#include <functional>
#include <numeric>

#include "CompileTimeVector.hpp"
#include "ProductFunctions.hpp"

template<typename T>
T opAdd(const T& t1, const T& t2) {
	std::cout << "add:\nt1: " << t1 << "\nt2:" << t2 << std::endl;
	return t1 + t2;
}

template<typename T>
int opSub(const T& t1, const T& t2) {
	std::cout << "subtract:\nt1: " << t1 << "\nt2:" << t2 << std::endl;
	return t1 - t2;
}

template<typename T>
int opMult(const T& t1, const T& t2) {
	std::cout << "mult:\nt1: " << t1 << "\nt2:" << t2 << std::endl;
	return t1 * t2;
}

template<typename T>
int opDiv(const T& t1, const T& t2) {
	std::cout << "div:\nt1: " << t1 << "\nt2:" << t2 << std::endl;
	return t1/t2;
}

int main()
{
	//a) Make vectors
	Vector<int, 3> v1(10);
	Vector<int, 3> v2(5);
	

	BinaryFunction<int> f_opV1 = opAdd<int>;
	BinaryFunction<int> f_opV2 = opMult<int>;
	BinaryFunction<int> f_opV3 = opSub<int>;
	BinaryFunction<int> f_opV4 = opDiv<int>;

	//b) Test first variant

	std::cout << inner_product(v1, v2, 0) << std::endl;
	//yup, the answer is 60 alright

	//c) Test second variant
	std::cout << inner_product(v1, v2, 0, f_opV1, f_opV2) << std::endl;
	std::cout << inner_product(v1, v2, 5, f_opV3, f_opV4) << std::endl;

	//d)
	auto op = outerProduct(v1, v2);
	op.Print();

	//e)
	Complex<int> c1(3, 4);
	Complex<int> c2(5, 6);

	Vector<Complex<int>, 4> v_c1(c1);
	Vector<Complex<int>, 3> v_c2(c2);

	auto op_c = outerProduct(v_c1, v_c2);
	op_c.Print();

    return 0;
}

