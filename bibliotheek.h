#pragma once
#include <vector>
#include <string>
#include "lid.h"
#include "boek.h"


class Bibliotheek
{
private:
	std::vector<Lid> leden;
	std::vector<Boek> boeken;

public:
	void voegLidToe(std::string naam);
	void haalLidWeg(Lid& lid);
	void voegBoekToe(Boek& boek);
	void haalBoekWeg(Boek& boek);
	void leenBoek(Boek& boek);
	void brengBoekTerug(Boek& boek);
	Lid& geefLid(std::string naam);
	void geefInfoBoeken();
	void geefInfoLeden();
	void haalBoekenOp(std::string fileName);
	void haalLedenOp(std::string fileName);
};

