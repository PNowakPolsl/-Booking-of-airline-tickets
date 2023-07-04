#include "SamolotPasazerski.h"

SamolotPasazerski::SamolotPasazerski(int rzedow, int siedzenia, int poklady)
	: Samolot(rzedow, siedzenia), liczbaPokladow(poklady) {}




void SamolotPasazerski::wydrukujInformacje()
{
	std::cout << "Informacje o samolocie pasaserskim" << std::endl;
	Samolot::wydrukujInformacje();
	std::cout << "Liczba pokladów: " << getLiczbaPokladow() << std::endl;
}

int SamolotPasazerski::getLiczbaPokladow()
{
	return liczbaPokladow;
}

std::string SamolotPasazerski::informacje()
{
	return "SamolotPasazerski " + Samolot::informacje() + std::to_string(liczbaPokladow) + "\n";
}

std::string SamolotPasazerski::informacje2()
{
	return "SamolotPasazerski " + Samolot::informacje2() + std::to_string(liczbaPokladow) + " ";
}
