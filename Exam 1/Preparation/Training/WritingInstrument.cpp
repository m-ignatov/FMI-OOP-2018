#include "WritingInstrument.h"
#include <cstring>
#pragma warning(disable:4996)

WritingInstrument::WritingInstrument() : manufYear(0)
{
	brand = new char[1];
	brand[0] = '\0';
}

WritingInstrument::WritingInstrument(const char * _brand, const unsigned int & _manufYear) : manufYear(_manufYear)
{
	brand = new char[strlen(_brand) + 1];
	strcpy(brand, _brand);
}

WritingInstrument::WritingInstrument(const WritingInstrument & rhs)
{
	brand = new char[strlen(rhs.getBrand()) + 1];
	strcpy(brand, rhs.getBrand());

	manufYear = rhs.getManufYear();
}

WritingInstrument & WritingInstrument::operator=(const WritingInstrument & rhs)
{
	if (this != &rhs)
	{
		delete[] brand;

		manufYear = rhs.getManufYear();
		brand = new char[strlen(rhs.getBrand()) + 1];
		strcpy(brand, rhs.getBrand());
	}
	return *this;
}

WritingInstrument::~WritingInstrument()
{
	delete[] brand;
}

const char * WritingInstrument::getBrand() const
{
	return brand;
}

const unsigned int WritingInstrument::getManufYear() const
{
	return manufYear;
}

void WritingInstrument::setBrand(const char * _brand)
{
	brand = new char[strlen(_brand) + 1];
	strcpy(brand, _brand);
}

void WritingInstrument::setManufYear(const unsigned int & _manufYear)
{
	manufYear = _manufYear;
}

std::istream & operator>>(std::istream & is, WritingInstrument & rhs)
{
	unsigned int year;
	char brand[1024];
	
	std::cout << "Input Year: ";
	is >> year;
	std::cout << "Input Brand: ";
	is >> brand;

	rhs.setBrand(brand);
	rhs.setManufYear(year);
	return is;
}

std::ostream & operator<<(std::ostream & os, const WritingInstrument & rhs)
{
	return os << rhs.getManufYear() << " " << rhs.getBrand() << std::endl;
}
