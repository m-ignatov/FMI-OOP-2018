#pragma once
#include <string>

class Account
{

public:
	Account();
	Account(const std::string&, const std::string&, const double&);
	virtual Account* copy() const = 0;
	virtual ~Account() {};

	virtual void deposit(const double&) = 0;
	virtual bool withdraw(const double&) = 0;
	virtual void display() = 0;

	double getAmount() const;
	void setAmount(const double&);
	std::string getIban() const;
	std::string getOwnerId() const;

private:
	std::string iban;
	std::string ownerId;
	double amount;
};