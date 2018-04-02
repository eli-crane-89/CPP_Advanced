#include <boost\algorithm\string.hpp>
#include <string>
#include <iostream>
#include <iterator>

using string = std::string;
int main()
{
	//a)
	std::cout << "\n\na)\n";
	string s = " Hello world with spaces ";

	//Copy trim
	string s2 = boost::trim_copy(s);
	std::cout << s2 << "." << std::endl;

	//Trim in place
	boost::trim(s);
	std::cout << s << "." << std::endl;

	//b)
	std::cout << "\n\nb)\n";
	s = "AAAHello world with AAAA";

	//Copy trim if
	s2 = boost::trim_copy_if(s, [](const char s) {return s == 'A'; });
	std::cout << s2 << "." << std::endl;

	//Trim if in place
	boost::trim_if(s, [](const char s) {return s == 'A'; } );
	std::cout << s << "." << std::endl;

	//c)
	std::cout << "\n\nc)\n";
	s = "AAAHello world with ABBB";

	std::cout << std::boolalpha << boost::starts_with(s, "AAA") << std::endl; //true
	std::cout << std::boolalpha << boost::starts_with(s, "BBB") << std::endl; //false
	std::cout << std::boolalpha << boost::ends_with(s, "BBB") << std::endl; //true
	std::cout << std::boolalpha << boost::ends_with(s, "ABB") << std::endl; //false

	//d)
	std::cout << "\n\nd)\n";
	string s3 = "Hello";
	string s4 = "HELLo";

	//contains
	//case sensitive
	std::cout << std::boolalpha << boost::contains(s, s3) << std::endl; //true
	std::cout << std::boolalpha << boost::contains(s, s4) << std::endl; //false
	//case insensitive
	std::cout << std::boolalpha << boost::icontains(s, s4) << std::endl; //true

	//if equal
	std::cout << std::boolalpha << (boost::equal(s3, s4)) << std::endl; //false
	std::cout << std::boolalpha << (boost::iequals(s3, s4)) << std::endl; //true

    return 0;
}

