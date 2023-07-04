#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include "Bilet.h"

Bilet::Bilet() {}
Bilet::Bilet(const Bilet& bilett)
{
   
        this->danePasazera = bilett.danePasazera;
        this->miejsce = bilett.miejsce;
        this->cena = bilett.cena;
        this->ulgowy = bilett.ulgowy;
    
}
;
Bilet::Bilet(const std::string& pasazer, const std::string& miejsce, double cena, bool ulgowy)
    : danePasazera(pasazer), miejsce(miejsce), cena(cena), ulgowy(ulgowy) {}

std::string Bilet::getMiejsce()
{
    return miejsce;
}

void Bilet::setMiejsce(int a, int b)
{
    miejsce = std::to_string(a) + "x" + std::to_string(b);
}

void Bilet::ObliczCene() {
    if (ulgowy)
        cena = cena * 0.5;
    
         
}
void Bilet::dodajDoCeny(double cenka) 
{
    cena += cenka;
}
void Bilet::setDanePasazera(std::string dane) {
    danePasazera = dane;
}
void Bilet::setUlgowy() {
    ulgowy = true;
}
void Bilet::WyswietlSzczegoly() const {
    if (ulgowy)
        std::cout << "Bilet ulgowy:" << std::endl;
    else
        std::cout << "Bilet normalny:" << std::endl;
    std::cout << "Dane pasasera: " << danePasazera << std::endl;
    std::cout << "Miejsce: " << miejsce << std::endl;

}

std::string Bilet::informacje()
{
    if (ulgowy == true)
        return danePasazera + " " + miejsce + " " + std::to_string(cena) + " " + "true";
    else
        return danePasazera + " " + miejsce + " " + std::to_string(cena) + " " + "false";
    //to string zamiana wartosci na stringa
}

std::string Bilet::getDanePasazera()
{
    return danePasazera; 
}
