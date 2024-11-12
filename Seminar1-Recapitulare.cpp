//#include<iostream>
//using namespace std;
//
//struct coordonategps
//{
//	int latitudine, longitudine;
//	float altitudine;
//	string locatie;
//};
//
//void afisarecoordonategps(coordonategps l)
//{
//	cout << "Latitudine: " << l.latitudine << endl;
//	cout << "Longitudine: " << l.longitudine << endl;
//	cout << "Altitudine: " << l.altitudine << endl;
//	cout << "Locatie: " << l.locatie << endl;
//}
// 
// Aici avem o structura si afisare.
//
//void modificareAltitudine(coordonategps* l, float nouaaltitudine)
//{
//	l->altitudine = nouaaltitudine; //-> este deferentiere+accesare
//}
//
//void modificaAltitudineRef(coordonategps& l, float nouaaltitudine)
//{
//	l.altitudine = nouaaltitudine;
//}
//
//coordonategps initializare(int latitudine, int longitudine, float altitudine, string locatie)
//{
//	coordonategps l;
//	l.latitudine = latitudine;
//	l.longitudine = longitudine;
//	l.altitudine = altitudine;
//	l.locatie = locatie;
//	return l;
//}
//
//int main()
//{
//	afisarecoordonategps(l);
//
//	coordonategps l2;
//	cout << "Introduceti latitudinea: ";
//	cin >> l2.latitudine;
//	cout << "Introduceti longitudinea: ";
//	cin >> l2.longitudine;
//	cout << "Introduceti altitudinea: ";
//	cin >> l2.altitudine;
//	cout << "Introduceti locatia: ";
//	cin >> l2.locatie;
//	afisarecoordonategps(l2);
//
//	modificareAltitudine(&l2, -20);
//
//	modificaAltitudineRef(l2, 3000);
//
//	afisarecoordonategps(l2);
//
//
//
//
//	return 0;
//}

#include <iostream>
using namespace std;

//Structura se scrie in afara main-ului.

struct Pix {
	float dimensiune;
	string marca,culoare;
	int id;
};

//Aceasta este functia pentru afisare, in antetul ei se regaseste variabila de tip Pix.
void afisarePix(Pix p){
	cout << "Dimensiune: " << p.dimensiune << "mm" << endl;
	cout << "Marca: " << p.marca << endl;
	cout << "Culoare: " << p.culoare << endl;
	cout << "Id: " << p.id << endl;

	cout << '\n' << '\n';
}

void modificareCuloare(Pix* p, string nouaCuloare) {
	p->culoare = nouaCuloare; // Dereferentiere + Accesare cu "->"
}

void afisareCuloarePix(Pix p) {
	cout << "Culoarea pixului p este: " << p.culoare << endl << endl;
}
Pix initializarePix(float dimensiune, string marca, string culoare) {
	static int idgen = 1;
	Pix p;
	p.dimensiune = dimensiune;
	p.marca = marca;
	p.culoare = culoare;
	p.id = idgen;
	idgen++;

	return p;
}

int main() {

	Pix p1;
	/*cout << "Introduceti dimensiunea pixului: "; cin >> p1.dimensiune;
	cout << "Introduceti marca pixului: "; cin >> p1.marca;
	cout << "Introduceti culoarea pixului: "; cin >> p1.culoare;

	afisarePix(p1);
	modificareCuloare(&p1, "Albastru");
	afisarePix(p1);*/

	Pix p2 = initializarePix(0.8, "Schneider", "Negru");
	Pix p3 = initializarePix(1, "Bic", "Negru");
	Pix p4 = initializarePix(0.2, "Auchan", "Verde");
	afisarePix(p2);
	modificareCuloare(&p2, "Albastru");
	afisareCuloarePix(p2);
	afisarePix(p3);
	afisarePix(p4);

	return 0;

	/*11.11.2024, ora 12:16
		Am trecut prin tot seminarul 1 in aprox. 30 min.*/
	 
}

