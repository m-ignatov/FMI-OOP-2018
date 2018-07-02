#pragma once
#include "Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount();
	CurrentAccount(const std::string&, const std::string&, const double&);
	virtual CurrentAccount* copy() const;
	virtual ~CurrentAccount() {}

	virtual void deposit(const double&);
	virtual bool withdraw(const double&);
	virtual void display();
};