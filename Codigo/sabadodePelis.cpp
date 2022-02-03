// Nombre del alumno .....
// Usuario del Juez ......

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Horas.h"
#include "Pilcula.h"
#include<algorithm>

using namespace std;

// función que resuelve el problema
//Lower_bound
int busqueda(vector<Hora> const& v, Hora const& hora) {
    int low = 0;
    int ultimo = v.size();
    while (low < ultimo) {
        int medio = low + (ultimo - low) / 2;

        if (hora < v[medio]) {
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


/*void resolver(vector<pelicula> v) {
    
    sort(v.begin(), v.end()-1);

    for (int i = 0; i < v.size(); i++) {
        Hora h = v[i].getFinPeli();
        cout << h << ' ' << v[i].getNombrePeli() << '\n';
    }

}*/

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    vector<pelicula> v;
    Hora inipeli, duracion;
    string nombrePeli;

    cin >> n;
    if (n == 0)
        return false;
    try {

        for (int i = 0; i < n; i++) {
            cin >> inipeli;
            cin >> duracion;
            getline(cin, nombrePeli);
            v.push_back({ inipeli,duracion,nombrePeli });
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++) {
            Hora h = v[i].getFinPeli();
            cout << h << ' ' << v[i].getNombrePeli() << '\n';
        }
    }catch (Error e) {
        cout << "ERROR\n";
    }
    cout << "---\n";
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
