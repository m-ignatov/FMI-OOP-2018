#include <iostream>
#include "BrowserHistory.h"

void string_copy(char orig[], char dest[])
{
	size_t i = 0;
	while ((dest[i] = orig[i++]) != '\0');
	dest[i] = '\0';
}


const char* printDate(const date& month)
{
	switch (month)
	{
	case January: return "January";
	case February: return "February";
	case March: return "March";
	case April: return "April";
	case May: return "May";
	case June: return "June";
	case July: return "July";
	case August: return "August";
	case September: return "September";
	case October: return "October";
	case November: return "November";
	case December: return "December";
	default: return "Invalid input!";
	}
}

BrowserHistory::BrowserHistory() : size(0), limit(1)
{
	entries = new HistoryEntry();
}

BrowserHistory::BrowserHistory(const BrowserHistory &rhs)
{
	size = rhs.size;
	limit = rhs.limit;
	entries = new HistoryEntry[size];

	for (size_t i = 0; i < size; i++)
	{
		entries[i] = rhs.entries[i];
	}
}

BrowserHistory::BrowserHistory(const int & N) : size(0), limit(N)
{
	entries = new HistoryEntry[N];
}

BrowserHistory::~BrowserHistory()
{
	delete[] entries;
}

void BrowserHistory::addNewEntry()
{
	if (size >= limit) std::cout << "Error! Limit reached." << std::endl;
	else
	{
		short m;
		char url[MAX_SIZE];
		std::cin >> m;
		std::cin.get();
		std::cin.getline(url, MAX_SIZE);

		entries[size].month = (date)m;
		string_copy(url, entries[size].url);
		size++;
	}
}

void BrowserHistory::addNewEntry(const HistoryEntry &rhs)
{
	if (size >= limit) std::cout << "Error! Limit reached." << std::endl;
	else
	{
		entries[size++] = rhs;
	}
}

void BrowserHistory::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << printDate(entries[i].month) << ", " << "URL: " << entries[i].url << std::endl;
	}
}

void BrowserHistory::printNumOfSitesByMonth(const short &m) const
{
	int br = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (entries[i].month != m) continue;
		br++;
	}

	std::cout << br << " website(s) in " << printDate((date)m) << std::endl;
}

void BrowserHistory::mostVisitedMonth() const
{
	if (!size) return;

	short max_month[13], max = -1, max_ind = 0;

	for (size_t i = 0; i < 13; i++)
	{
		max_month[i] = 0;
	}

	for (size_t i = 0; i < size; i++)
	{
		max_month[entries[i].month]++;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (max_month[i] > max)
		{
			max = max_month[i];
			max_ind = i;
		}
	}

	std::cout << "Most active month: " << printDate((date)max_ind) << std::endl;
}

void BrowserHistory::removeRecentEntry()
{
	if (size) size--;
}

BrowserHistory BrowserHistory::concat(const BrowserHistory &rhs)
{
	BrowserHistory tmp(limit + rhs.limit);

	for (size_t i = 0; i < size; i++)
	{
		tmp.entries[i] = entries[i];
		tmp.size++;
	}
	for (size_t i = 0; i < rhs.size; i++)
	{
		tmp.entries[tmp.size++] = rhs.entries[i];
	}
	return tmp;
}