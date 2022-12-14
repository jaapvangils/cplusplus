#include <iostream>
#include <string>

using namespace std;

// Bankrekening -> instance variabelen [ naam, saldo ]
// getters & setters publiek
// maak constructor voor bankrekening met params [ naam, saldo ]
// nieuwe bankrekening aanmaken en weergeven

class Bankrekening {
private:
	string Naam = "";
	double Saldo = -1;

public:
	// constructor
	Bankrekening(string Naam, double Saldo) { 
		this -> Naam = Naam;
		this -> Saldo = Saldo;
	}

	Bankrekening() {}; // default aanmaken zonder input kan ook: Bankrekening() = default;

	void maakNaam(string naam) {
		this->Naam = naam;
	}
	string leesNaam() {
		return this->Naam;
	}
	void maakSaldo(double saldo) {
		this->Saldo = saldo;
	}
	double leesSaldo() {
		return this->Saldo;
	}
};

int main() {
	Bankrekening BR1;
	BR1.maakNaam("Piet");
	BR1.maakSaldo(100);
	cout << BR1.leesNaam() << " " << BR1.leesSaldo() << endl;
	Bankrekening BR2 = Bankrekening("Klaas", 130.52);
	cout << BR2.leesNaam() << " " << BR2.leesSaldo() << endl;
		 
}
