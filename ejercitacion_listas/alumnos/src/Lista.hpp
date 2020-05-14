#include "Lista.h"

template <class T>
Lista<T>::Lista(): length_(0) {
    this->first_ = NULL;
    this->last_ = NULL;
}

template <class T>
Lista<T>::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

template <class T>
Lista<T>::~Lista() {
    // Completar
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista& aCopiar) {
    // Completar
    return *this;
}

template <class T>
void Lista<T>::agregarAdelante(const T& elem) {
    Nodo* new_nodo = new Nodo();
    new_nodo->data = elem;
    new_nodo->prev = nullptr;
    new_nodo->next = this->first_;
    if (this->first_ != nullptr) {
        this->first_->prev = new_nodo;
    }
    this->first_ = new_nodo;
    if (this->last_ == nullptr) {
        this->last_ = new_nodo;
    }
    this->length_++;
}

template <class T>
void Lista<T>::agregarAtras(const T& elem) {
    Nodo* new_nodo = new Nodo();
    new_nodo->data = elem;
    new_nodo->next = this->first_;
    new_nodo->prev = nullptr;
    if (this->first_ != nullptr) {
        this->first_->prev = new_nodo;
    }
    this->first_ = new_nodo;
    if (this->last_ == nullptr) {
        this->last_ = new_nodo;
    }
    this->length_++;
}

template <class T>
void Lista<T>::eliminar(Nat i) {

}

template <class T>
int Lista<T>::longitud() const {
    return length_;
}

template <class T>
const int& Lista<T>::iesimo(Nat i) const {
    Nodo* selected_nodo = this->first_;
    int counter = 0;
    while (counter < i) {
        selected_nodo = selected_nodo->next;
        counter++;
    }
    return selected_nodo->data;
}

template <class T>
int& Lista<T>::iesimo(Nat i) {
    Nodo* selected_nodo = this->first_;
    int counter = 0;
    while (counter < i) {
        selected_nodo = selected_nodo->next;
        counter++;
    }
    return selected_nodo->data;
}

template <class T>
void Lista<T>::mostrar(ostream& o) {
    // Completar
}
