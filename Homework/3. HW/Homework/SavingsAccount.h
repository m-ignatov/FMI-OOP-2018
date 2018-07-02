#pragma once
#include "Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount();
	SavingsAccount(const std::string&, const std::string&, const double&, const double&);
	virtual SavingsAccount* copy() const;
	virtual ~SavingsAccount() {}
	
	virtual void deposit(const double&);
	virtual bool withdraw(const double&);
	virtual void display();
	
	double getInterestRate() const;

private:
	double interestRate;
};