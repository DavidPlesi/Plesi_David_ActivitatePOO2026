#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Centrala {
	char* producator;
	int putere;//in kW
	float orePornita;//in ore
	bool on;

public:
	Centrala() {
		this->producator = new char[strlen("Tefal") + 1];
		strcpy(producator, "Tefal");
		this->putere = 6;
		this->orePornita = 1;
		this->on = true;
	}
	Centrala(const char* producator) {
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->putere = 6;
		this->orePornita = 1;
		this->on = true;
	}
	Centrala(const Centrala& c) {
		this->producator = new char[strlen(c.producator) + 1];
		strcpy(this->producator, c.producator);
		this->putere = c.putere;
		this->orePornita = c.orePornita;
		this->on = c.on;
	}

	~Centrala();//declarare destructor

	//operatori
	friend istream& operator>>(istream& i, Centrala& c) {
		cout << "Putere in kW: ";
		i >> c.putere;
		cout << "Ore pornita: ";
		i >> c.orePornita;
		return i;
	}
	friend ostream& operator<<(ostream& o, const Centrala& c) {
		o << c.putere * c.orePornita;
		return o;
	}
	float operator()() {
		return putere * orePornita;
	}
	//operator de cast/conversie
	explicit operator float() {
		return putere * orePornita;
	}
	explicit operator bool() {
		return putere > 5;
	}
	explicit operator int() {
		return (int)(putere * orePornita);
	}
};

Centrala::~Centrala() {//implementare destructor
	delete[]this->producator;
}
void main() {
	Centrala c;
	cin >> c;
	/*cout << "Centrala consuma: " << c() << "kWh";
	cout << "Centrala consuma: " << c << "kWh";*/
	cout << "Centrala consuma: " << (float)c << "kWh" << endl;
	cout << (bool)c << endl;
	cout << (int)c;
}