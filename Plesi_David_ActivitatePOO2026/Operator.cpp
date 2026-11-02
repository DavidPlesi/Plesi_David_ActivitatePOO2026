#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Avion {
	char* model;
	string* companie;
	int nrPasageri;
	float viteza;
	bool militar;

	const int idAvion;
	static int contor;

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
};