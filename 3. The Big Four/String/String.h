#pragma once
#include <iostream>

class String
{
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	char operator[](const int&) const;
	String operator+(const String&);

	bool operator==(const String&) const;
	bool operator!=(const String&) const;

	size_t getSize() const;
	const char* getString() const;
	void setString(const char*);

private:
	char* data;
	size_t size;

	bool empty() const;
	void setSize(const size_t&);
	size_t strlen(const char*) const;
	void strcpy(char*, const char*);
};

std::istream& operator>>(std::istream&, String&);
std::ostream& operator<<(std::ostream&, const String&);