#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Samolot.h"

Samolot::Samolot(int rzedow, int siedzenia)
    : liczbaRzedow(rzedow), liczbaSiedzenWRzedzie(siedzenia) {
    miejsca = new bool* [liczbaRzedow]; 

    for (int i = 0; i < liczbaRzedow; i++) {
        miejsca[i] = new bool[liczbaSiedzenWRzedzie]; 

        for (int j = 0; j < liczbaSiedzenWRzedzie; j++) {
            miejsca[i][j] = false; 
        }
    }
}

void Samolot::zarezerwujMiejsce(int i, int b)
{
    if (miejsca[i][b] == true) {
        std::cout << "Zajete" << std::endl;
    }
    else {
        miejsca[i][b] = true;
    }


}

void Samolot::zwolnijMiejsce(int i, int b)
{
    if (miejsca[i][b] == true)
        miejsca[i][b] = false;
    
}

bool Samolot::sprawdzMiejsca()
{
    for (int i=0; i < liczbaRzedow; i++) {
        for (int j = 0; j < liczbaSiedzenWRzedzie; j++) {
            if (miejsca[i][j] == false) {
                return true;
            }
        }
    }
    return false;
}

bool Samolot::sprawdzKonkretne(int i, int b)
{
    if (miejsca[i][b] == false)
        return true;
    else
        return false;
}

void Samolot::wyswietlMiejsca()
{
    for (int i = 0; i < liczbaRzedow; i++) {
        for (int j = 0; j < liczbaSiedzenWRzedzie; j++)
            std::cout << miejsca[i][j] << " ";
        std::cout << "\n";
    }
}


void Samolot::wydrukujInformacje()
{

    std::cout << "Liczba dostepnych miejsc w samolocie: " <<   std::endl;
    std::cout << "Liczba rzedow siedzen: " << getLiczbaRzedow() << std::endl;
    std::cout << "Liczba siedzen w rzedzie: " << getLiczbaSiedzenWRzedzie() << std::endl;
}

void Samolot::ustawMiejsca(std::vector<std::string> ustaw)
{
    int a = 3;
    for (int i = 0; i < liczbaRzedow; i++) {
        for (int j = 0; j < liczbaSiedzenWRzedzie; j++) {
            if(ustaw.at(a) == "1")
            miejsca[i][j] = true;
            else
            miejsca[i][j] = false;
        }
    }
}


int Samolot::getLiczbaRzedow()
{
    return liczbaRzedow;
}

int Samolot::getLiczbaSiedzenWRzedzie()
{
    return liczbaSiedzenWRzedzie;
}



std::string Samolot::informacje()
{
    
    std::string pom = "";
    for (int i = 0; i < liczbaRzedow; i++) {
        for (int j = 0; j < liczbaSiedzenWRzedzie; j++) {
            if(miejsca[i][j]==true)
            pom +=  "1 ";
            else
                pom += "0 ";
        }
    }
    return std::to_string(liczbaRzedow) + " " + std::to_string(liczbaSiedzenWRzedzie) + " " + pom;
}

std::string Samolot::informacje2()
{
    return std::to_string(liczbaRzedow) + " " + std::to_string(liczbaSiedzenWRzedzie) + " ";
}

