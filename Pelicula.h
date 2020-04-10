#include <iostream>
#include <string>
#include "Actor.h"

using namespace std;

class Pelicula {
public:
	Pelicula();

	// gets y sets
	void setNumPeli(int num);
	void setTitulo(string t);
	void setAnio(int a);
	void setDuracion(int d);
	void setGenero(string gen);

	int getNumPeli();
	string getTitulo();
	int getAnio();
	int getDuracion();
	string getGenero();
	int getCantActores();

	Actor getListaActores(int i);

	bool agregarActor(Actor r);

private:
	int numPeli;
	int anio;
	int duracion;
	string genero;
	int cantActores;
	Actor listaActores[10];
	string titulo;

	int cont;
};

Pelicula::Pelicula() {

	Actor listaActores[10];
	numPeli = 0;
	titulo = "----";
	anio = 0;
	duracion = 0;
	genero = "----";
	cantActores = 0;
	cont = 0;
	
}

bool Pelicula::agregarActor(Actor r) {

	if (cont < 10 && listaActores[cont].getID() != r.getID()) {
		listaActores[cont] = r;
		cont++;
		cantActores = cont;
		return true;
	}
	else {
		return false;
	}

}


Actor Pelicula::getListaActores(int i) {
	return listaActores[i];
}
int Pelicula::getCantActores() {
	cantActores = cont;
	return cantActores;
}

int Pelicula::getNumPeli() {
	return numPeli;
}
string Pelicula::getTitulo() {
	return titulo;
}
int Pelicula::getAnio() {
	return anio;
}
int Pelicula::getDuracion() {
	return duracion;
}
string Pelicula::getGenero() {
	return genero;
}

void Pelicula::setNumPeli(int num) {
	numPeli = num;
}
void Pelicula::setTitulo(string t) {
	titulo = t;
}
void Pelicula::setAnio(int a) {
	anio = a;
}
void Pelicula::setDuracion(int d) {
	duracion = d;
}
void Pelicula::setGenero(string gen) {
	genero = gen;
}
