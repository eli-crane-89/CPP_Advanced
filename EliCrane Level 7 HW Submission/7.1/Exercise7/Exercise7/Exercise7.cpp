#include "SUD.hpp"
#include "SUDB.hpp"
#include "Specializations.hpp"

//Global Function
double MultDouble(const double& var, double mult) {
	return var * mult;
}

int main()
{

	//a)
	// First instantiation 
	SUD<double, int, MyInput, MyOutput, MyConverter> sud; 
	sud.run();
	
	//b)
	// Second instantiation 
	//Class Template Member Function
	SUDB<std::string, std::complex<double>, MyInput2, MyOutput> sud2; 
	MyConverter2<std::string, std::complex<double>> myConv2;
	std::function<std::complex<double>(std::string)> process = std::bind(&MyConverter2<std::string, std::complex<double>>::convert, &myConv2, std::placeholders::_1);
	
	sud2.setProcess(process);
	sud2.run();

	//Lambda Function
	SUDB<double, double, MyInput, MyOutput> sud3;
	auto l_process = [](const double& var, double mult) {
		return var * mult;
	};
	std::function<double(double)> process2 = std::bind(l_process, std::placeholders::_1, 3.4);
	sud3.setProcess(process2);
	sud3.run();

	//Global Function
	process2 = std::bind(MultDouble, std::placeholders::_1, 6.8);
	sud3.setProcess(process2);
	sud3.run();
	
	//Functor
	MultiplyDouble md;
	process2 = std::bind(&MultiplyDouble::operator(), &md, std::placeholders::_1, 10.5);
	sud3.setProcess(process2);
	sud3.run();

	//Static Member Function
	process2 = std::bind(&MyConverter2<std::string, std::complex<double>>::StaticDoubleMultiply, std::placeholders::_1, 28.99);
	sud3.setProcess(process2);
	sud3.run();

	//The funtion object is more flexible since it allows you to bind a function that contains different numbers of input from the
	//original and you don't need to stick to the template structure, you just need to match T1 and T2. The advantage of the original
	//structure is that you only have to pass the class types without binding (only two lines of code to instantiate and run).

	//c)
	SUD<std::vector<std::string>, std::vector<std::string>, FileOpener, OutputFile, Processor> sudFile;
	sudFile.run();


    return 0;
}

