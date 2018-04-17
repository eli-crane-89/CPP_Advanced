#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>

int main()
{
	using namespace boost::numeric::ublas;


	matrix<double> m(3, 3);

	//matrix_row
	for (unsigned i = 0; i < m.size1(); ++i) {
		matrix_row<matrix<double> > mr(m, i);
		for (unsigned j = 0; j < mr.size(); ++j)
			mr(j) = 3 * i + j;
		std::cout << mr << std::endl;
	}
	std::cout << std::endl;

	//matrix_column
	for (unsigned i = 0; i < m.size1(); ++i) {
		matrix_column<matrix<double> > mc(m, i);
		for (unsigned j = 0; j < mc.size(); ++j)
			mc(j) = 3 * i + j;
		std::cout << mc << std::endl;
	}
	std::cout << std::endl;

	//matrix_row
	for (unsigned i = 0; i < m.size1(); ++i) {
		matrix_range<matrix<double> > mrng(m, range(0,1), range(0,1));
		for (unsigned i = 0; i < mrng.size1(); ++i)
			for (unsigned j = 0; j < mrng.size2(); ++j)
				mrng(i, j) = 3 * i + j;
		std::cout << mrng << std::endl;
	}
	std::cout << std::endl;

	//matrix_slice
	matrix_slice<matrix<double> > ms(m, slice(1, 1, 2), slice(1, 1, 2));
	for (unsigned i = 0; i < ms.size1(); ++i)
		for (unsigned j = 0; j < ms.size2(); ++j)
			ms(i, j) = 3 * i + j;
	std::cout << ms << std::endl;

	//b)
	matrix<double> m2(3, 3);
	matrix_slice< matrix<double> > ms2(m2, slice(0, 1, 3), slice(0, 1, 3));
	for (unsigned i = 0; i < ms2.size1(); ++i)
		for (unsigned j = 0; j < ms2.size2(); ++j)
			ms2(i, j) = 3 * i + j;
	std::cout << ms2 << std::endl;

    return 0;
}

