// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Horas.h"
using namespace std;

// función que resuelve el problema
//Lower_bound
int busqueda(vector<Hora> const &v, Hora const& hora) {
    int low = 0;
    int ultimo = v.size();
    while (low < ultimo){
        int medio = low + (ultimo - low) / 2;
        
        if (hora < v[medio]) { // ver operator<
            ultimo = medio;
        }
        else {
            low = medio + 1;
        }
    }
    return low;
}

/*int busqueda(vector<Hora> const& v, Hora hora) {
    int low = 0;
    int ultimo = v.size();
    while (low < ultimo) {
        int medio = (low + ultimo) / 2;

        if (hora < v[medio]) {
            ultimo = medio;
        }
        else if (v[medio] < hora) {
            low = medio + 1;
        }
        else {
            return medio;
        }
    }
    return low;
}*/


void resolver(vector<Hora> v, int consulta) {
    for (int i = 0; i < consulta; i++) {
       Hora hora;
       int j = 0;
       bool ok = false;

        try {

            cin >> hora;
            int pos = busqueda(v, hora);
            if (pos >= v.size()) {
                cout << "NO";
            }
            else {
                cout << v[pos];
            }

            cout << '\n';
        }
        catch (Error e) {
            cout << "ERROR\n";
        }
    }
    cout << "---\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    int consulta = 0;
    vector<Hora> v;
    Hora horas;

    cin >> n;
    cin >> consulta;
    if (n == 0 && consulta== 0)
        return false;

    for (int i = 0; i < n; i++) {
        cin >> horas;
        v.push_back(horas);
    }

    // escribir sol
    resolver(v, consulta);

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
