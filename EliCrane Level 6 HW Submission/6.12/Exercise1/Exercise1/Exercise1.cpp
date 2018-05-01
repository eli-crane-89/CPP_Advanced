#include <iostream>

#include "Counter.hpp"


int main()
{
	//Make shared pointers
	std::shared_ptr<Observable> c1 = std::make_shared<Counter>(0);
	std::shared_ptr<Observable> c2 = std::make_shared<Counter>(3);
	std::shared_ptr<Observable> c3 = std::make_shared<Counter>(17);
	std::shared_ptr<Observable> c4 = std::make_shared<Counter>(99);

	//Create Tree
	c2.get()->AddObservable(c3);
	c2.get()->AddObservable(c4);
	c1.get()->AddObservable(c2);

	//Update all trees
	c1.get()->Update();

    return 0;
}

