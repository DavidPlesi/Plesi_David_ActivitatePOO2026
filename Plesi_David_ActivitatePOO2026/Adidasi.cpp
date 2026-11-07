#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Adidasi {
	float marime;
	float pret;
	string* detalii;// culoare , marca , material;
	int nrDetalii;
	bool deOras;

public:
	Adidasi() {
		this->marime = 44.5;
		this->pret = 300;
		this->nrDetalii = 3;
		this->deOras = true;
		this->detalii = new string[this->nrDetalii];
		this->detalii[0] = "Albastrii";
		this->detalii[1] = "Nike";
		this->detalii[2] = "Sintetic";
	}
	Adidasi(const float marime) {
		this->marime = marime;
		this->pret = 300;
		this->nrDetalii = 3;
		this->deOras = true;
		this->detalii = new string[this->nrDetalii];
		this->detalii[0] = "Albastrii";
		this->detalii[1] = "Nike";
		this->detalii[2] = "Sintetic";
	}
	Adidasi(const Adidasi& a) {
		this->marime = a.marime;
		this->pret = a.pret;
		this->nrDetalii = a.nrDetalii;
		this->deOras = a.deOras;
		this->detalii = new string[this->nrDetalii];
		for (int i = 0;i < nrDetalii;i++) {
			this->detalii[i] = a.detalii[i];
		}
	}

	~Adidasi();//declarare destructor

	//operatori

	//operator functie

	float operator()(float TVA) {
		return this->pret + (TVA * this->pret);
	}

	//o functie friend in interiorul clasei , nu mai primeste pointerul this
	friend istream& operator>>(istream& i, Adidasi& a) {
		float pret;
		i >> a.pret;
		return i;
	}
	friend ostream& operator<<(ostream& o,const Adidasi& a) {
		o << a.pret;
		return o;
	}
};

Adidasi::~Adidasi() {//implementare destructor
	delete[]this->detalii;
}

void main() {
	Adidasi a;
	cout << "Pret + TVA: " << a(0.21f);

}