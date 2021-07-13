// Nombre del alumno HongXiang Chen y XinXiang Zhu
// Usuario del Juez C23 y C103

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

// función que resuelve el problema
int heroes(const Arbin<int> & a, int & maxEx) {
       // El coste seria O(n) siendo el n el numero de nodos que hay en el arbol,
       //ya que recorremos todo el arbol en profundidad hasta el ultimo nodo.

    if (a.esVacio()) {
        maxEx = 0;
        return 0;
    }
    else {
        int maxExIz, maxExDer;
        int heroes1 = heroes(a.hijoIz(), maxExIz);
        int heroes2 = heroes(a.hijoDr(), maxExDer);
        maxEx = max(maxExIz, maxExDer);

        if (heroes1 !=0|| heroes2 != 0) {
            if (a.raiz() != 0) {
                maxEx += a.raiz();
            }
            return heroes1 + heroes2;
        }

        if (a.raiz() != 0) {
            maxEx = a.raiz();
            return 1;
        }
        else {
            maxEx = 0;
            return 0;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol = Arbin<int>();

    arbol = arbol.leerArbol(-1);
    int max = 0;
    int equipos = 0;

    equipos = heroes(arbol, max);
    
    // escribir sol
    cout << equipos << ' ' << max<< '\n';
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