#ifndef REALACCOUNT_HPP
#define REALACCOUNT_HPP

#include <string>

#include "Account.hpp"

class RealAccount : public Account {
private:
	double balance;
	std::string password;

public:
	RealAccount();
	RealAccount(double, std::string);
	
	//Functions
	void Withdraw(double) throw(NoFundsException);
	double GetBalance() const;
	std::string GetPassword() const;
};

#endif