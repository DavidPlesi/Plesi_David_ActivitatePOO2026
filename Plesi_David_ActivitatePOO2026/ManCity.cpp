#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class ManchesterCity {

	const int anFondat = 1880;
	const int capacitateStadion = 61038;
	char* manager;
	float venit;
	bool faimos;

public:

	//constructor implicit

	ManchesterCity() {
		this->manager = new char[strlen("Enzo Maresca") + 1];
		strcpy(this->manager, "Enzo Maresca");
		this->venit = 803.61;
		this->faimos = true;
	}

	//constructor cu parametrii

	ManchesterCity(const char* manager) {
		this->manager = new char[strlen(manager) + 1];
		strcpy(this->manager, manager);
		this->venit = 803.61;
		this->faimos = true;
	}

	//constructor de copiere

	ManchesterCity(const ManchesterCity& m) 
	{
		this->manager = new char[strlen(m.manager) + 1];
		strcpy(this->manager, m.manager);
		this->venit = m.venit;
		this->faimos = m.faimos;

	}

	//declarare destructor

	~ManchesterCity();
																					
	//operatori

	ManchesterCity operator+(const ManchesterCity& M) {
		ManchesterCity rezultat = *this;//creez un obiect temporar , identic cu obiectul meu curent	
		rezultat.venit = this->venit + M.venit;
		return rezultat;
	}
	// getterii si setterii
	char* getManager() {
		return manager;
	}
	float getVenit() const {
		return venit;
	}
	bool getFaimos() {
		return faimos;
	}
	void setManager() {
		if (strlen(manager) > 0)
			this->manager = manager;
	}
	void setVenit(float v) {
		if (v > 0)
			this->venit = v;
	}
	void setFaimos() {
		this->faimos = faimos;
	}
};

//declar in afara clasei pt a nu lua si this-u si astfel avem doar 2 parametrii


istream& operator>>(istream& i, ManchesterCity& m) {
	float venit;
	i >> venit;
	m.setVenit(venit);
	return i;
}
ostream& operator<<(ostream& o, const ManchesterCity& m) {
	o << m.getVenit();
	return o;
}
ManchesterCity::~ManchesterCity() {		//implementare destructor in afara clasei
	delete[]this->manager;
}
void main() {
	float v1 = 803.61;
	float v2 = 803.61;
	
	float v = v1 + v2;
	ManchesterCity  m;
	cout << "Venit: ";
	cin >> m;
	cout << m;
	cout << endl;
	cout << "Suma veniturilor pe 2 ani: " << v;
}