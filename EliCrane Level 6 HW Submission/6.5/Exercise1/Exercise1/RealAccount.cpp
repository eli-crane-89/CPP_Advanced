#ifndef REALACCOUNT_CPP
#define REALACCOUNT_CPP

#include <iostream>
#include "RealAccount.hpp"

RealAccount::RealAccount() : balance(100.0) {};
RealAccount::RealAccount(double bal, std::string pw) : balance(bal), password(pw) {
	std::cout << "An account was created with a balance of: " << balance << " and a password of: " << pw << std::endl;
};

void RealAccount::Withdraw(double amt) {
	if (amt > balance) {
		throw NoFundsException();
	}

	balance -= amt;

	std::cout << "There was $" << amt << " withdrawn and $" << balance << " remains in the account." << std::endl;
}

double RealAccount::GetBalance() const{

	return balance;
}

std::string RealAccount::GetPassword() const{
	return password;
}

#endif