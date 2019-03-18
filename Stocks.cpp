#include "Stocks.h"
#include "Hash.h"
#include <iostream>
#include <string>

Stocks::Stocks()
{
}

Stocks::~Stocks()
{
	// free structs
}

void Stocks::add_stock()
{
	Hashtable h;
	std::string input;
	double high = 110.2; // test value

	std::cout << "Kuerzel eingeben: ";
	std::cin >> input;

	/* defining pointer to newly created object of Stocks
	and storing symbol into public string of Stocks */
	Stocks* ptr = new Stocks;
	ptr->symbol = input;

	h.hash(ptr, ptr->symbol);
}

