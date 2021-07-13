/*#include <iostream>
#include "Arbin.h"

using  namespace std;


int numero_neutros(const Arbin<int>& a, int& neutros, int postivos) {

    if (a.esVacio()) {
        return postivos;
    }

    int iz = numero_neutros(a.hijoIz(), neutros, postivos);
    int der = numero_neutros(a.hijoDr(), neutros, postivos);

    if (a.raiz() > 0) {
        postivos++;
    }
        
    if (iz == der) {
        neutros++;
    }

    postivos += iz + der;

    return postivos;
}

int numero_neutros(const Arbin<int> &a) {
    int ret = 0;
    numero_neutros(a, ret, 0);
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
        cout << numero_neutros(a) << endl;
        string resto_linea;
        getline(cin, resto_linea);
    }
    return 0;
}*/