#include "Car.h"

Car::Car() : Vehicle() {}

Car::Car(const Car & rhs) : Vehicle(rhs) {}

Car::Car(const char *make, const char *model, const char *color, const int &year, const int &mileage) : Vehicle(make, model, color, year, mileage) {}

Car & Car::operator=(const Car & rhs)
{
	Vehicle::operator= (rhs);
	return *this;
}

Car::~Car() {}

void Car::details() const
{
	std::cout << "Make: " << getMake() << '\n';
	std::cout << "Model: " << getModel() << '\n';
	std::cout << "Color: " << getColor() << '\n';
	std::cout << "Year: " << getYear() << '\n';
	std::cout << "Mileage: " << getMileage() << "\n\n";
};
