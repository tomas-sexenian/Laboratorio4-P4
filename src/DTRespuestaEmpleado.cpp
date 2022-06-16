#include "../include/cabezales/DTRespuestaEmpleado.hh"

string DTRespuestaEmpleado::getEmailEmpleado() {
	return emailEmpleado;
}

string DTRespuestaEmpleado::getComentario() {
	return comentario;
}

DTFecha DTRespuestaEmpleado::getFecha() {
	return fecha;
}
	
DTRespuestaEmpleado::DTRespuestaEmpleado() {
    emailEmpleado = "";
    comentario = "";
    fecha = DTFecha();
}

DTRespuestaEmpleado::DTRespuestaEmpleado(string UnEmail, string UnComentario, DTFecha UnaFecha) {
    comentario = UnComentario;
    emailEmpleado = UnEmail;
    fecha= UnaFecha;
}

DTRespuestaEmpleado::~DTRespuestaEmpleado() {
    delete &this->fecha;
}