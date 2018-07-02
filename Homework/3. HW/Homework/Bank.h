#pragma once
#include <string>
#include <vector>
#include "Customer.h"
#include "Account.h"

class Bank
{
public:
	Bank();
	Bank(const std::string&, const std::string&);
	Bank(const Bank&);
	Bank& operator=(const Bank&);
	~Bank();

	std::string getName() const;
	std::string getAddress() const;

	void addCustomer(const std::string&, const std::string&, const std::string&);
	void listCustomers() const;
	void deleteCustomer(const std::string&);
	void addAccount(const size_t&, const std::string&, const std::string&, const double&);
	void deleteAccount(const std::string&);
	void listAccounts() const;
	void listCustomerAccount(const std::string&) const;
	void transfer(const std::string&, const std::string&, const double&);
	void withdrawFromIban(const std::string&, const double&);
	void depositFromIban(const std::string&, const double&);
	void display() const;

private:
	void deleteAccount(unsigned int);
	void copyFrom(const Bank&);

	std::string name;
	std::string address;
	std::vector<Customer> customers;
	std::vector<Account*> accounts;
};