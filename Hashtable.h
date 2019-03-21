/*
 * Beinhaltet die Hashtabelle in welcher Pointer für
 * alle Aktien gespeichert werden. Das einzigartige
 * Symbol jeder Aktie soll bestimmen, wo die Aktie
 * abgespeichert wird.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 3

#include "Stock.h"
#include <string>
#include <iostream>

class Hashtable
{
private:
	// array holding pointers to class 'Stocks'
	Stock* table[TABLE_SIZE];
    
public:
	Hashtable();
	~Hashtable();
    
    // hash function for calculating index (PUBLIC FOR TESTING!)
    int hash(int&, int);
    int symToID(std::string&);
    int search(int&);
    bool isFree(int&);

    void addStock();
    void deleteStock();
    void importStockday();
    void searchStock();
    void plotStock();
    void save();
    void load();
};

#endif
