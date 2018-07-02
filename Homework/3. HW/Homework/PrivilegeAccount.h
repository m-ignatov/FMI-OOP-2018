#pragma once
#include "Account.h"
#include <string>

class PrivilegeAccount : public Account
{
public:
	PrivilegeAccount();
	PrivilegeAccount(const std::string&, const std::string&, const double&, const double&);
	virtual PrivilegeAccount* copy() const;
	virtual ~PrivilegeAccount() {}

	virtual void deposit(const double&);
	virtual bool withdraw(const double&);
	virtual void display();
	
	double getOverdraft() const;

private:
	double overdraft;
};