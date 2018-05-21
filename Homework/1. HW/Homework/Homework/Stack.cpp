#include "Stack.h"

Stack::Stack() : size(0), limit(1)
{
	data = new int[1];
	data[0] = 0;
}

Stack::Stack(const int &N) : size(0), limit(N)
{
	data = new int[N];
	for (size_t i = 0; i < N; i++)
	{
		data[i] = 0;
	}
}

Stack::~Stack()
{
	delete[] data;
}

void Stack::resize()
{
	limit = limit * 2;
	int *d_arr = new int[limit];

	for (size_t i = 0; i < size; i++)
	{
		d_arr[i] = data[i];
	}

	for (size_t i = size; i < limit; i++)
	{
		d_arr[i] = 0;
	}

	delete[] data;
	data = d_arr;
}

void Stack::push(const int &elem)
{
	if (size + 1 >= limit) resize();
	data[size++] = elem;
}

void Stack::pop()
{
	if (size) data[size--] = 0;
}

bool Stack::isEmpty() const
{
	return !size;
}

const int & Stack::getSize() const
{
	return size;
}

const int & Stack::top() const
{
	if (size) return data[size - 1];
}
