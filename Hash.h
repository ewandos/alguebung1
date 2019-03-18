#include "Stocks.h"
#include <string>
#include <iostream>

#ifndef HASH_H
#define HASH_H

class Hashtable
{
private:
	// actual array holding pointers to class 'Stocks'
	Stocks* table[1000];
public:
	Hashtable();
	~Hashtable();

	// hash function processing stock symbol to store object pointer
	void hash(Stocks* p, std::string sym);
};

#endif
