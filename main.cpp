#include <iostream>
#include "bibliotheek.h"
#include "lid.h"

using namespace std;


int main() {
	Bibliotheek bib;
	bib.voegLidToe("Jaap");
	bib.voegLidToe("Martin");

	bib.geefInfoLeden();

	Boek b1 = Boek( "Mulisch", "De aanslag", NietUitgeleend);
	bib.voegBoekToe(b1);
	Boek b2 = Boek("Tolstoy", "Oorlog en vrede", NietUitgeleend);
	bib.voegBoekToe(b2);
	bib.voegBoekToe(Boek("Die Ene", "Het huisje op de prairie", NietUitgeleend));
	bib.geefInfoBoeken();

	Lid& j = bib.geefLid("Jaap");
	j.leenBoek(bib,b1);

	bib.geefInfoBoeken();


	return 0;
}