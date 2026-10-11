/*O instituție dorește un program pentru
a gestiona situația școlară a elevilor folosind alocarea dinamică.
Problema:Se citește de la tastatură un număr întreg $n$,
reprezentând numărul de note pe care le are un elev.
Să se scrie o funcție care primește $n$ ca parametru,
alocă dinamic memorie în heap pentru un tablou de $n$ note (de tip float),
citește notele de la tastatură și returnează pointerul către zona de memorie alocată.*/

#include <iostream>

using namespace std;


float* citireNote(int& n)
{

	cout << "Nr de note: ";
	cin >> n;
	float* v = new float[n];
	for (int i = 0;i < n;i++) {
		cout << "Nota " << i + 1 << ": ";
		cin >> v[i];
	}
	return v;
}
void afisareNote(float* v, int n) {

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