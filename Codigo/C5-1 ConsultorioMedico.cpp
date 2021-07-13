#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>

using namespace std;




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