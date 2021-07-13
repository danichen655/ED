// Nombre del alumno HongXiang Chen y XinXiang Zhu
// Usuario del Juez C23 y C103

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Stack.h"

using namespace std;

// función que resuelve el problema

bool esCerrado(const char& c) { //O(1)
    return (c == ')' || c == ']' || c == '}');
}

bool esAbrierto(const char& c) {  //O(1)
    return (c == '(' || c == '{' || c == '[');
}

bool equilibrado (const string & cadena) { // el coste sera dependiendo el tamanho de la cadena, O(n)

	Stack<char> pila1 = Stack<char>();

	unsigned int i = 0;
	while (i < cadena.length()) {

		if (esAbrierto(cadena[i])) {
			pila1.push(cadena[i]);
		}
		else if (esCerrado(cadena[i])) {
			if (pila1.empty())
				return false;

			int aux = pila1.top();

			switch (aux) {
			case '(':
				if (cadena[i] != ')') return false;
				else pila1.pop();
				break;
			case '{':
				if (cadena[i] != '}') return false;
				else pila1.pop();
				break;
			case '[':
				if (cadena[i] != ']') return false;
				else pila1.pop();
				break;
			}
		}
		i++;
	}

	if (!pila1.empty())
		return false;

	return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

	string cadena;
	getline(cin, cadena);

    if (!std::cin)
        return false;

    bool sol = equilibrado(cadena);

    // escribir sol
	if (sol) {
		cout << "SI";
	}
	else {
		cout << "NO";
	}
	cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}