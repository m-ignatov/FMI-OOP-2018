#pragma once
#include <iostream>

class WritingInstrument
{
private:
	char* brand;
	unsigned int manufYear;

public:
	WritingInstrument();
	WritingInstrument(const char* _brand, const unsigned int& _manufYear);
	WritingInstrument(const WritingInstrument& rhs);
	WritingInstrument& operator=(const WritingInstrument& rhs);
	~WritingInstrument();

	const char* getBrand() const;
	const unsigned int getManufYear() const;
	void setBrand(const char* _brand);
	void setManufYear(const unsigned int& _manufYear);
};

std::istream& operator>>(std::istream& is, WritingInstrument& rhs);
std::ostream& operator<<(std::ostream& os, const WritingInstrument& rhs);