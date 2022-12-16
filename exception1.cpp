#include <exception>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

// functie met rnd willekeurig getal terug tussen -10 en 40
// in de main roepen we deze in een while loop aan
// Waarde op scherm, behalve bij negatief. Dan: gooien een exceptie
// try staat om de functie heen en catch: informatie over de exceptie en verlaten loop


//int divi(int x, int y) {
//	int r;
//	try {
//		r =  x / y;
//	}
//	catch (exception e) {
//		cout << "Deel niet door 0!/n";
//	}
//	return r;
//}

int generator() {
	int result = (rand() % 50) - 10;
	if (result < 0) {
		cout << result << "!!!!!\n";
		throw exception("Onder nul, daar houden wij niet van!\n");
	}
}

int main() {
	srand(time(0));
	try {
		while (true) {
			cout << "Generator: " << generator() << endl;
			sleep_until(system_clock::now() + seconds(1));
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	//cout << divi(4, 2) << endl;
	//cout << divi(4, 10) << endl;
}