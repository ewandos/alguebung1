#include "Stock.h"

Stock::Stock()
{
    stockdaysCount = 0;
}

Stock::~Stock()
{

}

void Stock::inputCSV(std::string &path) {
    // Open Filestream
    // Separate different Lines from eachother
    // using the "inputData()" Method of Stockday for each line
    // Close Filestream
    
    int lineCount = 0;
    std::string line;
    std::ifstream file (path);
    this->stockdaysCount = 0;
    
    if (file.is_open())
    {
        while (getline (file,line))
        {
            if (lineCount > 0) // Erste Zeile überspringen
            {
                // Füllt linear das Array auf und speichert die Größe.
                this->stockdays[stockdaysCount].inputData(line);
                this->stockdaysCount++;
            }
            lineCount++;
        }
        file.close();
    }
    else
    {
        std::cout << "Fehler: Datei liegt nicht im selben Verzeichnis \noder Dateiname entspricht nicht dem Kuerzel." << std::endl;
    }
}




