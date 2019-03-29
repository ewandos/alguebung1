#include <cmath>
#include <sstream>
#include <fstream>
#include <string>
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
        if (this->table[index]->symID == stockID)
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

void Hashtable::addStock(int userOrLoad, std::string* data)
{
	std::string sym;
	std::string name;
	std::string wkn;

	if (userOrLoad == 0) {
		// Get Stock Information from User
		sym = inputSymbol();
		name = inputName();
		wkn = inputWKN();
	}
	else {
		// Get Stock Information from load file (pointer containing sym, name & wkn)
		sym = data[0];
		name = data[1];
		wkn = data[2];
	}
    
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

void Hashtable::save() {
	std::ofstream saveFile;

	saveFile.open("save.csv");

	int i;
	int j;
	Stockday* current;
	// speichere nur gefüllte table slots (duh)
	for (i = 0; i < TABLE_SIZE; i++) {
		if (!isFree(i)) {

			// symbol, name, wkn
			saveFile << "header," << table[i]->symbol << "," << table[i]->name << "," << table[i]->wkn << std::endl;

			// jeder stockday eintrag
			j = 0;
			while (table[i]->stockdays[j].isFilled) {
				current = table[i]->stockdays;

				saveFile << current[j].date[0] << "-" << current[j].date[1] << "-" << current[j].date[2]
					<< "," << current[j].open << "," << current[j].high << ","
					<< current[j].low << "," << current[j].close << "," << current[j].adj << ","
					<< current[j].volume << std::endl;
				j++;
			}
		}
	}

	std::cout << "Speichern erfolgreich!" << std::endl;
	saveFile.close();
}

void Hashtable::load() {
	std::ifstream loadFile("save.csv");
	if (!loadFile.is_open()) {
		std::cout << "Speicherdatei konnte nicht geoeffnet werden. Druecken zum Beenden." << std::endl;
		return;
	}
	else {
		std::cout << "Speicherdatei gefunden.\n" << std::endl;
	}

	// strings related to header info
	std::string headerCheck;
	std::string curSymbol;
	std::string curName;
	std::string curWkn;
	// pointer consisting of symbol, name and wkn
	std::string* headerData = new std::string[3];

	// strings related to stockday info
	std::string date;
	std::string open;
	std::string high;
	std::string low;
	std::string close;
	std::string adj;
	std::string volume;
	// pointer consisting of stockday info
	std::string* stockdayData = new std::string[30];

	// line string for reading csv
	std::string line;

	while (std::getline(loadFile, line)) {

		std::stringstream ss(line);
		std::getline(ss, headerCheck, ',');

		if (headerCheck.compare("header") == 0) {	// check if in header line

			std::cout << "in header Zeile" << std::endl;

			std::getline(ss, curSymbol, ',');
			std::getline(ss, curName, ',');
			std::getline(ss, curWkn, ',');

			// input can happen
			headerData[0] = curSymbol;
			headerData[1] = curName;
			headerData[2] = curWkn;

			add(symToID(curSymbol));
			addStock(1, headerData);
		}
		else {
			std::cout << "Daten von " << curName << std::endl;
			/*
			std::getline(ss, date, ',');
			std::getline(ss, open, ',');
			std::getline(ss, high, ',');
			std::getline(ss, low, ',');
			std::getline(ss, close, ',');
			std::getline(ss, adj, ',');
			std::getline(ss, volume, ',');
			*/
		}
	}

	loadFile.close();
}
