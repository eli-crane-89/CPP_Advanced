#include <iostream>

#include "BitMap.hpp"

int main()
{
	//a)
	BitMap<3,4> bm = BitMap<3,4>(1);
	bm.Print();
	BitMap2<4, 5> bm2 = BitMap2<4, 5>();
	PrintBM2(bm2);
	BitMap<3, 4> bm3 = BitMap<3, 4>();
	bm3.Print();
	
	//b)
	std::cout << "\n\nb)\n";

	//bm = all true, and bm3 = all false

	//Merge bitmaps with free function
	BitFunction f_mask = modProp;
	BitMap<3, 4> bm4 = mask<3,4>(bm, bm3, f_mask);
	bm4.Print();
	//Output: Don't equal each other so all false
	
	//Use == operator function
	f_mask = EQUAL;
	bm4 = mask<3, 4>(bm3, bm4, f_mask);
	bm4.Print();
	//Output: Now bm4 is all false, so output is all true

	//Use != operator function
	f_mask = DNE;
	bm4 = mask<3, 4>(bm3, bm4, f_mask);
	bm4.Print();
	//Output now bm4 is all true, so it DNE bm3, all true

	//Use & operator function
	f_mask = AND;
	bm4 = mask<3, 4>(bm3, bm4, f_mask);
	bm4.Print();
	//bm4 is all true, bm3 is all false, all false

	//Use & operator function
	f_mask = OR;
	bm4 = mask<3, 4>(bm3, bm4, f_mask);
	bm4.Print();
	//bm4 is all false, bm3 is all false, all false

	//Use XOR operator function
	f_mask = XOR;
	bm4 = mask<3, 4>(bm3, bm4, f_mask);
	bm4.Print();
	//bm4 is all false, bm3 is all false, all false

	//Use COND operator function
	f_mask = COND;
	bm4 = mask<3, 4>(bm3, bm4, f_mask);
	bm4.Print();
	//bm4 is all false, bm3 is all false, all true

	//Use BICOND operator function
	f_mask = BICOND;
	bm4 = mask<3, 4>(bm3, bm4, f_mask);
	bm4.Print();
	//bm4 is all true, bm3 is all false, all false

	//c)
	std::cout << "\n\nc)\n";

	auto bm1_comp = BitMap<3, 4>();
	auto bm2_comp = BitMap2<3, 4>();

	//Initialization for BM
	auto initBM1 = [](BitMap<3, 4>& bm, std::string& s_bm) {
		auto stringCount = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				if (s_bm[stringCount] == '1') {
					bm[i][j] = 1;
				}
				else {
					bm[i][j] = 0;
				}
				stringCount++;
			}
		}
	};

	//Initialization for BM2
	auto initBM2 = [](BitMap2<3, 4>& bm, std::string& s_bm) {
		auto stringCount = 0;
		for (auto iter = bm.begin(); iter != bm.end(); iter++) {

			*iter = std::bitset<4>(s_bm.substr(0 + stringCount, 4));

			stringCount += iter->size();
		}
	};

	//Print BM2
	auto printBM2 = [](BitMap2<3, 4>&bm) {
		for (auto bs : bm) {
			for (int j = 0; j < bs.size(); j++) {
				std::cout << std::boolalpha << bs[j] << " ";
			}
			std::cout << std::endl;
		}
		
	};

	std::string s_bm = ("100011100010");
	initBM1(bm1_comp, s_bm);
	bm1_comp.Print();

	std::string s_bm2 = ("000101110100");
	initBM2(bm2_comp, s_bm2);
	printBM2(bm2_comp);

	//The bitmap2 has native iterators and can have its bits set by rows
	//bitmap due to my design, needs to have a custom string parser method applied
	//I find the right to left reading when you use bs = std::bs('0101001') to
	//be somewhat counterintuitive. Both needed customer print functions.
	//Bitsets also are missing some of the operator overload functionality we have provided
	//to the Proposition, such as biconditional and conditional, though it has many others
	

	
	
	

    return 0;
}

