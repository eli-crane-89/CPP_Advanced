#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <algorithm>


int main()
{
	using namespace boost::numeric::ublas;

	auto lPrint = [](vector<double> vDouble) {
		for (auto elem : vDouble) {
			std::cout << elem << std::endl;
		}
	};

	//a)
	vector<double> v1(3);
	v1[0] = 2.17;
	v1[1] = 1.3;
	v1[2] = 5.98;
	std::cout << "v1(1): " << v1(1) << std::endl;

	//b)
	vector<double> v2(3);
	v2[0] = 1.27;
	v2[1] = 3.1;
	v2[2] = 9.58;

	//Perform operations
	v1 += v2;
	lPrint(v1);
	v1 *= 2.5;
	lPrint(v1);
	v1 -= v2;
	lPrint(v1);

	//c)
	vector<double> v3(3); //result vector
	std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), std::multiplies<double>()); //insert results into v3
	lPrint(v3);

	
	//d)
	vector<double> v4(100, 5);
	lPrint(v4);



    return 0;
}

