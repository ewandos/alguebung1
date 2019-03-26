/*
 * Bildet einen Tag eines STOCKS (=Aktie).
 * Hier müssen alle Daten in einer Klasse gespeichert
 * werden, die für EINEN TAG gespeichert werden.
 * (Date,Open,High,Low,Close,Volume,Adj Close)
 * am besten alles doubles
 */

#ifndef Stockday_h
#define Stockday_h

#include <iostream>

class Stockday
{
public:
    Stockday();
    ~Stockday();
    
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
