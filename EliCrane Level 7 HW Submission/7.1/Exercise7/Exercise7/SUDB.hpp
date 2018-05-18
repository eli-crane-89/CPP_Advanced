#ifndef SUDB_HPP
#define SUDB_HPP

//Second version for problem b)

#include <string>
#include <iostream>
#include <functional>


template <typename T1, typename T2, template <typename T1> class Source, template <typename T2> class Sink>
class SUDB : private Source<T1>, private Sink<T2>
{ // System under discussion
private:
	// Define the requires interfaces that SUD needs
	using Source<T1>::message; // Get input
	std::function<T2(const T1&)> Processing; //Convert input to output
	using Sink<T2>::print; // Produce output
	using Sink<T2>::end; // End of program
public:
	void run()
	{// Core process, showing mediating role of SUD 
		auto var = message(); // I, input
		auto varConvert = Processing(var); // P, processing
		print(varConvert); // O. output
		end(); // O, signals end of program 
	}

	void setProcess(std::function<T2(const T1&)> processing) {
		Processing = processing;
	}
};



#endif