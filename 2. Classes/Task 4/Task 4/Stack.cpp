#include "Stack.h"

Stack::Stack() : size(0) {}

void Stack::push(const int & a)
{
	data[++size] = a;
}

void Stack::pop()
{
	data[size--] = 0;
}

const int Stack::top() const
{
	return data[size];
}

const bool Stack::isEmpty() const
{
	if (!size) return true;
	return false;
}
