/*O instituție dorește un program pentru
a gestiona situația școlară a elevilor folosind alocarea dinamică.
Problema:Se citește de la tastatură un număr întreg $n$,
reprezentând numărul de note pe care le are un elev.
Să se scrie o funcție care primește $n$ ca parametru,
alocă dinamic memorie în heap pentru un tablou de $n$ note (de tip float),
citește notele de la tastatură și returnează pointerul către zona de memorie alocată.*/

#include <iostream>

using namespace std;


float* citireNote(int& n)//pointerul la float , indica ca subprogramul va returna o adresa , si nu o valoare
{//astfel , va returna adresa primului element din vector care ne va permite sa citim tot vectorul

	cout << "Nr de note: ";
	cin >> n;
	float* v = new float[n];
	for (int i = 0;i < n;i++) {
		cout << "Nota " << i + 1 << ": ";
		cin >> v[i];
	}
	return v;//cand returnam v , v deja reprezinta adresa catre primul el din vect , deci nu mai am nevoie de *
}//daca as fi pus *v , el ar fi incercat sa reurneze valoarea stocata la adresa primului el si ar da eroare de compilare
void afisareNote(float* v, int n) {//deoarece mai sus am spus ca subp va returna o adresa nu o valoare

	for (int i = 0;i < n;i++) {
		cout << v[i] << " ";
	}
}
int main()
{
	int n = 0;
	float* note = citireNote(n);
	afisareNote(note, n);
	delete[] note;
	return 0;
}
