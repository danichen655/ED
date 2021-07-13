// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Arbin.h"

using namespace std;

// función que resuelve el problema
template <class T>
T resolver(const Arbin<T> & a) {
    if (!a.esVacio()) {
        
        if (a.hijoDr().esVacio() && a.hijoIz().esVacio()) {
            return a.raiz();
        }
        else if (a.hijoDr().esVacio()) {
            T aux = resolver(a.hijoIz());
            return min(aux, a.raiz());
        }
        else if (a.hijoIz().esVacio()) {
            T aux = resolver(a.hijoDr());
            return min(aux, a.raiz());
        }
        else {
            T aux = min(resolver(a.hijoDr()), resolver(a.hijoIz()));
            return min(aux, a.raiz());
        }


        /*T iz = resolver(a.hijoIz());
        T der = resolver(a.hijoDr());

        T aux = min(iz, der);
        return min(a.raiz(), aux);*/
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    cin >> tipo;

    if (!std::cin)
        return false;

    if (tipo == 'N') {
        Arbin<int> a;
        a = a.leerArbol(-1);

        cout << resolver(a);
       
    }
    else {
        Arbin<string> a;
        a  = a.leerArbol("#");
        cout << resolver(a);
    }

    cout << endl;

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