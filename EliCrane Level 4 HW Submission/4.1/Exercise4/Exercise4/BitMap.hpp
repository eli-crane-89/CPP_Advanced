#ifndef BITMAP_HPP
#define BITMAP_HPP

#include "CompileTimeMatrix.hpp"
#include "CompileTimeVector.hpp"

#include <bitset>
#include <string>
#include <functional>

#include "Proposition.hpp"
#include "CompileTimeMatrix.hpp"

//Define types
using value_type = Proposition;
template <int NR, int NC>
using BitMap = Matrix<value_type, NR, NC>;
template <int NR, int NC>
using BitMap2 = std::array<std::bitset<NC>, NR>;


//Print Function for Bitmap2
template<int NR, int NC>
void PrintBM2(const BitMap2<NR, NC>& bm2) {
	for (int i = 0; i < NR; i++) {
		for (int j = 0; j < NC; j++) {
			std::cout << bm2[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

//Superimposition function
Proposition modProp(const Proposition& p1, const Proposition& p2) {
	std::string bit = "0";

	if (p1 == p2) {
		bit = "1";
	}

	return Proposition(std::bitset<1>(bit));
}


//==
auto EQUAL = [](const Proposition& p1, const Proposition& p2) {  return p1 == p2; };
//!=
auto DNE = [](const Proposition& p1, const Proposition& p2) {  return p1 != p2; };
//&
auto AND = [](const Proposition& p1, const Proposition& p2) { return p1 & p2; };
//|
auto OR = [](const Proposition& p1, const Proposition& p2) { return p1 | p2; };
//XOR
auto XOR = [](const Proposition& p1, const Proposition& p2) { return p1 ^ p2; };
//Conditional
auto COND = [] (const Proposition& p1, const Proposition& p2) { return p1 % p2; };
//BiConditional
auto BICOND = [](const Proposition& p1, const Proposition& p2) { return p1 > p2; };

//Superimposition
using BitFunction = std::function<Proposition(const Proposition&, const Proposition&)>;
template <int NR, int NC>
BitMap<NR, NC> mask(const BitMap<NR, NC>& bm1, const BitMap<NR, NC>& bm2, const BitFunction& masker) {
	BitMap<NR, NC> bmRet(0); //To return
	int CallCount = 0;
	//Iterate through all values
	for (int i = 0; i < NR; i++) {
		for (int j = 0; j < NC; j++) {
			//Modify all values with masker
			bmRet[i][j] = masker(bm1[i][j], bm2[i][j]);
		}
	}

	return bmRet;

};

#endif // !BITMAP_HPP
