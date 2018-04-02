#include <regex>
#include <string>
#include <iostream>

int main()
{
	std::string text("Quick brown fox"), output;
	std::regex vowels("a|e|i|o|u");

	std::regex_replace(std::back_inserter(output), text.begin(), text.end(), vowels,"*");

	std::cout << output << std::endl;

    return 0;
}

