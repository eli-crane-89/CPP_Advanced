#ifndef SPECIALIZATIONS_HPP
#define SPECIALIZATIONS_HPP

#include <iostream>
#include <complex>
#include <boost\algorithm\string.hpp>
#include <algorithm>
#include <fstream>
#include <vector>

// Instance Systems 
template<typename T>
class MyInput {
public:
	T message() const {
		T var;

		std::cout << "Please input var of double type: \n";
		std::cin >> var;

		return var;
	}
};

template<typename T>
class MyInput2 {
public:
	T message() const {
		T var;

		std::cout << "Please input a complex number in string form (like '4 + 2i'): ";

		std::string input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Scurb blank line
		std::getline(std::cin, input);

		return input;
	}
};

template<typename T1, typename T2>
class MyConverter {
public:
	T2 convert(T1 var) const
	{ // Process string using Boost String Algorithm library 

		return static_cast<T2>(var);

	}
};

template<typename T1, typename T2>
class MyConverter2 {
public:
	static double StaticDoubleMultiply(const double& var, double mult) {
		return var * mult;
	}

	T2 convert(T1& var) const
	{ // Process string using Boost String Algorithm library to Parse Imaginary Number to std::complex
		//Split real and imaginary parts
		std::size_t pos_sign = var.find("+") != std::string::npos ? var.find("+") : var.find("-"); //Find plus or minus sign
		int inverse = var.find("+") != std::string::npos ? 1 : -1; //If negative

		//Real
		std::string s_real = var.substr(0, pos_sign);
		boost::trim(s_real);
		T2::value_type real = atof(s_real.c_str()); //Convert from char array to double

		//Imaginary
		std::string s_imag = var.substr(pos_sign+1);
		boost::trim(s_imag);
		std::remove_if(s_real.begin(), s_real.end(), isspace);
		T2::value_type imag = atof(s_imag.c_str()); //Convert from char array to double

		return std::complex<double>(real * inverse, imag);

	}
};


#endif


template<typename T>
class MyOutput {
public:
	void print(T& var) const {
		std::cout << var << std::endl;
	}

	void end() const {
		std::cout << "end" << std::endl;
	}
};

class MultiplyDouble {
public:
	MultiplyDouble() {};
	double operator()(const double& var, double mult) {
		return var * mult;
	}
};

//File Processing
template<typename T>
class FileOpener {

public:
	T message() {
		std::cout << "Opening file of TestFileInput.txt...\n" << std::endl;

		const std::string file = "TestFileInput.txt";

		T vLines;

		//Open File
		std::ifstream ifs(file, std::ifstream::in);

		T::value_type line;
		while (std::getline(ifs, line)) {
			vLines.push_back(line);
		}

		return vLines;
	}
};

template<typename T1, typename T2>
class Processor {
public:
	T2 convert(T1 vLines) {

		for (auto i = 0; i < vLines.size(); ++i) {
			boost::to_upper(vLines[i]);
		}

		return vLines;
	}
};

template<typename T>
class OutputFile{
public:
	void print(T vLines) {
		std::cout << "Writing to file TestFileOutput.txt..." << std::endl;

		std::ofstream writeFile("TestFileOutput.txt");

		for (auto line : vLines) {
			std::cout << "Writing line: " << line << std::endl;
			writeFile << line << std::endl;
		}
		writeFile.close();
	}

	void end() const {
		std::cout << "end" << std::endl;
	}
};

