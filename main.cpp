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


	archivo_actores.close();
	archivo_peliculas.close();
}

void Ingresar(Funcion funciones[], Pelicula peliculas[]) {
	int n, clave, sala1, hora, min;
	string nombre;
	int i = 0;
	cout << "Ingrese el numero de funciones que habran por el dia: ";
	cin >> n;

	// ****************** INVESTIGAR COMO FUNCIONA EL CIN.IGNORE **************************
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // investigar
			cout << "Ingrese un numero entero porfavor: " << endl;
			cin >> n;
		}
		if (!cin.fail())
			break;
	}
	while (n < 1) {
		cout << "Ingrese un numero mayor a 0 porfavor:  " << endl;
		cin >> n;
	}

	// Referencia: https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
	// *********************************************************************************


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
				funciones[i].setCveFuncion(peliculas[c].getTitulo());
			}
		}
		while (Existe == false) {
			cout << "Clave de pelicula no existe, ingrese denuevo: ";
			cin >> clave;
			for (int c = 0; c < 11; c++) {
				if (clave == peliculas[c].getNumPeli())
				{
					Existe = true;
				}
			}
		}

		cout << "Ingrese numero de sala de la funcion: ";
		cin >> sala1;
		cout << endl;
		funciones[i].setSala(sala1);

		cout << "Ingrese hora de la pelicula (entre 0 y 23): ";
		cin >> hora;
		cout << endl;
		while (hora < 0 || hora > 23) {
			cout << "Ingrese una hora valida: ";
			cin >> hora;

		}

		cout << "Ingrese minutos de la pelicula (entre 0 y 59): ";
		cin >> min;
		cout << endl;
		while (min < 0 || min > 59) {
			cout << "Ingrese minutos validos: ";
			cin >> min;

		}

		Hora reloj(hora, min);
		funciones[i].setHora(reloj);
		cout << endl << endl << endl;
		//funciones[i].muestra();

		i++;
	}
}

void OpcionA(Actor actores[]) {
	int act = 0;
	while (act < 20) {
		actores[act].muestra();
		act++;
	}
}

void OpcionB(Pelicula peliculas[]) {
	int pel = 0;
	int x = 0;
	while (pel < 10) {
		cout << peliculas[pel].getTitulo() << "\t";
		cout << peliculas[pel].getAnio() << "\t";
		cout << peliculas[pel].getDuracion() << "\t";
		cout << peliculas[pel].getGenero() << "\t";

		while (x < peliculas[pel].getCantActores()) {
			cout << peliculas[pel].getListaActores(x).getNombre() << "\t";
			x++;
		}
		x = 0;
		cout << endl;
		pel++;
	}
}

void OpcionC(Funcion funciones[]) {
	int fun = 0;
	while (funciones[fun].getNumPeli() != 0) {
		funciones[fun].muestra();
		fun++;
	}
}
void OpcionD(Funcion funciones[]) {
	int hrr, minn;
	cout << "Ingrese una hora: ";
	cin >> hrr;
	cout << "Ingrese minutos: ";
	cin >> minn;
	int cont = 0;
	while (funciones[cont].getNumPeli() != 0) {
		if (hrr == funciones[cont].getHora().gethh() && minn == funciones[cont].getHora().getmm()) {
			cout << "Sala: " << funciones[cont].getSala();
			cout << "\t" << "Pelicula: " <<  funciones[cont].getCveFuncion() << endl;
		}
		cont++;
	}
}

void OpcionE(Funcion funciones[], Pelicula peliculas[]) {
	int clave;
	cout << "Ingrese clave de la funcion: ";
	cin >> clave;
	int cont = 0;
	int cont2 = 0;
	bool Existe = false;
	bool ExisteFuncion = false;

	for (int c = 0; c < 10; c++) {
		if (clave == peliculas[c].getNumPeli())
		{
			Existe = true;
		}
	}
	
	while (funciones[cont].getNumPeli() != 0) {
		if (clave == funciones[cont].getNumPeli()) {
			while (peliculas[cont2].getNumPeli() != 0) {
				if (clave == peliculas[cont2].getNumPeli()) {

					int x = 0;
					ExisteFuncion = true;
					cout << endl << "Sala: " << funciones[cont].getSala() << endl;
					cout << "Titulo: " << peliculas[cont2].getTitulo() << endl;
					cout << "Hora: ";
					funciones[cont].getHora().muestra();
					cout << "Duracion: " << peliculas[cont2].getDuracion() << endl;
					cout << "Genero: " << peliculas[cont2].getGenero() << endl;
					cout << "Actores:  ";
					while (x < peliculas[cont2].getCantActores()) {
						cout << peliculas[cont2].getListaActores(x).getNombre() << "\t";
						x++;
					}
					break;
				}
				cont2++;
			}

		}

		cont++;
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

	
	while (ExisteFuncion == false) {
		cout << "No hay funcion de esa pelicula hoy..." << endl;
		ExisteFuncion = true;
	}
	ExisteFuncion = false;



}

int main() {
	Actor actores[20];
	Funcion funciones[20];
	Pelicula peliculas[20];

	Archivos(actores, funciones, peliculas);
	Ingresar(funciones,peliculas);
	//OpcionA(actores); 
	//OpcionB(peliculas);
	//cout << endl << endl << endl;
	OpcionC(funciones);
	cout << endl << endl << endl;
	OpcionE(funciones, peliculas);

	return 0;
}

