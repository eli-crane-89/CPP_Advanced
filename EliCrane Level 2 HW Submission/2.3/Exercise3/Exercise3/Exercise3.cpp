#include <iostream>
#include "Functions.hpp"

using namespace std;




int main()
{
	
	//a)
	// Scalar functions: double to double
	ScalarFunction f = [](double x) {return x*x; };
	ScalarFunction g = [=](double x) { return x; };

	std::cout << g(2) << ", " << g(8) << "*";
	// Set I: Arithmetic functions

	double scale = 2.0;
	auto fA = 2.0 * (f + g);
	auto fM = f - g;
	auto fD = f / g;
	auto fMul = f * g;
	auto fC = g << g << 4.0*g;// Compose
	auto fMinus = -(f + g);

	double x = 5.0;

	std::cout << fA(x) << ", " << fM(x) << ", " << fD(x) << ", "
		<< fMul(x) << ", compose: " << fC(x) << ", " << fMinus(x);

	//b) 
	auto ftmp = log(g);
	auto ftmp2 = cos(f);
	auto f2 = (abs(exp(g))*log(g) + sqrt(ftmp)) / ftmp2;
	std::cout << f2(x) << std::endl;

	//c)
	auto h1 = min(f, g);
	auto h2 = max(f, g);
	std::cout << "min(f,g): " << h1(2.0) << '\n';
	std::cout << "max(f,g): " << h2(2.0) << '\n';
	auto h3 = min(h1, max(2 * f, 3 * g));
	auto h4 = max(h2, max(-2 * f, 3 * g));

    return 0;
}

