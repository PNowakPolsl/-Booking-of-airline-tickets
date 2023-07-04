#include "Rezerwacja.h"



Rezerwacja::Rezerwacja(const Polaczenie& polaczenie, const Bilet& bilet, Samolot* samolot) : polaczenie(polaczenie), bilet(bilet), samolot(samolot) {}


void Rezerwacja::WyswietlSzczegoly()
{
	std::cout << "Szczegoly rezerwacji:" << std::endl;
	polaczenie.WyswietlSzczegoly();
	bilet.WyswietlSzczegoly();
	samolot->wydrukujInformacje();
}