#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes() {
}
void SistemaDeMensajes::registrarJugador(int id, string ip) {
    ConexionJugador *conn = new ConexionJugador(ip);
    this->_conns[id] = conn;
}
void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    ConexionJugador* conn = this->_conns[id];
    conn->enviarMensaje(mensaje);
}
bool SistemaDeMensajes::registrado(int id) const {
    return this->_conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const {
    return this->_conns[id]->ip();
}
SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i = 0; i < 4; i++) {
        if (_conns[i] != nullptr)
            delete _conns[i];
        if (_proxies[i] != nullptr)
            delete _proxies[i];
    }
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    if (this->registrado(id)) {
        delete _conns[id];
        _conns[id] = nullptr;
    }
}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    if(this->_proxies[id] == nullptr){
        ConexionJugador** conn = &this->_conns[id];
        this->_proxies[id] = new Proxy(conn);
    }
    return this->_proxies[id];
}