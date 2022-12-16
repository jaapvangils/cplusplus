#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string naam;

public:
	Person(string name) { // constructor
		this->setName(naam);
	}
//	Person(sring name) : name(name); // alternatief constructor
	Person() = default; //alternatief constructor
	string& getName() {
		return naam;
	}
	void setName(string& naam) {
		this->naam = naam;
	}
	virtual void showInfo() = 0; // persoon is abstract geworden door aanwezigheid van 1 regel met virtual!
};

class Employee : public Person { // class afgeleid van Person. Onderdelen van Person zijn ook te gebruiken
private:
	double salary;
	static constexpr double maxSalary = 4000; // statische constanten en functies horen op de classe.

public:
	Employee(string name, double salary) {
		setName(name);
		this->setSalary(salary);
	}
	double getSalary() {
		return salary;
	}
	void setSalary(double salary) {
		if (salary > maxSalary) {
			salary = maxSalary;
		}
		this -> salary = salary;
	}
	void showInfo() override { // zorgen dat override is, dus de bovenliggende classe wordt overschreven.
		cout << getName() << " , " << getSalary() << endl;
	}
	void showInfo(string naam) { // overloading - zelfde naam met functie met andere aanroep. Systeem herkent dit
		cout << naam << " , " << getSalary() << endl;
	}
};

class Manager : public Employee {
	double budget;

public: 
	Manager(string name, double salary, double budget) : Employee(name, salary), budget(budget) {}
	double getBudget() {
		return budget;
	}
	void setBurget(double budget) {
		this->budget = budget;
	}
	void showInfo() override { // zorgen dat override is, dus de bovenliggende classe wordt overschreven.
		cout << getName() << " , " << getSalary() << " , " << getBudget() << endl;
	}
};

int main() {
	// niet nodig als er een constructor is: Person* p1 = new Person(); // op de hyp plaatsen: person=pointer, synthesized constructor
	//Person p1;
	//Person p2 = person("Hans");
	//Person p3{ "Leonie" }; //sneller
	//Person p4("Peter"); //sneller
	//Person* p5 = &Person("Joke"); // persoon p5 als pointer naar adres &Person("Joke") op de stack
	//Person *p6 = &Person("Willem"); // zelfde als p5
	//Person& p7 = p1; // reference naar p1 = ALIAS

	//cout << "adres naar pointer: " << p1 << endl;
	//cout << p1->getName() << endl;
	//delete p1;
	//p1 = nullptr;

	Employee e1("Erik", 2000);
	Manager m1("Hans-Daniel", 6000, 65000);
	e1.showInfo("Willem");
	m1.showInfo();

	//polymorphism
	Employee e2("Irene", 1763);
	Person& p1 = e2; // virtuele persoon gekoppeld aan E2.
	p1.showInfo();
	Manager m2("Martin", 5000, 500'000);
	Person& p2 = m2;
	p2.showInfo();

	return 0;
}