#ifndef FILEPARSER_HPP
#define FILEPARSER_HPP

#include <boost\algorithm\string.hpp>
#include <string>
#include <vector>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <tuple>
#include <list>
#include <stdio.h>
#include <string>
#include <fstream>

using Data = std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;

//Positions
int pDate = 0, pOpen = 1, pHigh = 2, pLow = 3, pClose = 4, pVol = 5, pAdjClose = 6;

auto lPrint = [](const Data& d) {
	std::cout << "Date: " << std::get<0>(d).month() << " " << std::get<0>(d).day() << ", " << std::get<0>(d).year() << std::endl;
	std::cout << "Open: " << std::get<1>(d)[pOpen - 1] << std::endl;
	std::cout << "High: " << std::get<1>(d)[pHigh - 1] << std::endl;
	std::cout << "Low: " << std::get<1>(d)[pLow - 1] << std::endl;
	std::cout << "Close: " << std::get<1>(d)[pClose - 1] << std::endl;
	std::cout << "Vol: " << std::get<1>(d)[pVol - 1] << std::endl;
	std::cout << "AdjClose: " << std::get<1>(d)[pAdjClose - 1] << std::endl;
	std::cout << std::endl;
};


boost::gregorian::date createDate(const std::string& s) {
	std::vector<std::string> strs;

	boost::split(strs, s, boost::is_any_of("-"));

	boost::gregorian::date::year_type year = boost::lexical_cast<int>(strs[0]);
	boost::gregorian::date::month_type month = boost::lexical_cast<int>(strs[1]);
	boost::gregorian::date::day_type day = boost::lexical_cast<int>(strs[2]);

	return boost::gregorian::date(year, month, day);
}

ResultSet ResultSetCreator(const std::string fileName) {
	
	ResultSet rs;

	std::vector<std::string> vStrings;

	

	//fields
	boost::gregorian::date date;
	double Open, High, Low, Close, Vol, AdjClose;

	//Open File
	std::ifstream inputFile(fileName);

	std::string line;
	bool headerSkipped = false; //to skip header
	while (std::getline(inputFile, line)) {
		if (headerSkipped) {
			vStrings = boost::split(vStrings, line, boost::is_any_of(","));

			date = createDate(vStrings[pDate]);

			Open = boost::lexical_cast<double>(vStrings[pOpen]);
			High = boost::lexical_cast<double>(vStrings[pHigh]);
			Low = boost::lexical_cast<double>(vStrings[pLow]);
			Close = boost::lexical_cast<double>(vStrings[pClose]);
			Vol = boost::lexical_cast<double>(vStrings[pVol]);
			AdjClose = boost::lexical_cast<double>(vStrings[pAdjClose]);
			std::vector<double> vNums{ Open, High, Low, Close, Vol, AdjClose };

			Data d = std::make_tuple(date, vNums);

			rs.push_back(d);
		}
		else {
			headerSkipped = true;
		}
	}

	inputFile.close();

	return rs;

}

#endif