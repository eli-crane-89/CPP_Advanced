#ifndef INDEPENDENT_BITS_ENGINE_HPP
#define INDEPENDENT_BITS_ENGINE_HPP

#include <bitset>
#include <random>
#include <iostream>


template<class Engine, std::size_t W, class UIntType>
class independent_bits_engine {
private:
	std::bitset<W> _bs;
	int _bsVal;

public:

	//Constructor
	independent_bits_engine(UIntType seed) {

		Engine eng(seed);
		std::bernoulli_distribution dist(0.5);

		_bsVal = 0;

		for (int i = 0; i < W; i++) {
			_bs[i] = dist(eng);
		}

		_bsVal = (int)(_bs.to_ulong());
	};

	//Getters
	std::bitset<W> GetBS() {
		return _bs;
	}

	int GetVal() {
		return _bsVal;
	}

	//Stream overload
	friend std::ostream& operator << (std::ostream& stream, const independent_bits_engine& ibe) {
		for (int i = 0; i < ibe._bs.size(); i++) {
			stream << ibe._bs[i] << " ";
		}
		stream << std::endl;

		stream << ibe._bsVal << std::endl;

		return stream;
	};



};

template<std::size_t Width>
void TestIBE(int nTrials) {
	int bitCount = 0;

	for (int i = 0; i < nTrials; i++) {
		independent_bits_engine<std::mt19937, Width, int> ibe(i);

		bitCount += ibe.GetBS().count();
	}

	std::cout << "The bit count of a size: " << Width << " bitset after " << nTrials << " trials is ";
	std::cout << bitCount << " out of a possible " << Width * nTrials << "(" << (double)(bitCount) / (double)(nTrials * Width) * 100.0 << "%)";
	std::cout << std::endl << std::endl;
}


#endif