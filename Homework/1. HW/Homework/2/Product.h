#pragma once
const int MAX_SIZE = 256;

class Product
{
private:
	char SKU[MAX_SIZE];
	char brand[MAX_SIZE];
	char model[MAX_SIZE];
	double price;
	int count;

public:
	Product();

	void modify();
	void strcpy(char*, const char*);
	void print() const;
	void input();

	const char* getSKU() const;
	const char* getBrand() const;
	const char* getModel() const;
	const double& getPrice() const;
	const int& getCount() const;
	void setSKU(const char*);
	void setBrand(const char*);
	void setModel(const char*);
	void setPrice(const double&);
	void setCount(const int&);
};