#include "Hashtable.h"
#include <iostream>

int main()
{
    Hashtable hash;
	int input;
    /*
    std::cout << "  _____ _             _      __  __                                   " << std::endl;
    std::cout << " / ____| |           | |    |  \\/  |                                  " << std::endl;
    std::cout << "| (___ | |_ ___   ___| | __ | \\  / | __ _ _ __   __ _  __ _  ___ _ __ " << std::endl;
    std::cout << " \\___ \\| __/ _ \\ / __| |/ / | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|" << std::endl;
    std::cout << " ____) | || (_) | (__|   <  | |  | | (_| | | | | (_| | (_| |  __/ |   " << std::endl;
    std::cout << "|_____/ \\__\\___/ \\___|_|\\_\\ |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|   " << std::endl;
    std::cout << "                                                       __/ |          " << std::endl;
    std::cout << "von Andert & Ewert                                    |___/           " << std::endl;
    */
    
	while (true)
    {
		std::cout << "\n\nHauptmenü\n"
            "-------------\n"
			"1: Aktie hinzufuegen\n"
			"2: Aktie loeschen\n"
			"3: Aktien importieren\n"
			"4: Aktienkurs suchen\n"
			"5: Graphik anzeigen\n"
			"6: Speichern\n"
			"7: Laden\n"
			"8: Beenden\n\n"
            "Aktion wählen: ";

		std::cin >> input;

		switch (input)
        {
            case 0:
                std::cout << "Debugger ON" << std::endl;
                hash.debug = true;
                break;
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
