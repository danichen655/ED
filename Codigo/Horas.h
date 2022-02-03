#ifndef HORAS_H_
#define HORAS_H_

#include "Error.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Hora {

private:
	int hora;
	int min;
	int seg;
public:

	Hora() {};

	Hora(int hora, int min, int seg) {
		if (hora > 23 || hora < 0 || min > 59 || min < 0 || seg >59 || seg < 0) {
			throw Error("Error");
		}
		else {
			this->hora = hora;
			this->min = min;
			this->seg = seg;
		}
	}

	int getHoras() {
		return this->hora;
	}
	int getMin() {
		return this->min;
	}
	int getSeg() {
		return this->seg;
	}

	bool operator<(const Hora& h) const {
		if (this->hora < h.hora) {
			return true;
		}else if (this->hora == h.hora && this->min < h.min) {
			return true;
		}
		else if (this->hora == h.hora && this->min == h.min && this->seg < h.seg) {
			return true;
		}/*else if (this->hora == h.hora && this->min == h.min && this->seg == h.seg) {
			return true;
		}*/ // habilitar para el ejercicios de trenes
		return false;
	}

	bool operator== (const Hora & h) const {
		if (this->hora == h.hora && this->min == h.min && this->seg == h.seg) {
			return true;
		}
		return false;
	}

	Hora operator+(Hora& h) {
		Hora ret;
		
		int seg = h.getSeg() + this->seg;
		ret.seg = seg % 60;
		int min = h.getMin() + this->min + seg/60;
		ret.min = min % 60;
		int hora = h.getHoras() + this->hora + min/60;
		if (hora > 23) {
			throw Error("ERROR");
		}
		ret.hora = hora;
		return ret;
	}

};

inline istream& operator>> (istream& in, Hora& h) {
	int hr, m, s;
	char basura;
	in >> hr >> basura >> m >> basura >> s;
	h = Hora(hr, m, s);
	return in;
}

inline ostream &operator<< (ostream& out, Hora& h){
	out << setfill('0') << setw(2) << h.getHoras() << ":" << setfill('0') << setw(2)
		<< h.getMin() << ":" << setfill('0') << setw(2) << h.getSeg();

	return out;
}

#endif /* HORAS_H_ */