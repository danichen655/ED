#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>

using namespace std;

using dni = string;
using puntos = int;

const int MAX = 16;

class carnet {
	

private:

	unordered_map <dni, puntos> usuario;
	vector<int> v;

public:

	carnet() : v(MAX) {};

	void nuevo(dni d) {

		auto it = usuario.find(d);

		if (it == usuario.end()) {
			usuario.insert({ d, 15 });
			v[15]++;
		}else
			throw domain_error("ERROR: Conductor duplicado");
	}

	void quitar(dni d, puntos p) {

		auto it = usuario.find(d);

		if (it == usuario.end()) {
			throw domain_error("ERROR: Conductor inexistente");
		}

		v[it->second]--;

		if ((it->second - p) > 0) {
			it->second = it->second - p;

		}
		else {
			it->second = 0;
		}
		v[it->second]++;
	}

	puntos consultar(dni d) {
		auto it = usuario.find(d);

		if (it == usuario.end()) {
			throw domain_error("ERROR: Conductor inexistente");
		}

		return it->second;
	}

	puntos cuantos_con_puntos(puntos p) {
		if (p < 0 || p > 15)
			throw domain_error("ERROR: Puntos no validos");
		return v[p];
	}
};


void resolver(string accion, carnet& c) {
	dni d;
	puntos p;

	try {
		if (accion == "nuevo") {
			cin >> d;
			c.nuevo(d);
		}

		else if (accion == "quitar") {
			cin >> d >> p;
			c.quitar(d, p);
		}

		else if (accion == "consultar") {
			cin >> d;
			auto aux = c.consultar(d);
			cout << "Puntos de " << d << ": " << aux << '\n';
		}

		else if (accion == "cuantos_con_puntos") {
			cin >> p;
			int aux = c.cuantos_con_puntos(p);
			cout << "Con " << p << " puntos hay " << aux << '\n';
		}
	}

	catch (domain_error e) {
		cout << e.what() << '\n';
	}
}

bool resuelveCaso() {
	string comando;
	carnet c;

	cin >> comando;

	if (!std::cin)
		return false;

	while (comando != "FIN") {
		resolver(comando, c);
		cin >> comando;
	}

	cout << "---\n";

	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}