#include <boost/numeric/ublas/matrix_sparse.hpp>
#include <boost/numeric/ublas/triangular.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <complex>

using namespace boost::numeric::ublas;

int main()
{
	//a)
	std::complex<double> c1(5, 4);
	mapped_matrix<std::complex<double>> m(3, 3, 3*3);

	std::cout << m << std::endl;

	//insertion
	m.insert_element(1, 2, c1);
	m.insert_element(1, 1, c1);
	m.insert_element(2, 2, c1);
	std::cout << m << std::endl;

	//Erase
	m.erase_element(1, 2);
	std::cout << m << std::endl;

	//Clear
	m.clear(); //clears all elements
	std::cout << m << std::endl;

	//b)
	//Can only access columns equal to number of rows or less on lower matrix
	std::cout << std::endl;
	triangular_matrix<double, lower, row_major> ml1(3, 4);
	for (unsigned i = 0; i < ml1.size1(); ++i)
		for (unsigned j = 0; j <= i; ++j) //j <= i
			ml1(i, j) = 3 * i + j;
	std::cout << ml1 << std::endl;

	//No difference in access position despite column or row_major
	std::cout << std::endl;
	triangular_matrix<double, lower, column_major> ml2(3, 4);
	for (unsigned i = 0; i < ml2.size1(); ++i)
		for (unsigned j = 0; j <= i; ++j)
			ml2(i, j) = 3 * i + j;
	std::cout << ml2 << std::endl;

	//Can only access columns equal to or greater than row in upper matrix
	std::cout << std::endl;
	triangular_matrix<double, upper, row_major> ml3(3, 4);
	for (unsigned i = 0; i < ml3.size1(); ++i)
		for (unsigned j = i; j < ml3.size2(); ++j) //j = i
			ml3(i, j) = 3 * i + j;
	std::cout << ml3 << std::endl;

	std::cout << std::endl;
	triangular_matrix<double, upper, column_major> ml4(3, 4);
	for (unsigned i = 0; i < ml4.size1(); ++i)
		for (unsigned j = i; j < ml4.size2(); ++j)
			ml4(i, j) = 3 * i + j;
	std::cout << ml4 << std::endl;


	//c)
	std::cout << std::endl;
	matrix<double> m2(4, 3);
	std::cout << m2 << std::endl;
	triangular_adaptor<matrix<double>, upper> tau1(m2);
	std::cout << tau1 << std::endl;
	triangular_adaptor<matrix<double>, lower> tau2(m2);
	std::cout << tau2 << std::endl;


    return 0;
}

