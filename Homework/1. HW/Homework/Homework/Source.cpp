#include <iostream>
#include "Stack.h"

const char oper[] = "+-*/%";
const int MAX_SIZE = 101;

bool find(const char c, const char* oper)
{
	for (size_t i = 0; oper[i] != '\0'; i++)
	{
		if (c == oper[i]) return true;
	}
	return false;
}

int calculate(const char* opz)
{
	Stack stnum;

	for (int i = 0; opz[i]; i++)
	{
		if (isdigit(opz[i]) || (isdigit(opz[i + 1]) && opz[i] == '-'))
		{
			int sign = 1;
			if (opz[i] == '-')
			{
				sign = -1;
				i++;
			}

			int a = 0;
			while (isdigit(opz[i]))
			{
				a = a * 10 + opz[i] - '0';
				i++;
			}

			stnum.push(a*sign);
		}
		else if (find(opz[i], oper))
		{
			int a2 = stnum.top(); stnum.pop();
			int a1 = stnum.top(); stnum.pop();

			switch (opz[i])
			{
			case '+': stnum.push(a1 + a2); break;
			case '-': stnum.push(a1 - a2); break;
			case '*': stnum.push(a1*a2); break;
			case '%': stnum.push(a1%a2); break;
			case '/': if (a1) stnum.push(a1 / a2);
					  else std::cout << "Error - divide by Zero!";
					  break;
			}
		}
	}
	if (stnum.getSize() == 1) return stnum.top();
}

int main()
{
	char c[MAX_SIZE];
	std::cin.getline(c, MAX_SIZE);
	std::cout << calculate(c) << std::endl;
}