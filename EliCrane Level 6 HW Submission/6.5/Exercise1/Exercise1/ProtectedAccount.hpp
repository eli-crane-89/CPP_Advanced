#ifndef PROTECTEDACCOUNT_HPP
#define PROTECTEDACCOUNT_HPP

#include <memory>
#include <string>

#include "Account.hpp"
#include "RealAccount.hpp"

#include "NoAccessException.hpp"

class ProtectedAccount : public Account {
private:

	std::shared_ptr<Account> account;

public:
	ProtectedAccount(double, std::string);

	void Withdraw(double);
	double GetBalance() const;
	std::string GetPassword() const;
	double GetBalance(std::string) const throw (NoAccessException);
};

#endif