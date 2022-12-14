#include <iostream>
#include "bank.h"

int main() {
	Bankrekening BR1;
	BR1.maakNaam("Piet");
	BR1.maakSaldo(100);
	cout << BR1.leesNaam() << " " << BR1.leesSaldo() << endl;
	Bankrekening BR2 = Bankrekening("Klaas", 130.52);
	cout << BR2.leesNaam() << " " << BR2.leesSaldo() << endl;

}