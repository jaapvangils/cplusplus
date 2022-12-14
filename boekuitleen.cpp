#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Boekstatus {Uitgeleend, Teruggebracht, Kapot};

typedef struct Boek {
    string Auteur;
    string Titel;
    Boekstatus uitgeleend;
} Boek;

typedef struct Lid {
    string Naam;
    int LidNr;
} Lid;

void voegBoekToe(string boek, string schrijver, vector<Boek>& boeken) {
    Boek b = { schrijver, boek, Teruggebracht };
    boeken.push_back(b);
}

void voegLidToe(string naam, vector<Lid>& leden) {
    Lid l = { naam, leden.size()+1 };
    leden.push_back(l);

}

void leenBoekUit(string auteur, string titel,  vector<Boek>& boeken) {
    for (auto& b : boeken) {
        if (auteur == b.Auteur && titel == b.Titel) {
            b.uitgeleend = Uitgeleend;
        }
    }
}
//void krijgBoekTerug()


int main()
{
    vector<Lid> leden = {{"Andre",1},{"Martin",2}, {"Jaap",3}};
    vector<Boek> boeken = { 
        {"Piet", "Oorlog", Teruggebracht },
        { "Roosendaal", "Vrede", Teruggebracht },
        {"Marqeus","Duizend jaar eenzaamheid", Kapot } 
    };
    voegLidToe("Willem", leden);
    for (auto& l : leden) {
        cout << l.Naam << "," << l.LidNr << endl;
    }
    for (auto& b : boeken) {
        cout << b.Auteur << "," << b.Titel << ", uitgeleend: " << b.uitgeleend << endl;
    }
    cout << "\nNa Leen boek uit:\n";
    leenBoekUit("Piet", "Oorlog", boeken);
    for (auto& b : boeken) {
        cout << b.Auteur << "," << b.Titel << ", uitgeleend: " << b.uitgeleend << endl;
    }
    voegBoekToe("Koch", "Diner", boeken);
    cout << "\n Koch er bij : \n\n";
        for (auto& b : boeken) {
            cout << b.Auteur << "," << b.Titel << ", uitgeleend: " << b.uitgeleend << endl;
        }

}
