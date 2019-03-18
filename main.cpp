#include "Stock.h"
#include <iostream>

int main()
{
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
            case 1:
                // Add a Stock to the Hashtable
                break;
            case 2:
                // Remove a Stock of the Hashtable
                break;
            case 3:
                // Import a Stock from a CSV File
                break;
            case 4:
                // Read a specific Stock
                break;
            case 5:
                // Show a Graph of a specific Stock
                break;
            case 6:
                // Save the Hashtable
                break;
            case 7:
                // Load a Hashtable
            case 8:
                // Exit Application
                return 0;
            default:
                // Ask User to Enter valid input
                std::cout << "Please enter a valid option: ";
                break;
		}
	}

	return 0;
}
