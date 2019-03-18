/*
 * Beinhaltet die Klasse STOCK (=Aktie), welche durch
 * die einzigartige Bezeichung SYMBOL identifiziert wird.
 * STOCK importiert die Klasse STOCKDAY, welche die Daten
 * für eines Tages beinhaltet.
 */

#ifndef STOCK_H
#define STOCK_H

#include <iostream>

class Stock
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
	Stock();
	~Stock();

	// public string to identify object 
	std::string symbol;
};

#endif
