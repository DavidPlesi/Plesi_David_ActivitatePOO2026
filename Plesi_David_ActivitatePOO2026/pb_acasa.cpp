#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

class examenSpaniola {
public:
	char* denumire;
	float pret;
	int nrCategorii;
	int nrNivele;
	string* categorii;
	string* nivele;
	bool promovat;

	examenSpaniola() {
		this->denumire = new char[strlen("DELE") + 1];
		strcpy(denumire, "DELE");
		this->pret = 650;
		this->promovat = true;

		this->nrCategorii = 4;
		this->categorii = new string[nrCategorii];
		this->categorii[0] = "writing";
		this->categorii[1] = "reading";
		this->categorii[2] = "listening";
		this->categorii[3] = "speaking";

		this->nrNivele = 5;
		this->nivele = new string[nrNivele];
		this->nivele[0] = "A1";
		this->nivele[1] = "A2";
		this->nivele[2] = "B1";
		this->nivele[3] = "B2";
		this->nivele[4] = "C1";

	}
	void afisare() {
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret: " << this->pret << " lei" << endl;
		cout << "Nr categorii: " << this->nrCategorii << endl;
		cout << "Categoriile sunt: " << endl;
		for (int i = 0;i < nrCategorii;i++) {
			cout << categorii[i] << " ";
		}
		cout << endl;
		cout << "Nr nivele: " << this->nrNivele << endl;
		cout << "Nivelele sunt: " << endl;
		for(int j = 0;j < nrNivele;j++) {
			cout << nivele[j] << " ";
		}
		cout << endl << "Promovat: " << (this->promovat ? "Da" : "Nu");
	}

};

int main() {
	examenSpaniola e;
	e.afisare();
	return 0;
}