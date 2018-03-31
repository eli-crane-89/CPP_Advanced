#include <boost\random.hpp>
#include <boost\random\triangle_distribution.hpp>
#include <boost\random\lagged_fibonacci.hpp>
#include <boost\random\generate_canonical.hpp>
#include <iostream>
#include <iomanip>

auto lPrint = [](boost::variate_generator<boost::lagged_fibonacci19937&, boost::triangle_distribution<>>& vergen) {
	for (int i = 0; i < 10; i++) {
		std::cout << vergen() << std::endl;
	}
};
int main()
{
	//a)
	boost::lagged_fibonacci19937 eng_lfb;
	boost::triangle_distribution<> dist_tri(0.0, .6, 1.0);
	boost::variate_generator <boost::lagged_fibonacci19937&, boost::triangle_distribution<>> vargen_tri(eng_lfb, dist_tri);

	lPrint(vargen_tri);

	//b)
	boost::mt19937 eng_mt;
	double gc;

	for (int i = 0; i < 10; i++) {
		gc = boost::random::generate_canonical<double, 1500, boost::mt19937>(eng_mt);

		std::cout << std::setprecision(100) << "The generated canonical with " << 1500 << " random bits is: " << gc << std::endl;
	}

	//Numbers do not seem to change for lower values unless I change the number to 32, in which case the numbers stay the same up through 1500

    return 0;
}

