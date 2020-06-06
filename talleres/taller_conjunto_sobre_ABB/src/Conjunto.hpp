
#include "Conjunto.h"

template<class T>
Conjunto<T>::Conjunto(): _raiz(nullptr) {}

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v): valor(v), izq(nullptr), der(nullptr), _cant(0) {}

template<class T>
Conjunto<T>::~Conjunto() {
    _vaciar(_raiz);
    _raiz = nullptr;
}

template<class T>
bool Conjunto<T>::pertenece(const T &clave) const {
    if (_raiz == nullptr) {
        return false;
    }

    Nodo *nextNodo = _raiz;
    while (nextNodo != nullptr) {
        if (nextNodo->valor == clave) {
            return true;
        }

        if (nextNodo->valor > clave) {
            nextNodo = nextNodo->izq;
        } else {
            nextNodo = nextNodo->der;
        }
    }
    return false;
}

template<class T>
void Conjunto<T>::insertar(const T &clave) {
    Nodo *newNodo = new Nodo(clave);
    if (_raiz == nullptr) {
        _raiz = newNodo;
        return;
    }

    if (pertenece(clave)) {
        delete newNodo;
        return;
    }


    Nodo *nextNodo = _raiz;
    while (nextNodo != newNodo) {
        nextNodo->_cant++;
        if (nextNodo->valor < newNodo->valor) {
            if (nextNodo->der != nullptr) {
                nextNodo = nextNodo->der;
            } else {
                nextNodo->der = newNodo;
                nextNodo = newNodo;
            }
        } else {
            if (nextNodo->izq != nullptr) {
                nextNodo = nextNodo->izq;
            } else {
                nextNodo->izq = newNodo;
                nextNodo = newNodo;
            }
        }
    }

}

template<class T>
void Conjunto<T>::remover(const T &clave) {
    if (_raiz->valor == clave && _raiz->izq == nullptr && _raiz->der == nullptr) {
        delete _raiz;
        _raiz = nullptr;
        return;
    }
    _remover(clave, _raiz);
}

template<class T>
const T &Conjunto<T>::siguiente(const T &clave) {
    vector<T> v(_raiz->_cant+1);
    _raiz->inOrder(v, 0);
    int i = 0;
    while (i < v.size()) {
        if (v[i] == clave) {
            break;
        }
        i++;
    }
    Nodo* nodo = _obtenerNodo(v[i+1]);
    v.clear();
    return nodo->valor;
}

template<class T>
const T &Conjunto<T>::minimo() const {
    return _minimo(_raiz)->valor;

}

template<class T>
const T &Conjunto<T>::maximo() const {
    return _maximo(_raiz)->valor;
}

template<class T>
unsigned int Conjunto<T>::cardinal() const {
    if (_raiz == nullptr) return 0;
    return _raiz->_cant + 1;
}

template<class T>
void Conjunto<T>::mostrar(std::ostream &) const {
    assert(false);
}

template<class T>
typename Conjunto<T>::Nodo *Conjunto<T>::_maximo(Conjunto::Nodo *nodo) const {
    if (nodo == nullptr) {
        return 0;
    }

    if (nodo->der == nullptr) {
        return nodo;
    }
    return _maximo(nodo->der);
}

template<class T>
typename Conjunto<T>::Nodo *Conjunto<T>::_minimo(Nodo *nodo) const {
    if (nodo == nullptr) {
        return 0;
    }

    if (nodo->izq == nullptr) {
        return nodo;
    }

    return _minimo(nodo->izq);
}

template<class T>
void Conjunto<T>::_vaciar(Conjunto::Nodo *node) {
    if (node != nullptr) {
        _vaciar(node->izq);
        _vaciar(node->der);
        delete node;
    }
}

template<class T>
typename Conjunto<T>::Nodo *Conjunto<T>::_remover(const T &clave, Conjunto::Nodo *node) {
    if (node == NULL) return node;
    if(node->_cant != 0) node->_cant--;
    if (clave < node->valor)
        node->izq = _remover(clave, node->izq);
    else if (clave > node->valor)
        node->der = _remover(clave, node->der);
    else{
        bool removerRaiz = false;
        if (clave == _raiz->valor) removerRaiz = true;
        if (node->izq == NULL && node->der == NULL) {
            delete node;
            return NULL;
        } else if (node->izq == NULL){
            Nodo *temp = node->der;
            delete node;
            if (removerRaiz) _raiz = temp;
            return temp;
        }
        else if (node->der == NULL){
            Nodo *temp = node->izq;
            delete node;
            if (removerRaiz) _raiz = temp;
            return temp;
        }
        Nodo* temp = _minimo(node->der);
        node->valor = temp->valor;
        node->der = _remover(temp->valor, node->der);
        if (removerRaiz) _raiz = node;
    }
    return node;
}

template<class T>
typename Conjunto<T>::Nodo *Conjunto<T>::_obtenerNodo(const T &clave) {
    if (_raiz == nullptr) {
        return nullptr;
    }

    Nodo *nextNodo = _raiz;
    while (nextNodo != nullptr) {
        if (nextNodo->valor == clave) {
            return nextNodo;
        }

        if (nextNodo->valor > clave) {
            nextNodo = nextNodo->izq;
        } else {
            nextNodo = nextNodo->der;
        }
    }
    return nullptr;
}

template<class T>
void Conjunto<T>::Nodo::inOrder(vector<T>& v, int cantAnt) {
    int indice = cantIzq() + cantAnt;
    v[indice] = valor;

    if (izq != nullptr) izq->inOrder(v, cantAnt);
    if (der != nullptr) der->inOrder(v, indice + 1);
}

template<class T>
int Conjunto<T>::Nodo::cantIzq() {
    if (izq == nullptr) return 0;
    return izq->_cant+1;
}

