#pragma once
#include "Samolot.h"

class SamolotPasazerski : public Samolot
{
private:
    int liczbaPokladow;

public:
    SamolotPasazerski(int rzedow, int siedzenia, int poklady);


    

    void wydrukujInformacje() override;

    int getLiczbaPokladow();

    std::string informacje() override;
    std::string informacje2() override;

};