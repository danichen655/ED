#include <iostream>
#include <iomanip>
#include <fstream>
#include "Stack.h"
#include "Queue.h"


using namespace std;
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    cin >> n;

    if (n == 0) {
        return false;
    }

    Stack<int> pila;
    Queue<int> cola;
    int numero = 0;

    for (int i = 0; i < n; i++) {
        cin >> numero;
        if (numero < 0) {

            pila.push(numero);
        }
        else {
            cola.push_back(numero);
        }

    }

    while (!pila.empty()) {

        cout << pila.top() << ' ' ; pila.pop();

    }

    while (!cola.empty()) {
        cout << cola.front() << ' '; cola.pop_front();
    }
    cout << endl;

    // escribir sol

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
