#include "Stock.h"

Stock::Stock()
{
    stockdaysCount = 0;
    
    // Init the Stockdays
    for (int i = 0; i < 30; i++)
    {
        this->stockdays[i].isFilled = false;
    }
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
                this->stockdays[stockdaysCount].isFilled = true;
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

void Stock::plotStockdays()
{
    // Take Stockdays Array
    // Plot all available Stockdays
    // If not enough days -> Error Message
}

void Stock::printStockday()
{
    if (this->stockdays[0].isFilled)
    {
        // PRINT DATA
        std::cout << "Datum: " << stockdays[0].date[0] << "-";
        std::cout << stockdays[0].date[1] << "-";
        std::cout << stockdays[0].date[2] << std::endl;
        
        std::cout << "Open: " << stockdays[0].open << std::endl;
        std::cout << "High: " << stockdays[0].high << std::endl;
        std::cout << "Low: " << stockdays[0].low << std::endl;
        std::cout << "Close: " << stockdays[0].close << std::endl;
        std::cout << "Volumen: " << stockdays[0].volume << std::endl;
        std::cout << "Adj Close: " << stockdays[0].adj << std::endl;
    }
    
    else
    {
        std::cout << "Keine aktuellen Kursdaten gefunden!" << std::endl;
    }
}






