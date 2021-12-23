#include <iostream>
#include "Person.h"
using namespace std;
int main()
{
	try {
		person Adam("Adam", Gender::male); //первый человек
		person Eva("Eva", Gender::female); //второй человек
		person Kein = Eva.GiveBirth("Kein", Gender::male, Adam);
		person Avel = Eva.GiveBirth("Avel", Gender::male, Adam);
		person Azura = Eva.GiveBirth("Azura", Gender::female, Adam);
		person Enos = Azura.GiveBirth("Enos", Gender::male); //ребенок без отца
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
		person a = Enos.GiveBirth("Son of two fathers", Gender::male); //проверка на беременность Male гендера
	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}
}
