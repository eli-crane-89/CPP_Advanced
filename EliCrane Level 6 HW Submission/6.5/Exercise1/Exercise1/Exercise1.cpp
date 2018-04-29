#include <iostream>
#include <memory>

#include "ProtectedAccount.hpp"
#include "NoAccessException.hpp"
#include "NoFundsException.hpp"


int main()
{
	ProtectedAccount pa = ProtectedAccount(300, "Santa");

	std::cout << pa.GetBalance("Santa") << std::endl;

	pa.Withdraw(150);

	try {
		pa.Withdraw(200);
	}
	catch (NoFundsException& e) {
		e.Message();
	}

	try {
		pa.GetBalance("Sant");
	}
	catch (NoAccessException& e) {
		e.Message();
	}


    return 0;
}

