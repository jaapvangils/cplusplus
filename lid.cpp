#include "lid.h"
#include "bibliotheek.h"

Lid::Lid(std::string naam,int lidNr) {
	this->naam = naam;
	this->lidNr = lidNr;
}

std::string Lid::geefNaam() {
	return naam;
}

int Lid::geefNr() {
	return lidNr;
}

void Lid::leenBoek(Bibliotheek& bib, Boek& b) {
	bib.leenBoek(b);
	geleendeBoeken.push_back(b);
}

void Lid::brengBoekTerug(Bibliotheek& bib, Boek& b) {
	bib.brengBoekTerug(b);
	for (auto i = geleendeBoeken.begin(); i < geleendeBoeken.end(); i++) {
		if (b.geefAuteur() == i->geefAuteur() && b.geefTitel() == i->geefTitel()) {
			geleendeBoeken.erase(i);
		}
	}
}
