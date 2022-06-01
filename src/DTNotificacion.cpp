#include "../include/cabezales/DTNotificacion.hh"

string DTNotificacion::getAutor() {
	return autor;
}

int DTNotificacion::getPuntaje() {
	return puntaje;
}

string DTNotificacion::getComentario() {
	return comentario;
}
	
DTNotificacion::DTNotificacion() {
    autor = "";
    puntaje = 0;
    comentario = ""; 
}

DTNotificacion::DTNotificacion(string UnAutor, int UnPuntaje, string UnComentario) {
    autor = UnAutor;
    puntaje = UnPuntaje;
    comentario = UnComentario;
}

DTNotificacion::~DTNotificacion() {
}