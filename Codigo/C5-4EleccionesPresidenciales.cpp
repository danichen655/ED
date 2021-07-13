#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>

using namespace std;

using Estado = string;
using Partido = string;
typedef unordered_map <Partido, int> partidoVotos;

class ConteoVotos {

private:
    
    unordered_map<Estado, int> bibliotecaEstado;
    unordered_map<Estado, partidoVotos> bibliotecaPartido;
    
public:

    void nuevo_estado(const Estado &nombre, int num_compromisarios) {
  
        auto it = bibliotecaEstado.find(nombre);

        if (it == bibliotecaEstado.end()) {
            bibliotecaEstado.insert({ nombre, num_compromisarios });
         
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
            partidoVotos pVotos;
            bibliotecaPartido.insert({ estado,pVotos });
            auto it2 = bibliotecaPartido.find(estado);
            auto it3 = it2->second.find(partido);
           
            if (it2 == bibliotecaPartido.cend() || it3 == it2->second.cend()) {

                it2->second.insert({ partido,num_votos });
            }
            else {
               
                it3->second += num_votos;
            }

            
        }

        
    }

    Partido ganador_en(const Estado &estado) const {
        int ganador = 0;
        Partido p;

        auto it = bibliotecaPartido.find(estado);

        if (it == bibliotecaPartido.cend()) {
            throw domain_error("Estado no encontrado");
        }

        auto it2 = it->second.begin();

        while (it2 != it->second.end()) {

            if (ganador < it2->second) {

                ganador = it2->second;
                p = it2->first;
            }
            it2++;
        }
      
        return p;
    }

    vector<pair<Partido,int>> resultados() const {
        map<Partido, int> mapR;
        vector<pair<Partido, int>> resul;
        auto it = bibliotecaEstado.begin();
        Partido p;
    
        while (it != bibliotecaEstado.cend()) {
        
            p = ganador_en(it->first);
            auto it2 = mapR.find(p);

            if (it2 == mapR.cend()) {

                mapR.insert({ p,it->second });

            }
            else {
                it2->second += it->second;
            }
            
        
            it++;
        }

        auto it3 = mapR.begin();
        int i = 0;
        while (it3 != mapR.cend()) {

            resul.push_back({ it3->first,it3->second });
            i++;
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
