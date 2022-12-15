#include "boek.h"
#include <string>

Boek::Boek(std::string auteur, std::string titel, Status status ) {
	this->auteur = auteur;
	this->titel = titel;
	this->status = status;
}

std::string Boek::geefAuteur() {
	return auteur;
}
std::string Boek::geefTitel() {
	return titel;
}

Status Boek::getStatus() {
	return status;
}

void Boek::setStatus(Status s) {
	status = s;
}
