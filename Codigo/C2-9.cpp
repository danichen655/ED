C2 - 9.cpp

X
Tipo
Texto
Tamaño
2 KB(1.681 bytes)
Almacenamiento usado
2 KB(1.681 bytes)
Ubicación
P4
Propietario
yo
Modificado
13 abr 2021 por mí
Abierto
13:55 por mí
Creado el
13 abr 2021 con Google Drive Web
Añadir descripción
Los usuarios con acceso de lectura pueden descargar este elemento
﻿// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "List.h"

using namespace std;

// función que resuelve el problema
void resolver(List<int>& lista) { // O(n) siendo n el numero de elementos que hay en la lista

    List<int>::Iterator it = lista.begin();
    int ant = -1;

    while (it != lista.end()) {

        if (ant <= it.elem()) {
            ant = it.elem();
            it.next();
        }
        else {
            it = lista.erase(it);
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n = 0;
    List<int> lista = List<int>();
    cin >> n;
    while (n != -1) {
        lista.push_back(n);
        cin >> n;
    }

    resolver(lista);
    // escribir sol
    List<int>::ConstIterator it = lista.cbegin();
    while (it != lista.cend()) {
        cout << it.elem() << ' ';
        it.next();
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