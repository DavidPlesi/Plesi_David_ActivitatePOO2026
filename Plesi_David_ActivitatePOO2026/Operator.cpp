#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
//clasa
class Avion {
	char* model;
	string* companie;
	int nrPasageri;
	float viteza;
	bool militar;

	const int idAvion;
	inline static int contor = 114;
	//constructor

public:
	Avion() :idAvion(contor++) {
		this->model = new char[strlen("Boeing737-800") + 1];
		strcpy(this->model, "Boeing737");
		this->companie = new string[2];
		this->companie[0] = "Austrian ";
		this->companie[1] = "Airlines";
		this->nrPasageri = 189;
		this->viteza = 838;
		this->militar = false;
	}
	//constructor de copiere
	Avion(const Avion& a) :idAvion(contor++) {
		this->model = new char[strlen(a.model) + 1];
		strcpy(this->model, a.model);
		this->companie = new string[2];
		for (int i = 0;i < 2;i++) {
			this->companie[i] = a.companie[i];
		}
		this->nrPasageri = a.nrPasageri;
		this->viteza = a.viteza;
		this->militar = a.militar;
	}
	//operator=
	Avion& operator=(Avion& A) {
		if (this != &A) {
			if (this->model != NULL) 
				delete[]this->model;
			this->model = new char[strlen(A.model) + 1];
			strcpy(this->model, A.model);
			this->companie = new string[2];
			for (int i = 0;i < 2;i++) {
				this->companie[i] = A.companie[i];
			}
			this->nrPasageri = A.nrPasageri;
			this->viteza = A.viteza;
			this->militar = A.militar;
		}
		return *this;
	}
	//getterii

	int getNrPasageri() {
		return this->nrPasageri;
	}
	float getViteza() {
		return this->viteza;
	}
	string* getCompanie() {
		return this->companie;
	}
	char* getModel() {
		return this->model;
	}
	bool getMilitar() {
		return this->militar;
	}
	//folosesc operatorul=
	
};

int main() {
	Avion a1;
	Avion a2;
	a2 = a1;
	cout << "Nr Pasageri: " << a2.getNrPasageri();
}