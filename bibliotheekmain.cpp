#include <iostream>
#include "bibliotheek.h"
#include "lid.h"

using namespace std;


int main() {
	Bibliotheek bib;
	bib.voegLidToe("Jaap");
	bib.voegLidToe("Martin");
	Boek b1 = Boek( "Mulisch", "De aanslag", NietUitgeleend);
	bib.voegBoekToe(b1);
	Boek b2 = Boek("Tolstoy", "Oorlog en vrede", NietUitgeleend);
	bib.voegBoekToe(b2);

	Lid& j = bib.geefLid("Jaap");
	j.leenBoek(bib,b1);

	bib.haalBoekenOp("boeken.csv");
	bib.haalLedenOp("leden.csv");
	cout << "Boeken na alle handelingen: \n";
	bib.geefInfoBoeken();
	cout << "\n\nLeden na alle handelingne: \n";
	bib.geefInfoLeden();

	return 0;
}