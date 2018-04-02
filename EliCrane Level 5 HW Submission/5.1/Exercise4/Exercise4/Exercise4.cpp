#include "FileParser.hpp"

#include <iostream>
#include <string>


int main()
{
	ResultSet rs = ResultSetCreator("InputFile.txt");

	for (auto data : rs) {
		lPrint(data);
	}

    return 0;
}

