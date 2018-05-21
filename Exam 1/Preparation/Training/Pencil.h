#pragma once
#include "WritingInstrument.h"

class Pencil : public WritingInstrument
{
private:
	short hardness;

public:
	Pencil();
	Pencil(const char* brand, const unsigned int& manufYear, const short& hardness);

	const short& getHardness() const;
	void setHardness(const short& _hardness);

};

std::istream& operator>>(std::istream& is, Pencil& rhs);
std::ostream& operator<<(std::ostream& os, const Pencil& rhs);