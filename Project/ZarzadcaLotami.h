#pragma once
#include <vector>
#include "Rezerwacja.h"
#include <iostream>
#include <algorithm>

class ZarzadcaLotami {
private:
    std::vector<Rezerwacja*> rezerwacje;

public:
    void DodajRezerwacje(Rezerwacja* rezerwacja);

    void UsunRezerwacje(Rezerwacja* rezerwacja);


    void WyswietlWszystkieRezerwacje();
};