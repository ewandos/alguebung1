#include "Hashtable.h"
#include <iostream>

int main()
{
    Hashtable hash;
	int input;
    
    std::cout << "  _____ _             _      __  __                                   " << std::endl;
    std::cout << " / ____| |           | |    |  \\/  |                               " << std::endl;
    std::cout << "| (___ | |_ ___   ___| | __ | \\  / | __ _ _ __   __ _  __ _  ___ _ __ " << std::endl;
    std::cout << " \\___ \\| __/ _ \\ / __| |/ / | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '__|" << std::endl;
    std::cout << " ____) | || (_) | (__|   <  | |  | | (_| | | | | (_| | (_| |  __/ |   " << std::endl;
    std::cout << "|_____/ \\__\\___/ \\___|_|\\_\\ |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_|   " << std::endl;
    std::cout << "                                                       __/ |          " << std::endl;
    std::cout << "ehrfurchtvoll praesentiert von Andert & Ewert         |___/           " << std::endl;
    
	while (true)
    {
		std::cout << "\n\nHauptmenue\n"
            "-------------\n"
			"1: Aktie hinzufuegen\n"
			"2: Aktie loeschen\n"
			"3: Aktienkurse importieren\n"
			"4: Aktuellsten Aktienkurs ausgeben\n"
			"5: Graphik anzeigen\n"
			"6: Speichern\n"
			"7: Laden\n"
            "8: Beenden\n"
			"0: DEBUGGING\n\n"
            "Aktion waehlen: ";

		std::cin >> input;

		switch (input)
        {
            case 0:
                std::cout << "Debugger ON" << std::endl;
                hash.debug = true;
                break;
            case 1:
                // Eine Aktie mit Namen, WKN und Kuerzel wird hinzugefuegt
                hash.addStock(0, NULL); // FERTIG
                break;
            case 2:
                // Aktie wird geloescht
                hash.deleteStock(); // FERTIG
                break;
            case 3:
                // Kurswerte fuer eine Aktie werden aus einer csv Datei importiert
                hash.importStockday();
                break;
            case 4:
                // Eine Aktie wird in der Hashtabelle gesucht
                // (Eingabe von Namen oder Kuerzel) und der
                // aktuellste Kurseintrag wird ausgegeben.
                hash.searchStock(); // SUCHE FERTIG, AUSGABE FEHLT
                break;
            case 5:
                // Die Schlusskurse der letzten 30 Tage einer Aktie werden als ASCII
                // Grafik ausgegeben, Format ist frei waehlbar.
                hash.plotStock();
                break;
            case 6:
                // Programm speichert die Hashtabelle in eine Datei ab
                hash.save();
                break;
            case 7:
                // Programm laedt die Hashtabelle aus einer Datei
                hash.load();
				break;
            case 8:
                // Programm wird beendet
                return 0;
            default:
                // Ask User to Enter valid input
                std::cout << "Bitte mit gueltiger Eingabe wiederholen." << std::endl;
                break;
		}  
	}

	return 0;
}