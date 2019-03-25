#include <cmath>
#include "Hashtable.h"

/*
 * =================
 * CONSTRUCTOR & DESTRUCTOR
 * =================
 */

Hashtable::Hashtable()
{
    // DEBUG INFORMATION! : Im Code sind Outputs für Debug-Zwecke, welche nur bei true ausgegeben werden
    this->debug = false;
    
    // Init the Hashtable
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        this->table[i] = NULL;
    }
}

Hashtable::~Hashtable()
{
}

/*
 * =================
 * PRIVATE METHODS
 * =================
 */

int Hashtable::hash(int index, int steps = 0) {
    /*
     * index = ArrayIndex oder StockID
     * steps = wie oft die Hashfunktion in der Prozedur aufgerufen wurde (für Abbruchbedingungen)
     * sondierung = rechnet Summant für Index um zum nächsten Index zu springen
     */
    
    double sondierung = pow(2, (double)steps);
    return (index + (int)sondierung + steps) % TABLE_SIZE;
}

int Hashtable::add(int stockID, int steps = 0)
{
    int index = hash(stockID, steps);
    if(this->debug){std::cout << "Errechneter Index: " << index << " (" << stockID << ")" << std::endl;} //DEBUG
    
    // Abbruchbedingungen falls Tabelle voll ist
    if (steps < TABLE_SIZE)
    {
        // Kollisionsbehandlung (Rekursiv)
        if (isFree(index)) // wenn nicht besetzt ist
        {
            return index;
        }
        else // ansonsten
        {
            index = add(stockID, ++steps); // soll nächster Index geprüft werden (Quadratische Sondierung in Hash-Funktion)!
        }
    }
    else
    {
        std::cout << "Table is full. Please delete one Stock and try again!" << std::endl;
        return TABLE_SIZE + 69; // Ungültigen Wert (Wert welcher größer ist als das Array) zurückgeben für Error-Handling
    }
    
    return index;
}

int Hashtable::search(int stockID, int steps = 0)
{
    int index = hash(stockID, steps);
    if(this->debug){std::cout << "Errechneter Index: " << index << " (" << stockID << ")" << std::endl;} // <- DEBUG
    
    if (steps < TABLE_SIZE)
    {
        if (isFree(index))
        {
            index = search(stockID, ++steps);
        }
        else if (this->table[index]->number == stockID)
        {
            if(this->debug){std::cout << this->table[index]->number << " ? " << stockID << " (true)" << std::endl;} //DEBUG
            return index;
        }
        else
        {
            if(this->debug){std::cout << this->table[index]->number << " ? " << stockID << " (false)" << std::endl;} //DEBUG
            index = search(++stockID, ++steps);
        }
    }
    else
    {
        std::cout << "Nicht gefunden!" << std::endl;
        return TABLE_SIZE + 69; // Ungültigen Wert zurückgeben für Error-Handling
    }
    
    return index;
}

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
    
    if(this->debug){std::cout << "Index " << i;} //DEBUG
    
    if (this->table[i] == NULL)
    {
        if(this->debug){std::cout << " ist frei!" << std::endl;} //DEBUG
        return true;
    }
    else
    {
        if(this->debug){std::cout << " ist besetzt!" << std::endl;} //DEBUG
        return false;
    }
}

std::string inputSymbol()
{
    std::string sym; // string for Stock-Symbol
    
    /* Getting the Symbol */
    std::cout << "Kuerzel eingeben: ";
    std::cin >> sym;
    
    // TODO: Validierung!
    
    return sym;
}

std::string inputWKN()
{
    std::string wkn; // string for Stock-WKN
    
    /* Getting the WKN */
    std::cout << "WKN eingeben: ";
    std::cin >> wkn;
    
    // TODO: Validierung!
    
    return wkn;
}

std::string inputName()
{
    std::string name; // string for Stock-Name
    
    /* Getting the Name */
    std::cout << "Name eingeben: ";
    std::cin >> name;
    
    // TODO: Validierung!
    
    return name;
}

/*
 * =================
 * PUBLIC METHODS
 * =================
 */

void Hashtable::addStock()
{
    // Get Stock Information from User
    //std::string name = inputName();
    //std::string wkn = inputWKN();
    std::string sym = inputSymbol();
    
    /* Put the Stock in Hashtable */
    Stock* newStock = new Stock;    // defining pointer
    //newStock->wkn = wkn;
    //newStock->name = name;
    
    newStock->symbol = sym;     // set symbol of new stock
    newStock->number = symToID(sym);    // set ID based on Symbol

    
    int index = add(newStock->number); // get ArrayIndex based on ID, liefert TABLE_SIZE++ zurück wenn Tabelle voll ist
    
    // Wenn Alle Plätze belegt sind
    if (index < TABLE_SIZE)
    {
        if(this->debug){std::cout << "Eingesetzt am Index " << index << std::endl;} //DEBUG
        std::cout << "Aktie erfolgreich hinzugefügt!" << std::endl;
        this->table[index] = newStock; // adding Stock into Hashtable at calculated ArrayIndex
    }
}

void Hashtable::deleteStock()
{
    std::string sym = inputSymbol(); // Get Searched Symbol
    int id = symToID(sym); // Get searched ID
    int index = search(id);
    
    if(index < TABLE_SIZE)
    {
        if(this->debug){std::cout << "Gelöscht am Index: " << index << std::endl;} //DEBUG
        std::cout << "Aktie gelöscht!" << std::endl;
        delete this->table[index];
        this->table[index] = NULL;
    }
}

void Hashtable::importStockday()
{
    
}

void Hashtable::searchStock()
{
    std::string sym = inputSymbol(); // Get Searched Symbol
    int id = symToID(sym); // Get searched ID
    int index = search(id);
    
    if(index < TABLE_SIZE)
    {
        if(this->debug){std::cout << "Gefunden am Index: " << index << std::endl;} //DEBUG
        std::cout << "Aktie gefunden!" << std::endl;
        
        // TODO: Ausgabe von aktuellstem STOCKDAY , Ausgabe von ID ist nur zu Testzwecken!
        std::cout << "StockID: " << this->table[index]->number << std::endl;
    }
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




