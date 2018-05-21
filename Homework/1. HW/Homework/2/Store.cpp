#include "Store.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

bool cmp(const char*, const char*);

Store::Store() : size(0), limit(1)
{
	list = new Product();
}

Store::Store(const int &N) : size(0), limit(N)
{
	list = new Product[N];
}

Store::Store(const Store &rhs)
{
	size = rhs.size;
	for (size_t i = 0; i < size; i++)
	{
		list[i] = rhs.list[i];
	}
}

Store::~Store()
{
	delete[] list;
}

void Store::add()
{
	if (size >= limit) resize();
	Product pr;
	pr.input();
	list[size++] = pr;
}

void Store::remove()
{
	char c[MAX_SIZE];
	std::cin.get();
	std::cout << "Enter product SKU to delete: ";
	std::cin.getline(c, MAX_SIZE);

	for (size_t i = 0; i < size; i++)
	{
		if (cmp(list[i].getSKU(), c))
		{
			list[i] = list[size - 1];
			break;
		}
	}
	if (size) size--;
	system("pause");
}

void Store::modify()
{
	char c[MAX_SIZE];
	std::cin.get();
	std::cout << "Enter product SKU to modify: ";
	std::cin.getline(c, MAX_SIZE);

	for (size_t i = 0; i < size; i++)
	{
		if (cmp(list[i].getSKU(), c))
		{
			system("cls");
			list[i].print();
			list[i].modify();
			break;
		}
	}

	system("pause");
}

void Store::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		list[i].print();
		std::cout << '\n';
	}

	system("pause");
}

void Store::resize()
{
	limit = limit * 2;
	Product *d_arr = new Product[limit];

	for (size_t i = 0; i < size; i++)
	{
		d_arr[i] = list[i];
	}

	delete[] list;
	list = d_arr;
}

bool cmp(const char* lhs, const char* rhs)
{
	for (size_t i = 0; lhs[i] != '\0'; i++)
	{
		if (rhs[i] == '\0' || lhs[i] != rhs[i]) return false;
	}
	return true;
}