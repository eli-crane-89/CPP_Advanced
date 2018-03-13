#ifndef BITMATRIX_HPP
#define BITMATRIX_HPP

#include <array>
#include <bitset>
#include <iostream>
#include <memory>

//Alias
template<size_t N, size_t M>
using BitArray = std::array<std::bitset<M>, N>;


template<size_t N, size_t M>
class BitMatrix {
private:
	BitArray<N, M> arr;

public:

	//Default Constructor
	BitMatrix() {};

	//Parameter Constructor
	BitMatrix(std::array<long, N> arrVal) {
		auto iterVal = arrVal.begin();

		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			(*iter) = std::bitset<M>(*iterVal);

			//Increment iterVal
			iterVal++;
		}
	}

	//Copy Constructor
	BitMatrix(const BitMatrix<N, M>& orig) {
		//Only set if orig has elements in array
		if (orig.arr.size() > 0) {
			arr = orig.arr;
		}
	}

	//Move Constructor
	BitMatrix(BitMatrix<N, M>&& orig) {
		*this = std::move(orig);
	}

	//Getter
	BitArray<N, M> GetBitArray() const{
		return arr;
	}

	//Get Bit
	bool GetBit(size_t row, size_t col) const {

		return arr[row][col];
	}

	void SetBit(size_t row, size_t col, bool bl) {
		arr[row][col] = bl;
	}

	//Functions
	void SetBits() {
		for (auto iter = arr.begin(); iter != arr.end(); iter++){
			(*iter).set();
		}	
	}

	void FlipBits() {
		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			(*iter).flip();
		}
	}

	int Count() {
		int count = 0;
		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			count += (*iter).count();
		}
		return count;
	}

	bool None() {
		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			//If any bitsets don't have none, return false
			if (!(*iter).none()) {
				return false;
			}
		}
		return true;
	}

	bool Any() {
		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			//If any bitsets have any, return true
			if ((*iter).any()) {
				return true;
			}
		}
		return false;
	}

	bool All() {
		for (auto iter = arr.begin(); iter != arr.end(); iter++) {
			//If any bitsets dont have all, return false
			if (!(*iter).all()) {
				return false;
			}
		}
		return true;
	}

	//Assignment Operator
	BitMatrix<N, M>& operator= (const BitMatrix<N, M>& source) {
		if (this != &source) {
			arr = source.arr;
		}

		return *this;
	}

	//Bracket overload
	std::bitset<M> operator[](int row) const{
		return arr[row];
	}

	std::bitset<M>& operator[](int row) {
		return arr[row];
	}

	//Override XOR
	BitMatrix<N, M>& operator^=(const BitMatrix<N, M>& param) {
		std::array<std::bitset<M>, N> arr_param = param.arr;

		//Create iter for original
		auto iterOrig = arr.begin();

		for (auto param : arr_param ) {
			//Perform XOR on each bitset
			(*iterOrig) ^= param;

			//Increment iter orig
			iterOrig++;
		}

		return *this;
	}

	//Override OR
	BitMatrix<N, M>& operator|=(const BitMatrix<N, M>& param) {
		std::array<std::bitset<M>, N> arr_param = param.arr;

		//Create iter for original
		auto iterOrig = arr.begin();

		for (auto iter = arr_param.begin(); iter != arr_param.end(); iter++) {
			//Perform OR on each bitset
			(*iterOrig) |= (*iter);

			//Increment iter orig
			iterOrig++;
		}

		return *this;
	}

	//Override OR
	BitMatrix<N, M>& operator&=(const BitMatrix<N, M>& param) {
		std::array<std::bitset<M>, N> arr_param = param.arr;

		//Create iter for original
		auto iterOrig = arr.begin();

		for (auto iter = arr_param.begin(); iter != arr_param.end(); iter++) {
			//Perform AND on each bitset
			(*iterOrig) &= (*iter);

			//Increment iter orig
			iterOrig++;
		}

		return *this;
	}

	//Stream overload
	friend std::ostream& operator<<(std::ostream& stream, const BitMatrix& bm) {

		//Extract array for iterator consistency
		BitArray<N, M> ba = bm.GetBitArray();
		
		//Turn off boolalpha and add line before
		stream << std::noboolalpha << std::endl;

		for (auto iter = ba.begin(); iter != ba.end(); iter++) {
			//Print in reverse order with signed int so as not to overflow
			for (int i = (*iter).size() - 1; i >= 0 ; i--) {
				//std::cout << "i: " << i << std::endl;
				stream << " " << (*iter)[i] << " ";
			}
			stream << std::endl;
		}

		return stream;
	};

	


};





#endif // ! BITMATRIX_HPP
