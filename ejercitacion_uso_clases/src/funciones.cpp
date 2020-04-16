#include <vector>
#include <set>
#include <algorithm>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    if(s.size() == 0) {
        return vector<int>();
    }
    vector<int> res;
     for (int i = 0; i < s.size() - 1; ++i) {
         bool appear = false;
         for (int j = i+1; j < s.size() - 2; ++j) {
             if(s[i] == s[j]) {
                 appear = true;
             }
         }
         if (!appear) {
             res.push_back(s[i]);
         }
     }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> set(s.begin(), s.end());
    vector<int> res(set.begin(), set.end());
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> setA(a.begin(), a.end());
    set<int> setB(b.begin(), b.end());
    bool mismos_elementos = true;
    for(int i: b) {
       if(setA.count(i) != 1) {
            mismos_elementos = false;
       }
    }
    for(int i: a) {
        if(setB.count(i) != 1) {
            mismos_elementos = false;
        }
    }
    return mismos_elementos;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    //Jaja lo resolvi directo con set
    return mismos_elementos(a,b);
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;
    for (int number: s) {
        bool appear = false;
        for (pair<int, int> pair: res) {
            if (pair.first == number) {
                res[pair.first]++;
                appear = true;
            }
        }
        if(!appear) {
            res[number] = 1;
        }
    }
    return res;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    return vector<int>();
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    return set<int>();
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
