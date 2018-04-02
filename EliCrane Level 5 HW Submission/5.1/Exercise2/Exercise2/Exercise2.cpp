#include <boost\algorithm\string.hpp>
#include <boost\fusion\algorithm\query.hpp>
#include <iostream>
#include <string>

//Password Checker
bool PasswordChecker(const std::string& s) {

	if (s.length() <= 8) {
		std::cout << "Password length is below 8 characters.\n";
		return false;
	}

	if (!std::any_of(s.begin(), s.end(), boost::is_digit())) {
		std::cout << "Password must contain a digit.\n";
		return false;
	}

	if (!std::any_of(s.begin(), s.end(), boost::is_alpha())) {
		std::cout << "Password must contain alpha characters.\n";
		return false;
	}

	if (!std::any_of(s.begin(), s.end(), boost::is_upper())) {
		std::cout << "Password must contain an uppercase character.\n";
		return false;
	}

	if (std::any_of(s.begin(), s.end(), boost::is_cntrl())) {
		std::cout << "Password may not contain control characters.\n";
		return false;
	}

	if (std::any_of(s.begin(), s.end(), boost::is_space())) {
		std::cout << "Password may not contain spaces.\n";
		return false;
	}

	return true;

}
int main()
{
	//a)
	std::string s1 = "abdz3";
	std::string s2 = "1234";
	std::string s3 = "abd1 234\*";

	//P1 //check if characters are all either digits or alpha
	std::cout << std::boolalpha << boost::all(s1, boost::is_digit() || boost::is_alpha()) << std::endl; //true
	std::cout << std::boolalpha << boost::all(s2, boost::is_digit() || boost::is_alpha()) << std::endl; //true
	std::cout << std::boolalpha << boost::all(s3, boost::is_digit() || boost::is_alpha()) << std::endl; //false
	
	//P2 //not necessary according to forum discussion
	//std::cout << std::boolalpha << std::any_of(s1.begin(), s1.end(), boost::is_digit() && !boost::is_alpha()) << std::endl; //false
	//std::cout << std::boolalpha << std::any_of(s2.begin(), s2.end(), boost::is_digit() && !boost::is_alpha()) << std::endl; //false
	//std::cout << std::boolalpha << std::any_of(s3.begin(), s3.end(), boost::is_digit() && !boost::is_alpha()) << std::endl; //false
	
	//P3 //check if characters are all alpha
	std::cout << std::boolalpha << boost::all(s1, boost::is_alpha()) << std::endl; //false
	std::cout << std::boolalpha << boost::all(s2, boost::is_alpha()) << std::endl; //false
	std::cout << std::boolalpha << boost::all(s3, boost::is_alpha()) << std::endl; //false

	//b)
	std::string pwd1 = "Ahe789lloman";
	std::string pwd2("DanielDuffy1952");
	std::string pwd3("DanielDuffy");
	std::string pwd4("U19520829");
	std::string pwd5("19520829 U");
	std::string pwd6("1952U");
	std::string pwd7("U19520829\n");

	std::cout << "Password: " << pwd1 << " has passed: " << std::boolalpha << PasswordChecker(pwd1) << std::endl; //true
	std::cout << "Password: " << pwd2 << " has passed: " << std::boolalpha << PasswordChecker(pwd2) << std::endl; //true
	std::cout << "Password: " << pwd3 << " has passed: " << std::boolalpha << PasswordChecker(pwd3) << std::endl; //false
	std::cout << "Password: " << pwd4 << " has passed: " << std::boolalpha << PasswordChecker(pwd4) << std::endl; //true
	std::cout << "Password: " << pwd5 << " has passed: " << std::boolalpha << PasswordChecker(pwd5) << std::endl; //false
	std::cout << "Password: " << pwd6 << " has passed: " << std::boolalpha << PasswordChecker(pwd6) << std::endl; //false
	std::cout << "Password: " << pwd7 << " has passed: " << std::boolalpha << PasswordChecker(pwd7) << std::endl; //false

    return 0;
}

