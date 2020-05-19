#include <vector>
#include <set>
#include <algorithm>
#include "algobot.h"

bool masDeUnaAparicion(vector<int> vector, int i);

bool conjuntoEqual(set<LU> vector, set<LU> set);

bool duplicated(vector<set<LU>> vector, set<LU> set);

bool seRepite(vector<set<LU>> vector);

bool pertenece(set<LU> set, LU lu);

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
    vector<int> res;
    for(int i: s) {
        if(!masDeUnaAparicion(s, i)) {
            res.push_back(i);
        }
    }
    return res;
}

bool masDeUnaAparicion(vector<int> s, int i) {
    int counter = 0;
    for(int j: s) {
        if (j == i) {
            counter++;
        }
    }
    return counter > 1;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for (int i: a) {
        if(a.count(i) == 1 && b.count(i) == 1) {
            res.insert(i);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for (int number: s) {
        bool appear = false;
        for (pair<int, set<int>> pair: res) {
            if (pair.first == number % 10) {
                res[pair.first].insert(number);
                appear = true;
            }
        }
        if(!appear) {
            set<int> newMap;
            newMap.insert(number);
            res[number % 10] = (newMap);
        }
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    for (char letra: str) {
        bool appear = false;
        for (pair<char, char> charPair: tr) {
            if(charPair.first == letra) {
                res.push_back(charPair.second);
                appear = true;
            }
        }
        if (!appear) {
            res.push_back(letra);
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    vector<set<LU>> conjuntoDeLUs;
    for (Mail mail: s) {
        set<LU> LUs = mail.libretas();
        if (!duplicated(conjuntoDeLUs, LUs)) {
            conjuntoDeLUs.push_back(LUs);
        }
    }


    return seRepite(conjuntoDeLUs);
}

bool seRepite(vector<set<LU>> s) {
    for (set<LU> i: s) {
        for (LU lu: i) {
            int apariciones = 0;
            for (set<LU> j: s) {
                if(pertenece(j, lu)) {
                    apariciones++;
                }
            }
            if(apariciones > 1) {
                return true;
            }
        }
    }
    return false;
}

bool pertenece(set<LU> lus, LU lu) {
    for (LU j: lus) {
        if (lu.anio() == j.anio() && lu.numero() == j.numero()) {
            return true;
        }
    }
    return false;
}

bool duplicated(vector<set<LU>> conjunto_lus, set<LU> lus) {
    for(set<LU> i: conjunto_lus) {
        if (conjuntoEqual(i, lus)) {
            return true;
        }
    }
    return false;
}

bool conjuntoEqual(set<LU> lus1, set<LU> lus2) {
    bool equal = true;
    for (LU i: lus1) {
        if(!pertenece(lus2, i)) {
            equal = false;
        }
    }
    for (LU i: lus2) {
        if(!pertenece(lus1, i)) {
            equal = false;
        }
    }
    return equal;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> entregas_finales;
    for(Mail mail: s) {
        set<LU> libretas = mail.libretas();
        bool adjunto = mail.adjunto();
        bool aparece = false;
        for (pair<set<LU>, Mail> pair: entregas_finales) {
            if(!conjuntoEqual(mail.libretas(), pair.first) && adjunto) {
                entregas_finales[mail.libretas()] = mail;
                aparece = true;
            }
        }
        if(!aparece && adjunto) {
            entregas_finales[mail.libretas()] = mail;
        }
    }
    return entregas_finales;
}
