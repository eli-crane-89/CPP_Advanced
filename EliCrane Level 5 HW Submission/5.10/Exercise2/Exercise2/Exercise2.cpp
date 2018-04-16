#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <algorithm>


int main()
{
	using namespace boost::numeric::ublas;

	

	//a)
	matrix<double> m(7, 3, 4);

	//b)
	m(1, 2) = 7.8;
	auto lPrint = [](matrix<double> m) {
		for (auto i = 0; i < m.size1(); ++i) {
			for (auto j = 0; j < m.size2(); j++) {
				std::cout << m(i, j) << ", ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	};

	lPrint(m);

	//c)
	matrix<double> m2(7, 3, 1);

	//add
	m += m2;
	lPrint(m);

	//subtract
	m -= m2;
	lPrint(m);

	//d) resize
	m.resize(1, 4); //initializes extra column with min T value
	lPrint(m);

	//e)
	matrix<double> mZero(5, 6, 0);
	lPrint(mZero);

	matrix<double> mIdent(5, 5, 0);

	for (auto i = 0; i < mIdent.size1(); ++i) {
		for (auto j = 0; j < mIdent.size2(); ++j) {
			if (i == j) {
				mIdent(i, j) = 1;
			}
		}

	}

	lPrint(mIdent);

    return 0;
}

