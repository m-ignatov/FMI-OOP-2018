#include <iostream>
#include "Matrix.h"

int main()
{
	Matrix m, m1;
	m.input();
	m1.input();

	Matrix res = m.Multiplication(m1);
	std::cout << "Matrix M * M1" << std::endl;
	res.output();
	std::cout << std::endl;

	const int num = 3;
	std::cout << "Matrix M multiplied by " << num << std::endl;
	m.scalarMult(num).output();
	std::cout << std::endl;

	std::cout << "Matrix transpose" << std::endl;
	res.transpose().output();
	std::cout << std::endl;
}