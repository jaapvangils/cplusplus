#include <string>
#include "bank.h"

using namespace std;

Bankrekening::Bankrekening(string Naam, double Saldo) {
	this->Naam = Naam;
	this->Saldo = Saldo;
}

Bankrekening::Bankrekening() {}; // default aanmaken zonder input kan ook: Bankrekening() = default;

void Bankrekening::maakNaam(string naam) {
	this->Naam = naam;
}
string Bankrekening::leesNaam() {
	return this->Naam;
}
void Bankrekening::maakSaldo(double saldo) {
	this->Saldo = saldo;
}
double Bankrekening::leesSaldo() {
	return this->Saldo;
}