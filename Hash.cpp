#include "Hash.h"

Hashtable::Hashtable()
{
}

Hashtable::~Hashtable()
{
}

int Hashtable::hash(std::string &sym)
{
	// evaluate Arrayindex based on given symbol-string
    return 0;
}

void Hashtable::addStock() {
    std::string sym; // string for Stock-Symbol
    int ind; // Index for Hashtable
    
    /* Getting the Symbol */
    std::cout << "Kuerzel eingeben: ";
    std::cin >> sym;
    
    /* Put the Stock in Hashtable */
    Stock* newStock = new Stock; // defining pointer
    newStock->symbol = sym; // defining symbol of new stock
    ind = hash(sym); // getting Index based on Symbol
    
    this->table[ind] = newStock; // adding Stock into Hashtable at calculated index
}

