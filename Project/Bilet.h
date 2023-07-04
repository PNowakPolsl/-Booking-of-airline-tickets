#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
class Bilet {
protected:

    std::string danePasazera;
    std::string miejsce;

    double cena = 0;
    bool ulgowy = false;

public:
    Bilet();
    Bilet(const Bilet& bilett);
    Bilet(const std::string& pasazer, const std::string& miejsce, double cena, bool ulgowy);
    std::string getMiejsce();
    void setMiejsce(int a, int b);
    void ObliczCene();
    void dodajDoCeny(double cena);
    void setDanePasazera(std::string dane);
    void setUlgowy();
    void WyswietlSzczegoly() const;

    std::string informacje();

    std::string getDanePasazera();

};