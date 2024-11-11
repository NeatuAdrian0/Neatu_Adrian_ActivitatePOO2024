//
//#include<iostream>
//
//using namespace std;
//
//class Masina {
//public:
//	int nrRoti;
//	string marca;
//	float pret;
//	static int TVA;
//	const int anFabricatie;
//
//	Masina() :anFabricatie(2024), nrRoti(4) {
//		this->marca = "Dacia";
//		this->pret = 5000;
//	}
//	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
//		this->nrRoti = _nrRoti;
//		this->marca = marca;
//		this->pret = pret;
//	}
//
//
//	void afisare() {
//		cout << "Marca:" << this->marca << endl;
//		cout << "Nr roti:" << this->nrRoti << endl;
//		cout << "Pret:" << this->pret << endl;
//		cout << "TVA:" << this->TVA << endl;
//		cout << "An fabricatie:" << this->anFabricatie << endl;
//	}
//
//	float calculeazaPretTotal() {
//		return this->pret + (this->pret * (Masina::TVA / 100.0f));
//	}
//
//	static void modificaTVA(int noulTVA) {
//		if (noulTVA > 0) {
//			Masina::TVA = noulTVA;
//		}
//	}
//
//	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
//		float pretTotal = 0;
//		for (int i = 0; i < nrMasini; i++) {
//			pretTotal += vector[i].calculeazaPretTotal();
//		}
//		return pretTotal;
//	}
//
//};
//
//int Masina::TVA = 19;
//
//int main() {
//	Masina m1;
//	m1.afisare();
//
//	Masina m2(4, "Audi", 7000, 2020);
//	m2.afisare();
//
//	Masina::modificaTVA(21);
//
//	Masina* pointer = new Masina(6, "Volvo", 20000, 2022);
//	pointer->afisare();
//
//	cout << "Pret total:" << pointer->calculeazaPretTotal();
//
//	int nrMasini = 3;
//	Masina* vector;
//	vector = new Masina[nrMasini];
//
//	for (int i = 0; i < nrMasini; i++) {
//		vector[i].afisare();
//	}
//
//	cout << "Pret total flota:" << Masina::calculeazaPretTotalVector(nrMasini, vector) << endl;
//	//-> - dereferentiere + accesare
//	//[] - deplasare + dereferentiere 
//
//	delete[]vector;
//	return 1000;
//}

#include <iostream>
using namespace std;

class telefon {
public:
	int refreshRate;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;

	;

	//constructor implicit (fara parametrii)

	telefon() : anFabricatie(2024) {
		this->marca = "Samsung";
		this->pret = 4250;
		this->refreshRate = 120;
	}

	telefon(int refreshRate, string marca, float pret, int an) : anFabricatie(an) {
		this->refreshRate = refreshRate;
		this->marca = marca;
		this->pret = pret;
	}
	void afisare() {
		telefon t;
		cout << "Marca: " << this->marca << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Refresh Rate: " << this->refreshRate << endl;
		cout << "TVA: " << this->TVA << endl;
		cout << "An Fabricatie: " << this->anFabricatie;
		cout << endl << endl;
	}
	float calculeazaPretTotal() {
		return this->pret + (this->pret * (telefon::TVA / 100.f));
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0)
			telefon::TVA = noulTVA;
	}

	static float calculeazaPretTotalVector(int nrTelefoane, telefon* vector) {
		float pretTotal = 0;
		for(int i=0;i<nrTelefoane;i++)
		{
			pretTotal += vector[i].calculeazaPretTotal();
		}
		return pretTotal;
	}
};

int telefon::TVA = 19;

int main() {

	telefon t1 = telefon(60, "Iphone", 5400, 2022);
	t1.afisare();
	telefon t2 = telefon();
	t2.afisare();
	cout << endl << "Pret total Samsung: " << t2.calculeazaPretTotal() << " RON";

	telefon::modificaTVA(20);
	cout << endl << "Pret total cu noul TVA Samsung: " << t2.calculeazaPretTotal() << " RON";

	telefon* pointer = new telefon(60, "Huawei", 2800, 2024);
	pointer->afisare();
	cout << endl << "Pret total HUAWEI:" << pointer->calculeazaPretTotal();
	cout << endl << endl << endl;


	int nrTelefoane = 3;
	telefon* vector;
	vector = new telefon[nrTelefoane];

	for (int i = 0; i < nrTelefoane; i++) {
		vector[i].afisare();
	}
	cout << "Pret total flota:" << telefon::calculeazaPretTotalVector(nrTelefoane, vector) << endl;

	delete[] vector;

	return 0;
}