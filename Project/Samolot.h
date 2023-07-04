#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Samolot {
protected:
   
    
    int liczbaRzedow;
    int liczbaSiedzenWRzedzie;
    bool** miejsca;
    

public:
    Samolot(int rzedow, int siedzenia);

    void zarezerwujMiejsce(int i, int b);
    void zwolnijMiejsce(int i, int b);
    bool sprawdzMiejsca();
    bool sprawdzKonkretne(int i, int b);
    void wyswietlMiejsca();

    virtual void wydrukujInformacje();

    void ustawMiejsca(std::vector<std::string> ustaw);

    int getLiczbaRzedow();
    int getLiczbaSiedzenWRzedzie();

    

    virtual std::string informacje();
    virtual std::string informacje2();

};