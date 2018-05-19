#include "DVM.hpp"
#include "Implementation.hpp"

int main()
{
	DVM<EbaySource, EbayResource, EbaySink, EbayMIS> dvmEbay;
	dvmEbay.runItemBuyingSystem();

    return 0;
}

