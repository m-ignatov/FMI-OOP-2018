#include "String.h"
#include <cassert>

String::String() : size(0)
{
	data = new char[1];
	*data = '\0';
}

String::String(const char *str)
{
	setString(str);
}

String::String(const String &rhs)
{
	setString(rhs.getString());
}

String & String::operator=(const String &rhs)
{
	if (this != &rhs)
	{
		delete[] data;
		setString(rhs.getString());
	}
	return *this;
}

String::~String()
{
	delete[] data;
}

char String::operator[](const int& id) const
{
	const char* c = getString();
	assert(id >= 0 && id < strlen(c) && "Error! Out of bounds\n");
	return c[id];
}

String String::operator+(const String&rhs)
{
	String newString;
	size_t i = 0;
	newString.setSize(getSize() + rhs.getSize());
	char * tString = new char[newString.getSize() + 1];

	for (i; i < getSize(); i++)
	{
		tString[i] = data[i];
	}
	for (i; i < newString.getSize(); i++)
	{
		tString[i] = rhs.getString()[i - getSize()];
	}
	tString[i] = '\0';
	newString.setString(tString);
	return newString;
}

bool String::operator==(const String &rhs) const
{
	const char* c1 = rhs.getString();
	const char* c2 = getString();
	bool flag = 0;

	for (size_t i = 0; i <= size; i++)
	{
		if (c1[i] != c2[i])
		{
			flag = 1;
			break;
		}
	}
	return !flag;
}

bool String::operator!=(const String &rhs) const
{
	return !(*this == rhs);
}

const char * String::getString() const
{
	return data;
}

void String::setSize(const size_t &_size)
{
	size = _size;
}

size_t String::getSize() const
{
	return size;
}

void String::setString(const char *str)
{
	size = strlen(str);
	data = new char[size + 1];
	strcpy(data, str);
}

bool String::empty() const
{
	return !size;
}

size_t String::strlen(const char *str) const
{
	size_t size = -1;
	for (size; str[++size] != '\0';);
	return size;
}

void String::strcpy(char *lhs, const char *rhs)
{
	size_t i;
	for (i = 0; rhs[i] != '\0'; i++)
	{
		if (lhs[i] == '\0')
		{
			std::cout << "Error copying string\n";
			break;
		}
		lhs[i] = rhs[i];
	}
	lhs[i] = '\0';
}

std::istream & operator>>(std::istream &is, String &rhs)
{
	const int size = 4096;
	char dataT[size];
	is.getline(dataT, size, '\n');
	rhs.setString(dataT);
	return is;
}

std::ostream & operator<<(std::ostream &os, const String &rhs)
{
	return os << rhs.getString() << '\n';
}
