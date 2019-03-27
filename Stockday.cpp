#include "Stockday.h"

Stockday::Stockday() { 
   
}

Stockday::~Stockday() { 
    
}

void Stockday::inputData(std::string input) {
    // Get one line from the CSV which represents ONE Day
    // and parse it to Stockdays-Variables
    
    std::vector<double> vect;
    std::stringstream ss(input); // Create Strignstream from Input
    
    double value = 0; // Temporary Input Value
    
    while (ss >> value) // Cast to Double
    {
        vect.push_back(value); // Push to Vector
        
        if (ss.peek() == ',') // Discard Delimiters
        {
            ss.ignore();
        }
    }
    
    for (int i = 0; i < vect.size(); i++) // Go through Vector
    {
        // Order in CSV is everytime the same
        // so the index in vector represents the correct values of stockday
        switch (i)
        {
            case 0: // YEAR
                this->date[0] = vect.at(i);
                break;
            case 1: // MONTH
                this->date[1] = vect.at(i) * (-1);
                break;
            case 2: // DAY
                this->date[2] = vect.at(i) * (-1);
                break;
            case 3: // OPEN
                this->open = vect.at(i);
                break;
            case 4: // HIGH
                this->high = vect.at(i);
                break;
            case 5: // LOW
                this->low = vect.at(i);
                break;
            case 6: // CLOSE
                this->close = vect.at(i);
                break;
            case 7: // ADJ CLOSE
                this->adj = vect.at(i);
                break;
            case 8: // VOLUMEN
                this->volume = vect.at(i);
                break;
            default:
                std::cout << "CSV nicht korrekt formatiert!" << std::endl;
                return;
                break;
        }
    }
}

