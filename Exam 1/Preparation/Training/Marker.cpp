#include "Marker.h"
#pragma warning(disable:4996)
Marker::Marker() : WritingInstrument()
{
	color = new char[1];
	color = '\0';
}

Marker::Marker(const char * brand, const unsigned int & manufYear, const char * _color) : WritingInstrument(brand, manufYear)
{
	color = new char[strlen(_color) + 1];
	strcpy(color, _color);
}

Marker::Marker(const Marker & rhs) : WritingInstrument(rhs)
{
	color = new char[strlen(rhs.getColor()) + 1];
	strcpy(color, rhs.getColor());
}

Marker & Marker::operator=(const Marker & rhs)
{
	if (this != &rhs)
	{
		WritingInstrument::operator=(rhs);
		delete[] color;
		color = new char[strlen(rhs.getColor()) + 1];
		strcpy(color, rhs.getColor());
	}
	return *this;
}

Marker::~Marker()
{
	delete[] color;
}

const char * Marker::getColor() const
{
	return color;
}

void Marker::setColor(const char * _color)
{
	color = new char[strlen(_color) + 1];
	strcpy(color, _color);
}

std::istream & operator>>(std::istream & is, Marker & rhs)
{
	char color[1024];
	operator>>(is, (WritingInstrument&)rhs);
	std::cout << "Input Color: ";
	is >> color;
	rhs.setColor(color);
	return is;
}

std::ostream & operator<<(std::ostream & os, const Marker & rhs)
{
	return os << rhs.getColor() << " " << (WritingInstrument)rhs;
}
