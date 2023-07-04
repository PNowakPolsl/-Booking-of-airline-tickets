#pragma once
#include <iostream>
#include<string>
#include<fstream>

class Polaczenie {
private:
    std::string skad;
    std::string dokad;
    std::string godzinaWylotu;
    std::string godzinaPrzylotu;
    std::string dzienTygodnia;
    int cenaPolaczenia;

public:
    Polaczenie();
    Polaczenie(const std::string& skad, const std::string& dokad);
    Polaczenie(const std::string& skad, const std::string& dokad, const std::string& godzinaWylotu, const std::string& godzinaPrzylotu,
        const std::string& dzienTygodnia, const int& cenaPolaczenia);

    double getCenaPolaczenia();

    void WyswietlSzczegoly();

    std::string informacje();

};