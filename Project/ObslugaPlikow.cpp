#include <fstream>
#include "ObslugaPlikow.h"
#include "SamolotBiznesowy.h"
#include "SamolotLuksusowy.h"
#include "SamolotPasazerski.h"

void ObslugaPlikow::wczytajPolaczenie(std::vector<Polaczenie*>& polaczenie, const std::string& fileName)
{
    std::fstream plik;
    plik.open(fileName);
    std::string linia;
    while (std::getline(plik, linia)) {
        Polaczenie* pol = nullptr;
        std::stringstream ss(linia);
        int i = 0;
        std::string tab[6];
        std::string token;
        while (std::getline(ss, token, ' '))
        {
            tab[i] = token;
            i++;
        }
        pol = new Polaczenie(tab[0], tab[1], tab[2], tab[3], tab[4], std::stod(tab[5]));
        polaczenie.push_back(pol);
    }
    plik.close();
}

void ObslugaPlikow::wczytajSamolot(std::vector<Samolot*>& samolot, const std::string& fileName)
{
    std::fstream plik;
    plik.open(fileName);
    std::string linia;
    while (std::getline(plik, linia)) {
        Samolot* sam = nullptr;
        std::stringstream ss(linia);
        
        std::vector<std::string>tab;
        std::string token;
        while (std::getline(ss, token, ' '))
        {
            tab.push_back(token);
        }
        if (tab[0] == "SamolotPasazerski") {
            sam = new SamolotPasazerski(std::stoi(tab[1]), std::stoi(tab[2]), std::stoi(tab.back()));
            sam->ustawMiejsca(tab);
        }
        if (tab[0] == "SamolotLuksusowy") {
            sam = new SamolotLuksusowy(std::stoi(tab[1]), std::stoi(tab[2]), std::stoi(tab.back()));
            sam->ustawMiejsca(tab);
        }
        if (tab[0] == "SamolotBiznesowy") {
            sam = new SamolotBiznesowy(std::stoi(tab[1]), std::stoi(tab[2]), std::stoi(tab.back()));
            sam->ustawMiejsca(tab);
        }

        samolot.push_back(sam);
    }
    plik.close();
}

void ObslugaPlikow::zapiszSamolot(std::vector<Samolot*>& samolot, const std::string& fileName)
{
    std::ofstream plik(fileName);
    if (plik.is_open())
    {
        for (const auto& samolocik : samolot)
        {
            plik << samolocik->informacje();

        }
        plik.close();
        std::cout << "Rezerwacje zostaly zapisane do pliku." << std::endl;
    }
    else
    {
        std::cerr << "Blad podczas otwierania pliku do zapisu." << std::endl;
    }
}

void ObslugaPlikow::zapiszRezerwacje(std::vector<Rezerwacja*>& rezerwacj, const std::string& fileName)
{
    std::ofstream plik(fileName);
    if (plik.is_open())
    {
        for (const auto& rezerwacja : rezerwacj)
        {
            plik << rezerwacja->samolot->informacje2();

            plik << rezerwacja->polaczenie.informacje();
            plik << rezerwacja->bilet.informacje() << std::endl;

        }
        plik.close();
        std::cout << "Rezerwacje zostaly zapisane do pliku." << std::endl;
    }
    else
    {
        std::cerr << "Blad podczas otwierania pliku do zapisu." << std::endl;
    }
}

void ObslugaPlikow::wczytajRezerwacje(std::vector<Rezerwacja*>& rezerwacj, const std::string& fileName)
{
    std::ifstream plik(fileName);
    if (plik.is_open() && czyPlikIstnieje(fileName))
    {
        
        std::string linia;
        while (std::getline(plik, linia)) {
            Samolot* sam = nullptr;
            std::stringstream ss(linia);
            
            std::vector<std::string> tab;
            std::string token;
            while (std::getline(ss, token, ' '))
            {
                tab.push_back(token);
                
            }
            if (tab[0] == "SamolotPasazerski") {
                sam = new SamolotPasazerski(std::stoi(tab[1]), std::stoi(tab[2]), std::stoi(tab[3]));
               
            }
            if (tab[0] == "SamolotLuksusowy") {
                sam = new SamolotLuksusowy(std::stoi(tab[1]), std::stoi(tab[2]), std::stoi(tab[3]));
                
            }
            if (tab[0] == "SamolotBiznesowy") {
                sam = new SamolotBiznesowy(std::stoi(tab[1]), std::stoi(tab[2]), std::stoi(tab[3]));
               
            }
            Polaczenie polaczenix(tab[4], tab[5], tab[6], tab[7], tab[8], std::stoi(tab[9]));
            Bilet* bilet = nullptr;
            if (tab[13] == "true") {
                
                Bilet bilett(tab[10], tab[11], std::stod(tab[12]), true);
                bilet = new Bilet(bilett);
            }
            else {
                Bilet bilett(tab[10], tab[11], std::stod(tab[12]), false);
                bilet = new Bilet(bilett);
            }

            Rezerwacja* rezerwacja = new Rezerwacja(polaczenix, *bilet, sam);
            rezerwacj.push_back(rezerwacja);
        }
    }
}

bool ObslugaPlikow::czyPlikIstnieje(std::string nazwaPliku)
{
    return bool(std::ifstream(nazwaPliku));
}


void ObslugaPlikow::zapiszInformacjeOMiejscach(const bool** miejsca, int liczbaRzedow, int liczbaSiedzenWRzedzie, const std::string& nazwaPliku)
{  std::ofstream plik(nazwaPliku);

    if (plik.is_open()) {
        for (int i = 0; i < liczbaRzedow; i++) {
            for (int j = 0; j < liczbaSiedzenWRzedzie; j++) {
                plik << miejsca[i][j] << " ";
            }
            plik << std::endl;
        }

        plik.close();
        std::cout << "Informacje o zajêtych miejscach zapisane do pliku: " << nazwaPliku << std::endl;
    }
    else {
        std::cout << "B³¹d otwarcia pliku: " << nazwaPliku << std::endl;
    }
}

void ObslugaPlikow::wczytajInformacjeOMiejscach(bool** miejsca, int liczbaRzedow, int liczbaSiedzenWRzedzie, const std::string& nazwaPliku)
{
    std::ifstream plik(nazwaPliku);

    if (plik.is_open()) {
        for (int i = 0; i < liczbaRzedow; i++) {
            for (int j = 0; j < liczbaSiedzenWRzedzie; j++) {
                int zajeteMiejsce;
                plik >> zajeteMiejsce;
                miejsca[i][j] = static_cast<bool>(zajeteMiejsce);
            }
        }

        plik.close();
        std::cout << "Informacje o zajêtych miejscach wczytane z pliku: " << nazwaPliku << std::endl;
    }
    else {
        std::cout << "B³¹d otwarcia pliku: " << nazwaPliku << std::endl;
    }
}

     
  
    

