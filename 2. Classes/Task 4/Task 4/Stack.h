#pragma once

const int N = 100;

class Stack
{
private:
	int data[N];
	int size;

public:
	Stack();
	
	void push(const int& a);
	void pop();
	const int top() const;
	const bool isEmpty() const;
};