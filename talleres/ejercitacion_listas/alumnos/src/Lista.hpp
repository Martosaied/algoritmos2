#include "Lista.h"

Lista::Lista(): length_(0), first_(nullptr), last_(nullptr) {}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    this->delete_all();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    if (this->length_ != 0) this->delete_all();
    this->length_ = 0;
    for (int i = 0; i < aCopiar.longitud(); ++i) {
        this->agregarAtras(aCopiar.iesimo(i));
    }
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
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

void Lista::agregarAtras(const int& elem) {
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

void Lista::eliminar(Nat i) {
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

int Lista::longitud() const {
    return length_;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* selected_nodo = this->first_;
    int counter = 0;
    while (counter < i) {
        selected_nodo = selected_nodo->next;
        counter++;
    }
    return selected_nodo->data;
}

int& Lista::iesimo(Nat i) {
    Nodo* selected_nodo = this->first_;
    int counter = 0;
    while (counter < i) {
        selected_nodo = selected_nodo->next;
        counter++;
    }
    return selected_nodo->data;
}

void Lista::mostrar(ostream& o) {
    // Completar
}

void Lista::delete_all() {
    while (this->first_ != nullptr) {
        this->eliminar(0);
    }
}
