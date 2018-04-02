#include "FIleReader.hpp"

int main()
{

	auto rs = ResultSetCreator("InputFile.txt");

	for (auto elem : rs) {
		lPrint(elem);
	}

    return 0;
}

