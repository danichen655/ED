#ifndef Pelicula_H
#define Pelicula_H

#include "Error.h"
#include "Horas.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class pelicula {
private :
	string nombrePeli;
	Hora ini, fin, duracion;

	pelicula() {};
public:
	pelicula(Hora ini, Hora duracion, string nombre) {
		this->ini = ini;
		this->duracion = duracion;
		this->nombrePeli = nombre;
		this->fin = ini + duracion;
	}

	Hora getFinPeli() const{
		return this->fin;
	}

	string getNombrePeli() const{
		return this->nombrePeli;
	}

	bool operator< (pelicula peli) {
		if (this->fin == peli.getFinPeli() && this->nombrePeli < peli.getNombrePeli()) 
			return true;
		if (this->fin < peli.getFinPeli())
			return true;
		
		return false;
	}
};

/*inline ostream& operator<< (ostream& out, Hora& h) {
	out << setfill('0') << setw(2) << h.getHoras() << ":" << setfill('0') << setw(2)
		<< h.getMin() << ":" << setfill('0') << setw(2) << h.getSeg();

	return out;
}*/
#endif /* HORAS_H_ */