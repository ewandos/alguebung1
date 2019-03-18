#include <string>

#ifndef STOCKS_H
#define STOCKS_H

class Stocks
{
private:
	// struct holding each of the 30 entries' stock data
	struct stockData
    {
		// testing with only one element
		double high;
	};

	// array of type struct stockData
	struct stockData entries[30];
	
public:
	Stocks();
	~Stocks();

	// public string to identify object 
	std::string symbol;

	void add_stock();
};

#endif
