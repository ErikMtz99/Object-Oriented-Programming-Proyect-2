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
	bool existe_hora = false;
	cout << "Ingrese una hora: ";
	cin >> hrr;
	cout << "Ingrese minutos: ";
	cin >> minn;
	int cont = 0;
	while (funciones[cont].getNumPeli() != 0) {
		if (hrr == funciones[cont].getHora().gethh() && minn == funciones[cont].getHora().getmm()) {
			cout << "Sala: " << funciones[cont].getSala();
			cout << "\t" << "Pelicula: " <<  funciones[cont].getCveFuncion() << endl;
			existe_hora = true;
		}
		cont++;
	}
	if (existe_hora == false) {
		cout << "No hay funcion a esa hora. " << endl;
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

void OpcionF(Actor actores[], Pelicula peliculas[]) {
	int aidi;
	bool Existe = false;
	cout << "Ingrese el id del actor: ";
	cin >> aidi;
	for (int cont = 0; cont < 20; cont++) {
		if (actores[cont].getID() == aidi)
		{
			Existe = true;
		}
	}

	while (Existe == false) {
		cout << "iD invalido, ingrese denuevo: ";
		cin >> aidi;
		for (int cont = 0; cont < 20; cont++) {
			if (actores[cont].getID() == aidi)
			{
				Existe = true;
			}
		}
	}

	for (int hola = 0; hola < 10; hola++ ) {
		int num_actor = peliculas[hola].getCantActores();
		int k = 0;
		static bool imprimir_nombre = false;
		while (k<num_actor) {
			if (aidi == peliculas[hola].getListaActores(k).getID()) {
				if (imprimir_nombre == false) {
					cout << "Actor: " << peliculas[hola].getListaActores(k).getNombre() << endl << endl;
					imprimir_nombre = true;
				}
				cout << "Pelicula: " << peliculas[hola].getTitulo() << endl;
				cout << "Anio: " << peliculas[hola].getAnio() << endl;
				cout << endl;
			}
			k++;
		}
	}
	

}

int main() {
	Actor actores[20];
	Funcion funciones[20];
	Pelicula peliculas[20];

	Archivos(actores, funciones, peliculas);
	Ingresar(funciones,peliculas);

	while (true) {

		cout << endl;
		cout << endl;
		cout << "Ingrese una de las siguientes opciones porfavor: " << endl;
		cout << "[1] Consulta de actores" << endl;
		cout << "[2] Consulta de peliculas" << endl;
		cout << "[3] Consulta de funciones" << endl;
		cout << "[4] Consulta de funciones por hora" << endl;
		cout << "[5] Consulta por clave de funcion" << endl;
		cout << "[6] Consulta de peliculas donde sale un actor" << endl;
		cout << "[7] Salir" << endl;
		int respuesta;
		bool salir = false;
		cin >> respuesta;

		switch (respuesta) {
		case 1:
			OpcionA(actores);
			break;
		case 2:
			OpcionB(peliculas);
			break;
		case 3:
			OpcionC(funciones);
			break;
		case 4:
			OpcionD(funciones);
			break;
		case 5:
			OpcionE(funciones, peliculas);
			break;
		case 6:
			OpcionF(actores, peliculas);
			break;
		case 7:
			cout << "Quisiera salir de la aplicacion? (SI = 1, NO = 2)" << endl;
			int respuesta2;
			cin >> respuesta2;
			if (respuesta2 == 1) {
				salir = true;
				break;
			}
			else {}
			break;

		default:
			cout << "numero invalido, intente denuevo" << endl;
		}

		if (salir == true) {
			break;
		}
	}


	return 0;
}

