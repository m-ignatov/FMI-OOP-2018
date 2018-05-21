#include "House.h"
#include <cstring>
#pragma warning(disable: 4996)

House::House() : Building(), rooms(0)
{
	owner = new char[1];
	owner[0] = '\0';
}

House::House(const unsigned int&h, const unsigned int&a, const unsigned int&f, const unsigned int&r, const char*o) : Building(h, a, f), rooms(r)
{
	owner = new char[strlen(o) + 1];
	strcpy(owner, o);
}

House::House(const House &rhs) : Building(rhs), rooms(rhs.getRooms())
{
	owner = new char[strlen(rhs.getOwner()) + 1];
	strcpy(owner, rhs.getOwner());
}

House & House::operator=(const House &rhs)
{
	if (this != &rhs)
	{
		delete[] owner;
		Building::operator=(rhs);
		rooms = rhs.getRooms();
		owner = new char[strlen(rhs.getOwner()) + 1];
		strcpy(owner, rhs.getOwner());
	}
	return *this;
}

House::~House()
{
	delete[] owner;
}

unsigned int House::getRooms() const
{
	return rooms;
}

const char * House::getOwner() const
{
	return owner;
}

void House::setRooms(const unsigned int &r)
{
	rooms = r;
}

void House::setOwner(const char *o)
{
	owner = new char[strlen(o) + 1];
	strcpy(owner, o);
}

bool House::operator<(const House &rhs)
{
	return getRooms() < rhs.getRooms();
}

std::ostream & operator<<(std::ostream & os, const House & rhs)
{
	os << (Building&)rhs;
	return os << "Rooms: " << rhs.getRooms() << "\nOwner: " << rhs.getOwner() << "\n\n";
}
