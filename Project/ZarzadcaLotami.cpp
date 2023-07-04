#pragma once

#include "ZarzadcaLotami.h"

void ZarzadcaLotami::DodajRezerwacje(Rezerwacja* rezerwacja) {
    rezerwacje.push_back(rezerwacja);
}

void ZarzadcaLotami::UsunRezerwacje(Rezerwacja* rezerwacja) {
    auto it = std::find(rezerwacje.begin(), rezerwacje.end(), rezerwacja);
    if (it != rezerwacje.end()) {
        rezerwacje.erase(it);
        std::cout << "Rezerwacja zosta³a usuniêta." << std::endl;
    }
    else {
        std::cout << "Nie znaleziono takiej rezerwacji." << std::endl;
    }
}

void ZarzadcaLotami::WyswietlWszystkieRezerwacje() {
    std::cout << "Lista wszystkich rezerwacji:" << std::endl;
    for (const auto& rezerwacja : rezerwacje) {
        rezerwacja->WyswietlSzczegoly();
        std::cout << std::endl;
    }
}