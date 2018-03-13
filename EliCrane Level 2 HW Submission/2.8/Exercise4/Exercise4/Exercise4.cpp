#include <vector>
#include <iostream>

bool intersects(const std::vector<bool>& vb1, const std::vector<bool>& vb2) {
	
	//Get iterator for second vb2
	auto iter2 = vb2.begin();

	for (auto iter1 = vb1.begin(); iter1 < vb1.end(); iter1++) {

		//Check if bit is set, and if so is bit set on same location on second vector
		if (*iter1 == 1 && *iter1 == *iter2) {
			return true;
		}
		//increment iter2
		iter2++;
		
	}

	return false;
}

int main()
{
	std::vector<bool> vBool;

	vBool.push_back(0);
	vBool.push_back(1);
	vBool.push_back(0);
	vBool.push_back(1);

	//Cannot make a bool vector from string
	//Cannot subset a vector from a starting index natively

	//does not work
	//throws different error
	//try {
		//std::cout << vBool[2] << std::endl;
	//}
	//catch (std::out_of_range& oor) {
	//	std::cout << "index out of range." << std::endl;
	//}

	//catch invalid arguments
	try {
		vBool.push_back(2);
	}
	catch (const std::invalid_argument& ia) {
		std::cout << "Invalid bit given." << std::endl;
	}

	//Invalid argument is not caught
	vBool.pop_back();

	//d)
	//Set all bits
	//Cannot set all bits
	//vBool.set();

	//Reset all bits
	//Cannot reset all bits
	//vBool.reset();

	//Check for set bits
	//Cannot easily count bits
	//if (vBool.all()) {
	//	std::cout << "All bits are set.\n";
	//}
	//else if vBool.any()) {
	//	std::cout << "There are set bits: " << vBool.count() << std::endl;
	//}
	//else if (vBool.none()) {
	//	std::cout << "The are no bits set\n";
	//}

	//Access elements
	std::cout << "The bit at the 2nd position of bs4 is: " << vBool[2] << std::endl; //1, third from right

	//Count the number of set bits
	//Cannot count bits
	//std::cout << "bs4 has set bits: " << vBool.count() << std::endl;

	//e)
	//Convert
	//Cannot natively output to string or to u_long
	//std::cout << "vBool to string: " << vBool << std::endl; //1001
	//std::cout << "vBool to ulong: " << vBool.to_ulong() << std::endl; //4
	//std::cout << "bs8 to ullong: " << bs8.to_ullong << std::endl; //no to ullong function

	//f)
	//Check if equal
	std::vector<bool> vBool2;
	vBool2.push_back(0);
	vBool2.push_back(1);
	vBool2.push_back(1);
	vBool2.push_back(1);

	std::cout << "vBool2 equals vBool2: " << std::boolalpha << (vBool == vBool2) << std::endl; //false
	std::cout << "vBool2 not equals vBool2: " << std::boolalpha << (vBool != vBool2) << std::endl; //true

	//Exercise 2 probs with dynamic bitsets

	//b) toggle on bits
	//Caanot set
	//vBool.set();
	//vBool.set();

	//c) 
	//Xor
	//Cannot perform
	//std::cout << (vBool ^= vBool2) << std::endl;
	//And
	///std::cout << (vBool &= vBool2) << std::endl;
	//Or
	//std::cout << (vBool |= vBool2) << std::endl;

	//d)
	//Left shift
	//Cannot left shift
	//std::cout << (vBool << 1) << std::endl;

	//Right shift
	//Cannot right shift
	//std::cout << (vBool >> 1) << std::endl;

	//e)
	//Cannot be hashed natively
	//hash
	//size_t h1 = std::hash<std::vector<bool>>(vBool);
	//std::cout << h1 << std::endl;


	//b)

	vBool.resize(10, 1);
	vBool.clear();
	vBool.push_back(0);
	vBool.pop_back();
	//vBool.append(4);


	//c)
	//Cannot natively check for subset or poper subset
	//std::cout << (vBool.is_subset_of(vBool2)) << std::endl; //true
	//std::cout << (vBool2.is_subset_of(vBool)) << std::endl; //false

	//std::cout << (vBool.is_proper_subset_of(vBool2)) << std::endl; //true
	//std::cout << (vBool2.is_proper_subset_of(vBool)) << std::endl; //false


	//d)
	//No way to natively rfind on a vector
	//std::cout << "The first bit can be found in vBool at: " << std::find(vBool.begin(), vBool.end) << std::endl;//2
	//std::cout << "The next bit can be found in bs12 at: " << bs12.find_next(2) << std::endl; //6

	//b)
	std::vector<bool> vb1;
	vb1.push_back(0);
	vb1.push_back(1);

	std::vector<bool> vb2;
	vb2.push_back(1);
	vb2.push_back(0);

	std::vector<bool> vb3;
	vb3.push_back(0);
	vb3.push_back(1);

	std::cout << std::boolalpha << intersects(vb1, vb2) << std::endl; //false
	std::cout << std::boolalpha << intersects(vb1, vb3) << std::endl; //true

	//Obviously bit sets are better as they specialized to deal with many bit sets problems
	//I'll admit, I found this exercise a little unnecessary as it never occured to me that a vector
	//would be better at handling bitsets after the first couple of exercises with bitsets
	
    return 0;
}

