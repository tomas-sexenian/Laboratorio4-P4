#include "../include/cabezales/DTInfoUsuario.hh"

DTInfoUsuario::~DTInfoUsuario() {
}

DTInfoUsuario::DTInfoUsuario() {
    nombre = "";
    email = "";
}

DTInfoUsuario::DTInfoUsuario(string UnNombre, string UnEmail) {
    nombre = UnNombre;
    email = UnEmail;
}

string DTInfoUsuario::getNombre() {
    return nombre;
}

string DTInfoUsuario::getEmail() {
    return email;
}
