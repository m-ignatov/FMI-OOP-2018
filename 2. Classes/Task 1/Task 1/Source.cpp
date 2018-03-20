#include <iostream>
#include "BankAccount.h"

int main()
{
	BankAccount dummyAccount;
	BankAccount bankAccountJS("John Smith", "BG80BNBG96611020345678", 1000.);

	dummyAccount.getInfo();

	bankAccountJS.getInfo();
	bankAccountJS.Widthdraw(14.32);
	bankAccountJS.Deposit(300);
}