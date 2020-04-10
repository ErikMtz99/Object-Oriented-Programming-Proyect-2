#include <iostream>
#include <string>

using namespace std;

class Actor {
public:
	Actor();
	Actor(int i, string nom);

	void setID(int j);
	void setNombre(string n);

	int getID();
	string getNombre();

	void muestra();

private:
	int id;
	string nombre;
};


Actor::Actor() {
	id = 0;
	nombre = "-----";
}
Actor::Actor(int i, string nom) {
	id = i;
	nombre = nom;
}

void Actor::muestra() {
	cout << id << " " << nombre << endl;
}
void Actor::setID(int j) {
	id = j;
}
void Actor::setNombre(string n) {
	nombre = n;
}
int Actor::getID() {
	return id;
}
string Actor::getNombre() {
	return nombre;
}