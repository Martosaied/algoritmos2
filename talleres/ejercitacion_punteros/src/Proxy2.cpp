#include "Proxy2.h"

// Completar ...
Proxy::Proxy(ConexionJugador** conn): _conn(conn) {}

void Proxy::enviarMensaje(string msg) {
    ConexionJugador* conn = *_conn;
    conn->enviarMensaje(msg);
}