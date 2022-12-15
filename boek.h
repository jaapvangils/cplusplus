#pragma once
#include <string>

enum Status {Uitgeleend, NietUitgeleend};

class Boek
{

private:
	std::string auteur;
	std::string titel;
	Status status;

public:
	Boek(std::string auteur, std::string title, Status s);
	std::string geefAuteur();
	std::string geefTitel();
	Status getStatus();
	void setStatus(Status s);
};

