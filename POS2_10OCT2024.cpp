#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
//structura
//pointeri
//vectori
//transmiterea unui vector ca parametru
//citirea unui vector


struct Tara {
	char* denumire;
	int nrLocuitori;
	string capitala;
	bool areIesireLaMare;
};

void afisasareTara(Tara tara) {

}

void afisarePointerLaTara(Tara* pt) {
	cout << "Nume:" << pt->denumire << endl;
	cout << "Numar locuitori:" << pt->nrLocuitori << endl;
	cout << "Capitala:" << pt->capitala << endl;
	cout << "Are iesire la mare:" << (pt->areIesireLaMare ? "DA" : "NU") << endl;
}

Tara* citirePointerLaTara() {
	Tara* p = new Tara();
	cout << "Capitala:";
	cin >> p->capitala;

	cout << "Denumire:";
	char buffer[100];
	cin >> buffer;
	p->denumire = new char[strlen(buffer) + 1];
	strcpy_s(p->denumire, strlen(buffer) + 1, buffer);

	cout << "Numar locuiitori:";
	cin >> p->nrLocuitori;

	cout << "Are iesire la mare? (0 - NU; 1 - DA) ";
	cin >> p->areIesireLaMare;

	return p;
}
int main() 
{
	Tara tara;
	tara.areIesireLaMare = false;

	Tara* pTara;
	pTara = new Tara();
	pTara->areIesireLaMare = true;
	pTara->capitala = "Bucuresti";
	pTara->denumire = new char[strlen("Romania") + 1];
	//shallow copy = atr. adrese , nu informatii
	strcpy_s(pTara->denumire, strlen("Romania") + 1, "Romania");
	pTara->nrLocuitori = 200;

	afisarePointerLaTara(pTara);

	//Tara* p2Tara = citirePointerLaTara();
	//afisarePointerLaTara(p2Tara);

	//alocare dinamica

	Tara *vector;
	vector = new Tara[2];

	//vector de pointeri
	int nrPointeri = 2;
	Tara** pointeri;
	pointeri = new Tara * [2];
	pointeri = new Tara * [nrPointeri];
	for (int i = 0; i < nrPointeri; i++) {
		pointeri[i] = citirePointerLaTara();

	}

	//procesare

	for (int i = 0; i < nrPointeri; i++)
	{
		afisarePointerLaTara(pointeri[i]);
	}
}