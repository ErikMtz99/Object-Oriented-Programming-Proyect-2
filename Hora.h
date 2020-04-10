#include<iostream>
#include <iomanip>

using namespace std;

class Hora {
public:
	Hora();
	Hora(int a, int b);

	int gethh();
	int getmm();
	
	void sethh(int hora);
	void setmm(int minuto);

	void muestra();

private:
	int hh;
	int mm;
};

Hora::Hora() {
	hh = 0;
	mm = 0;
}
Hora::Hora(int a, int b) {
	hh = a;
	mm = b;
}

void Hora::muestra() {
	cout << setw(2) << setfill('0') << hh << ":"
		<< setw(2) << setfill('0') << mm << endl;
}
void Hora::sethh(int a) {
	hh = a;
}
void Hora::setmm(int b) {
	mm = b;
}
int Hora::gethh() {
	return hh;
}
int Hora::getmm() {
	return mm;
}
