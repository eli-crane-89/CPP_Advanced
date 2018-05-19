#include "DVM.hpp"
#include "ImplementationEbay.hpp"

int main()
{
	//a)
	DVM<EbaySource, EbayResource, EbaySink, EbayMIS> dvmEbay;
	dvmEbay.runItemBuyingSystem();

	//b)


    return 0;
}

