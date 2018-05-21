#include <iostream>
#include "BrowserHistory.h"

int main()
{
	BrowserHistory bh(10), bh1(5);
	bh.addNewEntry();

	for (size_t i = 0; i < 5; i++)
	{
		bh1.addNewEntry();
	}

	BrowserHistory newBh = bh.concat(bh1);
	newBh.print();
	newBh.mostVisitedMonth();
	newBh.printNumOfSitesByMonth(4);
	newBh.removeRecentEntry();
	newBh.print();
}