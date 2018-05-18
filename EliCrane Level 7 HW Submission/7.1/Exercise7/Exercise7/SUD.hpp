#ifndef SUD_HPP
#define SUD_HPP

#include <string>
#include <iostream>

template <typename T1, typename T2,template <typename T1> class Source,template <typename T2> class Sink,template <typename T1, typename T2> class Processing>
class SUD : private Source<T1>, private Sink<T2>, private Processing<T1, T2>
{ // System under discussion
private:
	// Define the requires interfaces that SUD needs
	using Source<T1>::message; // Get input
	using Processing<T1,T2>::convert; // Convert input to output
	using Sink<T2>::print; // Produce output
	using Sink<T2>::end; // End of program
public:
	void run()
	{// Core process, showing mediating role of SUD 
		auto var = message(); // I, input
		auto varConvert = convert(var); // P, processing
		print(varConvert); // O. output
		end(); // O, signals end of program 
	} 

};


#endif