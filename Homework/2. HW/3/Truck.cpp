#include "Truck.h"
#include <iostream>

Truck::Truck() : Vehicle(), size(0) { }

Truck::Truck(const Truck & rhs) : Vehicle(rhs), size(rhs.size) {}

Truck::Truck(const char *make, const char *model, const char *color, const int &year, const int &mileage, const int& size) : Vehicle(make, model, color, year, mileage)
{
	this->size = size;
}

Truck & Truck::operator=(const Truck & rhs)
{
	Vehicle::operator=(rhs);
	if (this != &rhs)
	{
		size = rhs.size;
	}

	return *this;
}

Truck::~Truck() { std::cout << "~Truck"; }

void Truck::details() const
{
	std::cout << "Make: " << getMake() << '\n';
	std::cout << "Model: " << getModel() << '\n';
	std::cout << "Color: " << getColor() << '\n';
	std::cout << "Year: " << getYear() << '\n';
	std::cout << "Mileage: " << getMileage() << '\n';
	std::cout << "Size:" << size << "\n\n";
}
