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
		std::cout << "Erfolgreich importiert!" << std::endl;
    }
    else
    {
        std::cout << "Fehler: Datei liegt nicht im selben Verzeichnis \noder Dateiname entspricht nicht dem Kuerzel." << std::endl;
    }
}

void Stock::plotStockdays()
{
	int i;
	double min, max;
	
	// überprüfen, ob mindestens 7 Tage an Daten enthalten sind
	for (i = 0; i < 7; i++) {
		if (stockdays[i].isFilled == false) {
			std::cout << "Wird nicht geplottet, nicht genügend Daten" << std::endl;
			return;
		}
	}

	// Minimum und Maximum-Wert errechnen
	i = 0;
	min = stockdays[0].close;
	max = stockdays[0].close;
	while (stockdays[i].isFilled) {

		if (stockdays[i].close < min) {
			min = stockdays[i].close;
		}
		if (stockdays[i].close > max) {
			max = stockdays[i].close;
		}

		i++;
	}

	// Skalierungsfaktor berechnen und in for Schleife zum plotten verwenden
	float scale = (max - min) / 30;
	i = 0;
	while (stockdays[i].isFilled) {
		std::cout << stockdays[i].date[0] << "-"; 
		if (stockdays[i].date[1] < 10) { std::cout << "0"; }
		std::cout << stockdays[i].date[1] << "-";
		if (stockdays[i].date[2] < 10) { std::cout << "0"; }
		std::cout << stockdays[i].date[2] << " |";
		for (int j = 0; j < ((stockdays[i].close - min) / scale) + ((max - min) / scale * 0.25); j++) {
			std::cout << "#";
		}
		std::cout << "  " << stockdays[i].close << std::endl;

		i++;
	}

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






