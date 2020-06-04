
#include "Conjunto.h"

template<class T>
Conjunto<T>::Conjunto(): _raiz(nullptr) {}

template<class T>
Conjunto<T>::~Conjunto() {
    _vaciar(_raiz);
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
    if (pertenece(clave)) {
        return;
    }

    Nodo *newNodo = new Nodo(clave);

    if (_raiz == nullptr) {
        _raiz = newNodo;
        _raiz->_cant = 1;
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
    _remover(clave, _raiz);
}

template<class T>
void Conjunto<T>::_remover(const T &clave, Nodo *node) {
    Nodo *temp;
    node->_cant--;
    if (node == nullptr)
        return;
    else if (clave < node->valor)
        _remover(clave, node->izq);
    else if (clave > node->valor)
        _remover(clave, node->der);
    else if (node->izq && node->der) {
        temp = _minimo(node->der);
        node->valor = temp->valor;
        _remover(node->valor, node->der);
    } else {
        if (node->izq == nullptr && node->der == nullptr) {
            delete node;
        } else if (node->izq == nullptr) {
            temp = node;
            node->valor = node->der->valor;
            node->der = node->der->der;
            node->izq = node->der->izq;
            delete temp;
        } else if (node->der == nullptr) {
            temp = node;
            node->valor = node->izq->valor;
            node->der = node->izq->der;
            node->izq = node->izq->izq;
            delete temp;

        }
    }
}

template<class T>
const T &Conjunto<T>::siguiente(const T &clave) {

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
unsigned int Conjunto<T>::cardinal() const {
    if (_raiz == nullptr) return 0;
    return _raiz->_cant;
}

template<class T>
unsigned int Conjunto<T>::_cardinal(const Nodo *nodo) const {
    if (nodo == nullptr) {
        return 0;
    }
    return 1 + _cardinal(nodo->izq) + _cardinal(nodo->der);
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
void Conjunto<T>::_vaciar(Conjunto::Nodo *node) {
    if (node == nullptr) {
        return;
    }
    _vaciar(node->izq);
    _vaciar(node->der);
    delete node;
}

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v): valor(v), izq(nullptr), der(nullptr) {}



