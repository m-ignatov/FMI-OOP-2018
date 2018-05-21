#include "Pencil.h"
#pragma warning(disable:4996)

Pencil::Pencil() : WritingInstrument(), hardness(0)
{
}

Pencil::Pencil(const char * brand, const unsigned int & manufYear, const short & _hardness) : WritingInstrument(brand, manufYear)
{
	hardness = _hardness;
}

const short & Pencil::getHardness() const
{
	return hardness;
}

void Pencil::setHardness(const short& _hardness)
{
	hardness = _hardness;
}

std::istream & operator>>(std::istream & is, Pencil & rhs)
{
	short hard;
	is >> (WritingInstrument&)rhs;
	std::cout << "Input Hardness: ";
	is >> hard;
	rhs.setHardness(hard);
	return is;
}

std::ostream & operator<<(std::ostream & os, const Pencil & rhs)
{
	return os << rhs.getHardness() << " " << (WritingInstrument)rhs;
}
