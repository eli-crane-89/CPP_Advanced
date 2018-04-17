#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/range/numeric.hpp>
#include <iostream>
#include <boost/numeric/ublas/operations.hpp>
#include <boost/numeric/ublas/io.hpp>


int main()
{
	using namespace boost::numeric::ublas;

	vector<double> v1(4);
	vector<double> v2(4);
	
	auto lFill = [](vector<double>& v, double seed) {
		for (int i = 0; i < v.size(); ++i) {
			v.insert_element(i, seed * i);
		}
	};

	lFill(v1, 3.4);
	lFill(v2, 6.8);


	//Inner Product
	std::cout << inner_prod(v1, v2) << std::endl;

	//Out Product
	std::cout << outer_prod(v1, v2) << std::endl;

	//Add
	v1 += v2;
	std::cout << v1 << std::endl;

	//Subtract
	v1 -= v2;
	std::cout << v1 << std::endl;

	//Euclidean Norm
	std::cout << norm_2(v1) << std::endl;

	//L1 Norm
	std::cout << norm_1(v1) << std::endl;

	//Max Norm
	std::cout << norm_inf(v1) << std::endl;

	//Define Matrix
	matrix<double> m(3, 4);
	for (int i = 0; i < m.size1(); ++i)
		for (int j = 0; j < m.size2(); ++j)
			m(i, j) = 3 * i + j;

	//L1 norm
	std::cout << norm_1(m) << std::endl;

	//Max Norm
	std::cout << norm_inf(m) << std::endl;

	//Multiply by vector
	std::cout << prod(m, v1) << std::endl;



    return 0;
}

