// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

using namespace std;

// función que resuelve el problema
bool aBinario(const Arbin<int> & a, int& maximo, int & minimo) {

    if (!a.esVacio()) {

        if (a.hijoIz().esVacio() && a.hijoDr().esVacio()) {
            maximo = a.raiz();
            minimo = a.raiz();
            return true;
        }
        else if (a.hijoDr().esVacio()) {

            int maxIz, minIz;

            aBinario(a.hijoIz(), maxIz, minIz);

            maximo = max(a.raiz(), maxIz);
            minimo = min(a.raiz(), minIz);

            if (a.raiz() > a.hijoIz().raiz()) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (a.hijoIz().esVacio()) {

            if (a.raiz() < a.hijoDr().raiz()) {
                return true && aBinario(a.hijoDr());
            }
            else {
                return false;
            }
        }
        else {
            return (a.raiz() < a.hijoDr().raiz())&& (a.raiz() > a.hijoIz().raiz())&&  aBinario(a.hijoIz()) && aBinario(a.hijoDr());
        }

    }
    else {
        return true;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> a = a.leerArbol(-1);

    if (aBinario(a)) {
        cout << "SI" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}