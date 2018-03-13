
#include "BaseDerived.hpp"



int main()
{
	//a)
	std::list<SharedBase> list_sp;

	//std::list<std::unique_ptr<Base>> list_up;
	//The unique pointer errors out at compile time because unqiue ptr cannot access private members


	//b) Factor function for derived
	for (int i = 0; i < 3; i++) {
		cout << "hello" << endl;

		list_sp.push_back(DerivedFactory());
	}

	//c)
	//Base and Derived destructors called 3x each

    return 0;
}

