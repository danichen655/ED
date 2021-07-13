#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num = 0;
    int salto = 0;
    cin >> num >> salto;
    if (num == 0)
        return false;

    List<int> lista;

    for (int i = 1; i <= num; i++) {
        lista.push_back(i);
    }
    lista.afortunado(salto);

    auto it = lista.cbegin();

    while (it != lista.cend()) {

        cout << it.elem();
        it++;

    }

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
