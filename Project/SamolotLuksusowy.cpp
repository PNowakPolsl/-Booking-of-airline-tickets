#include "SamolotLuksusowy.h"

SamolotLuksusowy::SamolotLuksusowy(int rzedow, int siedzenia, int bary)
	: Samolot(rzedow, siedzenia), liczbaBarow(bary) {}



void SamolotLuksusowy::wydrukujInformacje()
{
	std::cout << "Informacje o samolocie luksusowym" << std::endl;
	Samolot::wydrukujInformacje();
	std::cout << "Liczba barow: " << getLiczbaBarow() << std::endl;
}

int SamolotLuksusowy::getLiczbaBarow()
{
	return liczbaBarow;
}

std::string SamolotLuksusowy::informacje()
{
	return "SamolotLuksusowy " + Samolot::informacje() + std::to_string(liczbaBarow) + "\n";
}

std::string SamolotLuksusowy::informacje2()
{
	return "SamolotLuksusowy " + Samolot::informacje2() + std::to_string(liczbaBarow) + " ";
}
