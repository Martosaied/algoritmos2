#include "Lista.h"

template <class T>
Lista<T>::Lista(): length_(0), first_(nullptr), last_(nullptr) {}

template <class T>
Lista<T>::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

template <class T>
Lista<T>::~Lista() {
    this->delete_all();
}

template <class T>
Lista<T>& Lista<T>::operator=(const Lista& aCopiar) {
    if (this->length_ != 0) this->delete_all();
    this->length_ = 0;
    for (int i = 0; i < aCopiar.longitud(); ++i) {
        this->agregarAtras(aCopiar.iesimo(i));
    }
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
    new_nodo->prev = this->last_;
    new_nodo->next = nullptr;
    if (this->last_ != nullptr) {
        this->last_->next = new_nodo;
    }
    this->last_ = new_nodo;
    if (this->first_ == nullptr) {
        this->first_ = new_nodo;
    }
    this->length_++;
}

template <class T>
void Lista<T>::eliminar(Nat i) {
    int counter = 0;
    Nodo* node_to_delete = this->first_;
    while(counter < i) {
        node_to_delete = node_to_delete->next;
        counter++;
    }

    Nodo* prev = node_to_delete->prev;
    Nodo* next = node_to_delete->next;

    if (prev != nullptr) {
        prev->next = next;
    }
    if (next != nullptr) {
        next->prev = prev;
    }

    if (i == 0) {
        this->first_ = next;
    }
    if (i == this->length_-1) {
        this->last_ = prev;
    }

    delete node_to_delete;
    this->length_--;
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

template<class T>
void Lista<T>::delete_all() {
    while (this->first_ != nullptr) {
        this->eliminar(0);
    }
}
