#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Bicicleta;
class Frane {
	int diametruDisc;
	char* marcaFrane;
	bool franeHidraulice;
	bool franePeDisc;
public:
	Frane() {
		this->diametruDisc = 160;
		this->marcaFrane = new char[strlen("Shimano") + 1];
		strcpy(this->marcaFrane, "Shimano");
		this->franeHidraulice = true;
		this->franePeDisc = true;
	}
	Frane(const char* marcaFrane) {
		this->diametruDisc = 160;
		this->marcaFrane = new char[strlen(marcaFrane) + 1];
		strcpy(this->marcaFrane, marcaFrane);
		this->franeHidraulice = true;
		this->franePeDisc = true;
	}
	Frane(const Frane& f) {
		this->diametruDisc = f.diametruDisc;
		this->marcaFrane = new char[strlen(f.marcaFrane) + 1];
		strcpy(this->marcaFrane, f.marcaFrane);
		this->franeHidraulice = f.franeHidraulice;
		this->franePeDisc = f.franePeDisc;
	}
	~Frane();//declarare destructor
	friend int operator+(Bicicleta& b, Frane& f);
};
Frane::~Frane() {//destructor
	delete[]this->marcaFrane;
}
class Bicicleta {
	int nrFoi;
	int diametruRotii;
	int nrViteze;
	char* producator;
	bool electrica;
	Frane frane;//relatia has a , bicicleta are frane
public:
	Bicicleta() {
		this->nrFoi = 2;
		this->diametruRotii = 29;
		this->nrViteze = 9;
		this->producator = new char[strlen("Decathlon") + 1];
		strcpy(this->producator, "Decathlon");
		this->electrica = false;
	}
	Bicicleta(const char* producator) {
		this->nrFoi = 2;
		this->diametruRotii = 29;
		this->nrViteze = 9;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->electrica = false;
	}
	Bicicleta(const Bicicleta& b) {
		this->nrFoi = b.nrFoi;
		this->diametruRotii = b.diametruRotii;
		this->nrViteze = b.nrViteze;
		this->producator = new char[strlen(b.producator) + 1];
		strcpy(this->producator, b.producator);
		this->electrica = b.electrica;
	}
	~Bicicleta();//declarare destructor
	//operatori
	friend int operator+(Bicicleta& b, Frane& f) {
		return b.nrFoi + f.diametruDisc;
	}
	Bicicleta operator++() {//forma prefixata ++a
		this->nrViteze++;
		return *this;
	}
	Bicicleta operator++(int) {//forma postfixata
		Bicicleta copie = *this;//face copie la val initiala
		this->nrViteze++;//incrementeaza 
		return copie; // returneaza copia val initiale , neincrementata
	}
};
Bicicleta::~Bicicleta() {
	delete[]this->producator;
}

void main() {

}