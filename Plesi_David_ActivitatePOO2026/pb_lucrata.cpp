#include <iostream>

using namespace std;

double* citestePreturi(int& n)
{
	cout << "Nr produse ";
	cin >> n;
	double* v = new double[n];
	for (int i = 0;i < n;i++) {
		cout << "Pretul produsului " << i + 1 << " ";
		cin >> v[i];
	}
	return v;
}
void afisareProduse(double* preturi, int n, double prag) {//preturi reprezinta v ul meu , vectorul
	bool gasit = false;
	for (int i = 0;i < n;i++) {
		if (preturi[i] > prag)
			cout << preturi[i];
		gasit = true;
	}
	if (!gasit)
		cout << "Nu sunt produse peste prag";
}
int main() {
	int n = 0;
	double* preturi = citestePreturi(n);//am citit vectorul de preturi
	cout << "Pune prag ";
	double prag;
	cin >> prag;
	afisareProduse(preturi, n, prag);
	delete[] preturi;
	return 0;
}