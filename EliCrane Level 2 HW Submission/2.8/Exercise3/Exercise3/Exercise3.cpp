#include <boost/dynamic_bitset.hpp>
#include <iostream>
#include <string>

int main()
{
	//a)
	//Exercise 1 probs with dynamic bitsets
	//a)
	//bitset from u long
	unsigned long num = 4;
	boost::dynamic_bitset<> bs = boost::dynamic_bitset<>(num);

	std::cout << bs << std::endl;

	//bitset from u long long
	//cannot do with dynamic bitset
	//unsigned long long ull = -156;
	//boost::dynamic_bitset<> bs2 = boost::dynamic_bitset<>(ull);

	//std::cout << bs2 << std::endl;

	//b)
	//bitsets from string
	boost::dynamic_bitset<> bs3(std::string("100"));
	boost::dynamic_bitset<> bs4(std::string("1100100"));
	std::cout << bs3 << std::endl;
	std::cout << bs4 << std::endl;

	//bitsets from strings and index
	//does not work since dynamic bitsets are not subsettable

	boost::dynamic_bitset<> bs5(std::string("100"),0,1); //1
	boost::dynamic_bitset<> bs6(std::string("1100100"),1,1); //1 
	std::cout << bs5 << std::endl;
	std::cout << bs6 << std::endl;

	//c)
	//catch out of range error
	//does not work since dynamic bitsets throw an assertion error
	
	//try {
	//	boost::dynamic_bitset<>  bs7(std::string("1000"), 4);
	//}
	//catch (std::out_of_range& oor) {
	//	std::cout << "index out of range." << std::endl;
	//}

	//catch invalid arguments
	//does not work since dynamic bitsets throw an assertion error

	//try {
	//	boost::dynamic_bitset<>  bs7(std::string("1002"));
	//}
	//catch (const std::invalid_argument& ia) {
	//	std::cout << "Invalid bit given." << std::endl;
	//}

	//d)
	//Set all bits
	bs5.set();
	std::cout << bs5 << std::endl; //1111

	//Reset all bits
	bs5.reset();
	std::cout << bs5 << std::endl; //0000

	//Check for set bits
	if (bs5.all()) {
		std::cout << "All bits are set.\n";
	}
	else if (bs5.any()) {
		std::cout << "There are set bits: " << bs5.count() << std::endl;
	}
	else if (bs5.none()) {
		std::cout << "The are no bits set\n";
	}

	//Access elements
	std::cout << "The bit at the 2nd position of bs4 is: " << bs4[2] << std::endl; //1, third from right

	//Count the number of set bits
	std::cout << "bs4 has set bits: " << bs4.count() << std::endl;

	//e)
	//Convert
	boost::dynamic_bitset<> bs8(std::string("1001"));
	std::cout << "bs8 to string: " << bs8 << std::endl; //1001
	std::cout << "bs8 to ulong: " << bs8.to_ulong() << std::endl; //4
	//std::cout << "bs8 to ullong: " << bs8.to_ullong << std::endl; //no to ullong function

	//f)
	//Check if equal
	std::cout << "bs8 equals bs5: " << std::boolalpha << (bs8 == bs5) << std::endl; //false
	std::cout << "bs8 not equals bs5: " << std::boolalpha << (bs8 != bs5) << std::endl; //true

	//Exercise 2 probs with dynamic bitsets
	//a) create two bitsets
	boost::dynamic_bitset<> bs1_2(5);
	boost::dynamic_bitset<> bs2_2(5);

	//b) toggle on bits
	bs1_2.set();
	bs2_2.set();

	//c) 
	//Xor
	std::cout << (bs1_2 ^= bs2_2) << std::endl;
	//And
	std::cout << (bs1_2 &= bs2_2) << std::endl;
	//Or
	std::cout << (bs1_2 |= bs2_2) << std::endl;

	//d)
	//Left shift
	std::cout << (bs1_2 << 1) << std::endl;

	//Right shift
	std::cout << (bs1_2 >> 1) << std::endl;

	//e)
	//Cannot be hashed natively
	//hash
	//size_t h1 = std::hash<boost::dynamic_bitset<>>(bs1_2);
	//std::cout << h1 << std::endl;
	//size_t h2 = hash_fn(bs2);
	//std::cout << h2 << std::endl;

	//b)
	std::cout << "bs: " << bs << std::endl; //0000
	bs.resize(10, 1);
	std::cout << "Resize: " << bs << std::endl; //1111110000
	bs.clear();
	std::cout << "Clear: " << bs << std::endl; // Blank
	bs.resize(10, 1);
	std::cout << "Resize: " << bs << std::endl; //1111111111
	bs.push_back(0);
	std::cout << "Push Back: " << bs << std::endl; //01111111111
	bs.pop_back();
	std::cout << "Pop Back: " << bs << std::endl; //1111111111
	bs.append(4);
	std::cout << "Append: " << bs << std::endl; //0000000000000000000000000000010011111111111

	//c)
	boost::dynamic_bitset<> bs9(std::string("1001"));
	boost::dynamic_bitset<> bs10(std::string("1000"));
	boost::dynamic_bitset<> bs11(std::string("1111"));

	std::cout << (bs10.is_subset_of(bs9)) << std::endl; //true
	std::cout << (bs9.is_subset_of(bs10)) << std::endl; //false
	std::cout << (bs10.is_subset_of(bs11)) << std::endl; //true
	std::cout << (bs11.is_subset_of(bs10)) << std::endl; //false

	std::cout << (bs10.is_proper_subset_of(bs9)) << std::endl; //true
	std::cout << (bs9.is_proper_subset_of(bs10)) << std::endl; //false
	std::cout << (bs10.is_proper_subset_of(bs11)) << std::endl; //true
	std::cout << (bs11.is_proper_subset_of(bs10)) << std::endl; //false

	//d)
	boost::dynamic_bitset<> bs12(std::string("1000100"));
	std::cout << "The first bit can be found in bs12 at: " << bs12.find_first() << std::endl;//2
	std::cout << "The next bit can be found in bs12 at: " << bs12.find_next(2) << std::endl; //6




    return 0;
}

