#include <iostream>
#include <string>
#include "Hora.h"

using namespace std;

class Funcion {
public:
	Funcion();
	Funcion(string fun, int num, Hora hr, int s);

	void setCveFuncion(string hola);
	void setNumPeli(int n);
	void setHora(Hora h);
	void setSala(int x);

	string getCveFuncion();
	int getNumPeli();
	Hora getHora();
	int getSala();

	void muestra();

private:
	string cveFuncion;
	int numPeli;
	Hora hora;
	int sala;
};


Funcion::Funcion() {
	Hora inicio(0, 0);
	cveFuncion = "----";
	numPeli = 0;
	hora = inicio;
	sala = 0;
}

Funcion::Funcion(string fun, int num, Hora hr, int s) {
	cveFuncion = fun;
	numPeli = num;
	hora = hr;
	sala = s;
}

void Funcion::muestra() {
	//Hora h;
	cout << cveFuncion << "\t" << numPeli << "\t" << sala << "\t";
	hora.muestra();
	cout << endl;
}
void Funcion::setCveFuncion(string hola) {
	cveFuncion = hola;
}
void Funcion::setNumPeli(int n) {
	numPeli = n;
}
void Funcion::setHora(Hora h) {
	hora = h;
}
void Funcion::setSala(int x) {
	sala = x;
}

string Funcion::getCveFuncion() {
	return cveFuncion;
}
int Funcion::getNumPeli() {
	return numPeli;
}
Hora Funcion::getHora() {
	return hora;
}
int Funcion::getSala() {
	return sala;
}