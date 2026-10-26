#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;


class Fructe {
	int nrTipFructe;
	string* tipFructe;
	bool exotic;
	float calorii;

	Fructe() {
		
		this->nrTipFructe = 3;
		this->tipFructe = new string[this->nrTipFructe];
		this->tipFructe[0] = "Ananas";
		this->tipFructe[1] = "Piersica";
		this->tipFructe[2] = "Fructul Pasiunii";
		this->exotic = true;
		this->calorii = 60;

	}
	
	Fructe(const Fructe& f) {
		this->nrTipFructe = f.nrTipFructe;
		this->calorii = f.calorii;
		tipFructe = new string[this->nrTipFructe];
		for (int i = 0;i < nrTipFructe;i++) {
			this->tipFructe[i] = f.tipFructe[i];
		}
	}
};
int main() {

}