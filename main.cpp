#include "Hashtable.h"
#include <iostream>

int main()
{
    Hashtable hash;
	int input;
    
	while (true)
    {
		std::cout << "Aktion waehlen\n"
			"1: Aktie hinzufuegen\n"
			"2: Aktie loeschen\n"
			"3: Aktien importieren\n"
			"4: Aktienkurs suchen\n"
			"5: Graphik anzeigen\n"
			"6: Speichern\n"
			"7: Laden\n"
			"8: Beenden" << std::endl;

		std::cin >> input;

		switch (input)
        {
            case 1:
                // Eine Aktie mit Namen, WKN und Kürzel wird hinzugefügt
                hash.addStock();
                break;
            case 2:
                // Aktie wird gelöscht
                hash.deleteStock();
                break;
            case 3:
                // Kurswerte für eine Aktie werden aus einer csv Datei importiert
                hash.importStockday();
                break;
            case 4:
                // Eine Aktie wird in der Hashtabelle gesucht
                // (Eingabe von Namen oder Kürzel) und der
                // aktuellste Kurseintrag wird ausgegeben.
                hash.searchStock();
                break;
            case 5:
                // Die Schlusskurse der letzten 30 Tage einer Aktie werden als ASCII
                // Grafik ausgegeben, Format ist frei wählbar.
                hash.plotStock();
                break;
            case 6:
                // Programm speichert die Hashtabelle in eine Datei ab
                hash.save();
                break;
            case 7:
                // Programm lädt die Hashtabelle aus einer Datei
                hash.load();
            case 8:
                // Programm wird beendet
                return 0;
            default:
                // Ask User to Enter valid input
                std::cout << "Please enter a valid option: ";
                break;
		}
	}

	return 0;
}
