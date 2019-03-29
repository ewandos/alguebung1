/*
 * Beinhaltet die Klasse STOCK (=Aktie), welche durch
 * die einzigartige Bezeichung SYMBOL identifiziert wird.
 * STOCK importiert die Klasse STOCKDAY, welche die Daten
 * fuer eines Tages beinhaltet.
 */

#ifndef STOCK_H
#define STOCK_H

#include "Stockday.h"
#include <iostream>
#include <fstream>
#include <string>

class Stock
{
private:
    // Struct Data are now Classes called STOCKDAY
    Stockday stockdays[30];
    int stockdaysCount;
	int getAsciiByOs();
	
public:
	Stock();
	~Stock();

	// public attributes to identify object
	std::string symbol;
    std::string name;
    std::string wkn;
    double symID;

    void inputCSV(std::string&);
    void plotStockdays();
    void printStockday();
};

#endif
