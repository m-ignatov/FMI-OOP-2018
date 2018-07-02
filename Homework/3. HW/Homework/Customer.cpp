#include "Customer.h"
#include <iostream>

Customer::Customer() : id(""), name(""), address("") {}

Customer::Customer(const std::string &_id, const std::string &_name, const std::string &_address) : id(_id), name(_name) , address(_address) {}

std::string Customer::getId() const
{
	return id;
}

std::string Customer::getName() const
{
	return name;
}

std::string Customer::getAddress() const
{
	return address;
}

void Customer::display() const
{
	std::cout << "ID: " << id; std::cout << "\n";
	std::cout << "Name: " << name; std::cout << "\n";
	std::cout << "Address: " << address; std::cout << "\n\n";
}
