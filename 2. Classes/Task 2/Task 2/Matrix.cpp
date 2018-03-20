#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < N; j++) matrix[i][j] = 0;
}

void Matrix::input()
{
	std::cout << "Input matrix with size " << N << ":" << std::endl;

	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < N; j++) std::cin >> matrix[i][j];
}

const void Matrix::output()
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

Matrix Matrix::scalarMult(const int & num)
{
	Matrix m;

	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < N; j++)
			m.matrix[i][j] = num * matrix[i][j];

	return m;
}

Matrix Matrix::transpose()
{
	Matrix m;

	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < N; j++)
			m.matrix[i][j] = matrix[j][i];

	return m;
}

Matrix Matrix::Multiplication(const Matrix & M2)
{
	Matrix m;

	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < N; j++)
			for (size_t k = 0; k < N; k++)
				m.matrix[i][j] += matrix[i][k] * M2.matrix[k][j];

	return m;
}
