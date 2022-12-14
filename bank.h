#pragma once
using namespace std;

class Bankrekening {
private:
	string Naam = "";
	double Saldo = -1;

public:
	Bankrekening(string Naam, double Saldo);
	Bankrekening();

	void maakNaam(string naam);
	string leesNaam();
	void maakSaldo(double saldo);
	double leesSaldo();
};