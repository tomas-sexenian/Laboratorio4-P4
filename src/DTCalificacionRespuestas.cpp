#include "../include/cabezales/DTCalificacionRespuestas.hh"

list<DTRespuestaEmpleado> DTCalificacionRespuestas::getRespuestas() {
	return respuestas;
}

DTCalificacion DTCalificacionRespuestas::getCalificacion() {
	return calificacion;
}
	
DTCalificacionRespuestas::DTCalificacionRespuestas() {
    calificacion = DTCalificacion();
    list<DTRespuestaEmpleado> lista;
    respuestas = lista;
}

DTCalificacionRespuestas::DTCalificacionRespuestas(DTCalificacion UnaCalificacion,list<DTRespuestaEmpleado> UnasRespuestas ) {
    calificacion = UnaCalificacion;
    respuestas = UnasRespuestas;
}

DTCalificacionRespuestas::~DTCalificacionRespuestas() {
}