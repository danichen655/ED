#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

class gestor_futbolistas {
public:

	void fichar(const string& jugador, const string& equipo) {

		auto it = jugador_equipoMap.find(jugador);

		if (it == jugador_equipoMap.cend()) {
			auto itEquipo = equipo_jugadoresMap.find(equipo);

			if (itEquipo == equipo_jugadoresMap.cend()) {
				equipo_jugadoresMap.insert(equipo, jugador);

			}else{
				itEquipo->second.push_back(jugador);
			}
			jugador_equipoMap.insert(jugador, equipo);
		}
		else {
			if (it->second != equipo) { // cambio de equipo
				jugador_equipoMap.erase(it);
				jugador_equipoMap.insert(jugador, equipo);
			}
		}

	}

	string equipo_actual(const string& jugador)const {

		auto it = jugador_equipoMap.find(jugador);

		if (it == jugador_equipoMap.cend()) {
			
			throw domain_error("Jugador inexistente");
		}

		return it->second;
	}

	int fichados(const string& equipo)const {
		
		auto it = equipo_jugadoresMap.find(equipo);
		if (it == equipo_jugadoresMap.cend()) {
			throw domain_error("Equipo inexistente");
		}
		return it->second.size();
	}

	vector<string> ultimos_fichajes(const string& equipo, int n)const {


	}

	int cuantos_equipos(const string& jugador) {


	}
private:
	unordered_map<string, string> jugador_equipoMap;
	unordered_map<string, list<string>> equipo_jugadoresMap;

	list<string> listaJugadores;
};

bool resuelveCaso() {
	string action, jugador, equipo;
	int n;
	gestor_futbolistas Gestor;

	cin >> action;
	if (!cin) { return false; }

	while (action != "FIN") {

		try {
			if (action == "fichar") {
				cin >> jugador >> equipo;
				Gestor.fichar(jugador, equipo);
			}
			else if (action == "equipo_actual") {
				cin >> jugador;
				equipo = Gestor.equipo_actual(jugador);
				cout << "El equipo de " << jugador << " es " << equipo << "\n";
			}
			else if (action == "fichados") {
				cin >> equipo;
				n = Gestor.fichados(equipo);
				cout << "Jugadores fichados por " << equipo << ": " << n << "\n";
			}

			else if (action == "ultimos_fichajes") {
				cin >> equipo >> n;
				vector<string> vec = Gestor.ultimos_fichajes(equipo, n);
				int tam = vec.size();
				cout << "Ultimos fichajes de " << equipo << ":";
				for (int i = 0; i < tam; ++i) {
					cout << " " << vec[i];
				}
				cout << "\n";
			}
			else if (action == "cuantos_equipos") {
				cin >> jugador;
				n = Gestor.cuantos_equipos(jugador);
				cout << "Equipos que han fichado a " << jugador << ": " << n << "\n";
			}
		}
		catch (domain_error& err) {
			cout << "ERROR: " << err.what() << "\n";
		}

		cin >> action;
	}

	cout << "---\n";
	return true;
}



int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso()) {
	}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif

	return 0;

}