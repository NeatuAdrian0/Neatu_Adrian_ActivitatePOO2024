#include <iostream>
#include <fstream>
#include <map>
using namespace std;


int main() {
	map<int, float> valori;
	valori.insert(pair<int, float>(7, 75.8));
	valori.insert(pair<int, float>(23, 102.6));
	valori.insert(pair<int, float>(3, 32.3));

	//cheia e primul nr.

	valori[12] = 45.5;//nu avem cheie, deci o creaza automat si o insereaza.

	cout << valori[12];
}