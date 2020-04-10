#include <iostream>
#include <fstream>
#include "Pelicula.h"
#include "Funcion.h"


using namespace std;

void Archivos(Actor actores[], Funcion funciones[], Pelicula peliculas[]) { // cree un void para que el main estuviera mas corto
	cout << peliculas[0].getListaActores(0).getID() << endl;
	ifstream archivo_actores, archivo_peliculas;
	archivo_actores.open("actores.txt");
	archivo_peliculas.open("peliculas.txt");

	int x;
	int i = 0;
	int j = 0;
	string nom;

	while (i < 20) {
		archivo_actores >> x;
		getline(archivo_actores, nom);
		actores[i].setID(x);
		actores[i].setNombre(nom);
		i++;
		cout << x << " " << nom << endl;
	}

	int a, b, c, numActores;
	string g, t;

	while (j < 20) {

		int idx = 0;
		int ide;


		archivo_peliculas >> a >> b >> c >> g >> numActores;


		while (idx < numActores) { // checar esta parte porque no esta saliendo
			archivo_peliculas >> ide;
			int y = 0;
			while (y < 20) {
				if (actores[y].getID() == ide) {
					peliculas[j].agregarActor(actores[y]);
					/*peliculas[j].getListaActores(0).muestra();
					cout << "hola" << endl;*/
					break;
				}
				y++;
			}

			idx++;
		}

		getline(archivo_peliculas, t);

		peliculas[j].setNumPeli(a);
		peliculas[j].setAnio(b);
		peliculas[j].setDuracion(c);
		peliculas[j].setGenero(g);
		peliculas[j].setTitulo(t);

		j++;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	peliculas[9].getListaActores(0).muestra();

	cout << peliculas[9].getDuracion() << endl;
	cout << peliculas[9].getAnio() << endl;
	cout << peliculas[9].getNumPeli() << endl;
	cout << peliculas[9].getTitulo();

	archivo_actores.close();
	archivo_peliculas.close();
}

int main() {
	Actor actores[20];
	Funcion funciones[20];
	Pelicula peliculas[20];

	Archivos(actores, funciones, peliculas);

	//cout << "------------------" << endl;

	//cout << peliculas[2].getCantActores() << endl;
	//actores[2].muestra();
	//cout << peliculas[1].getTitulo() << endl;
	//
	//peliculas[3].getListaActores(1).muestra();

	return 0;
}
