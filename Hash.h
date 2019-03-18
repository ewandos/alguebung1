#ifndef HASH_H
#define HASH_H

#include "Stock.h"
#include <string>
#include <iostream>

class Hashtable
{
private:
	// array holding pointers to class 'Stocks'
	Stock* table[1000];
    
    // hash function for calculating index
    int hash(std::string&);
    
public:
	Hashtable();
	~Hashtable();

    void addStock();
};

#endif
