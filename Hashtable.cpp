#include "Hashtable.h"

/*
 * =================
 * CONSTRUCTOR & DESTRUCTOR
 * =================
 */

Hashtable::Hashtable()
{
    for (int i = 0; i < 1000; i++)
    {
        this->table[i] = NULL;
    }
}

Hashtable::~Hashtable()
{
}

int Hashtable::hash(int &stockID)
{
    // TODO: Abbruchbedingung wenn dass die Tabelle voll ist!
    
    int index = stockID % 1000;
    std::cout << "Geprüfter Index: " << index << std::endl; //DEBUG
    
    if (isFree(index)) // wenn nicht besetzt ist
    {
        return index;
    }
    else // ansonsten
    {
        index = hash(++index); // soll der Index für die nächsthöhere Position geprüft werden (Lineare Kollision)
    }
    
    return index;
}

/*
 * =================
 * PRIVATE METHODS
 * =================
 */

int Hashtable::symToID(std::string &sym)
{
    //calculate and unique ID for any given Stock based on its symbol
    
    std::string temp = "";
    
    for (int i = 0; i < sym.length(); i++)
    {
        int f = (int)sym[i]; // convert every char of the symbol to int
        temp.append(std::to_string(f)); // append every int to another in a new string
    }
    
    int index = std::stoi(temp); //cast it to int again
    
    return index;
}

bool Hashtable::isFree(int &i)
{
    // Check if there is an Pointer at given Index and return bool-value
    
    if (this->table[i] == NULL)
    {
        std::cout << "FREI!" << std::endl; //DEBUG
        return  true;
    }
    else
    {
        std::cout << "BESETZT!" << std::endl; //DEBUG
        return false;
    }
}

std::string inputSymbol()
{
    std::string sym; // string for Stock-Symbol
    
    /* Getting the Symbol */
    std::cout << "Kuerzel eingeben: ";
    std::cin >> sym;
    return sym;
}

/*
 * =================
 * PUBLIC METHODS
 * =================
 */

void Hashtable::addStock()
{
    std::string sym = inputSymbol(); // Get Stock-Symbol from User
    int index = 0;
    
    /* Put the Stock in Hashtable */
    Stock* newStock = new Stock;    // defining pointer
    newStock->symbol = sym;     // set symbol of new stock
    newStock->number = symToID(sym);    // set ID based on Symbol
    
    index = hash(newStock->number); // set ArrayIndex based on ID
    
    // TODO: Kollisionsbehandlung
    
    this->table[index] = newStock; // adding Stock into Hashtable at calculated ArrayIndex
    
}

void Hashtable::deleteStock()
{
    // unbedingt danach den Platz auf NULL setzen.
}

void Hashtable::importStock()
{
    
}

void Hashtable::searchStock()
{
    
}

void Hashtable::plotStock()
{

}

void Hashtable::save()
{

}

void Hashtable::load()
{

}



