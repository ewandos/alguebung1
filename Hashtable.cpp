#include <cmath>
#include "Hashtable.h"

/*
 * =================
 * CONSTRUCTOR & DESTRUCTOR
 * =================
 */

Hashtable::Hashtable()
{
    // DEBUG INFORMATION! : Im Code sind Outputs fuer Debug-Zwecke, welche nur bei true ausgegeben werden
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
     * steps = wie oft die Hashfunktion in der Prozedur aufgerufen wurde (fuer Abbruchbedingungen)
     * sondierung = rechnet Summant fuer Index um zum naechsten Index zu springen
     */
    
    double sondierung = pow(2, (double)steps);
    return (index + (int)sondierung + steps) % TABLE_SIZE;
}

int Hashtable::add(int stockID, int steps = 0)
{
    int index = hash(stockID, steps);
    if(this->debug){std::cout << "Errechneter Index: " << index << " (" << stockID << ")" << std::endl;} //DEBUG
    
    // Abbruchbedingungen falls Tabelle voll ist
    if (steps < TABLE_SIZE && !sameID(index, stockID))
    {
        // Kollisionsbehandlung (Rekursiv)
        if (isFree(index)) // wenn Platz frei ist
        {
            return index;
        }
        else
        {
            index = add(stockID, ++steps); // soll naechster Index geprueft werden (Quadratische Sondierung in Hash-Funktion)!
        }
    }
    else if (steps > TABLE_SIZE)
    {
        std::cout << "Tabelle ist voll! Bitte loeschen Sie einen Eintrag." << std::endl;
        return TABLE_SIZE + 69; // Ungueltigen Wert (Wert welcher groeßer ist als das Array) zurueckgeben fuer Error-Handling
    }
    else
    {
        // Wenn Aktie schon existiert.
        std::cout << "Aktie existiert schon!" << std::endl;
        return TABLE_SIZE + 69;
    }
    
    return index;
}

int Hashtable::search(int stockID, int steps = 0)
{
    int index = hash(stockID, steps);
    if(this->debug){std::cout << "Errechneter Index: " << index << " (" << stockID << ")" << std::endl;} // <- DEBUG
    
    // Abbruchbedingungen falls Tabelle voll ist ODER eine Aktie mit selber ID schon existiert.
    if (steps < TABLE_SIZE)
    {
        if (isFree(index)) // wenn Platz frei ist
        {
            index = search(stockID, ++steps);
        }
        else if (this->table[index]->symID == stockID)
        {
            if(this->debug){std::cout << this->table[index]->symID << " ? " << stockID << " (true)" << std::endl;} //DEBUG
            return index;
        }
        else
        {
            if(this->debug){std::cout << this->table[index]->symID << " ? " << stockID << " (false)" << std::endl;} //DEBUG
            index = search(++stockID, ++steps); // soll naechster Index geprueft werden (Quadratische Sondierung in Hash-Funktion)!
        }
    }
    else
    {
        std::cout << "Aktie nicht gefunden!" << std::endl;
        return TABLE_SIZE + 69; // Ungueltigen Wert zurueckgeben fuer Error-Handling
    }
    
    return index;
}

double Hashtable::symToID(std::string &sym)
{
    //calculate and unique ID for any given Stock based on its symbol
    
    std::string temp = "";
    
    for (int i = 0; i < sym.length(); i++)
    {
        int f = (int)sym[i]; // convert every char of the symbol to int
        temp.append(std::to_string(f)); // append every int to another in a new string
    }
    
    double id = std::stod(temp); //cast it to double
    
    return id;
}

bool Hashtable::isFree(int &index)
{
    // Check if there is an Pointer at given Index and return bool-value
    
    if(this->debug){std::cout << "Index " << index;} //DEBUG
    
    if (this->table[index] == NULL)
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

bool Hashtable::sameID(int &index, int &stockID)
{
    // Ueberprueft ob Index Frei ist und wenn er es nicht ist,
    // ob dort schon die Aktie liegt, die wir hinzufügen wollen.
    
    if (!isFree(index))
    {
        if (this->table[index]->symID == stockID || this->table[index]->namID == stockID)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    return false;
}

std::string inputSymbol() // evtl in Classe Stock verlegen
{
    std::string sym;
    
    /* Getting the Symbol */
    std::cout << "Kuerzel der Aktie eingeben: ";
    std::cin >> sym;
    
    // TODO: Validierung!
    
    return sym;
}

std::string inputWKN() // evtl in Classe Stock verlegen
{
    std::string wkn;
    
    /* Getting the WKN */
    std::cout << "WKN eingeben: ";
    std::cin >> wkn;
    
    // TODO: Validierung!
    
    return wkn;
}

std::string inputName() // evtl in Classe Stock verlegen
{
    std::string name;
    
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
    std::string sym = inputSymbol();
    std::string name = inputName();
    std::string wkn = inputWKN();
    
    // Generierung der ID
    double symID = symToID(sym);
    
    /* Put the Stock in Hashtable */
    Stock* newStock = new Stock;    // defining pointer
    
    newStock->symbol = sym;     // set symbol of new stock
    newStock->symID = symID;    // set ID based on Symbol
    
    newStock->name = name;
    newStock->wkn = wkn;
    
    int index = add(newStock->symID); // get ArrayIndex based on ID, liefert TABLE_SIZE++ zurueck wenn Tabelle voll ist
    
    if (index < TABLE_SIZE)
    {
        if(this->debug){std::cout << "Eingesetzt am Index " << index << std::endl;} //DEBUG
        std::cout << "Aktie erfolgreich hinzugefuegt!" << std::endl;
        this->table[index] = newStock; // adding Stock into Hashtable at calculated ArrayIndex
    }
    
    else
    {
        delete newStock;
    }
}

void Hashtable::deleteStock()
{
    std::string sym = inputSymbol(); // Get Searched Symbol
    int id = symToID(sym); // Get searched ID
    int index = search(id);
    
    if(index < TABLE_SIZE)
    {
        if(this->debug){std::cout << "Geloescht am Index: " << index << std::endl;} //DEBUG
        std::cout << "Aktie geloescht!" << std::endl;
        delete this->table[index];
        this->table[index] = NULL;
    }
}

void Hashtable::importStockday()
{
    std::cout << "Bitte die .csv Datei im selben Verzeichnis ablegen." << std::endl;
    std::string sym = inputSymbol(); // Get Searched Symbol
    int id = symToID(sym); // Get searched ID
    int index = search(id);
    
    if(index < TABLE_SIZE)
    {
        // CSV is named equal to Symbol, so we can search instantly
        std::string path = sym.append(".csv");
        this->table[index]->inputCSV(path);
    }
}

void Hashtable::searchStock()
{
    std::string sym = inputSymbol(); // Get Searched Symbol
    int id = symToID(sym); // Get searched ID
    int index = search(id);
    
    if(index < TABLE_SIZE)
    {
        if(this->debug){std::cout << "Gefunden am Index: " << index << std::endl;} //DEBUG
        
        std::cout << "\nNeuste Daten zu " << sym << ":" << std::endl;
        this->table[index]->printStockday();
    }
}

void Hashtable::plotStock()
{
	std::string sym = inputSymbol(); // Get Searched Symbol
	int id = symToID(sym); // Get searched ID
	int index = search(id);

	if (index < TABLE_SIZE)
	{
		if (this->debug) { std::cout << "Gefunden am Index: " << index << std::endl; } //DEBUG

		std::cout << "\nGraphik zu " << sym << ":\n" << std::endl;
		this->table[index]->plotStockdays();
	}
}

void Hashtable::save()
{

}

void Hashtable::load()
{

}
