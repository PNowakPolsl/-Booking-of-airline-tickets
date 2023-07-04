#pragma once
#include "Samolot.h"
#include "Bilet.h"
#include "Polaczenie.h"
class Rezerwacja {
public:
    Polaczenie polaczenie;
    Bilet bilet;
    Samolot* samolot;

public:
    Rezerwacja(const Polaczenie& polaczenie, const Bilet& bilet, Samolot* samolot);


    void WyswietlSzczegoly();
};