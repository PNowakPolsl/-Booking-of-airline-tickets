#include "Rezerwacja.h"
#include "ObslugaPlikow.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <filesystem>

void wypiszSamoloty(std::vector<Samolot*> samoloty) {
    int i = 0;
    for (const auto& samolo : samoloty) {
        std::cout << i++ << std::endl;
        samolo->wydrukujInformacje();
    }
}void wypiszPolaczenie(std::vector<Polaczenie*>polaczenie) {
    int i = 0;
    for (const auto& polaczen : polaczenie) {
        std::cout << i++ << std::endl;
        polaczen->WyswietlSzczegoly();
    }
}

void zwolnijMiejsce(std::vector<Samolot*> &samoloty, int rzad, int kolumna, int rzadx, int kolumnax) {
    for (const auto& samolo : samoloty) {
        if (samolo->getLiczbaRzedow() == rzad && samolo->getLiczbaSiedzenWRzedzie() == kolumna) {
            samolo->zwolnijMiejsce(rzadx, kolumnax);
        }

    }
}



int main() {

    std::vector<Polaczenie*>polaczenie;
    std::vector<Rezerwacja*>rezerwacja;
    std::vector<Samolot*>samoloty;
    ObslugaPlikow::wczytajPolaczenie(polaczenie, "polaczenia.txt");

    ObslugaPlikow::wczytajRezerwacje(rezerwacja, "rezerwacja.txt");

    ObslugaPlikow::wczytajSamolot(samoloty, "rodzaje.txt");

    bool koniec = false;

    while (!koniec) {
        std::cout << "MENU" << std::endl;
        std::cout << "1 - Rezerwacja Lotu" << std::endl;
        std::cout << "2 - Wyswietl rezerwacje" << std::endl;
        std::cout << "3 - Usun rezerwacje" << std::endl;
        std::cout << "4 - Koniec" << std::endl;

        int wybor;
        std::cin >> wybor;
        switch (wybor)
        {

        case 1:
        {
            wypiszSamoloty(samoloty);


            int a, b, c;
            Samolot* samolot = nullptr;

            while (true) {
                std::cout << "Jaki samolot: ";
                std::cin >> a;
                if(a <= samoloty.size() && a >= 0)
                    if (samoloty.at(a)->sprawdzMiejsca())
                        break;
                std::cout << "Nie ma miejsc w tym samolocie. Prosze wybrac inny \n";
            }
            samoloty.at(a)->wyswietlMiejsca();
            while (true){

                std::cout << "Wybierz rzad" << std::endl;
                std::cin >> b;
                std::cout << "Wybierz kolumne" << std::endl;
                std::cin >> c;
                if (samoloty.at(a)->sprawdzKonkretne(b - 1, c - 1)) {
                    samoloty.at(a)->zarezerwujMiejsce(b - 1, c - 1);
                    break;

                }
                std::cout << "Te miejsce w samolocie jest juz zajete. Prosze wybrac inne \n";
            }
            samolot = samoloty.at(a);
          
            



            wypiszPolaczenie(polaczenie);
            std::cout << "Jakie polaczenie? ";
            std::cin >> a;
            Polaczenie polaczen = *polaczenie.at(a);

            std::cout << "Podaj dane do biletu" << std::endl;
            Bilet bilet = Bilet();

            bilet.setMiejsce(b, c);
            std::string pom;
            std::cout << "Podaj swoje dane: ";
            std::cin >> pom;
            bilet.setDanePasazera(pom);
            std::string czyUlgowy;
            const std::type_info& typeInfo = typeid(*samolot);
            std::string nameOfClass = typeInfo.name();
            if (nameOfClass.substr(6) == "SamolotBiznesowy")
                bilet.dodajDoCeny(150);
            else if (nameOfClass.substr(6) == "SamolotLuksusowy")
                bilet.dodajDoCeny(300);
            else if (nameOfClass.substr(6) == "SamolotBiznesowy")
                bilet.dodajDoCeny(50);

            //bilet + polaczenie.cen
            bilet.dodajDoCeny(polaczen.getCenaPolaczenia());


            std::cout << "Czy ulgowy? true/false ";
            std::cin >> czyUlgowy;
            if (czyUlgowy == "true")
                bilet.setUlgowy();
            bilet.ObliczCene();
            Rezerwacja* rezerwacj = new Rezerwacja(polaczen, bilet, samolot);
            rezerwacja.push_back(rezerwacj);

            std::cout << "Rezerwacja lotu zostala dodana." << std::endl;

            system("pause");

            ObslugaPlikow::zapiszRezerwacje(rezerwacja, "rezerwacja.txt");
            ObslugaPlikow::zapiszSamolot(samoloty, "rodzaje.txt");

            break;
        }

        case 2:
        {
            std::cout << "Podaj swoje dane" << std::endl;
            std::cin.ignore();
            std::string dane;
            std::getline(std::cin, dane);
            for (auto& rezerwation : rezerwacja) {
                if (rezerwation->bilet.getDanePasazera() == dane)
                    rezerwation->WyswietlSzczegoly();
            }

            system("pause");
            //wypisz rezerwacje dla danej osoby
            break;
        }
        case 3:
        {
            std::cin.ignore();
            std::string dane;
            std::cout << "Podaj dane pasazera: ";
            std::getline(std::cin, dane);

            int i = 0;
            bool usunietoRezerwacje = false;
            std::string rzad;
            std::string kolumna;

            for (auto it = rezerwacja.begin(); it != rezerwacja.end();)
            {
                
                if ((*it)->bilet.getDanePasazera() == dane)
                {
                    size_t pos = (*it)->bilet.getMiejsce().find('x');
                    
                    zwolnijMiejsce(samoloty, (*it)->samolot->getLiczbaRzedow(), (*it)->samolot->getLiczbaSiedzenWRzedzie(), std::stoi((*it)->bilet.getMiejsce().substr(0, pos))-1, std::stoi((*it)->bilet.getMiejsce().substr(pos + 1))-1);
                    delete* it;
                    it = rezerwacja.erase(it);
                    usunietoRezerwacje = true;
                }
                else
                {
                    ++it;
                }
                i++;
            }

            if (usunietoRezerwacje)
            {
                std::cout << "Rezerwacja dla podanego pasazera zostala usunieta." << std::endl;
            }
            else
            {
                std::cout << "Nie znaleziono rezerwacji dla podanego pasazera." << std::endl;
            }
            system("pause");
            ObslugaPlikow::zapiszRezerwacje(rezerwacja, "rezerwacja.txt");
            ObslugaPlikow::zapiszSamolot(samoloty, "rodzaje.txt");
            //usun rezerwacje danej osoby
            break;
        }
        case 4:
            koniec = true;
        default:
            break;
        }
        system("cls");
    }
        for (auto& rezerwacja : rezerwacja) {
            delete rezerwacja;
        }
        rezerwacja.clear();

        for (auto& samolot : samoloty) {
            delete samolot;
        }
        samoloty.clear();

        for (auto& polaczenie : polaczenie) {
            delete polaczenie;
        }
        polaczenie.clear();

        return 0;
    
}
