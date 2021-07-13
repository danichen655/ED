#include <iostream>
#include "Arbin.h"

using namespace std;

int numero_adivinosAux(const Arbin <int>& a, int & adivinos, int pares) {

    if (a.esVacio()) {
        return pares;
    }

    if (a.hijoDr().esVacio() && a.hijoIz().esVacio()) {
        if (a.raiz() % 2 == 0) {
            pares++;
        }

        return pares;
    }

    int iz = numero_adivinosAux(a.hijoIz(), adivinos, pares);
    int der = numero_adivinosAux(a.hijoDr(), adivinos, pares);

    pares = iz + der;
    if (a.raiz() == pares) {
        adivinos++;
    }
    if (a.raiz() % 2 == 0) {
        pares++;
    }
   
    return pares;
}

int numero_adivinos(const Arbin<int>& a) {

    int ret = 0;

    numero_adivinosAux(a, ret, 0);

    return ret;
}

Arbin<int> lee_arbol(istream& in) {
    char c;
    in >> c;
    switch (c) {
    case '#': return Arbin<int>();
    case '[': {
        int raiz;
        in >> raiz;
        in >> c;
        return Arbin<int>(raiz);
    }
    case '(': {
        Arbin<int> iz = lee_arbol(in);
        int raiz;
        in >> raiz;
        Arbin<int> dr = lee_arbol(in);
        in >> c;
        return Arbin<int>(iz, raiz, dr);
    }
    default: return Arbin<int>();
    }
}


int main() {
    Arbin<int> arbol;
    while (cin.peek() != EOF) {
        Arbin<int> a = lee_arbol(cin);
        cout << numero_adivinos(a) << endl;
        string resto_linea;
        getline(cin, resto_linea);
    }
    return 0;
}