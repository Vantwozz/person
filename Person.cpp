#include <iostream>
#include "Person.h"
using namespace std;
int main()
{
	try {
		person Adam("Adam", Gender::male);
		person Eva("Eva", Gender::female);
		person Kein = Eva.GiveBirth("Kein", Gender::male, Adam);
		person Avel = Eva.GiveBirth("Avel", Gender::male, Adam);
		person Azura = Eva.GiveBirth("Azura", Gender::female, Adam);
		person Enos = Azura.GiveBirth("Enos", Gender::male);
		Adam.print();
		cout << endl;
		Eva.print();
		cout << endl;
		Kein.print();
		cout << endl;
		Avel.print();
		cout << endl;
		Azura.print();
		cout << endl;
		Enos.print();
		cout << endl;
		person a = Enos.GiveBirth("Son of two fathers", Gender::male);
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
}