
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
    raiz = _copy(d.raiz);
}

template <typename T>
typename string_map<T>::Nodo* string_map<T>::_copy(Nodo* nodeToCopy) {
    if (nodeToCopy == nullptr) {
        return NULL;
    }
    Nodo* treeNew = new Nodo();
    treeNew->definicion = nodeToCopy->definicion;
    for (int i = 0; i < 256; ++i) {
        treeNew->siguientes[i] = _copy(nodeToCopy->siguientes[i]);
    }
    return treeNew;
}

template <typename T>
string_map<T>::~string_map(){
    _vaciar(raiz);
    raiz = nullptr;
}

template<class T>
void string_map<T>::_vaciar(string_map::Nodo *node) {
    if (node != nullptr) {
        for (int i = 0; i < 256; ++i) {
            _vaciar(node->siguientes[i]);
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
    return _count(clave, raiz) ? 1 : 0;
}

template <typename T>
bool string_map<T>::_count(const string& clave, string_map::Nodo *actualNode) const {
    if (clave == "") {
        return actualNode->definicion != NULL;
    }

    int firstChar = int(clave[0]);
    if (actualNode->siguientes[firstChar] == nullptr) {
        Nodo* newNode = new Nodo();
        actualNode->siguientes[firstChar] = newNode;
    }
    string claveNoConstante = clave;
    claveNoConstante.erase(0, 1);
    return _count(claveNoConstante, actualNode->siguientes[firstChar]);
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
        actualNode->definicion = new T(data.second);
        _size++;
        return;
    }

    int firstChar = int(data.first[0]);
    if (actualNode->siguientes[firstChar] == NULL) {
        Nodo* newNodo = new Nodo();
        actualNode->siguientes[firstChar] = newNodo;
    }
    string poppedString = data.first;
    poppedString.erase(0, 1);
    pair<string, T> newPair (poppedString, data.second);
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
        Nodo* newNode = new Nodo();
        actualNode->siguientes[firstChar] = newNode;
    }
    clave.erase(0, 1);
    return _at(clave, actualNode->siguientes[firstChar]);
}
