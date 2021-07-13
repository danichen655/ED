// Autores: HongXiang Chen y XingXiang Zhu
// Juez : C23 y C103

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

using Estado = string;
using Partido = string;


class ConteoVotos {

private:

    typedef struct {

        int num_compromisarios;
        unordered_map<Partido, int> bibliotecaPartido;
        unordered_map<Partido, int>::iterator itGanador;
    }vEstado;

    unordered_map<Estado, vEstado> bibliotecaEstado;
    map<Partido, int> partidosMap;

public:
    // Anotacion:
    // n = el tamanho total de la biblioteca

    // find tiene coste lineal O(n)
    // insert tiene coste O(n+1) = O(n), ya que tiene que insertar en la ultima posicion libre.
    // => esta funcione tiene coste lineal.
    void nuevo_estado(const Estado& nombre, int num_compromisarios) {

        auto it = bibliotecaEstado.find(nombre);

        if (it == bibliotecaEstado.end()) {
            bibliotecaEstado.insert({ nombre, {num_compromisarios} });
        }
        else {
            throw domain_error("Estado ya existente");
        }
    }

    // la primera parte tiene coste lineal como explicado en la anterior funcion con los costes de find e insert.
    //Segunda parte: el find de partidosMap es O(log n) ya que usamos usamos un mapa ordenado, y hace una busqueda binaria.
    //              el insert de partidosMap tambien es O(log n) ya que usamos usamos un mapa ordenado, y hace una busqueda binaria.
    //y las operaciones de esta funcion tiene un coste constante.
    //=> esta funcione tiene un coste de O(n).

    void sumar_votos(const Estado& estado, const Partido& partido, int num_votos) {

        auto it = bibliotecaEstado.find(estado);

        if (it == bibliotecaEstado.cend()) {
            throw domain_error("Estado no encontrado");
        }
        else {
            // 1ªparte
            auto it2 = it->second.bibliotecaPartido.find(partido);

            if (it2 == it->second.bibliotecaPartido.cend()) {

                it->second.bibliotecaPartido.insert({ partido,num_votos });
                it2 = it->second.bibliotecaPartido.find(partido);
            }
            else {
                it2->second += num_votos;
            }
            // fin 1ªparte
            //2ª parte
            if (it->second.bibliotecaPartido.size() == 1) { // cuando no habias partidos
                it->second.itGanador = it2;
                
                auto itAux = partidosMap.find(partido);
                if (itAux == partidosMap.end()) { // si no encuentra el partido y lo anhade
                    partidosMap.insert({ partido, it->second.num_compromisarios });
                }else { // existe en el mapa de partido y lo actualiza
                    itAux->second += it->second.num_compromisarios;
                }
            }
            else if (it->second.itGanador->second < it2->second) { 
                //quitamos los compromisarios del partido ganador anterior
                auto itGanadorAnt = partidosMap.find(it->second.itGanador->first);
                 
                itGanadorAnt->second -= it->second.num_compromisarios;

                it->second.itGanador = it2;
                // Y le sumamos los numeros de compromisarios actual.
                auto itGanadorAct = partidosMap.find(partido);
                if (itGanadorAct == partidosMap.end()) { // si no esta el nuevo partido ganador
                    partidosMap.insert({ partido, it->second.num_compromisarios });
                }
                else { // si esta ya el partido

                    itGanadorAct->second += it->second.num_compromisarios;
                }
            }
            //fin 2ªparte
        }
    }

    //En esta funcion por tener el find del unordered map, es de coste lineal O(n).
    Partido ganador_en(const Estado& estado) const {
        int ganador = 0;
        Partido p;

        auto it = bibliotecaEstado.find(estado);

        if (it == bibliotecaEstado.cend()) {
            throw domain_error("Estado no encontrado");
        }


        return it->second.itGanador->first;
    }


    /* vector<pair<Partido, int>> resultados() const {

         vector<pair<Partido, int>> resul;
         auto it = bibliotecaEstado.begin();
         Partido pa;

         while (it != bibliotecaEstado.cend()) {

             pa= ganador_en(it->first);
             auto it2 = find_if(resul.begin(), resul.end(), [pa](const pair <string, int>& p) {
                 return p.first == pa;
              });

             if (it2 == resul.end()) {

                 resul.push_back({ pa,it->second.num_compromisarios });

             }
             else {
                 it2->second += it->second.num_compromisarios;
             }


             it++;
         }
         sort(resul.begin(), resul.end());
         return resul;
     }
  }; */

    /*vector<pair<Partido, int>> resultados() const {
        map<Partido, int> mapR;
        vector<pair<Partido, int>> resul;
        auto it = bibliotecaEstado.begin();
        Partido p;

        while (it != bibliotecaEstado.cend()) {

            p = ganador_en(it->first);
            auto it2 = mapR.find(p);

            if (it2 == mapR.cend()) {

                mapR.insert({ p,it->second.num_compromisarios });

            }
            else {
                it2->second += it->second.num_compromisarios;
            }


            it++;
        }

        auto it3 = mapR.begin();
        while (it3 != mapR.cend()) {

            resul.push_back({ it3->first,it3->second });
            it3++;

        }

        return resul;
    }*/

    // Esta funcion tambien tiene coste O(n), ya que tenemos que recorrer todo el map para insertar en nuestro vector<pair<...>>
    vector<pair<Partido, int>> resultados() const {

        vector<pair<Partido, int> > v;
        //copy(partidosMap.begin(), partidosMap.end(), back_inserter(v));

        auto it3 = partidosMap.cbegin();
        while (it3 != partidosMap.cend()) {
            if (it3->second > 0) {
                v.push_back({ it3->first,it3->second });
            }
            it3++;
        }

        return v;
    }
};


bool resuelveCaso() {
    string comando;
    cin >> comando;
    if (!cin) return false;

    ConteoVotos elecciones;

    while (comando != "FIN") {
        try {
            if (comando == "nuevo_estado") {
                Estado estado;
                int num_compromisarios;
                cin >> estado >> num_compromisarios;
                elecciones.nuevo_estado(estado, num_compromisarios);
            }
            else if (comando == "sumar_votos") {
                Estado estado;
                Partido partido;
                int num_votos;
                cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(estado, partido, num_votos);
            }
            else if (comando == "ganador_en") {
                Estado estado;
                cin >> estado;
                Partido ganador = elecciones.ganador_en(estado);
                cout << "Ganador en " << estado << ": " << ganador << "\n";
            }
            else if (comando == "resultados") {

                for (const auto it : elecciones.resultados()) {
                    cout << it.first << " " << it.second << "\n";
                }
            }
        }
        catch (std::exception& e) {
            cout << e.what() << "\n";
        }
        cin >> comando;
    }

    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {}

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
