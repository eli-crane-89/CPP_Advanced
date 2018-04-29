#ifndef PROTECTEDACCOUNT_CPP
#define PROTECTEDACCOUNT_CPP
#include <iostream>
#include "ProtectedAccount.hpp"

ProtectedAccount::ProtectedAccount(double bal, std::string pw) {

	account = std::make_shared<RealAccount>(bal, pw);
}

void ProtectedAccount::Withdraw(double amt) {
	account.get()->Withdraw(amt);
}



double ProtectedAccount::GetBalance(std::string pw) const {

	if (pw != account.get()->GetPassword()) {
		throw NoAccessException();
	}

	return account.get()->GetBalance();
}

double ProtectedAccount::GetBalance() const {

	return account.get()->GetBalance();
}

std::string ProtectedAccount::GetPassword() const {

	return account.get()->GetPassword();
}


#endif