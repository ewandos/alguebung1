/*
 * Bildet einen Tag eines STOCKS (=Aktie).
 * Hier muessen alle Daten in einer Klasse gespeichert
 * werden, die fuer EINEN TAG gespeichert werden.
 * (Date,Open,High,Low,Close,Volume,Adj Close)
 * am besten alles doubles
 */

#ifndef Stockday_h
#define Stockday_h

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Stockday
{
public:
    Stockday();
    ~Stockday();
    bool isFilled;
    
    int date[3];
    double open;
    double high;
    double low;
    double close;
    double volume;
    double adj;
    
    void inputData(std::string); // Input ONE LINE of the CSV
};

#endif
