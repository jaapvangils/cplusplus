#include <iostream>
#include <vector>

/*
Read a set of integers into a vector from the console.
• Calculateand print the sum of each pair of adjacent elements in the vector.
• If the size of the vector is odd, tell the userand print the value of the
last element without summing it.
• Now change your program so that it prints the sum of the firstand
last elements, followed by the sum of the secondand second - to - last and so on
*/

using namespace std;

int main() {
	vector<int> v;
	int getal = 0;
	int teller = 0;
	cout << "geef reeks, -1 voor einde.\n";
	while ( getal != -1 ) {
		teller++;
		cout << teller << ":";
		cin >> getal;
		v.push_back(getal);
	}
	v.pop_back();

	cout << "\nOpgegeven getallen zijn:" << endl;
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		cout <<	*i << " , ";
	}
	
	cout << "\nCalculate and print the sum of each pair of adjacent elements in the vector. \n";
	for (auto i = v.begin(); i != v.end(); i++) {
		if (i + 1 != v.end()) {
			cout << *i + *(i + 1) << " , ";
		}
		else {
			cout << " Odd:" << *i << endl;
		}
	}

	cout << "\nNow change your program so that it prints the sum of the firstand \n last elements, followed by the sum of the secondand second - to - last and so on\n";

	bool doorgaan = true;
	auto alpha = v.begin();
	auto omega = v.end()-1;
	while (doorgaan) {
		cout << *alpha << " + " << *omega << " = " << ( *alpha + *omega ) << endl;
		alpha++;
		if (alpha == omega) {
			doorgaan = false;
		}
		omega--;
		if (alpha == omega) { 
			cout << "odd:" << *alpha; 
			doorgaan = false; 
		}
	}

}
