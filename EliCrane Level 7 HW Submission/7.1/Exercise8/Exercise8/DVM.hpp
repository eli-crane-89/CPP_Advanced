#ifndef DVM_HPP
#define DVM_HPP

#include <memory>

#include "ISource.hpp"
#include "IResource.hpp"
#include "ISink.hpp"
#include "IMIS.hpp"

template<class GSource, class GResource, class GSink, class GMIS>
class DVM {
private:
	std::unique_ptr<ISource> p_GSource;
	std::unique_ptr<IResource> p_GResource;
	std::unique_ptr<ISink> p_GSink;
	std::unique_ptr<IMIS> p_GMIS;

public:

	//Constructor
	DVM() {
		p_GSource = std::make_unique<GSource>();
		p_GResource = std::make_unique<GResource>();
		p_GSink = std::make_unique<GSink>();
		p_GMIS = std::make_unique<GMIS>();
	}

	void runItemBuyingSystem() {
		p_GResource.get()->displayProducts(); //Display products
		auto productChoice = p_GSource.get()->message(); //Get Customer Input As Tuple
		p_GResource.get()->getProduct(productChoice); //Inform Customer of Purchase
		p_GResource.get()->updateProduct(productChoice); //Update Product Amount
		p_GSink.get()->notify(std::get<0>(productChoice), true); //Thank customer
		p_GMIS.get()->notify(); //Close Session
	}

};

#endif