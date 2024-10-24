#include <iostream>

using namespace std;

class Masina {
private:
	int nrRoti;
	string marca;
	float pret;
	string* producatori;
	static int TVA;
	const int anFabricatie; //atrb apartinand obiectului , se definesc prin constructor;
public:

	Masina() :anFabricatie(2024), nrRoti(4) {
		this->marca = "Dacia";
		this->pret = 5000;
		producatori = NULL;
		this->producatori = new string[this->nrRoti];
		for (int i = 0; i < this->nrRoti; i++)
			this->producatori[i] = "Michelin";
	}
	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
		nrRoti = _nrRoti;
		this->marca = marca; //this se pune pt a face distinctia dintre 1.atribut 2.parametru , daca avem acelasi nume folosim this pt a nu se condfunda
		this->pret = pret; 
		for (int i = 0; i < this->nrRoti; i++)
			this->producatori[i] = "Michelin";

	}
	string getMarca() {
		return this->marca;
	}
	void setMarca(string marca) {
		if (marca.length() > 2)
			this->marca = marca;
	}
	float getPret() {
		return this->pret;
	}
	void setPret(float pret)
	{
		if (pret > 0)
			this->pret = pret;
	}
	string* getProducatori() {
		return this->producatori;
	}

	string getProducatori(int index) {
		if (index >= 0 && index < this->nrRoti)
			return this->producatori[index];
	}
	void setNrRoti(int nrRoti, string* producatori) {
		if (nrRoti > 0) {
			this->nrRoti = nrRoti;
			if (this->producatori != NULL) {
				delete[]this->producatori;
			}
			this->producatori = new string[nrRoti];
			for (int i = 0; i < nrRoti; i++) {
				this->producatori[i] = producatori[i];
			}
		}
	}
	void afisare() {
		cout << endl;
		cout << "Marca: " << this->marca << endl;
		cout << "nrRoti: " << this->nrRoti << endl;
		if(this->producatori !=NULL)
		for (int i = 0; i < this->nrRoti; i++) {
			cout << this->producatori[i] << ", ";
		}
		cout << "Pret: " << this->pret << endl;
		cout << "TVA: " << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;

	}
	//nu trebuie parametri pt ca avem this
	float calculeazaPretTotal() {

		return this->pret + (this->pret * (Masina::TVA) / 100.0f);
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0)
			Masina::TVA = noulTVA;
	}
};



int Masina::TVA = 19;


int main() {
	Masina m;
	cout << m.getMarca() << endl;
	m.setMarca("Audi");
	cout << m.getMarca() << endl;
	//m.afisare();

	Masina m2(4, "BMW", 45000, 2021);
	//m2.afisare();
	cout << endl << endl;
	cout << m2.getProducatori()[1]<< endl;
	cout << m2.getProducatori(1);

	m2.setNrRoti(6,new string[6]{"m","c","b","h","p"});
	cout << m2.getProducatori();
}