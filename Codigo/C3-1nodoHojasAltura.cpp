#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

using namespace std;

// función que resuelve el problema
void calcular(const Arbin<char>& a, int& nodo, int & hojas, int& altura) {

    if (a.esVacio()) {
        return;
    }
    int nodoIz = 0, alturaIz = 0;
    int nodoDer = 0, alturaDer = 0;

    if (a.hijoDr().esVacio() && a.hijoIz().esVacio()) {
        hojas++;
        altura++;
        nodo++;
    }
    else if (a.hijoIz().esVacio()) {
        calcular(a.hijoDr(), nodoIz, hojas, alturaDer);

    }
    else if (a.hijoDr().esVacio()) {
        calcular(a.hijoIz(), nodoDer, hojas, alturaIz);
    }
    else {
        calcular(a.hijoIz(), nodoIz, hojas, alturaIz);
        calcular(a.hijoDr(), nodoDer, hojas, alturaDer);
    }

    nodo = nodoIz + nodoDer + 1;
    altura = max(alturaIz, alturaDer) + 1;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<char> arbol;

    arbol = arbol.leerArbol('.');

    int nodo = 0, altura = 0, hojas = 0;
    if (arbol.esVacio()) {
        cout << 0 << ' ' << 0 << ' ' << 0 << ' ';
    }
    else {

        calcular(arbol, nodo, hojas, altura);
        cout << nodo << ' ' << hojas << ' ' << altura;
    }

    cout << endl;
    
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