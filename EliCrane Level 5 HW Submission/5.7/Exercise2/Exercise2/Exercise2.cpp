#include <iostream>
#include <string>
#include <boost/bimap/bimap.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

struct IpAddress {};
struct DomainName {};

int main()
{
	//a)
	using namespace boost::bimaps;

	//Create typedef DNS
	typedef bimap
	<
		unordered_set_of<tagged<boost::uuids::uuid, DomainName>>,
		unordered_set_of<tagged<std::string, IpAddress>>,
		list_of_relation
	> DNS;

	//Instanitate
	DNS dnsDB;

	//b)
	//Create UUIDs for DNS
	using namespace boost::uuids;
	string_generator strGen;
	uuid u1 = strGen("00000000-0000-0000-0000-000000000000");
	uuid u2 = strGen("0123456789abcdef0123456789ABCDEF");

	//Insert elements via push_back
	dnsDB.push_back(DNS::value_type(u1, "www.hello.com"));
	dnsDB.push_back(DNS::value_type(u2, "www.secret.com"));

	//Find
	std::cout << "The IpAddress associated with u1 is: " << dnsDB.left.find(u1)->get<IpAddress>() << std::endl;
	std::cout << "The DomainName associated with www.hello.com is: " << dnsDB.right.find("www.hello.com")->get<DomainName>() << std::endl;

	//c) Print Fucntion

	auto lPrint = [](const DNS& dns) {
		std::cout << std::endl;
		for (auto elem : dns) {
			std::cout << elem.get<DomainName>() << " : " << elem.get<IpAddress>() << std::endl;
		}
	};

	lPrint(dnsDB);



    return 0;
}

