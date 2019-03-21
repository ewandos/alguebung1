#include "Hashtable.h"

/*
 * =================
 * CONSTRUCTOR & DESTRUCTOR
 * =================
 */

Hashtable::Hashtable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        this->table[i] = NULL;
    }
}

Hashtable::~Hashtable()
{
}

int Hashtable::hash(int &stockID, int steps = 0)
{
    int index = stockID % TABLE_SIZE;
    std::cout << "Geprüfter Index: " << index << std::endl; //DEBUG
    
    //Abbruchbedingungen falls Tabelle voll ist
    if (steps < TABLE_SIZE)
    {
        // Kollisionsbehandlung (Rekursiv)
        if (isFree(index)) // wenn nicht besetzt ist
        {
            return index;
        }
        else // ansonsten
        {
            index = hash(++index, ++steps); // soll der Index für die nächsthöhere Position geprüft werden (Lineare Kollision)
        }
    }
    else
    {
        return TABLE_SIZE + 69; // Ungültigen Wert zurückgeben für Error-Handling
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
    
    index = hash(newStock->number); // set ArrayIndex based on ID, liefert TABLE_SIZE++ zurück wenn Tabelle voll ist
    
    // Wenn Alle Plätze belegt sind
    if (index > TABLE_SIZE)
    {
        std::cout << "Table is full. Please delete one Stock and try again!" << std::endl;
    }
    else
    {
        this->table[index] = newStock; // adding Stock into Hashtable at calculated ArrayIndex
    }
}

void Hashtable::deleteStock()
{
    std::string sym = inputSymbol();
}

void Hashtable::importStockday()
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



