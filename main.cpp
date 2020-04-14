#include <iostream>
#include <fstream>
#include "Pelicula.h"
#include "Funcion.h"


using namespace std;

void Archivos(Actor actores[], Funcion funciones[], Pelicula peliculas[]) {
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


		while (idx < numActores) { 
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

	cout << peliculas[4].getTitulo() << endl;

	archivo_actores.close();
	archivo_peliculas.close();
}

int main() {
	Actor actores[20];
	Funcion funciones[20];
	Pelicula peliculas[20];

	Archivos(actores, funciones, peliculas);
	int n, clave, sala;
	string nombre;
	int i = 0;
	cout << "Ingrese el numero de funciones que habran por el dia: ";
	cin >> n;
	while (n < 1) {
		cout << "Ingrese un numero mayor a 0 porfavor:  " << endl;
		cin >> n;
	}

	while (i < n) {

			cout << "Ingrese clave de la funcion: ";
			cin >> clave;
			bool Existe = false;
			cout << endl;
			for (int c = 0; c < 10; c++) {
				if (clave == peliculas[c].getNumPeli())
						{
							Existe = true;
							funciones[i].setNumPeli(clave);
						}
			}
			while (Existe == false) {
				cout << "Clave de pelicula no existe, ingrese denuevo: ";
				cin >> clave;
				for (int c = 0; c < 10; c++) {
					if (clave == peliculas[c].getNumPeli())
					{
						Existe = true;
					}
				}
			}

			/*cout << "Ingrese numero de sala de la funcion: ";
			cin >> sala;
			cout << endl;
			Existe = false;
			for (int c = 0; c < n; c++) {
				if (sala != funciones[c].getSala())
				{
					Existe = true;
					funciones[i].setSala(sala);
				}
			}
			while (Existe == false) {
				cout << "Sala ocupada, ingrese otra: ";
				cin >> sala;
				for (int c = 0; c < n; c++) {
					if (sala != funciones[c].getSala())
					{
						Existe = true;
						funciones[i].setSala(sala);
					}
				}
			}*/

		i++;
	}

	return 0;
}
