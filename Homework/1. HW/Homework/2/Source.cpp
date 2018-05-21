#include <iostream>
#include "Store.h"

Store myStore;

void menu()
{
	char c;
	bool flag = false;

	while (!flag)
	{
		system("cls");
		std::cout << "A Add new product\nX Delete product\nC Change product\nD Display products\nQ Quit\n";
		std::cin.get(c);
		system("cls");

		switch (c)
		{
		case'A': case 'a':
			myStore.add();
			break;
		case'X': case 'x':
			myStore.remove();
			break;
		case'C': case 'c':
			myStore.modify();
			break;
		case'D': case 'd':
			myStore.print();
			break;
		case 'Q': case 'q':
			flag = true;
			break;
		default:
			break;
		}
	}
}

int main()
{
	menu();
}
