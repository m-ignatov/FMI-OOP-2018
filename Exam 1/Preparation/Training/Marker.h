#pragma once
#include "WritingInstrument.h"

class Marker : public WritingInstrument
{
private:
	char* color;

public:
	Marker();
	Marker(const char* brand, const unsigned int& manufYear, const char* color);
	Marker(const Marker& rhs);
	Marker& operator=(const Marker& rhs);
	~Marker();

	const char* getColor() const;
	void setColor(const char* _color);

};

std::istream& operator>>(std::istream& is, Marker& rhs);
std::ostream& operator<<(std::ostream& os, const Marker& rhs);