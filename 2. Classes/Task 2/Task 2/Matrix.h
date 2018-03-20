#pragma once

const int N = 3;

class Matrix
{
private:
	float matrix[N][N];

public:
	Matrix();

	void input();
	const void output();
	
	Matrix scalarMult(const int& num);
	Matrix transpose();
	Matrix Multiplication(const Matrix& M2);
};