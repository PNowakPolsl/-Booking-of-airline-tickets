#include "SamolotBiznesowy.h"

SamolotBiznesowy::SamolotBiznesowy(int rzedow, int siedzenia, int strefyVIP)
	: Samolot(rzedow, siedzenia), liczbaStrefVIP(strefyVIP) {}



void SamolotBiznesowy::wydrukujInformacje()
{
	std::cout << "Informacje o samolocie biznesowym" << std::endl;
	Samolot::wydrukujInformacje();
	std::cout << "Liczba stref VIP: " << getLiczbaStrefVIP() << std::endl;
}

int SamolotBiznesowy::getLiczbaStrefVIP()
{
	return liczbaStrefVIP;
}

std::string SamolotBiznesowy::informacje()
{
	return "SamolotBiznesowy " + Samolot::informacje() + std::to_string(liczbaStrefVIP) + "\n";
}

std::string SamolotBiznesowy::informacje2()
{
	return "SamolotBiznesowy " + Samolot::informacje2() + std::to_string(liczbaStrefVIP) + " ";
}
