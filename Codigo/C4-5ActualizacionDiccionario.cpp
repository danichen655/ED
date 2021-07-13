#include <sstream> //para strinstream
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

//Hay que elegir un diccionario.
//¿Necesitamos que esté ordenado? ¿Que no lo esté?

// Si, necesitamos que este ordenado, ya que tenemos que recorrer todo el diccionario en orden para ver los cambio 
typedef map<string, int> Diccionario;

//Método para leer un diccionario
void leerDiccionario(Diccionario& diccionario) {
    string linea;
    getline(cin, linea);
    stringstream lin(linea); //procesar la línea
    string clave;
    int valor;
    while (lin >> clave) {
        lin >> valor;
        diccionario.insert({clave, valor});
    }
}

//Método que hace el problema. Recibe los diccionarios antiguo y nuevo.
//Debe devolver los cambios en alguna/s estructura/s adecuada/s
void calcularCambios(const Diccionario& DiccionarioAntiguo, const Diccionario& DiccionarioNuevo, vector<string> & nuevos, vector<string> &quitados,vector<string> &modificados) {
    //Tiene como coste O(n + m) = O(n), ya que recorremos los dos diccionarios.
                // siendo n el tamaño del primer diccionario 
                // y m el segundo dicc

    //Los accesos a los claves o los valore tiene coste constante.

    auto itAnt = DiccionarioAntiguo.begin();
    auto itNew = DiccionarioNuevo.begin();

    while (itAnt != DiccionarioAntiguo.end() || itNew != DiccionarioNuevo.end()) {

        if (itAnt == DiccionarioAntiguo.end()) {
            nuevos.push_back(itNew->first);
            itNew++;
        }
        else if (itNew == DiccionarioNuevo.end()) {
            quitados.push_back(itAnt->first);
            itAnt++;
        }
        else {

            if(itAnt->first == itNew->first && itAnt->second != itNew->second){
                modificados.push_back(itAnt->first);
                itAnt++;
                itNew++;
            }
            else if (itAnt->first < itNew->first) {
                quitados.push_back(itAnt->first);
                itAnt++;
            }
            else if (itAnt->first > itNew->first) {
                nuevos.push_back(itNew->first);
                itNew++;
            }
            else { // si son iguales 
                itAnt++;
                itNew++;
            }
        }
    }
}

//Método para escribir por pantalla los cambios en los diccionarios.
void printCambios(vector<string>& nuevos, vector<string>& quitados, vector<string>& modificados) { 
    // EL tamaño seria la suma de todo los size() de todos los vectores. => O(n), como peor de los casos, hay que imprimir todo el primer diccionario y el segundo.
    
    if (nuevos.empty() && quitados.empty() && modificados.empty()) {
        cout << "Sin cambios\n";
    }
    else {

        if (!nuevos.empty()) {
            cout << "+ ";

            for (int i = 0; i < nuevos.size(); i++) {
                cout << nuevos[i];
                if (i < nuevos.size() - 1) {
                    cout << ' ';
                }
            }
            
            cout << '\n';
        }

        if (!quitados.empty()) {
            cout << "- ";
            for (int i = 0; i < quitados.size(); i++) {
                cout << quitados[i];
                if (i < quitados.size() - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }

        if (!modificados.empty()) {
            cout << "* ";
            int i = 0;

            for (int i = 0; i < modificados.size(); i++) {
                cout << modificados[i];
                if (i < modificados.size() - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
    }

    cout << "---\n";
}

//Esqueleto para resuelve caso: leemos los diccionarios, calculamos
//los cambios y los sacamos por pantalla.
void resuelveCaso() {

    Diccionario DiccionarioAntiguo, DiccionarioNuevo;

    leerDiccionario(DiccionarioAntiguo);
    leerDiccionario(DiccionarioNuevo);

    vector<string> nuevos;
    vector<string> quitados;
    vector<string> modificados;


    calcularCambios(DiccionarioAntiguo, DiccionarioNuevo, nuevos, quitados, modificados);
    printCambios(nuevos, quitados, modificados);
}

//Método main.
int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    int numCasos;
    std::cin >> numCasos;
    std::cin.ignore(1); //ignorar salto de línea
    for (int i = 0; i < numCasos; i++) {
        resuelveCaso();
    }

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
#endif

    return 0;
}
