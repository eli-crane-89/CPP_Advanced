#ifndef IMPLEMENTATION_HPP
#define IMPLEMENTATION_HPP

#include "ISource.hpp"
#include "IResource.hpp"
#include "ISink.hpp"
#include "IMIS.hpp"

#include <iostream>

class EbaySource : public ISource {
public:
	std::tuple <std::string, int> message() {
		std::cout << "Please make your product choice: ";
		std::string product;
		std::getline(std::cin, product);

		std::cout << "Please choose your quantity: ";
		int quantity;
		std::cin >> quantity;

		return std::make_tuple(product, quantity);
	}
};

#include <map>

class EbayResource : public IResource {
private:
	std::map<std::string, int> Products = { {"Cables",12},{"Lumber",13},{"Smoking Papers",20} };

public:
	void displayProducts() {
		std::cout << "The " << Products.size() << " products you can choose to buy are:\n";

		int prodNo = 1;
		for (auto iter = Products.begin(); iter != Products.end(); ++iter) {
			std::cout << prodNo << ") " << iter->first << " quantity: " << iter->second << std::endl;
			++prodNo;
		}
		std::cout << std::endl;

	};

	void getProduct(std::tuple<std::string, int> productChoice) {

		std::cout << "You have chosen to buy " << std::get<1>(productChoice) << " of product " << std::get<0>(productChoice) << ".\n";

	};

	void updateProduct(std::tuple<std::string, int> productChoice) {
		std::cout << "Decrementing the quantity of " << std::get<0>(productChoice) << " by " << std::get<1>(productChoice) << ".\n";

		auto iterProd = Products.find(std::get<0>(productChoice));
		iterProd->second -= std::get<1>(productChoice); //Decrement quantity

		std::cout << "The product " << std::get<0>(productChoice) << " now has quantity: " << iterProd->second << ".\n";
	};
};

class EbaySink : public ISink {
	void notify(std::string product, bool status) {
		std::cout << "Thank you for buying " << product << " with us today.\n";

		if (status) {
			std::cout << "You are a valued customer.\n";
		}
	}
};

class EbayMIS : public IMIS {
	void notify() {
		std::cout << "Your shopping session has ended.\n";
	}
};

#endif