#include "Lista.h"

Lista::Lista(): length_(0), first_(nullptr), last_(nullptr) {}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    delete_all();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    if (length_ != 0) delete_all();
    length_ = 0;
    for (int i = 0; i < aCopiar.longitud(); ++i) {
        agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* new_nodo = new Nodo();
    new_nodo->data = elem;
    new_nodo->prev = nullptr;
    new_nodo->next = first_;
    if (first_ != nullptr) {
        first_->prev = new_nodo;
    }
    first_ = new_nodo;
    if (last_ == nullptr) {
        last_ = new_nodo;
    }
    length_++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* new_nodo = new Nodo();
    new_nodo->data = elem;
    new_nodo->prev = last_;
    new_nodo->next = nullptr;
    if (last_ != nullptr) {
        last_->next = new_nodo;
    }
    last_ = new_nodo;
    if (first_ == nullptr) {
        first_ = new_nodo;
    }
    length_++;
}

void Lista::eliminar(Nat i) {
    int counter = 0;
    Nodo* node_to_delete = first_;
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
        first_ = next;
    }
    if (i == length_-1) {
        last_ = prev;
    }

    delete node_to_delete;
    length_--;
}

int Lista::longitud() const {
    return length_;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* selected_nodo = first_;
    int counter = 0;
    while (counter < i) {
        selected_nodo = selected_nodo->next;
        counter++;
    }
    return selected_nodo->data;
}

int& Lista::iesimo(Nat i) {
    Nodo* selected_nodo = first_;
    int counter = 0;
    while (counter < i) {
        selected_nodo = selected_nodo->next;
        counter++;
    }
    return selected_nodo->data;
}

void Lista::mostrar(ostream& o) {
    for (int i = 0; i < length_-1; ++i) {
        o << iesimo(i) << '\n';
    }
    o << iesimo(length_-1);
}

void Lista::delete_all() {
    while (first_ != nullptr) {
        eliminar(0);
    }
}
