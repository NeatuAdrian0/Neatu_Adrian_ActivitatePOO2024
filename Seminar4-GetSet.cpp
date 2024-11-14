//#include<iostream>
//
//using namespace std;
//
//class Masina {
//private:
//	int nrRoti;
//	string* producatori;
//	string marca;
//	float pret;
//	static int TVA;
//	const int anFabricatie;
//public:
//	Masina() :anFabricatie(2024), nrRoti(4) {
//		this->marca = "Dacia";
//		this->pret = 5000;
//		this->producatori = NULL;
//	}
//	Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an) {
//		this->nrRoti = _nrRoti;
//		this->marca = marca;
//		this->pret = pret;
//		this->producatori = new string[this->nrRoti];
//		for (int i = 0; i < this->nrRoti; i++) {
//			this->producatori[i] = "Michelin";
//		}
//	}
//	Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
//		this->nrRoti = m.nrRoti;
//		this->marca = m.marca;
//		this->pret = m.pret;
//		this->producatori = new string[m.nrRoti];
//		for (int i = 0; i < m.nrRoti; i++) {
//			this->producatori[i] = m.producatori[i];
//		}
//	}
//
//	~Masina() {
//		if (this->producatori != NULL) {
//			delete[]this->producatori;
//		}
//	}
//
//	string getMarca() {
//		return this->marca;
//	}
//	void setMarca(string marca) {
//		if (marca.length() > 2) {
//			this->marca = marca;
//		}
//	}
//	float getPret() {
//		return this->pret;
//	}
//	void setPret(float pret) {
//		if (pret > 0) {
//			this->pret = pret;
//		}
//	}
//	string* getProducatori() {
//		return this->producatori;
//	}
//
//	string getProducator(int index) {
//		if (index >= 0 && index < this->nrRoti) {
//			return this->producatori[index];
//		}
//		else {
//			return "NU a fost gasit.";
//		}
//	}
//	void setNrRoti(int nrRoti, string* producatori) {
//		if (nrRoti > 0) {
//			this->nrRoti = nrRoti;
//			if (this->producatori != NULL) {
//				delete[]this->producatori;
//			}
//			this->producatori = new string[nrRoti];
//			for (int i = 0; i < nrRoti; i++) {
//				this->producatori[i] = producatori[i];
//			}
//		}
//	}
//
//	void afisare() {
//		cout << "Marca:" << this->marca << endl;
//		cout << "Nr roti:" << this->nrRoti << ": ";
//		if (this->producatori != NULL) {
//			for (int i = 0; i < this->nrRoti; i++) {
//				cout << this->producatori[i] << ", ";
//			}
//		}
//		cout << endl;
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
//	Masina m;
//	cout << m.getMarca() << endl;
//	m.setMarca("Audi");
//	cout << m.getMarca() << endl;
//	m.afisare();
//
//	Masina m2(4, "BMW", 45000, 2021);
//	m2.afisare();
//	cout << endl << endl;
//	cout << m2.getProducatori()[1] << endl;
//	cout << m2.getProducator(1) << endl;
//
//	m2.setNrRoti(6, new string[6]{ "Michelin","Continental","Bridgestone", "Pirelli", "Hankoover", "POO" });
//	cout << m2.getProducator(4) << endl;
//
//	Masina m3(m2);
//	Masina m4 = m2;
//	cout << m4.getProducator(2);
//
//	Masina* vector = new Masina[100];
//	//am lucrat cu ele
//	delete[]vector;
//}

#include <iostream>
using namespace std;

class telefon {
private:
    int refreshRate;
    string marca;
    float pret;
    static int TVA;

public:
    const int anFabricatie;

    
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

  
    telefon(const telefon& copie) : anFabricatie(copie.anFabricatie) {
        this->refreshRate = copie.refreshRate;
        this->marca = copie.marca;
        this->pret = copie.pret;
    }
    
    ~telefon() {
        cout << "Destructorul a fost apelat." << endl;
    }

    
    string getMarca() {
        return this->marca;
    }
    int getRefreshRate() {
        return this->refreshRate;
    }
    float getPret() {
        return this->pret;
    }

   
    void setMarca(string _marca) {
        if (_marca.length() > 0)
            this->marca = _marca;
    }
    void setRefreshRate(int refreshRate) {
        if (refreshRate > 0)
            this->refreshRate = refreshRate;
    }
    void setPret(float pret) {
        if (pret > 0)
            this->pret = pret;
    }

   
    void afisare() {
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
        for (int i = 0; i < nrTelefoane; i++) {
            pretTotal += vector[i].calculeazaPretTotal();
        }
        return pretTotal;
    }
};


int telefon::TVA = 19;

int main() {

	telefon t = telefon();
	t.afisare();
	cout << t.getMarca() << endl << t.getPret() << " RON" << endl << t.getRefreshRate() << " Hz" << endl;
	cout << t.anFabricatie << endl << endl;

	t.setPret(1250);
	t.setMarca("Motorola");
	t.setRefreshRate(75);

	cout << t.getMarca() << endl << t.getPret() << " RON" << endl << t.getRefreshRate() << " Hz" << endl;
	cout << t.anFabricatie << endl;

    //Testam constructorul de copiere:

    telefon t1;
    t1.afisare();

    telefon t1copie = t1;

    cout << "Afisare copie: ";
    t1copie.afisare();
	
	return 0;
}