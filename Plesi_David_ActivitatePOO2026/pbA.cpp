#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Burger {
public:
	char* denumire;
	int nrIngrediente;
	int nrCalorii;
	float pret;
	string* ingrediente;

	Burger() {
		this->denumire = new char[strlen("Cheeseburger") + 1];
		strcpy(denumire, "Cheeseburger");
		this->nrIngrediente = 4;
		this->nrCalorii = 1200;
		this->pret = 19.99;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "Chifle";
		this->ingrediente[1] = "Cascaval";
		this->ingrediente[2] = "Carne";
		this->ingrediente[3] = "Ceapa";
	}

	Burger(const Burger& b) {
		this->denumire = new char[strlen(b.denumire) + 1];
		strcpy(denumire, b.denumire);
		this->nrIngrediente = b.nrIngrediente;
		this->nrCalorii = b.nrCalorii;
		this->pret = b.pret;
		this->ingrediente = new string[this->nrIngrediente];
		this->ingrediente[0] = "Chifle";
		this->ingrediente[1] = "Cascaval";
		this->ingrediente[2] = "Carne";
		this->ingrediente[3] = "Ceapa";
		for (int i = 0;i < this->nrIngrediente;i++) {
			this->ingrediente[i] = b.ingrediente[i];
		}
	}
	~Burger();
	void afisare() {
		cout << "Denumire: " << this->denumire << endl;
		cout << "Nr ingrediente: " << this->nrIngrediente << endl;
		for (int i = 0;i < nrIngrediente;i++) {
			cout << ingrediente[i] << " ";
		}
		cout << endl;
		cout << "Nr calorii: " << this->nrCalorii << endl;
		cout << "Pret: " << this->pret << endl;
		
	}
	};

	Burger::~Burger() {//:: inseamna ca functia de dinainte de :: apartine clasei care urmeaza dupa ::
		delete[]this->denumire;
		delete[]this->ingrediente;
	}
	void main() {
		Burger b;
		b.afisare();
	}
