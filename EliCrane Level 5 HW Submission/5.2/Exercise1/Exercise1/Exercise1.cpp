#include <regex>
#include <iostream>

int main()
{
	//a)
	//Must have [a-z] chars throughout string
	std::regex myReg("[a-z]*");
	//
	std::regex myReg2("[a-z]+");

	std::string s1("aza");
	std::string s2("1");
	std::string s3("b");
	std::string s4("ZZ TOP");

	std::cout << std::boolalpha << std::regex_match(s1, myReg) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(s1, myReg2) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(s2, myReg) << std::endl; //false
	std::cout << std::boolalpha << std::regex_match(s2, myReg2) << std::endl; //false
	std::cout << std::boolalpha << std::regex_match(s3, myReg) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(s3, myReg2) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(s4, myReg) << std::endl; //fasle
	std::cout << std::boolalpha << std::regex_match(s4, myReg2) << std::endl; //false

	//b)
	//must have digit or 
	std::regex myNumericReg("\\d{2}");
	std::string f("34");
	std::string s("345");

	std::cout << std::boolalpha << std::regex_match(f, myNumericReg) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(s, myNumericReg) << std::endl; //false

	//c)
	//match new or delete
	std::regex myAltReg("(new)|(delete)");
	std::string s4A("new");
	std::string s5("delete");
	std::string s6("malloc");

	std::cout << std::boolalpha << std::regex_match(s4A, myAltReg) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(s5, myAltReg) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(s6, myAltReg) << std::endl; //false

	//d)
	//Match capital A 0-N times
	std::regex myReg3("A*");
	//Match Capital A 1-N times
	std::regex myReg4("A+");
	//Matches two numbers
	std::regex myReg5("(\\d{2})");
	//std::regex myReg6("\\d{2, 4}");
	//Matches 1 to n numbers
	std::regex myReg7("\\d{1,}");

	std::string testA("1");

	std::cout << std::boolalpha << std::regex_match(testA, myReg3) << std::endl; //false
	std::cout << std::boolalpha << std::regex_match(testA, myReg4) << std::endl; //false
	std::cout << std::boolalpha << std::regex_match(testA, myReg5) << std::endl; //false
	std::cout << std::boolalpha << std::regex_match(testA, myReg7) << std::endl; //true

	//e)
	std::cout << std::endl;
	std::regex rC("(\\w)*"); // Alphanumeric (word) A-Za-z0-9
	std::regex rC1("(\\W)*"); // Not a word
	std::regex rC2("[A-Za-z0-9_]*"); // Alphanumeric (word) A-Za-z0-9

	std::string sC1("abc");
	std::string sC2("A12678Z909za");

	std::cout << std::boolalpha << std::regex_match(sC1, rC) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(sC1, rC1) << std::endl; //false
	std::cout << std::boolalpha << std::regex_match(sC1, rC2) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(sC2, rC) << std::endl; //true
	std::cout << std::boolalpha << std::regex_match(sC2, rC1) << std::endl; //false
	std::cout << std::boolalpha << std::regex_match(sC2, rC2) << std::endl; //true


    return 0;
}

