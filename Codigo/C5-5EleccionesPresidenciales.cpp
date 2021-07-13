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
 
    
    


public:

    void nuevo_estado(const Estado &nombre, int num_compromisarios) {
  
        auto it = bibliotecaEstado.find(nombre);

        if (it == bibliotecaEstado.end()) {
            bibliotecaEstado.insert({ nombre, {num_compromisarios} });
         
        }
        else {
            throw domain_error("Estado ya existente");
        }
    }  

    void sumar_votos(const Estado &estado, const Partido &partido, int num_votos) {
  

        auto it = bibliotecaEstado.find(estado);

        if (it == bibliotecaEstado.cend()) {
            throw domain_error("Estado no encontrado");
        }
        else {
        
            auto it2 = it->second.bibliotecaPartido.find(partido);

            if (it2 == it->second.bibliotecaPartido.cend()) {

                it->second.bibliotecaPartido.insert({ partido,num_votos });
                it2 = it->second.bibliotecaPartido.find(partido);
            }
            else {

                it2->second += num_votos;
            }

            
            if (it->second.bibliotecaPartido.size() == 1 ) {
                it->second.itGanador = it2;
               
            }else if(it->second.itGanador->second < it2->second){
                
                it->second.itGanador = it2;
            }
                      
        }

        
    }

    Partido ganador_en(const Estado &estado) const {
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

    vector<pair<Partido, int>> resultados() const {
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
            } else if (comando == "sumar_votos") {
                Estado estado;
                Partido partido;
                int num_votos;
                cin >> estado >> partido >> num_votos;
                elecciones.sumar_votos(estado, partido, num_votos);
            } else if (comando == "ganador_en") {
                Estado estado;
                cin >> estado;
                Partido ganador  = elecciones.ganador_en(estado);
                cout << "Ganador en " << estado << ": " << ganador << "\n";
            } else if (comando == "resultados") {
           
                for (const auto it : elecciones.resultados()) {
                    cout << it.first << " " << it.second << "\n";
                }
            }
        } catch (std::exception &e) {
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

    while(resuelveCaso()) { }

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
