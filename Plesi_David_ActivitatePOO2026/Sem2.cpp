#include <iostream>

using namespace std;

struct Cladire {
	char* culoare;
	float inaltime;
	int nrEtaje;
	bool deschis;

};
Cladire citireCladire() {
	Cladire c;
	char x[100];//retinut in stack
	cout << "Culoare: ";
	cin >> x;
	c.culoare = new(char[strlen(x) + 1]);
	strcpy_s(c.culoare, strlen(x) + 1, x);//(destinatia, de unde copiem)
	cout << "Inaltime: ";
	cin >> c.inaltime;
	cout << "Nr etaje: ";
	cin >> c.nrEtaje;
	cout << "Deschis(0/1): ";
	cin >> c.deschis;
	return c;
}
void afisareCladire(Cladire c) {//fiecare subpr are zona lui de memorie. dupa ce se termina functia stiva ei se sterge
	cout << "Culoarea este: " << c.culoare;
	cout << "Inaltimea este: " << c.inaltime;
	cout << "Nr etaje este: " << c.culoare;
	cout << "Deschis(1/0) " << c.deschis;

}
int main() {

	Cladire c = citireCladire();
	afisareCladire(c);
	/*char* vectorC;
	vectorC = new char[strlen("POO") + 1];
	strcpy_s(vectorC, strlen("POO") + 1, "POO");

	int nrCladiri = 5;
	Cladire* cladiri;
	cladiri = new Cladire[nrCladiri];
	cladiri = (Cladire*)malloc(sizeof(Cladire) * nrCladiri);*/
}