#include <iostream>
#include <fstream>
using namespace std;


class Cofetarie {
protected:
		string denumire;

public:
		Cofetarie() {
			this->denumire = "Cofetarie";
		}
		virtual string getDenumire() {
			return denumire;
		}

};


class CofetarieOnline :public Cofetarie {
public:
	string getDenumire() {
		return denumire + " online";
	}
};

int main() {
	Cofetarie* cof = new CofetarieOnline();

	cout << cof->getDenumire();
	int a;
	fstream f("fisier.dat", ios::out | ios::binary);
	f.write((char*)&a, sizeof(a));
	f.close();
	return 0;
}