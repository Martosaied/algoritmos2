
#include "string_map.h"

template<class T>
string_map<T>::Nodo::Nodo(): siguientes(256) {}

template <typename T>
string_map<T>::string_map(): raiz(), _size() {
    raiz = new Nodo();
    _size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    // COMPLETAR
}

template <typename T>
string_map<T>::~string_map(){
    // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    return 4;
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    // COMPLETAR
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    return _at(clave, raiz);
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    // COMPLETAR
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
        actualNode->definicion = *data.second;
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
        return actualNode->definicion;
    }

    int firstChar = int(clave[0]);
    if (actualNode->siguientes[firstChar] == nullptr) {
        Nodo* newNode = new Nodo();
        actualNode->siguientes[firstChar] = newNode;
    }
    clave.erase(0, 1);
    _at(clave, actualNode->siguientes[firstChar]);
}
