#pragma once
#include "Building.h"

class House : public Building
{
private:
	unsigned int rooms;
	char* owner;

public:
	House();
	House(const unsigned int&, const unsigned int&, const unsigned int&, const unsigned int&, const char*);
	House(const House&);
	House& operator=(const House&);
	~House();

	unsigned int getRooms() const;
	const char* getOwner() const;
	void setRooms(const unsigned int&);
	void setOwner(const char*);

	bool operator< (const House&);
};

std::ostream& operator<<(std::ostream&, const House&);