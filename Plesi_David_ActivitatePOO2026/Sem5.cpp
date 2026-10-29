#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Prajitura {
public:
	char* denumire;
	float pret;
	int cantitate;
	bool dePost;
	int nrIngrediente;
	string* ingrediente;
	const int id;
	static int contor;
public:friend class Student;



	  Prajitura operator+(const Prajitura& p) {//daca transmitem prin referinta treebuie sa fie si constanta
		  Prajitura result = *this;
		  result.pret = this->pret + p.pret;
		  result.cantitate = this->cantitate + p.cantitate;
		  return result;
	  }
	  Prajitura() : id(contor++) {
		  this->denumire = new char[strlen("Tiramisu") + 1];
		  strcpy(denumire, "Tiramisu");
		  this->pret = 15;
		  this->cantitate = 250;
		  this->dePost = true;
		  this->nrIngrediente = 3;
		  this->ingrediente = new string[this->nrIngrediente];
		  this->ingrediente[0] = "piscoturi";
		  this->ingrediente[1] = "vanilie";
		  this->ingrediente[2] = "cafea";
	  }

	  Prajitura(const char* denumire, float pret) : id(contor++) {
		  this->denumire = new char[strlen(denumire) + 1];
		  strcpy(this->denumire, denumire);
		  this->pret = pret;
		  this->cantitate = 250;
		  this->dePost = true;
		  this->nrIngrediente = 3;
		  this->ingrediente = new string[this->nrIngrediente];
		  this->ingrediente[0] = "piscoturi";
		  this->ingrediente[1] = "vanilie";
		  this->ingrediente[2] = "cafea";
	  }

	  Prajitura(const Prajitura& p) :id(contor++) {
		  this->denumire = new char[strlen(p.denumire) + 1];
		  strcpy(this->denumire, p.denumire);

		  this->pret = p.pret;
		  this->cantitate = p.cantitate;
		  this->dePost = p.dePost;
		  this->nrIngrediente = p.nrIngrediente;

		  this->ingrediente = new string[this->nrIngrediente];
		  for (int i = 0; i < this->nrIngrediente;i++) {
			  this->ingrediente[i] = p.ingrediente[i];
		  }
	  }
	  ~Prajitura(); //declarare destructor

	  Prajitura& operator=(const Prajitura& P1) {
		  if (this != &P1)
		  {
			  this->cantitate = P1.cantitate;
			  if (this->denumire != NULL) {
				  delete[]this->denumire;
			  }
			  this->denumire = new char[strlen(P1.denumire) + 1];
			  strcpy(this->denumire, P1.denumire);
			  this->dePost = P1.dePost;
			  this->pret = P1.pret;
			  this->nrIngrediente = P1.nrIngrediente;
			  this->ingrediente = new string[this->nrIngrediente];
			  for (int i = 0;i < P1.nrIngrediente;i++) {
				  this->ingrediente[i] = P1.ingrediente[i];
			  }
		  }
		  return *this;
	  }

	  int getCantitate() {
		  return this->cantitate;
	  }
	  int getNrIngrediente() {
		  return this->nrIngrediente;
	  }
	  int getPret() {
		  return this->pret;
	  }
	  static int getContor() {
		  return contor;
	  }

	  void afisare()
	  {
		  cout << "Denumire: " << this->denumire << endl;
		  cout << "Pret: " << this->pret << endl;
		  cout << "Cantitate: " << this->cantitate << endl;
		  cout << "De Post: " << (this->dePost ? "DA" : "NU") << endl;
		  cout << "Nr ingrediente: " << this->nrIngrediente << endl;
		  cout << "Ingredientele sunt: ";
		  for (int i = 0;i < this->nrIngrediente;i++)
		  {
			  cout << this->ingrediente[i] << "; ";
		  }
		  cout << endl;

	  }
	  float costMediuGram() {
		  if (this->cantitate == 0) {
			  return 0;
		  }
		  else {
			  return this->pret / this->cantitate;
		  }
	  }

	  void modificaDenumire(const char* denumire) {
		  delete this->denumire;

		  this->denumire = new char[strlen(denumire) + 1];
		  strcpy(this->denumire, denumire);
	  }



};
int Prajitura::contor = 100;
Prajitura::~Prajitura() { // implementez destructor
	delete[] this->denumire;
	delete[] this->ingrediente;
}


float calculeazaCantitateTotala(Prajitura* prajituri, int nr_prajituri) {
	float greutate = 0;

	for (int p = 0; p < nr_prajituri; p++)
		greutate += prajituri[p].getCantitate();

	return greutate;
}

float calculeazaPretPerIngredient(Prajitura p) {
	if (p.getNrIngrediente() != 0) {
		return p.getPret() / p.getNrIngrediente();
	}
	return 0;

}

class Student {
private:
	string nume;
	Prajitura prajitura;
public:
	Student() {
		this->nume = "Andrei";
	}
	Student(string nume, Prajitura p) {
		this->nume = nume;
		this->prajitura = p;
	}
	string getNume() {
		return this->nume;
	}
	Prajitura getPrajitura() {
		return this->prajitura;
	}
	void setNume() {
		this->nume = nume;
	}
	void setPrajitura(Prajitura p)//setteri sunt de tip void
	{
		this->prajitura = p;
	}
	float calculeazaNrTotalCalorii(float caloriiPerGram) {
		float nrTotal = caloriiPerGram * this->prajitura.getCantitate();
		return nrTotal;
	}

};
void afiseazaMasa() {
	cout << this->nume << " mananca prajitura" << this->prajitura.denumire;
}
void main() {

	Prajitura p;
	p.afisare();
	Prajitura::getContor();
	Prajitura P1("amandina", 20);
	Student s1("Cristian", P1);
	cout << "Nr Total Calorii" << s1.calculeazaNrTotalCalorii(0.5);

	s1.afiseazaMasa();
	//testati tot ce implementati
	//cout << calculeazaPretPerIngredient(p);
	//tema:20 operatori = 


}