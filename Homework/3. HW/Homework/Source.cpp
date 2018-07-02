#include <iostream>
#include <string>
#include "CurrentAccount.h"
#include "Bank.h"

Bank bank("UniCredit", "Sofia, Bulgaria");

void addNewCustomer()
{
	std::cout << "ADD NEW CUSTOMER\n\n";

	std::string customerId, name, address;
	std::cout << "Customer details\n";
	std::cout << "Customer ID: ";
	getline(std::cin, customerId);
	std::cout << "Name: ";
	getline(std::cin, name);
	std::cout << "Address: ";
	getline(std::cin, address);

	bank.addCustomer(customerId, name, address);
}

void deleteCustomer()
{
	std::cout << "DELETE CUSTOMER\n\n";

	std::string customerId;
	std::cout << "Customer ID: ";
	getline(std::cin, customerId);
	bank.deleteCustomer(customerId);
}

void listCustomerAccount()
{
	std::cout << "LIST CUSTOMER ACCOUNT\n\n";

	std::string customerId;
	std::cout << "Customer ID: ";
	getline(std::cin, customerId);
	bank.listCustomerAccount(customerId);
}

void addAccount()
{
	std::cout << "ADD ACCOUNT\n\n";

	std::string iban, ownerId;
	double amount;
	size_t accountType;

	std::cout << "Choose: (1) Current Account | (2) Savings Account | (3) Privilege Account\nAccount Type: ";
	std::cin >> accountType;
	std::cin.get();
	std::cout << "IBAN: ";
	getline(std::cin, iban);
	std::cout << "Owner ID: ";
	getline(std::cin, ownerId);
	std::cout << "Amount: ";
	std::cin >> amount;
	bank.addAccount(accountType, iban, ownerId, amount);
}

void deleteAccount()
{
	std::cout << "DELETE ACCOUNT\n\n";

	std::string iban;
	std::cout << "IBAN: ";
	getline(std::cin, iban);
	bank.deleteAccount(iban);
}

void withdrawFromAccount()
{
	std::cout << "WITHDRAW FROM ACCOUNT\n\n";

	std::string iban;
	double amount;
	std::cout << "IBAN: ";
	getline(std::cin, iban);
	std::cout << "Input amount to withdraw: ";
	std::cin >> amount;
	bank.withdrawFromIban(iban, amount);
}

void depositFromAccount()
{
	std::cout << "DEPOSIT FROM ACCOUNT\n\n";

	std::string iban;
	double amount;
	std::cout << "IBAN: ";
	getline(std::cin, iban);
	std::cout << "Input amount to deposit: ";
	std::cin >> amount;
	bank.depositFromIban(iban, amount);
}

void transfer()
{
	std::cout << "TRANSFER\n\n";

	std::string fromIban, toIban;
	double amount;
	std::cout << "From IBAN: ";
	std::cin >> fromIban;
	std::cout << "To IBAN: ";
	std::cin >> toIban;
	std::cout << "Amount: ";
	std::cin >> amount;
	bank.transfer(fromIban, toIban, amount);
}

bool validate(const std::string& in)
{
	for (size_t i = 0; i < in.size(); i++)
	{
		if (!isdigit(in[i])) return false;
	}
	return !in.empty();
}


int main()
{
	bank.addCustomer("1000", "John Smith", "Studentski Grad");
	bank.addCustomer("1", "Momchil", "Ignatov 12 Str.");
	bank.addAccount(1, "1000", "1000", 120.3);

	bool flag = true;

	while (flag)
	{
		system("cls");
		std::cout << "1 List customers\n2 Add new customer\n3 Delete customer\n4 List all accounts\n5 List customer accounts\n6 Add new account\n7 Delete account\n8 Withdraw from account\n9 Deposit to account\n10 Transfer\n11 Display info for the bank\n12 Quit\n";

		std::string str;
		std::getline(std::cin, str, '\n');
		if (!validate(str)) continue;
		int c = std::stoi(str);

		system("cls");

		switch (c)
		{
		case 1:
			bank.listCustomers();
			break;
		case 2:
			addNewCustomer();
			break;
		case 3:
			deleteCustomer();
			break;
		case 4:
			bank.listAccounts();
			break;
		case 5:
			listCustomerAccount();
			break;
		case 6:
			addAccount();
			break;
		case 7:
			deleteAccount();
			break;
		case 8:
			withdrawFromAccount();
			break;
		case 9:
			depositFromAccount();
			break;
		case 10:
			transfer();
			break;
		case 11:
			bank.display();
			break;
		case 12:
			flag = false;
			break;
		default:
			std::cout << "Invalid input!\n";
			break;
		}
		if (flag) system("pause");
	}
}