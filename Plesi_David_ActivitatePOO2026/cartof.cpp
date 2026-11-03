#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Cartof {
	char* taraDeProvenienta;
	float greutate;
	bool dulce;
	int nrCartofi;
public:
	friend istream& operator>>(istream& in, Cartof& c) {
		cout << "Nr de Cartofi Folositi: ";
		in >> c.nrCartofi;
		return in;
	}
	//constructor fara parametrii/implicit
	Cartof() {
		this->taraDeProvenienta = new char[strlen("Spania") + 1];
		strcpy(this->taraDeProvenienta, "Spania");
		this->greutate = 120;
		this->dulce = false;
	}
	//constructor cu parametrii
	Cartof(const char* taraDeProvenienta) {
		this->taraDeProvenienta = new char[strlen(taraDeProvenienta) + 1];
		strcpy(this->taraDeProvenienta, taraDeProvenienta);
		this->greutate = 120;
		this->dulce = false;
	}
	//constructor de copiere primeste o referinta const la un obiect de tipul cartof
	Cartof(const Cartof& C) {
		this->taraDeProvenienta = new char[strlen(C.taraDeProvenienta) + 1];
		strcpy(this->taraDeProvenienta, C.taraDeProvenienta);
		this->greutate = C.greutate;
		this->dulce = C.dulce;
	}
	//getteri
	int getNrCartofi() {
		return this->nrCartofi;
	}
	char* getTaraDeProvenienta() {
		return this->taraDeProvenienta;
	}
	float getGreutate() {
		return this->greutate;
	}
	//destructor
	~Cartof();
};
Cartof::~Cartof() {
	delete[]this->taraDeProvenienta;
}
void calculeazaCantitatePiure(int nrCartofi) {
	cout << "La " << nrCartofi << " cartofi , cantitatea de piure posibila este " << 120 * nrCartofi<<"g";
}

int main() {
	Cartof c;
	cin >> c;
	calculeazaCantitatePiure(c.getNrCartofi());
}