#include "Account.h"

Account::Account() : iban(""), ownerId(""), amount(0.) {}

Account::Account(const std::string& _iban, const std::string& _ownerId, const double& _amount) : iban(_iban), ownerId(_ownerId), amount( _amount) {}

double Account::getAmount() const
{
	return amount;
}

void Account::setAmount(const double & newAmount)
{
	amount = newAmount;
}

std::string Account::getIban() const
{
	return iban;
}

std::string Account::getOwnerId() const
{
	return ownerId;
}
