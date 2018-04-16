#include <boost\signals2.hpp>
#include <iostream>


//b)
struct SumCombiner
{

	typedef double result_type;
	

	template <typename InputIterator>
	double operator()(InputIterator first, InputIterator last)
	{
		double sum = 0;
		while (first != last)
		{
			sum += *first;
			++first;
		}
		return sum;
	}
};


//a)
auto superAdd = [](double d1, double d2) {
	return d1 + d2 * 3;
};

double superMultiply(double d1, double d2) {
	return d1 * d2 * 3;
}

int main()
{
	//c)
	boost::signals2::signal<double(double, double), SumCombiner> sig;

	sig.connect(std::bind(superAdd, std::placeholders::_1, std::placeholders::_2)); //15.9
	sig.connect([](double d1, double d2) {
		return d1 - d2 - 3;
	}); //-4.3
	sig.connect(&superMultiply); //38.7 

	std::cout << sig(3.0, 4.3) << std::endl;
	//The answer is correct 15.9 - 4.3 + 38.7 = 50.3


	return 0;
}

