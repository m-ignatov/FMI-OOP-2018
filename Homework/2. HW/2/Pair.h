#pragma once

template<typename T>
class Pair
{
private:
	char* key;
	T value;

	void setKey(const char* key)
	{
		this->key = new char[strlen(key) + 1];
		strcpy(this->key, key);
	}

public:
	Pair();
	Pair(const Pair<T>&);
	Pair(const char*, const T&);
	Pair<T>& operator=(const Pair<T>&);
	~Pair();

	const char* getKey() const
	{
		return key;
	}
	const T& getValue() const
	{
		return value;
	}
	void setValue(const T& val)
	{
		value = val;
	}
};

template<typename T>
Pair<T>::Pair() : value(T())
{
	key = new char{ '\0' };
}

template<typename T>
Pair<T>::Pair(const Pair<T>& rhs)
{
	setKey(rhs.key);
	setValue(rhs.value);
}

template<typename T>
Pair<T>::Pair(const char * key, const T & value)
{
	setKey(key);
	setValue(value);
}

template<typename T>
Pair<T> & Pair<T>::operator=(const Pair<T> & rhs)
{
	if (this != &rhs)
	{
		delete[] key;
		setKey(rhs.key);
		setValue(rhs.value);
	}
	return *this;
}

template<typename T>
Pair<T>::~Pair()
{
	delete[] key;
}