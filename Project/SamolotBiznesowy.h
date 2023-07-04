#pragma once
#include "Samolot.h"
class SamolotBiznesowy : public Samolot
{
private:
    int liczbaStrefVIP;

public:
    SamolotBiznesowy(int rzedow, int siedzenia, int strefyVIP);


    

    void wydrukujInformacje() override;

    int getLiczbaStrefVIP();

    std::string informacje() override;
    std::string informacje2() override;
};
