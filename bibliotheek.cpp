#include "bibliotheek.h"
#include <iostream>


void Bibliotheek::voegLidToe(std::string naam) {
	leden.push_back(Lid(naam, leden.size() + 1));
}
void Bibliotheek::haalLidWeg(Lid& lid) {
	for (auto i = leden.begin(); i < leden.end(); i++) {
		if (lid.geefNr() == i->geefNr()) {
			leden.erase(i);
		}
	}

}

Lid& Bibliotheek::geefLid(std:: string naam) {
	for (auto i = leden.begin(); i < leden.end(); i++) {
		if (naam == i->geefNaam()) {
			return *i;
		}
	}

}
void Bibliotheek::voegBoekToe(Boek& boek) {
	boeken.push_back(boek);

}
void Bibliotheek::haalBoekWeg(Boek& boek) {
	for (auto i = boeken.begin(); i < boeken.end(); i++) {
		if (boek.geefAuteur() == i->geefAuteur() && boek.geefTitel() == i->geefTitel()) {
			boeken.erase(i);
		}
	}
}

void Bibliotheek::leenBoek(Boek& boek) {
	for (auto& b : boeken) {
		if (boek.geefAuteur() == b.geefAuteur() && boek.geefTitel() == b.geefTitel()) {
			b.setStatus(Uitgeleend);
		}
	}
}
void Bibliotheek::brengBoekTerug(Boek& boek) {
	for (auto& b : boeken) {
		if (boek.geefAuteur() == b.geefAuteur() && boek.geefTitel() == b.geefTitel()) {
			b.setStatus(NietUitgeleend);
		}
	}
}

void Bibliotheek::geefInfoBoeken() {
	for (auto& b : boeken) {
		std::cout << b.geefTitel() << "," << b.getStatus() << std::endl;
	}
}
void Bibliotheek::geefInfoLeden() {
	for (auto& l : leden) {
		std::cout << l.geefNaam() << "," << l.geefNr() << std::endl;
	}
}
