#include <iostream>
#include <string>

using namespace std;

class Car {
private:  // bij gebruik protected: kunnen de subclasses er wel bij!
	string type;
	double price;

public: // getters en setters
	//constructor:
	Car(string t, double p) {
		type = t;
		price = p;
	}

	Car() = default; // als je een leeg document wil toestaan

	string getType() {
		return type;
	}
	void setType(string t) {
		type = t;
	}
	double getPrice() {
		return price;
	}
	void setPrice(double p) {
		price = p;
	}
	void showInfo() {
		cout << type << "," << price << endl;
	}
};

class ElectricCar : public Car {
private: 
	double battCap;

public:
	//ElectricCar(string t, double p, double c): {
	//	setType(t);
	//	setPrice(p);
	//	setBattCap(c);
	//}
	ElectricCar(string t, double p, double c) : Car(t, p), battCap(c) {}

	void setBattCap(double c) {
		battCap = c;
	}
	double getBattCap() {
		return battCap;
	}
};

int main() {
	Car c1;
	c1.setType("Golf");
	c1.setPrice(25000);
	c1.showInfo();

	ElectricCar e1("Volvo", 75000,1000);
	e1.showInfo();
}