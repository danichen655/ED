// Nombre del alumno HongXaing Chen y XinXiang Zhu
// Usuario del Juez C23 y C103

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "Arbin.h"

using namespace std;

void frontera(const Arbin<int> & a, list<int> & q) { // El coste seria O(n) siendo el n el numero de nodos que hay en el arbol,
                                                        //ya que recorremos todo el arbol en profundidad hasta el ultimo nodo.

    if (!a.esVacio()) {

        if (a.hijoDr().esVacio() && a.hijoIz().esVacio()) {
            q.push_back(a.raiz());
        }
        else if (a.hijoDr().esVacio()) {
            frontera(a.hijoIz(), q);
        }
        else if (a.hijoIz().esVacio()) {
            frontera(a.hijoDr(), q);
        }
        else if (!a.hijoIz().esVacio() && !a.hijoDr().esVacio()) {
            frontera(a.hijoIz(), q);
            frontera(a.hijoDr(), q);
        }

    }
}

void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol;
    list<int> q;

    arbol = arbol.leerArbol(-1);
  
    // escribir sol
    frontera(arbol, q);
    while (!q.empty()) {
        
        cout << q.front()<< ' ';
        q.pop_front();

    }
    
    cout << '\n';
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