#include <boost\algorithm\string.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <map>

boost::gregorian::date createDate(const std::string& s) {
	std::vector<std::string> strs;

	boost::split(strs, s, boost::is_any_of("-"));

	boost::gregorian::date::year_type year = boost::lexical_cast<int>(strs[0]);
	boost::gregorian::date::month_type month = boost::lexical_cast<int>(strs[1]);
	boost::gregorian::date::day_type day = boost::lexical_cast<int>(strs[2]);
	
	return boost::gregorian::date(year, month, day);
}

std::map<std::string, double> makeMap(const std::string& s) {
	std::map<std::string, double> res;

	std::vector<std::string> vStrings;
	boost::split(vStrings, s, boost::is_any_of("=") || boost::is_any_of(","));

	auto iter = vStrings.begin();
	while(iter != vStrings.end()) {
		auto key = boost::trim_copy(*iter);
		//pre-increment iter to get next value
		auto value = boost::lexical_cast<double>(boost::trim_copy(*++iter));
		res.insert(std::make_pair(key, value));

		++iter;
	}

	return res;
}

int main()
{
	//a)
	std::string sA("1,2,3,4/5/9*56");
	std::vector<std::string> strs;
	boost::split(strs, sA, boost::is_any_of(",") || boost::is_any_of("*"));

	std::string sJoin = boost::algorithm::join(strs, "/");
	std::cout << "sJoin: " << sJoin << std::endl;

	//b)
	std::string sDate("2016-12-31");
	boost::gregorian::date d = createDate(sDate);

	std::cout << "The date is: " << d.month() << " " << d.day() << ", " << d.year() << "." << std::endl;

	//c)

	std::string sPair = { "port = 23, pin = 87, value = 34.4" };

	std::map<std::string, double> m = makeMap(sPair);

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		std::cout << iter->first << " : " << iter->second << std::endl;
	}

    return 0;
}

