
#include <iostream>

#include "BitMatrix.hpp"

int main()
{
	//a) will use one dimensional array with each element carry a bit set of Size N
	

	//b)

	
	//Single row matrix proof

	//Construct BitMatrix of 1 bitsets of size 4
	BitMatrix<1, 4> bmOne = BitMatrix<1, 4>();
	std::cout << bmOne << std::endl;

	bmOne.SetBits();

	//Construct BitMatrix of 3 bitsets of size 4 with predetermined value on each row
	std::array<long, 1> arrValOne = {4};
	BitMatrix<1, 4> bmOneParam = BitMatrix<1, 4>(arrValOne);
	std::cout << bmOneParam << std::endl;

	//Test copy
	BitMatrix<1, 4> bmOne2 = BitMatrix<1, 4>();
	bmOne2 = bmOne;
	std::cout << "bmOne2 after copy: " << bmOne2 << std::endl;

	//Test Assignment
	BitMatrix<1, 4> bmOne3 = bmOne2;
	std::cout << "bmOne3 after assignment: " << bmOne3 << std::endl;

	//Test Move
	BitMatrix<1, 4> bmOne4 = std::move(bmOne3);
	std::cout << "bmOne4 after move: " << bmOne4 << std::endl;

	//c)
	//Test bools
	std::cout << std::boolalpha << "All: " << bmOne.All() << std::endl;
	std::cout << std::boolalpha << "Any: " << bmOne.Any() << std::endl;
	std::cout << std::boolalpha << "None: " << bmOne.None() << std::endl;

	//Flip Bits
	bmOne.FlipBits();
	std::cout << bmOne << std::endl;
	std::cout << std::boolalpha << "All: " << bmOne.All() << std::endl;
	std::cout << std::boolalpha << "Any: " << bmOne.Any() << std::endl;
	std::cout << std::boolalpha << "None: " << bmOne.None() << std::endl;

	//Set and Get Bit
	bmOne.SetBit(0, 2, 1);
	std::cout << std::noboolalpha << bmOne.GetBit(0, 2) << std::endl;
	std::cout << bmOne << std::endl;

	//Bracket overload
	bmOne[0][1] = 1;
	std::cout << std::noboolalpha << bmOne[0][1] << std::endl;
	std::cout << bmOne << std::endl;

	//Count
	std::cout << "The number of set bits in bm: " << bmOne.Count() << std::endl;

	//d)
	bmOne ^= bmOne4;
	std::cout << std::endl << "bmOne after XOR with bmOne4: " << bmOne << std::endl;

	bmOne |= bmOne4;
	std::cout << std::endl << "bm after OR with bmOne4: " << bmOne << std::endl;

	bmOne &= bmOne4;
	std::cout << std::endl << "bmOne after AND with bmOne4: " << bmOne << std::endl;

	//Construct BitMatrix of 3 bitsets of size 4
	BitMatrix<3, 4> bm = BitMatrix<3,4>();
	std::cout << bm << std::endl;

	bm.SetBits();

	//Construct BitMatrix of 3 bitsets of size 4 with predetermined value on each row
	std::array<long, 3> arrVal = { 4,7,8 };
	BitMatrix<3, 4> bmParam = BitMatrix<3, 4>(arrVal);
	std::cout << bmParam << std::endl;

	//Test copy
	BitMatrix<3, 4> bm2 = BitMatrix<3, 4>();
	bm2 = bmParam;
	std::cout << "bm2 after copy: " << bm2 << std::endl;

	//Test Assignment
	BitMatrix<3, 4> bm3 = bm2;
	std::cout << "bm3 after assignment: " << bm3 << std::endl;

	//Test Move
	BitMatrix<3, 4> bm4 = std::move(bm3);
	std::cout << "bm4 after move: " << bm4 << std::endl;

	//c)
	//Test bools
	std::cout << std::boolalpha << "All: " << bm.All() << std::endl;
	std::cout << std::boolalpha << "Any: " << bm.Any() << std::endl;
	std::cout << std::boolalpha << "None: " << bm.None() << std::endl;

	//Flip Bits
	bm.FlipBits();
	std::cout << bm << std::endl;
	std::cout << std::boolalpha << "All: " << bm.All() << std::endl;
	std::cout << std::boolalpha << "Any: " << bm.Any() << std::endl;
	std::cout << std::boolalpha << "None: " << bm.None() << std::endl;

	//Set and Get Bit
	bm.SetBit(2, 2, 1);
	std::cout << std::noboolalpha << bm.GetBit(2, 2) << std::endl;
	std::cout << bm << std::endl;

	//Bracket overload
	bm[2][1] = 1;
	std::cout << std::noboolalpha << bm[2][1] << std::endl;
	std::cout << bm << std::endl;

	//Count
	std::cout << "The number of set bits in bm: " << bm.Count() << std::endl;
	
	//d)
	bm ^= bm4;
	std::cout << std::endl << "bm after XOR with bm4: " << bm << std::endl;

	bm |= bm4;
	std::cout << std::endl << "bm after OR with bm4: " << bm << std::endl;

	bm &= bm4;
	std::cout << std::endl << "bm after AND with bm4: " << bm << std::endl;
	

    return 0;
}

