#pragma once

const int MAX_SIZE = 256;

enum date
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

struct HistoryEntry
{
	date month;
	char url[MAX_SIZE];

	HistoryEntry() : month(), url("") {};
};