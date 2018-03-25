#ifndef ADDITIONALFUNCTIONS_HPP
#define ADDITIONALFUNCTIONS_HPP

#include <string>
#include <algorithm>
#include <vector>

//Trim unary predicate
struct Trim {
	Trim() {};

	std::string operator()(const std::string& s) {
		std::vector<char> vChars = { ' ','\n','\t' };
		int sBegin = 0;
		int sEnd = 0;
		int posCount = 0;
		for (char c : s) {
			//If cannot find c in escape chars, continue
			if (std::find(vChars.begin(), vChars.end(), c) == vChars.end()) {

				//Only assign beginning position if it is first that meets this criteria
				if (sBegin == 0) {
					sBegin = posCount;
				}
				//always assign sEnd to last non trimmable term
				sEnd = posCount;
			}
			//increment position count
			posCount++;
		}

		std::string sRet = s.substr(sBegin, sEnd - sBegin + 1);

		return sRet;
	}
};

//Split string into vector based on key char
struct SplitString {
	char _keyChar;
	SplitString(char keyChar) : _keyChar(keyChar){};

	std::vector<std::string> operator()(const std::string& s) {
		std::vector<std::string> vRet;
		std::string sVal;

		auto iterBeginString = s.begin();
		auto iterEndString = s.begin();

		while (iterEndString != s.end()) {
			iterEndString = std::find(iterBeginString, s.end(), _keyChar);

			int sBegin = std::distance(s.begin(), iterBeginString);
			int sEnd = std::distance(iterBeginString, iterEndString);
			sVal = s.substr(sBegin, sEnd);
			if (sVal.length() > 0) { //Only append if length is greater than 0
				vRet.push_back(sVal);
			}

			if (iterEndString != s.end()) {
				//Set iterBeginString to next after iterEndString
				iterBeginString = iterEndString + 1;
			}


		}
		return vRet;
	}
};

std::string JoinStrings(const std::string s1, const std::string s2) {
	std::string res;

	for (char c : s1) {
		res.push_back(c);
	}

	for (char c : s2) {
		res.push_back(c);
	}

	return res;
}

#endif