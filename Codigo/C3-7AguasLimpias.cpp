// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

using namespace std;

// función que resuelve el problema
/*int navegable(const Arbin<int>& a, int& tramosNvegables) {
    
    if (a.esVacio()) {
        return 0;
    }

    if (a.hijoDr().esVacio() && a.hijoIz().esVacio()) {
        return 1;
    }

    int caudal_izquierdo = navegable(a.hijoIz(), tramosNvegables);
    int caudal_derecho = navegable(a.hijoDr(), tramosNvegables);

    if (caudal_derecho >= 3) {
        tramosNvegables++;
    }
    if (caudal_izquierdo >= 3) {
        tramosNvegables++;
    }

    int caudal = caudal_izquierdo + caudal_derecho - a.raiz();

    if (caudal < 0) {
        return 0;
    }

    return caudal;
}*/

int navegable(const Arbin<int>& a, int& tramosNvegables) {

    if (a.esVacio()) {
        return 0;
    }

    if (a.hijoDr().esVacio() && a.hijoIz().esVacio()) {
        return 1;
    }

    int iz = navegable(a.hijoIz(), tramosNvegables);
    int der = navegable(a.hijoDr(), tramosNvegables);

    if (iz >= 3) {
        tramosNvegables++;
    }

    if (der >= 3) {
        tramosNvegables++;
    }

    int caudal = iz + der - a.raiz();

    if (caudal < 0) {
        caudal = 0;
    }

    return caudal;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> a = a.leerArbol(-1);

    int n = 0;
    navegable(a, n);

    cout << n << endl;
    
    // escribir sol


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