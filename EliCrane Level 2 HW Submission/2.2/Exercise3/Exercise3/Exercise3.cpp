#ifndef EXERCISE3_HPP
#define EXERCISE3_HPP

#include <vector>
#include <memory>

#include "AddCode.hpp"

int main() {

	std::cout << std::endl << "Exercise3:" << std::endl;

	int i = 1;
	unsigned int ui = 5;
	int ineg = -1;
	const int j = 2;
	const std::vector<double> vConst;
	int * p_i = &i;
	const std::vector<double> * p_vConst = &vConst;
	std::shared_ptr<std::vector<double>> sp_v;
	volatile int vi = 7;
	volatile std::vector<double> vVol;


	//d)
	ConvertSignedUnsigned(i); //Converts to unsigned
	ConvertSignedUnsigned(ui); //Convert to signed
	ConvertSignedUnsigned(ineg); //Converts to unsigned, Strange behavior on negative

	ConvertConstNonConst(i); //Convert to const
	ConvertConstNonConst(j); //Convert to non const
	ConvertConstNonConst(vConst); //Convert to non const
	ConvertConstNonConst(p_i); //Convert to const

	ConvertPointerNonPointer(p_i); //Converts to non pointer
	ConvertPointerNonPointer(i); //Convert to pointer
	ConvertPointerNonPointer(p_vConst); //Converts to non pointer
	ConvertPointerNonPointer(sp_v); //Converts to pointer


	ConvertVolatileNonVolatile(i); //Converts to volatile
	ConvertVolatileNonVolatile(vi); //Converts to non volatile
	//ConvertVolatileNonVolatile(vVol); //Does not work


	return 0;

}


#endif