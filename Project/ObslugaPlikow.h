#pragma once
#include "Polaczenie.h"
#include "Samolot.h"
#include "Rezerwacja.h"
class ObslugaPlikow
{
public:
    static void wczytajPolaczenie(std::vector<Polaczenie*>& polaczenie, const std::string& fileName);
    static void wczytajSamolot(std::vector<Samolot*>& samolot, const std::string& fileName);
    static void zapiszSamolot(std::vector<Samolot*>& samolot, const std::string& fileName);
    static void zapiszRezerwacje(std::vector<Rezerwacja*>& rezerwacj, const std::string& fileName);
    static void wczytajRezerwacje(std::vector<Rezerwacja*>& rezerwacj, const std::string& fileName);
    
    static bool czyPlikIstnieje(std::string nazwaPliku);

    void zapiszInformacjeOMiejscach(const bool** miejsca, int liczbaRzedow, int liczbaSiedzenWRzedzie, const std::string& nazwaPliku);
    void wczytajInformacjeOMiejscach(bool** miejsca, int liczbaRzedow, int liczbaSiedzenWRzedzie, const std::string& nazwaPliku);
};