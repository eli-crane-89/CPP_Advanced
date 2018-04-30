#include <iostream>

#include "Counter.hpp"
#include "DoubleFormat.hpp"
#include "LongFormat.hpp"

int main()
{
	//Create Counter
	Counter* c(new Counter);

	//Create Observers
	DoubleFormat df(c);
	LongFormat lf(c);


	//Increment and Decrement to Check Notifications
	c->IncreaseCounter();
	c->IncreaseCounter();
	c->DecreaseCounter();
	//Both observers being notified

	//Remove process
	c->Detach(&df);
	std::cout << "Removed observer:\n";
	c->DecreaseCounter();
	//Process successfully removed

    return 0;
}

