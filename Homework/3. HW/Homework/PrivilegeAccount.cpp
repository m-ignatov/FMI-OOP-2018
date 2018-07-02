#include "PrivilegeAccount.h"
#include <iostream>

PrivilegeAccount::PrivilegeAccount() : Account(), overdraft(0) {}

PrivilegeAccount::PrivilegeAccount(const std::string& _iban, const std::string& _ownerId, const double& _amount, const double& _overdraft) : Account(_iban, _ownerId, _amount), overdraft(_overdraft) {}

double PrivilegeAccount::getOverdraft() const
{
	return overdraft;
}

void PrivilegeAccount::deposit(const double & input)
{
	setAmount(getAmount() + input);
}

bool PrivilegeAccount::withdraw(const double & input)
{
	if (getAmount() + overdraft < input) return false;
	setAmount(getAmount() - input);
	return true;
}

void PrivilegeAccount::display()
{
	std::cout << "Type: Privilege Account\n";
	std::cout << "IBAN: " << getIban(); std::cout << "\n";
	std::cout << "Owner ID: " << getOwnerId(); std::cout << "\n";
	std::cout << "Overdraft: " << getOverdraft(); std::cout << "\n";
	std::cout << "Amount: " << getAmount(); std::cout << "\n\n";
}

PrivilegeAccount * PrivilegeAccount::copy() const
{
	return new PrivilegeAccount(*this);
}
