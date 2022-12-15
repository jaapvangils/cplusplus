#include "bibliotheek.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Windows.h>



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
		std::cout << b.geefTitel() << "," << b.geefAuteur() << "," << b.getStatus() << std::endl;
	}
}
void Bibliotheek::geefInfoLeden() {
	for (auto& l : leden) {
		std::cout << l.geefNaam() << "," << l.geefNr() << std::endl;
	}
}
void Bibliotheek::haalBoekenOp(std::string fileName) {
	std::string line, word;
	std::vector<std::string> tempBoek;
	std::ifstream infile;
	infile.open(fileName);
	while (std::getline(infile, line)) {
		std::istringstream inLine(line);
		while (std::getline(inLine, word, ',')) {
			//			std::cout << word << std::endl;
			tempBoek.push_back(word);
		}
		if (tempBoek.size() == 2) {
			Boek b = Boek(tempBoek[1], tempBoek[0], NietUitgeleend);
			voegBoekToe(b);
		}
		tempBoek.clear();
	}
	infile.close();
}

void Bibliotheek::haalLedenOp(std::string fileName) {
	std::string line;
	std::ifstream infile;
	infile.open(fileName);
	std::cout << "Laden:";
	while (std::getline(infile, line)) {
		voegLidToe(line);
		std::cout << "#";
		Sleep(300);
	}
	infile.close();
}