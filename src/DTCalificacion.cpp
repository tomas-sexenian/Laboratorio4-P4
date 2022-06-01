#include "../include/cabezales/DTCalificacion.hh"

int DTCalificacion::getPuntaje() {
    return puntaje;
}

string DTCalificacion::getComentario() {
    return comentario;
}

DTFecha DTCalificacion::getFecha() {
    return fecha;
}

DTCalificacion::DTCalificacion() {
    puntaje = 0;
    comentario = "";
    fecha = DTFecha();
}

DTCalificacion::DTCalificacion(int UnPuntaje, string UnComentario, DTFecha UnaFecha) {
    puntaje = UnPuntaje;
    comentario = UnComentario;
    fecha = UnaFecha;
}

DTCalificacion::~DTCalificacion() {
}
