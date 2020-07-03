
#include "string_map.h"

template<class T>
string_map<T>::Nodo::Nodo(): siguientes(256), definicion(NULL) {}

template <typename T>
string_map<T>::string_map(): raiz(), _size() {
    raiz = new Nodo();
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    _size = d._size;
    _vaciar(raiz);
    if(d.raiz != nullptr){
        raiz = new Nodo(d.raiz);
    }
}

template<typename T>
string_map<T>::Nodo::Nodo(const Nodo* aCopiar) : siguientes(256, nullptr), definicion(nullptr) {
    if(aCopiar->definicion != nullptr){
        definicion = new T(*aCopiar->definicion);
    }
    for (int i = 0; i < aCopiar->siguientes.size(); ++i) {
        if(aCopiar->siguientes[i] != nullptr){
            siguientes[i] = new Nodo(aCopiar->siguientes[i]);
        }
    }
}

template <typename T>
string_map<T>::~string_map(){
    _vaciar(raiz);
    raiz = nullptr;
}

template<class T>
void string_map<T>::_vaciar(string_map::Nodo *node) {
    if(node != nullptr){
        for (int i = 0; i < node->siguientes.size(); ++i) {
            _vaciar(node->siguientes[i]);
        }
        if(node->definicion != nullptr){
            delete node->definicion;
        }
        delete node;
    }
}


template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const {
    return _count(clave, raiz);
}

template <typename T>
int string_map<T>::_count(const string& clave, string_map::Nodo *actualNode) const {
    if (clave == "") {
        return actualNode->definicion != NULL ? 1 : 0;
    }

    int firstChar = int(clave[0]);
    if (actualNode->siguientes[firstChar] == nullptr) {
        actualNode->siguientes[firstChar] = new Nodo();
    }
    string claveNoConstante = clave;
    return _count(claveNoConstante.erase(0, 1), actualNode->siguientes[firstChar]);
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    return _at(clave, raiz);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    return _at(clave, raiz);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    int i = 0;
    Nodo* lastNodeDef = new Nodo();
    int lastIndex = 0;
    Nodo* actualNode = raiz;
    while (i < clave.size()) {
        actualNode = actualNode->siguientes[int(clave[i])];
        if (i + 1 == clave.size()) {
            delete actualNode->definicion;
            actualNode->definicion = NULL;
        }
        int cantHijos = 0;
        for (int j = 0; j < 256; ++j) {
            if (actualNode->siguientes[j] != NULL) {
                cantHijos++;
            }
        }
        if (cantHijos > 2 || actualNode->definicion != NULL) {
            lastNodeDef = actualNode->siguientes[int(clave[i])];
            lastIndex = int(clave[i+1]);
        }
        i++;
    }
    _vaciar(lastNodeDef->siguientes[lastIndex]);
    delete lastNodeDef;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

template<typename T>
void string_map<T>::_insert(const pair<string, T>& data, string_map::Nodo* actualNode) {
    if (data.first == "") {
        if (actualNode->definicion != nullptr) {
            delete actualNode->definicion;
        } else {
            _size++;
        }
        actualNode->definicion = new T(data.second);
        return;
    }

    int firstChar = int(data.first[0]);
    if (actualNode->siguientes[firstChar] == NULL) {
        actualNode->siguientes[firstChar] = new Nodo();
    }
    string stringToErase = data.first;
    pair<string, T> newPair (stringToErase.erase(0, 1), data.second);
    _insert(newPair, actualNode->siguientes[firstChar]);
}

template<typename T>
void string_map<T>::insert(const pair<string, T>& data) {
    return _insert(data, raiz);
}

template<typename T>
T& string_map<T>::_at(string clave, string_map::Nodo *actualNode) {
    if (clave == "") {
        return *actualNode->definicion;
    }
    int firstChar = int(clave[0]);
    if (actualNode->siguientes[firstChar] == nullptr) {
        actualNode->siguientes[firstChar] = new Nodo();
    }
    return _at(clave.erase(0, 1), actualNode->siguientes[firstChar]);
}
