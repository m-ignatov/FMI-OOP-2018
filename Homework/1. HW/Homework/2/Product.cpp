#include "Product.h"
#include <fstream>
#include <iostream>

Product::Product() : SKU("N/A"), brand("N/A"), model("N/A"), price(0.), count(0) {}

void Product::modify()
{
	std::cout << "What would you like to modify?\n";
	std::cout << "1.SKU\n2.Brand\n3.Model\n4.Price\n5.Availability\n";
	char c;
	std::cin.get(c);

	switch (c)
	{
	case '1':
		std::cin >> SKU;
		break;
	case '2':
		std::cin.get();
		std::cin.getline(brand, MAX_SIZE);
		break;
	case '3':
		std::cin.get();
		std::cin.getline(model, MAX_SIZE);
		break;
	case '4':
		std::cin >> price;
		break;
	case '5':
		std::cin >> count;
		break;
	default:
		std::cout << "Error" << std::endl;
		break;
	}
}

void Product::strcpy(char *dest, const char *orig)
{
	int i = 0;
	while ((dest[i] = orig[i++]) != '\0');
	dest[i] = '\0';
}

void Product::print() const
{
	std::cout << "SKU: " << SKU << std::endl;
	std::cout << "Product: " << brand << " " << model << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Availability: " << count << std::endl;
}

void Product::input()
{
	std::cout << "SKU:";
	std::cin >> SKU; std::cin.get();
	std::cout << "Brand:";
	std::cin.getline(brand, MAX_SIZE);
	std::cout << "Model:";
	std::cin.getline(model, MAX_SIZE);
	std::cout << "Price:";
	std::cin >> price;
	std::cout << "Availability:";
	std::cin >> count;
}

const char* Product::getSKU() const
{
	return SKU;
}

const char * Product::getBrand() const
{
	return brand;
}

const char * Product::getModel() const
{
	return model;
}

const double & Product::getPrice() const
{
	return price;
}

const int & Product::getCount() const
{
	return count;
}

void Product::setSKU(const char* sku)
{
	strcpy(SKU, sku);
}

void Product::setBrand(const char *_brand)
{
	strcpy(brand, _brand);
}

void Product::setModel(const char *_model)
{
	strcpy(model, _model);
}

void Product::setPrice(const double &_price)
{
	price = _price;
}

void Product::setCount(const int &cnt)
{
	count = cnt;
}
