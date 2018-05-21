#pragma once
#include "HistoryEntry.h"

class BrowserHistory
{
private:
	HistoryEntry * entries;
	int size;
	int limit;

public:
	BrowserHistory(const int& _N);
	BrowserHistory();
	BrowserHistory(const BrowserHistory&);
	~BrowserHistory();

	void addNewEntry();
	void addNewEntry(const HistoryEntry&);
	void print() const;
	void printNumOfSitesByMonth(const short&) const;
	void mostVisitedMonth() const;
	void removeRecentEntry();
	BrowserHistory concat(const BrowserHistory&);
};