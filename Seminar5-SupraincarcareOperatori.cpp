/*
 OPERATORI BINARI:

• Operatori aritmetici : +, -, *, / , %;
• Operatori de atribuire compusa : +=, -=, *=, /=, %=;
• Operatori pentru comparatie(sau relationali) : <, <= , >, >= , == , != ;
• Operatori logici : || , &&;
• Alti operatori.
*/

#include <iostream>
using namespace std;

class Parfum {
private:
	
	string marca;
	char* model;
	float pret;
	const int cantitate;
	bool reincarcabil;

public:

	// Constructor implicit 

	Parfum() : cantitate(125) {
		this->marca = "Dior";
		this->model = new char[strlen("Sauvage") + 1];
		strcpy_s(this->model, strlen("Sauvage") + 1, "Sauvage");
		this->pret = 600;
		this->reincarcabil = true;
	}

	//Constructor cu parametrii

	Parfum(string marca, const char* model, float pret, const int cantitate,bool reincarcabil) : cantitate(cantitate) {
		this->marca = marca;
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
		this->pret = pret;
		this->reincarcabil = reincarcabil;
	}

	//Destructor

	~Parfum() {
		//cout << "Destructorul a fost apelat.";
		delete[]model;
	}

	//Constructor de copiere

	Parfum(const Parfum& copie) : cantitate(copie.cantitate) {
		this->marca = copie.marca;
		this->pret = copie.pret;
		this->reincarcabil = reincarcabil;
		this->model = new char[strlen(copie.model) + 1];
		strcpy_s(this->model, strlen(copie.model) + 1, copie.model);
	}

	// Getteri

	string getMarca() {
		return this->marca;
	}
	char* getModel() {
		return this->model;
	}
	float getPret() {
		return this->pret;
	}
	const int getCantitate(){
		return this->cantitate;
	}

	// Setteri

	void setMarca(string marca) {
		if (marca.length() > 0)
			this->marca = marca;
	}
	void setModel(char* model) {
		if (strlen(model) > 0) {
			if (model != nullptr) {
				delete[] this->model;
			} 
				this->model = new char[strlen(model) + 1];

				strcpy_s(this->model, strlen(model) + 1, model);
		}
	}
	void setPret(float pret) {
		if (pret > 0)
			this->pret = pret;
	}


	void afisare() {
		cout << "Marca: " << this->marca << endl;
		cout << "Model: " << this->model << endl;
		cout << "Pret: " << this->pret << " RON" << endl;
		cout << "Cantitate: " << this->cantitate << " ml" << endl;
		cout << "Reincarcabil?: " << this->reincarcabil << endl;
	}

	// Operatori

	Parfum operator+(const Parfum& p) const{
		Parfum temp = *this;
		temp.pret = this->pret + p.pret;
		temp.marca = this->marca + p.marca;
		return temp;
	}
	Parfum& operator=(const Parfum& other) {
		if (this != &other) {
			this->marca = other.marca;
			this->pret = other.pret;

			// Eliberam memoria existenta pentru model
			delete[] this->model;

			// Alocam si copiem noul model
			this->model = new char[strlen(other.model) + 1];
			strcpy_s(this->model, strlen(other.model) + 1, other.model);
		}
		return *this;
	}

	Parfum operator+(float adaosPret) const{
		Parfum temp = *this;
		temp.pret += adaosPret;
		return *this;

	}
	Parfum operator+=(float adaosPret) {
		this->pret += adaosPret;
		return *this;
	}
	Parfum operator+=(Parfum p) {
				this->pret = this->pret + p.pret;
				return *this;
			}
	bool operator<(Parfum p) {
		return this->pret < p.pret;
	}
	bool operator>(Parfum p) {
		return this->pret > p.pret;
	}
	Parfum operator!() const {
		return Parfum(this->marca, this->model, this->pret, this->cantitate, !this->reincarcabil);
	}

	friend istream& operator>>(istream& input, Parfum& p) {
		cout << "Marca:";
		input >> p.marca;
		cout << "Pret: ";
		input >> p.pret;
		cout << "Reincarcabil: ";
		input >> p.reincarcabil;

		return input;
	}
	friend ostream& operator<<(ostream& output, Parfum p);
};

ostream& operator<<(ostream& output, Parfum& p) {
	output << p.pret;
	output << p.cantitate;
	output << p.reincarcabil;
	output << p.marca;
	output << p.model;
	return output;
}
int main() {

	Parfum p1;
	p1.afisare();

	Parfum p2 = Parfum("Jean Paul Gaultier", "Le Male", 629, 125,true);
	p2.afisare();

	p1 = p1 + p2;
	cout << p1.getPret() << endl << p1.getMarca() << endl;

	p2 += 2000;;
	cout << p2.getPret() << endl;

	p2 += p1;
	cout << p2.getPret() << endl;

	/*if (p1 < p2) cout << "p1 e mai ieftin ca p2'\n'";
	if (p1 > p2) cout << "p1 e mai scump ca p2'\n'";
	else cout << "p1 nu e mai scump ca p2'\n'";*/

	Parfum p3 = !p1;
	p3.afisare();

	Parfum p4;
	//cin >> p4;

	cout << p4;







}