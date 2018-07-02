#pragma once
#include <string>

class Customer
{
public:
	Customer();
	Customer(const std::string&, const std::string&, const std::string&);

	void display() const;
	std::string getId() const;
	std::string getName() const;
	std::string getAddress() const;


private:
	std::string id;
	std::string name;
	std::string address;
};