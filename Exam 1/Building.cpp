#include "Building.h"

Building::Building() : height(0), area(0), floors(0) {}

Building::Building(const unsigned int &h, const unsigned int &a, const unsigned int &f) : height(h), area(a), floors(f) {}

unsigned int Building::getHeight() const
{
	return height;
}

unsigned int Building::getArea() const
{
	return area;
}

unsigned int Building::getFloors() const
{
	return floors;
}

void Building::setHeight(const unsigned int &h)
{
	height = h;
}

void Building::setArea(const unsigned int &a)
{
	area = a;
}

void Building::setFloors(const unsigned int &f)
{
	floors = f;
}

unsigned int Building::getTotalArea() const
{
	return area*floors;
}

bool Building::operator<(const Building &rhs)
{
	return (getTotalArea() < rhs.getTotalArea());
}

std::ostream & operator<<(std::ostream & os, const Building & rhs)
{
	return os << "Height: " << rhs.getHeight() << "\nArea: " << rhs.getArea() << "\nFloors: " << rhs.getFloors() << '\n';
}
