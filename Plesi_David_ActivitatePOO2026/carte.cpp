#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
class Carte;

class Pagina {
	int nrCuvinte;
public:
	Pagina() {
		this->nrCuvinte = 400;
	}
	Pagina(int nrCuvinte) {
		this->nrCuvinte = nrCuvinte;
	}
	Pagina(Pagina& p) {
		this->nrCuvinte = p.nrCuvinte;
	}
	friend istream& operator>>(istream& i, Carte& c);
	friend ostream& operator<<(ostream& o, const Carte& c);
};
class Carte {
	int nrPagini;
	int nrCapitole;
	string* numeAutori;
	int nrAutori;
	bool deCopii;
	Pagina pagina;
public:
	Carte() {
		this->nrAutori = 2;
		this->numeAutori = new string[this->nrAutori];
		this->numeAutori[0] = "Gabriel Garcia Marquez";
		this->numeAutori[1] = "Eligio Garcia Marquez";
		this->nrCapitole = 20;
		this->nrPagini = 300;
		this->deCopii = false;
	}
	Carte(string* numeAutori,int nrAutori) {
		this->nrAutori = nrAutori;
		this->numeAutori = new string[this->nrAutori];
		this->numeAutori[0] = numeAutori[0];
		this->numeAutori[1] = numeAutori[1];
		this->nrCapitole = 20;
		this->nrPagini = 300;
		this->deCopii = false;
	}
	Carte(const Carte& c) {
		this->nrAutori = c.nrAutori;
		this->numeAutori = new string[this->nrAutori];
		for (int i = 0;i < this->nrAutori;i++) {
			this->numeAutori[i] = c.numeAutori[i];
		}
		this->numeAutori[0] = c.numeAutori[0];
		this->numeAutori[1] = c.numeAutori[1];
		this->nrCapitole = c.nrCapitole;
		this->nrPagini = c.nrPagini;
		this->deCopii = c.deCopii;
	}
	~Carte();//declarare destructor'
	//operatori
	friend istream& operator>>(istream& i, Carte& c) {
		cout << "Nr Pagini: ";
		i >> c.nrPagini;
		cout << "Nr cuvinte: ";
		i >> c.pagina.nrCuvinte;
		return i;
	}
	friend ostream& operator<<(ostream& o, const Carte& c) {
		o << "Nr Pagini = " << c.nrPagini << endl;
		o << "Nr Cuvinte Total = " << c.pagina.nrCuvinte * c.nrPagini;
		return o;
	}
};

Carte::~Carte() {//implementare destructor
	delete[]this->numeAutori;
}

void main() {
	Carte c;
	Pagina p;
	cin >> c;
	cout << c;
}