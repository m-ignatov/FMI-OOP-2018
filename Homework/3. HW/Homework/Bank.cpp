#include "Bank.h"
#include "CurrentAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include <iostream>

Bank::Bank() : name(""), address("") {}

Bank::Bank(const std::string & name, const std::string & address)
{
	this->name = name;
	this->address = address;
}

Bank::Bank(const Bank &rhs)
{
	copyFrom(rhs);
}

Bank & Bank::operator=(const Bank &rhs)
{
	if (this != &rhs)
	{
		for (size_t i = 0; i < accounts.size(); i++)
		{
			delete accounts[i];
		}
		accounts.erase(accounts.begin(), accounts.end());
		customers.erase(customers.begin(), customers.end());
		copyFrom(rhs);
	}
	return *this;
}

Bank::~Bank()
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		delete accounts[i];
	}
}

std::string Bank::getName() const
{
	return name;
}

std::string Bank::getAddress() const
{
	return address;
}

void Bank::addCustomer(const std::string & customerId, const std::string & name, const std::string & address)
{
	for (size_t i = 0; i < customers.size(); i++)
	{
		if (customers[i].getId() == customerId) return;
	}
	customers.push_back(Customer(customerId, name, address)); // TODO - WATCH OUT!!!
}

void Bank::listCustomers() const
{
	for (size_t i = 0; i < customers.size(); i++)
	{
		customers[i].display();
	}
}

void Bank::deleteCustomer(const std::string &customerId)
{
	for (size_t i = 0; i < customers.size(); i++)
	{
		if (customers[i].getId() == customerId)
		{
			customers.erase(customers.begin() + i);
		}
	}
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerId() == customerId)
		{
			deleteAccount(i);
		}
	}
}

void Bank::addAccount(const size_t& type, const std::string & iban, const std::string & ownerId, const double & amount)
{
	bool flag = false;

	for (size_t i = 0; i < customers.size(); i++)
	{
		if (customers[i].getId() == ownerId) flag = true;
	}
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			std::cout << "IBAN: " << iban << " already exists!\n";
			return;
		}
	}

	if (!flag) std::cout << "No such customer with ID:" << ownerId << "\n";
	else
	{
		Account* tmp;

		if (type == 1)
		{
			tmp = new CurrentAccount(iban, ownerId, amount);
		}
		else if (type == 2)
		{
			double interestR;
			std::cout << "Interest Rate: ";
			std::cin >> interestR;
			tmp = new SavingsAccount(iban, ownerId, amount, interestR);
		}
		else if (type == 3)
		{
			double overdraft;
			std::cout << "Overdraft: ";
			std::cin >> overdraft;
			tmp = new PrivilegeAccount(iban, ownerId, amount, overdraft);
		}
		else
		{
			std::cout << "Invalid account type!\n";
			return;
		}
		accounts.push_back(tmp);
	}
}

void Bank::deleteAccount(const std::string & iban)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			deleteAccount(i);
		}
	}
}

void Bank::listAccounts() const
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		accounts[i]->display();
	}
}

void Bank::listCustomerAccount(const std::string & customerId) const
{
	std::cout << "Customer " << customerId << " has these accounts\n";
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerId() == customerId)
		{
			accounts[i]->display();
		}
	}
}

void Bank::transfer(const std::string & fromIban, const std::string & toIban, const double & amount)
{
	int fromInd = -1, toInd = -1;
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == fromIban)
		{
			fromInd = i;
			if (accounts[i]->getAmount() < amount)
			{
				std::cout << "Not enough money to transfer\n";
				return;
			}
		}
		if (accounts[i]->getIban() == toIban) toInd = i;
	}

	if (fromInd == -1 || toInd == -1)
	{
		std::cout << "Unable to tranfer money! IBAN not found\n";
		return;
	}

	accounts[fromInd]->setAmount(accounts[fromInd]->getAmount() - amount);
	accounts[toInd]->setAmount(accounts[toInd]->getAmount() + amount);
	std::cout << "Tranfer successful!\n";
}

void Bank::withdrawFromIban(const std::string & iban, const double & amount)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			if (accounts[i]->withdraw(amount))
			{
				std::cout << "Withdraw successful!\n";
			}
			else
			{
				std::cout << "Not enough money to withdraw!\n";
			}
			return;
		}
	}
	std::cout << "IBAN not found!\n";
}

void Bank::depositFromIban(const std::string & iban, const double & amount)
{
	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getIban() == iban)
		{
			accounts[i]->deposit(amount);
			std::cout << "Deposit successful!\n";
			return;
		}
	}
	std::cout << "IBAN not found!\n";
}

void Bank::display() const
{
	std::cout << "Bank: " << name << "\n";
	std::cout << "Address: " << address << "\n";
	std::cout << customers.size() << " customer(s) and ";
	std::cout << accounts.size() << " account(s)\n";
}

void Bank::deleteAccount(unsigned int i)
{
	delete accounts[i];
	accounts.erase(accounts.begin() + i);
}

void Bank::copyFrom(const Bank & rhs)
{
	name = rhs.name;
	address = rhs.address;

	for (size_t i = 0; i < rhs.customers.size(); i++)
	{
		customers.push_back(rhs.customers[i]);
	}
	for (size_t i = 0; i < rhs.accounts.size(); i++)
	{
		accounts.push_back(rhs.accounts[i]->copy());
	}
}
