#include "SavingsAccount.h"
#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() : Account(), interestRate(0) {}

SavingsAccount::SavingsAccount(const std::string& _iban, const std::string& _ownerId, const double& _amount, const double& _inRate) : Account(_iban, _ownerId, _amount), interestRate(_inRate) {}

void SavingsAccount::deposit(const double&  input)
{
	setAmount(getAmount() + input);
}

bool SavingsAccount::withdraw(const double& input)
{
	if (getAmount() - input < 0) return false;
	setAmount(getAmount() - input);
	return true;
}

void SavingsAccount::display()
{
	std::cout << "Savings Account\n";
	std::cout << "IBAN: " << getIban(); std::cout << "\n";
	std::cout << "Owner ID: " << getOwnerId(); std::cout << "\n";
	std::cout << "Interest Rate: " << getInterestRate(); std::cout << "\n";
	std::cout << "Amount: " << getAmount(); std::cout << "\n\n";
}

SavingsAccount * SavingsAccount::copy() const
{
	return new SavingsAccount(*this);
}

double SavingsAccount::getInterestRate() const
{
	return interestRate;
}
