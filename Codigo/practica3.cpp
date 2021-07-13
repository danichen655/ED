// Nombre del alumno HongXiang Chen y XinXiang Zhu
// Usuario del Juez C23 y C103


#include <iostream>
#include <iomanip>
#include <fstream>
#include "QueueP3.h"
#include <stack>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    stack<int> p;

    Queue<int> cola = Queue<int>();
    Queue<int> cola2 = Queue<int>();
    int num = 0;
    unsigned int pos = 0;
    cin >> num ;
    while (num != -1) {
        cola.push_back(num);
        cin >> num;
    }
    cin >> pos;
    cin >> num;
    while (num != -1) {
        cola2.push_back(num);
        cin >> num;
    }
    cout << cola << '\n';
    cola.colarse(pos,cola2);
    cout << cola << '\n';
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