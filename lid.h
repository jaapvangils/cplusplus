#pragma once
#include <string>
#include <vector>
#include "boek.h"

class Bibliotheek;

class Lid
{
private:
	std::string naam = "";
	int lidNr = -1;
	std::vector<Boek> geleendeBoeken;

public:
	std::string geefNaam();
	int geefNr();
	Lid(std::string naam,int lidNr);
	void leenBoek(Bibliotheek& bib, Boek& b);
	void brengBoekTerug(Bibliotheek& bib, Boek& b);
};

