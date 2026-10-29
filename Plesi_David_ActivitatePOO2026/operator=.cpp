#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Masina {
public:
	char* denumire;
	float rulaj;
	bool manuala;
	int nrLocuri;
	int caiPutere;
	const int idMasina;//id ul e constant , pt ca nu vrem sa il modificam 
	static int contor;//contorul este static , adica este acelasi de fiecare data cand e apelat constructorul Masina

	Masina(): idMasina(contor++){
		this->denumire = new char[strlen("Fiat Punto") + 1];
		strcpy(denumire, "Fiat Punto");
		this->rulaj = 100000;
		this->manuala = true;
		this->nrLocuri = 5;
		this->caiPutere = 120;
	}
	Masina& operator=(const Masina& m) {//punem & la Masina pt a indica ca tipul returnat va fi o referinta catre obiectul original , nu o copie a lui. 
		//punem & la Masina in interiorul () pt a indica ca nu creem o copie noua a obiectului "m" ,
		//ci primeste o referinta direct catre obiectul original "m" aflat in memorie.
		if (this != &m) {
			if (this->denumire != NULL) {
				delete[]this->denumire;
			}
			this->denumire = new char[strlen(m.denumire) + 1];
			strcpy(this->denumire, m.denumire);
			this->rulaj = m.rulaj;
			this->manuala = m.manuala;
			this->nrLocuri = m.nrLocuri;
			this->caiPutere = m.caiPutere;
		}
		return *this;
	}
	Masina operator+(const Masina& m1) {//pun & la tipul obiectului m1 (la Masina) pentru a nu crea o copie noua a obiectului m1
		Masina rezultat;
		rezultat.caiPutere = this->caiPutere + m1.caiPutere;
		rezultat.rulaj = this->rulaj + m1.rulaj;
		return rezultat;
	}
	};

int main() {
	Masina m;
}