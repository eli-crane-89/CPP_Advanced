#include <iostream>

#include "Counter.hpp"


int main()
{
	Counter c1;
	Counter c2(3);
	Counter c3(17);
	Counter c4(15);

	c2.AddObservable(&c3);
	c2.AddObservable(&c4);
	c1.AddObservable(&c2);

	//Updates c2, c3, c4
	c1.IncreaseCounter();

    return 0;
}

