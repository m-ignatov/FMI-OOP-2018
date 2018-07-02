#include "CurrentAccount.h"
#include <iostream>

CurrentAccount::CurrentAccount() : Account() {}

CurrentAccount::CurrentAccount(const std::string& _iban, const std::string& _ownerId, const double& _amount) : Account(_iban, _ownerId, _amount) {}

CurrentAccount * CurrentAccount::copy() const
{
	return new CurrentAccount(*this);
}

void CurrentAccount::deposit(const double&  input)
{
	setAmount(getAmount() + input);
}

bool CurrentAccount::withdraw(const double& input)
{
	if (getAmount() - input < 0) return false;
	setAmount(getAmount() - input);
	return true;
}

void CurrentAccount::display()
{
	std::cout << "Type: Current Account\n";
	std::cout << "IBAN: " << getIban(); std::cout << "\n";
	std::cout << "Owner ID: " << getOwnerId(); std::cout << "\n";
	std::cout << "Amount: " << getAmount(); std::cout << "\n\n";
}
