#include <iostream>
#include <string>
#include <fstream>
#include "Polaczenie.h"

Polaczenie::Polaczenie() {}
Polaczenie::Polaczenie(const std::string& skad, const std::string& dokad) : skad(skad), dokad(dokad) {}
Polaczenie::Polaczenie(const std::string& skad, const std::string& dokad, const std::string& godzinaWylotu, const std::string& godzinaPrzylotu,
    const std::string& dzienTygodnia, const int& cenaPolaczenia)
    : skad(skad), dokad(dokad), godzinaWylotu(godzinaWylotu), godzinaPrzylotu(godzinaPrzylotu), dzienTygodnia(dzienTygodnia), cenaPolaczenia(cenaPolaczenia) {}

double Polaczenie::getCenaPolaczenia()
{
    return cenaPolaczenia;
}

void Polaczenie::WyswietlSzczegoly() {
    std::cout << "Skad: " << skad << std::endl;
    std::cout << "Dokad: " << dokad << std::endl;
    std::cout << "Godzina wylotu: " << godzinaWylotu << std::endl;
    std::cout << "Godzina przylotu: " << godzinaPrzylotu << std::endl;
    std::cout << "Dzien tygodnia: " << dzienTygodnia << std::endl;
    std::cout << "Cena Polaczenia: " << cenaPolaczenia << std::endl;
}

std::string Polaczenie::informacje()
{
    return skad + " " + dokad + " " + godzinaWylotu + " " + godzinaPrzylotu + " " + dzienTygodnia + " " + std::to_string(cenaPolaczenia) + " ";
}