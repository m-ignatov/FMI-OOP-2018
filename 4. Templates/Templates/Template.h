#pragma once
#include <algorithm>

template<typename T>
T median(T* collection, int size)
{
	int hSize = size / 2;
	T med;

	if (size % 2) med = collection[hSize];
	else med = (collection[hSize] + collection[hSize - 1]) / 2;
	return med;
}

template<typename T>
T mode(T* collection, int size)
{
	std::sort(collection, collection + size);

	int count = 0;
	int countMode = 0;
	T cur = collection[0];
	T mode;

	for (size_t i = 1; i < size; i++)
	{
		while (collection[i++] == cur && i < size) count++;
		if (count > countMode)
		{
			countMode = count;
			mode = cur;
		}
		count = 1;
		cur = collection[i];
	}
	return mode;
}

template<typename T>
T average(T* collection, int size)
{
	T avg = 0;

	for (size_t i = 0; i < size; i++)
	{
		avg += collection[i];
	}
	avg /= size;

	return avg;
}

template<typename T>
T accumulates(T* collection, int size)
{
	T sum = 0;

	for (size_t i = 0; i < size; i++)
	{
		sum += collection[i];
	}
	return sum;
}

template<typename T>
T max(T* collection, int size)
{
	T max = collection[0];

	for (size_t i = 1; i < size; i++)
	{
		if (collection[i] > max) max = collection[i];
	}
	return max;
}

template<typename T>
T min(T* collection, int size)
{
	T min = collection[0];

	for (size_t i = 1; i < size; i++)
	{
		if (collection[i] < min) min = collection[i];
	}
	return min;
}


template<typename T>
T* reverse(T* collection, int size)
{
	T* newCol = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		newCol[i] = collection[size - i - 1];
	}
	return newCol;
}


template<typename T>
T* take(T* collection, int size, int n)
{
	T* newCol = new T[n];

	for (size_t i = 0; i < n; i++)
	{
		newCol[i] = collection[i];
	}
	return newCol;
}


template<typename T>
T* skip(T* collection, int size, int n)
{
	T* newCol = new T[n];

	for (size_t i = n; i < size; i++)
	{
		newCol[i - n] = collection[i];
	}
	return newCol;
}
