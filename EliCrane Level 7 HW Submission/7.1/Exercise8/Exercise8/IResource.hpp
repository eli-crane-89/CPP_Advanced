#ifndef IRESOURCE_HPP
#define	IRESOURCE_HPP

#include <tuple>
#include <string>	

class IResource {
public:
	//Displays available products and quantities
	virtual void displayProducts() = 0;
	//Shows customer purchased product
	virtual void getProduct(std::tuple<std::string, int>) = 0;
	//Updates stock
	virtual void updateProduct(std::tuple<std::string, int>) = 0;
};

#endif