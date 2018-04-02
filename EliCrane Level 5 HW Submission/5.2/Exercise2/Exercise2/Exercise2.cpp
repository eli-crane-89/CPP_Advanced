#include <regex>
#include <iostream>

int main()
{
	std::regex mySearchReg("(rain)|(Spain)");
	std::string myText("The rain in Spain stays mainly on the plain");
	std::smatch m;
	std::cout << std::distance(m.begin(), m.end()) << std::endl;

	//If regex_search returns true
	if (std::regex_search(myText, m, mySearchReg)) {
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			//Regex search returns first full match (rain), + sub match(rain) + the zero match of Spain (blank line)
			std::cout << *iter << std::endl;
		}
	}

    return 0;
}

