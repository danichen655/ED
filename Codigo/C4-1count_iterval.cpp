// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeSet.h"
using namespace std;

// función que resuelve el problema
void resolver() {


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num, numInter, casos, lower, uper;
    cin >> num >> numInter;
    if (!std::cin)
        return false;
    TreeSet<int> arbol = TreeSet<int>();

    for (int i = 0; i < num; i++) {
        cin >> casos;
        arbol.insert(casos);

    }
    for (int i = 0; i < numInter; i++) {
        cin >> lower >> uper;
        cout << arbol.count_interval(lower, uper) << '\n';

    }
    cout << "---\n";


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