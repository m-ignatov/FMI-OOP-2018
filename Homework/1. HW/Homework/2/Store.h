#pragma once
#include "Product.h"

class Store
{
private:
	Product * list;
	int size;
	int limit;
	void resize();

public:
	Store();
	Store(const int&);
	Store(const Store&);
	~Store();

	void add();
	void remove();
	void modify();
	void print() const;
};