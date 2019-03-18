#include "Stocks.h"
#include <iostream>

int main()
{
	Stocks s;
	int input;
	while (true)
    {
		std::cout << "Aktion waehlen\n"
			"1: Aktie hinzufuegen\n"
			"2: Aktie loeschen\n"
			"3: Aktien importieren\n"
			"4: Aktienkurs ausgeben\n"
			"5: Graphik anzeigen\n"
			"6: Speichern\n"
			"7: Laden\n"
			"8: Beenden" << std::endl;

		std::cin >> input;

		switch (input)
        {
		case 1: s.add_stock(); break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8: return 0;
		default: break;
		}
	}

	return 0;
}
