#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

#include "NoFundsException.hpp"

class Account {
public:
	virtual void Withdraw(double) throw(NoFundsException) = 0;
	virtual double GetBalance() const = 0;
	virtual std::string GetPassword() const = 0;
};

#endif