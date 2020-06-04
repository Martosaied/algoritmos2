
#include "Conjunto.h"

template<class T>
Conjunto<T>::Conjunto(): _raiz(nullptr) {}

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
        _raiz->_cant = 1;
    }

    if (pertenece(clave)) {
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
    _remover(clave, _raiz);
}

template<class T>
void Conjunto<T>::_remover(const T &clave, Nodo *node) {
    if (clave == _raiz->valor && _raiz->izq == nullptr && _raiz->der == nullptr) {
        _raiz = nullptr;
    }
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
            temp = node->der;
            node->valor = node->der->valor;
            node->der = (node->der) ? node->der->der : NULL;
            node->izq = (node->der) ? node->der->izq : NULL;
            delete temp;
        } else if (node->der == nullptr) {
            temp = node->izq;
            node->valor = node->izq->valor;
            node->der = (node->izq) ? node->izq->der : NULL;
            node->izq = (node->izq) ? node->izq->izq : NULL;
            delete temp;
        }
    }
}

template<class T>
const T &Conjunto<T>::siguiente(const T &clave) {
    vector<T> v(_raiz->_cant, 0);
    _raiz->inOrder(v, 0);
    int indice = -1;
    int i = 0;
    while (indice == -1) {
        if (v[i] != clave) {
            i++;
        } else {
            indice = i;
        }
    }
    return 6;
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
    if (node != nullptr) {
        _vaciar(node->izq);
        _vaciar(node->der);
        delete node;
    }

}

template<class T>
Conjunto<T>::Nodo::Nodo(const T &v): valor(v), izq(nullptr), der(nullptr), _cant(0) {}

template<class T>
void Conjunto<T>::Nodo::inOrder(vector<T> &v, int cantAnt) {
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