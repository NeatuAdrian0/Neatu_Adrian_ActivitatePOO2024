#include <iostream>

using namespace std;

class Masina {
public:
	int nrRoti;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie; //atrb apartinand obiectului , se definesc prin constructor;

	Masina():anFabricatie(2024),nrRoti(4) {
		this->marca = "Dacia";
		this->pret = 5000;
	}
	Masina(int _nrRoti, string marca, float pret, int an):anFabricatie(an) {
		nrRoti = _nrRoti;
		this->marca = marca; //this se pune pt a face distinctia dintre 1.atribut 2.parametru , daca avem acelasi nume folosim this pt a nu se condfunda
		this->pret = pret;
		
	}
	void afisare() {
		cout << endl;
		cout << "Marca: " << this->marca << endl;
		cout << "nrRoti: " << this->nrRoti << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "TVA: " << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;
	}
	//nu trebuie parametri pt ca avem this
	float calculeazaPretTotal() {

		return this->pret + (this->pret * (Masina::TVA) / 100.0f);
	}
	static void modificaTVA(int noulTVA) {
		if(noulTVA>0)
		Masina::TVA = noulTVA;
	}
};



int Masina::TVA = 19;


int main() {

	Masina m1;
	m1.afisare();

	Masina m2(4, "Audi", 7000, 2020);
	m2.afisare();

	Masina::modificaTVA(-21);

	Masina* pointer = new Masina(6, "Volvo", 20000, 2022);
	pointer->afisare();

	int nrMasini = 3;
	Masina* vector;
	vector = new Masina[nrMasini];

	for (int i = 0; i < nrMasini; i++) {
		vector[i].afisare();
	}
	//-> - dereferentiere + accesare
	//[] - deplasare + dereferentiere
	cout << "Pret total: " << pointer->calculeazaPretTotal();
	return 0;
}