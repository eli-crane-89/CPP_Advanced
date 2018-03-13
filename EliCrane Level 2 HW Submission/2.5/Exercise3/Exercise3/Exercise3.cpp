#include <iostream>
#include <boost/math/special_functions/next.hpp>

namespace bm = boost::math;

int main()
{
	//a)
	// Number gaps/bits/ULP between
	// 2 floating-point values a and b
	// Returns a signed value indicating whether a < b
	double a = 0.1; 
	double b = a + std::numeric_limits<double>::min();
	std::cout << bm::float_distance(a, b) << std::endl; //0
	std::cout << bm::float_prior(a) << std::endl; //.1
	std::cout << bm::float_next(a) << std::endl; //.1
	std::cout << bm::float_prior(b) << std::endl; //.1
	std::cout << bm::float_next(b) << std::endl; //.1
	a = 1.0; b = 0.0;
	std::cout << bm::float_distance(a, b) << std::endl; //-4.06718e+18
	std::cout << bm::float_prior(a) << std::endl; //1
	std::cout << bm::float_next(a) << std::endl; //1
	std::cout << bm::float_prior(b) << std::endl; //-4.94066e-324
	std::cout << bm::float_next(b) << std::endl; //4.94066e-324
	//std::cout << bm::float_next(std::numeric_limits<double>::max()) << std::endl; //Overflow error
	std::cout << bm::float_prior(std::numeric_limits<double>::min()) << std::endl; //2.22507e-308
	std::cout << bm::float_prior(bm::float_prior(std::numeric_limits<double>::min())) << std::endl; //2.22507e-308
	std::cout << bm::float_prior(std::numeric_limits<int>::min()) << std::endl; //-2.14748e+09
	std::cout << bm::float_next(std::numeric_limits<int>::max()) << std::endl; //2.14748e+09
	//std::cout << bm::float_advance(std::numeric_limits<double>::max(),1) << std::endl; //Overflow error
	std::cout << bm::float_advance(std::numeric_limits<double>::max(), -1) << std::endl; //1.79769e+308
	std::cout << bm::float_advance(std::numeric_limits<double>::min(), 100) << std::endl; //2.22507e-308
	std::cout << bm::float_advance(std::numeric_limits<double>::min(), -5) << std::endl; //2.22507e-308
	std::cout << bm::float_advance(std::numeric_limits<double>::min(), -10) << std::endl; //2.22507e-308
	std::cout << bm::nextafter(0,1) << std::endl; //-4.94066e-324
	std::cout << bm::nextafter(1, 1) << std::endl; //-4.94066e-324
	std::cout << bm::nextafter(std::numeric_limits<double>::min(), -1) << std::endl; //2.22507e-308
	std::cout << bm::nextafter(std::numeric_limits<double>::min(), 1) << std::endl; //2.22507e-308
	std::cout << bm::nextafter(std::numeric_limits<double>::max(), 1) << std::endl; //1.79769e+308
	std::cout << bm::nextafter(std::numeric_limits<double>::max(), 0) << std::endl; //1.79769e+308
	std::cout << bm::float_distance(std::numeric_limits<double>::min(), 1) << std::endl; //4.6028e+18
	std::cout << bm::float_distance(std::numeric_limits<double>::min(), -1) << std::endl; //-4.61169e+18

	//Overflow errors are not thrown on numeric limit min, and also not on numeric_limits max sometimes

    return 0;
}

