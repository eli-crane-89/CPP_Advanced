#include <iostream>
#include <bitset>
#include <string>


int main()
{
	//a)
	//bitset from u long
	unsigned long num = 4;
	std::bitset<3> bs = std::bitset<3>(num);

	std::cout << bs.to_string() << std::endl;

	//bitset from u long long
	unsigned long long ull = -156;
	std::bitset<7> bs2 = std::bitset<7>(ull);

	std::cout << bs2.to_string() << std::endl;

	//b)
	//bitsets from string
	std::bitset<3> bs3("100");
	std::bitset<7> bs4("1100100");
	std::cout << bs3.to_string() << std::endl;
	std::cout << bs4.to_string() << std::endl;

	//bitsets from strings and index
	std::bitset<4> bs5(std::string("100"),0,1); //0001
	std::bitset<7> bs6(std::string("1100100"),1,1); //0000001
	std::cout << bs5.to_string() << std::endl;
	std::cout << bs6.to_string() << std::endl;

	//c)
	//catch out of range error
	try {
		std::bitset<3> bs7(std::string("1000"), 5);
	}
	catch (const std::out_of_range& oor){
		std::cout << "index out of range." << std::endl;
	}

	//catch invalid arguments
	try {
		std::bitset<3> bs7(std::string("1002"));
	}
	catch (const std::invalid_argument& ia) {
		std::cout << "Invalid bit given." << std::endl;
	}

	//d)

	//Set all bits
	bs5.set();
	std::cout << bs5.to_string() << std::endl; //1111

	//Reset all bits
	bs5.reset();
	std::cout << bs5.to_string() << std::endl; //0000

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
	std::bitset<4> bs8(std::string("1001"));
	std::cout << "bs8 to string: " << bs8.to_string() << std::endl; //1001
	std::cout << "bs8 to ulong: " << bs8.to_ulong() << std::endl; //4
	std::cout << "bs8 to ullong: " << bs8.to_ullong() << std::endl; //4

	//f)
	//Check if equal
	std::cout << "bs8 equals bs5: " << std::boolalpha << (bs8 == bs5) << std::endl; //false
	std::cout << "bs8 not equals bs5: " << std::boolalpha << (bs8 != bs5) << std::endl; //true


    return 0;
}

