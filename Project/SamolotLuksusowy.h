#pragma once
#include "Samolot.h"
class SamolotLuksusowy : public Samolot
{
private:
    int liczbaBarow;

public:
    SamolotLuksusowy(int rzedow, int siedzenia, int bary);


    

    void wydrukujInformacje() override;

    int getLiczbaBarow();

    std::string informacje() override;
    std::string informacje2() override;
};
