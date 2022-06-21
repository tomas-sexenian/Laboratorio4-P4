#include "../include/cabezales/DTRespuestaEmpleado.hh"


string DTRespuestaEmpleado::getComentario() {
	return comentario;
}

DTFecha DTRespuestaEmpleado::getFecha() {
	return fecha;
}
	
DTRespuestaEmpleado::DTRespuestaEmpleado() {
    comentario = "";
    fecha = DTFecha();
}

DTRespuestaEmpleado::DTRespuestaEmpleado(string UnComentario, DTFecha UnaFecha) {
    comentario = UnComentario;
    fecha= UnaFecha;
}

DTRespuestaEmpleado::~DTRespuestaEmpleado() {
}