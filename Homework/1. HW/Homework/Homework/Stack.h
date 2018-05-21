#pragma once

class Stack
{
private:
	int size;
	int limit;
	int* data;
	void resize();

public:
	Stack();
	Stack(const int&);
	~Stack();

	void push(const int&);
	void pop();
	bool isEmpty() const;
	const int& getSize() const;
	const int& top() const;
};