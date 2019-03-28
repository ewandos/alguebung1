/*
 * Beinhaltet die Hashtabelle in welcher Pointer fuer
 * alle Aktien gespeichert werden. Das einzigartige
 * Symbol jeder Aktie soll bestimmen, wo die Aktie
 * abgespeichert wird.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 20

#include "Stock.h"
#include <string>
#include <iostream>

class Hashtable
{
private:
	// array holding pointers to class 'Stocks'
	Stock* table[TABLE_SIZE];
    
    int hash(int, int);
    int add(int, int);
    int symToID(std::string&);
    int search(int, int);
    bool isFree(int&);
    
public:
	Hashtable();
	~Hashtable();
    bool debug;
    
    void addStock();
    void deleteStock();
    void importStockday();
    void searchStock();
    void plotStock();
    void save();
    void load();
};

#endif
