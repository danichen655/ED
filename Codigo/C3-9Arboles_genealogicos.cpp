// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

// función que resuelve el problema
void genealogicos(const Arbin<int>& a, int &altura, bool & genea) { // El coste seria O(n) siendo el n el numero de nodos que hay en el arbol,
                                                                    //ya que recorremos todo el arbol en profundidad hasta el ultimo nodo.
    if (a.esVacio()) {
        altura = 0;
        genea = true;
    }
    else {

        if (a.hijoDr().esVacio() && a.hijoIz().esVacio()){ // si no tiene hijos.
            altura = 1;
            genea = true;
        }
        else {
            int alturaDer, alturaIz;
            bool genDer, genIz;
            genealogicos(a.hijoIz(), alturaIz, genIz);
            genealogicos(a.hijoDr(), alturaDer, genDer);

            altura = max(alturaDer, alturaIz) + 1;
        
            if (!a.hijoDr().esVacio() && !a.hijoIz().esVacio()) {
                genea = ((a.raiz() >= a.hijoIz().raiz() + 18) && (a.raiz() >= a.hijoDr().raiz() + 18) && genDer &&
                    (a.hijoIz().raiz() >= a.hijoDr().raiz() + 2 ) && genIz);
            }
            else if (!a.hijoIz().esVacio()) {
                genea = ((a.raiz() >= a.hijoIz().raiz() + 18) && genIz);
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    Arbin<int> arbol = arbol.leerArbol(-1);

    int altura = 0;
    bool gen = false;

    genealogicos(arbol, altura, gen);

    // escribir sol
    if (gen) {
        cout << "SI " << altura << '\n';
    }
    else {
        cout << "NO\n";
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