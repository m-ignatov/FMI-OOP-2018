#pragma once
#include "Pair.h"

template<typename T>
class Settings
{
private:
	Pair<T> * container;
	unsigned int size;
	unsigned int maxSize;
	void resize();
	int find(const char*) const;
	void add(const char* key, const T& value);

public:
	Settings();
	Settings(const Settings<T>&);
	Settings<T>& operator=(const Settings<T>&);
	~Settings();

	unsigned int count() const { return size; }
	void set(const char*, const T&);
	bool get(const char*, T&) const;
};

template<typename T>
Settings<T>::Settings() : size(0), maxSize(1), container(new Pair<T>[1]) {}

template<typename T>
Settings<T>::Settings(const Settings<T> &rhs)
{
	size = rhs.size;
	maxSize = rhs.maxSize;
	container = new Pair<T>[maxSize];

	for (size_t i = 0; i < size; i++)
	{
		container[i] = rhs.container[i];
	}
}

template<typename T>
Settings<T> & Settings<T>::operator=(const Settings<T> & rhs)
{
	if (this != &rhs)
	{
		delete[] container;
		size = rhs.size;
		maxSize = rhs.maxSize;
		container = new Pair<T>[maxSize];

		for (size_t i = 0; i < size; i++)
		{
			container[i] = rhs.container[i];
		}
	}
	return *this;
}

template<typename T>
Settings<T>::~Settings()
{
	delete[] container;
}

template<typename T>
void Settings<T>::set(const char * key, const T& value)
{
	int res = find(key);

	if (res != -1)
	{
		container[res].setValue(value);
		return;
	}
	add(key, value);
}

template<typename T>
void Settings<T>::add(const char* key, const T& value)
{
	if (size + 1 > maxSize) resize();
	container[size++] = Pair<T>(key, value);
}

template<typename T>
bool Settings<T>::get(const char * key, T & value) const
{
	int res = find(key);
	if (res != -1)
	{
		value = container[res].getValue();
		return true;
	}
	return false;
}

template<typename T>
void Settings<T>::resize()
{
	maxSize *= 2;
	Pair<T>* newCon = new Pair<T>[maxSize];

	for (size_t i = 0; i < size; i++)
	{
		newCon[i] = container[i];
	}
	delete[] container;
	container = newCon;
}

template<typename T>
int Settings<T>::find(const char* key) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(key, container[i].getKey())) return i;
	}
	return -1;
}