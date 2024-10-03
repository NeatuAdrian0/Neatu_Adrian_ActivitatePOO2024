#include <iostream>
using namespace std;

struct CoordonateGPS
{
		int latitudine;
		int longitudine;
		float altitudine;
		string locatie;

};
void afisarecoordonateGPS(CoordonateGPS l)
{
	cout << "Latitudine " << l.latitudine << endl;
	cout << "Longitudine " << l.longitudine << endl;
	cout << "Altitudine " << l.altitudine << endl;
	cout << l.locatie;
}

void modificaAltitudine(CoordonateGPS *l, float nouaAltitudine)
{
	l->altitudine = nouaAltitudine; //-> dereferentiere + Accesare
}

void modificaAltitudineRef(CoordonateGPS& l, float nouaAltitudine) {


}
int main()
{
	CoordonateGPS l;
	l.latitudine = 46;
	l.longitudine = 22;
	l.altitudine = 1010;
	l.locatie = "Predeal";

	afisarecoordonateGPS(l);

	CoordonateGPS l2;



	cout << "Introduceti latitudinea: "; cin >> l2.latitudine;
	cout << "Introduceti longitudine: "; cin >> l2.longitudine;
	cout << "Introduceti altitudinea: "; cin >> l2.altitudine;
	cout << "Introduceti locatia: "; cin >> l2.locatie;

	modificaAltitudine(&l2, 2000);
	afisarecoordonateGPS(l2);



	return 0;
}