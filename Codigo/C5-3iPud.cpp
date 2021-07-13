#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include <assert.h>

using namespace std;

using cancion = string;
using artista = string;

class iPud {

private:

    unordered_map<cancion, int> cancionDuracionMap;
    unordered_map<cancion, list<cancion>::iterator> playListMap;
    unordered_map<cancion, list<cancion>::iterator> playedListMap;
    list<cancion> playList;

    list<cancion> playedList;

    int tiempo = 0;

public:

    void addSong(cancion S, artista A, int D) {

        auto it = cancionDuracionMap.find(S);

        if (it == cancionDuracionMap.cend()) {
            cancionDuracionMap.insert({ S, D });
        }
        else {
            throw domain_error("ERROR");
        }

    }

    void addToPlaylist(cancion S) {

        auto it = cancionDuracionMap.find(S);

        if (it == cancionDuracionMap.cend()) {
            throw domain_error("ERROR");
        }
        else {
            auto it2 = playListMap.find(S);
            if (it2 == playListMap.cend()) {
                playList.push_back(S);
                playListMap.insert({ S, playList.end() });
                tiempo += it->second;
            }
            else {
                throw domain_error("ERROR");
            }
        }

    }

    cancion current() {
        if (!playList.empty()) {
            return playList.front();
            
        }
        else {
            throw domain_error("current");
        }
        
    }

    void play() {
        if (!playList.empty()) {
            cancion cancion = playList.front();
            playList.pop_front();
            playListMap.erase(cancion);

            auto it = playedListMap.find(cancion);
            if (it != playedListMap.end()) {
                playedList.erase(it->second);
                playedListMap.erase(it);
            }
            
            playedList.push_front(cancion);
            playedListMap.insert({ cancion, playedList.begin() });
            tiempo -= cancionDuracionMap.at(cancion);
        }
    }

    int totalTime() {
        return tiempo;
    }

    list<cancion> recent(int N) {
        list<cancion> lista;
        auto it = playedList.cbegin();
        int i = 0;
        while (it != playedList.cend() && i < N) {

            lista.push_back(*it);

            i++;
            it++;
        }
        return lista;
    }

    void deleteSong(cancion S) {
        auto it = cancionDuracionMap.find(S);
        auto it2 = playListMap.find(S);
        auto it3 = playedListMap.find(S);

        if (it != cancionDuracionMap.cend()) {
            cancionDuracionMap.erase(it);
        }

        if (it2 != playListMap.cend()) {
            tiempo -= it->second;
            playList.erase(it2->second);
            playListMap.erase(it2);

        }

        if (it3 != playedListMap.cend()) {

            playedList.erase(it3->second);
            playedListMap.erase(it3);

        }
        
    }

};

bool resuelve() {
    string operacion;
    cin >> operacion;
    if (!cin)
        return false;
    cancion tit; artista aut; int dur;
    iPud ipud;
    while (operacion != "FIN") {
        try {
            if (operacion == "addSong") {
                cin >> tit >> aut >> dur;
                ipud.addSong(tit, aut, dur);
            }
            else if (operacion == "addToPlaylist") {
                cin >> tit;
                ipud.addToPlaylist(tit);
            }
            else if (operacion == "current") {
                tit = ipud.current(); // aunque no se hace nada, puede producir error
            }
            else if (operacion == "play") {
                try {
                    string tocando = ipud.current(); // para saber si la lista es vac¨ªa
                    ipud.play();
                    cout << "Sonando " << tocando << '\n';
                }
                catch (std::exception& e) {
                    cout << "No hay canciones en la lista\n";
                }
            }
            else if (operacion == "totalTime") {
                cout << "Tiempo total " << ipud.totalTime() << '\n';
            }
            else if (operacion == "recent") {
                int N;
                cin >> N;
                auto lista = ipud.recent(N);
                if (lista.empty())
                    cout << "No hay canciones recientes\n";
                else {
                    cout << "Las " << lista.size() << " mas recientes\n";
                    for (auto const& s : lista)
                        cout << "    " << s << '\n';
                }
            }
            else if (operacion == "deleteSong") {
                cin >> tit;
                ipud.deleteSong(tit);
            }
            else { // operacion desconocida
                assert(false);
            }
        }
        catch (std::exception& e) {
            cout << "ERROR " << e.what() << '\n';
        }
        cin >> operacion;
    }
    cout << "---\n";
    return true;
}

int main() {
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelve());
#ifndef DOMJUDGE
    cin.rdbuf(cinbuf);
#endif
    return 0;
}

