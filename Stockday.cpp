#include "Stockday.h"

Stockday::Stockday() { 
   
}

Stockday::~Stockday() { 
    
}

void Stockday::inputData(std::string input) {
    // Input CSV Data
    // Get OneLine from CSV which is ONE Day and parse it to Class Variables
    // https://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
    // http://www.cplusplus.com/reference/vector/vector/
    
    std::vector<double> vect;
    std::stringstream ss(input);
    
    double value = 0;
    
    
    
    while (ss >> value)
    {
        vect.push_back(value);
        
        if (ss.peek() == ',')
        {
            ss.ignore();
        }
    }
    
    for (int i = 0; i < vect.size(); i++)
    {
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
            default: // WHATEVER YOU CUNT
                break;
        }
    }
}

