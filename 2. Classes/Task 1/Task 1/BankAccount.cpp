#include "BankAccount.h"
#include <iostream>
#include <cstring>

BankAccount::BankAccount() : availabilityCash(0.), name("N/A"), bankAccountNumber("N/A") {}

BankAccount::BankAccount(const char * _name, const char * IBAN, const float & cash) : availabilityCash(cash)
{
	strcpy_s(name, _name);
	strcpy_s(bankAccountNumber, IBAN);
}

const void BankAccount::getInfo()
{
	std::cout << "Name: " << name << "\nIBAN: " << bankAccountNumber << "\nAvailability: " << availabilityCash << " BGN" << std::endl;
	std::cout << std::endl;
}

void BankAccount::Deposit(const float & input)
{
	availabilityCash += input;
	std::cout << "Deposit OK" << std::endl;
	getInfo();
}

void BankAccount::Widthdraw(const float & input)
{
	availabilityCash -= input;
	std::cout << "Widthdraw OK" << std::endl;
	getInfo();
}

const char * BankAccount::getName() const
{
	return bankAccountNumber;
}

void BankAccount::setName(const char * _name)
{
	strcpy_s(name, _name);
}

const char * BankAccount::getBankAccountNumber() const
{
	return bankAccountNumber;
}

void BankAccount::setBankAccountNumber(const char * _IBAN)
{
	strcpy_s(bankAccountNumber, _IBAN);
}

const float& BankAccount::getAvailabilityCash() const
{
	return availabilityCash;
}

void BankAccount::setAvailabilityCash(const float & _cash)
{
	availabilityCash = _cash;
}
