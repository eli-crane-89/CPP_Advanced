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
#include <regex>

using Data = std::tuple<boost::gregorian::date, std::vector<double>>;
using ResultSet = std::list<Data>;

//Positions
int pOpen = 0, pHigh = 1, pLow = 2, pClose = 3, pVol = 4, pAdjClose = 5;

auto lPrint = [](const Data& d) {
	std::cout << "Date: " << std::get<0>(d).month() << " " << std::get<0>(d).day() << ", " << std::get<0>(d).year() << std::endl;
	std::cout << "Open: " << std::get<1>(d)[pOpen] << std::endl;
	std::cout << "High: " << std::get<1>(d)[pHigh] << std::endl;
	std::cout << "Low: " << std::get<1>(d)[pLow] << std::endl;
	std::cout << "Close: " << std::get<1>(d)[pClose] << std::endl;
	std::cout << "Vol: " << std::get<1>(d)[pVol] << std::endl;
	std::cout << "AdjClose: " << std::get<1>(d)[pAdjClose] << std::endl;
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

auto lCheckValid = [&](const std::string& s, std::regex& rx) {
	std::smatch m;
	
	return std::regex_search(s, m, rx);
};

Data DataFromLine(const std::string& line, std::regex& rx) {
	Data d;

	//Get valid string and join
	auto it_token = std::sregex_token_iterator(line.begin(), line.end(), rx);
	auto it_token_end = std::sregex_token_iterator();
	std::string validString = "";

	while (it_token != it_token_end) {
		validString += *it_token;
		it_token++;
	}

	//Make date string
	boost::gregorian::date date = createDate(validString.substr(0,10));

	//Get the divided numbers
	std::string dividedNumbers = validString.substr(11);
	
	//Return all non commas
	std::regex rx_comma(",");
	auto it_token_dn = std::sregex_token_iterator(dividedNumbers.begin(), dividedNumbers.end(), rx_comma, -1);
	auto it_token_dn_end = std::sregex_token_iterator();

	//Place into vector of doubles
	std::vector<double> vValues;
	while (it_token_dn != it_token_dn_end) {

		vValues.push_back(boost::lexical_cast<double>(*it_token_dn));

		it_token_dn++;
	}

	//Make data tuple
	d = std::make_tuple(date, vValues);

	return d;
}

ResultSet ResultSetCreator(const std::string fileName) {

	ResultSet rs;

	std::vector<std::string> vStrings;

	std::regex reg_valid("(\\d{4})(-)\\d{2}(-)\\d{2}((,[[:digit:]]+)(\\.[[:digit:]]+)?){6}");

	//fields
	boost::gregorian::date date;
	double Open, High, Low, Close, Vol, AdjClose;

	//Open File
	std::ifstream inputFile(fileName);
	std::string line;
	while (std::getline(inputFile, line)) {
		//if valid, add data
		if (lCheckValid(line, reg_valid)){

			Data d = DataFromLine(line, reg_valid);
			rs.push_back(d);
		}

	}

	inputFile.close();

	return rs;

}

#endif