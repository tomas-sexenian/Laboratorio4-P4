#include "../include/cabezales/DTInfoHostal.hh"

DTInfoHostal::~DTInfoHostal() {
}

DTInfoHostal::DTInfoHostal() {
    list<string> lista;
    comentarios = lista;
    promedioCalificaciones = 0;
}

DTInfoHostal::DTInfoHostal(list<string> UnosComentarios, float UnPromedio) {
    comentarios = UnosComentarios;
    promedioCalificaciones = UnPromedio;
}

list<string> DTInfoHostal::getComentarios() {
    return comentarios;
}

float DTInfoHostal::getPromedioCalificaciones() {
    return promedioCalificaciones;
}