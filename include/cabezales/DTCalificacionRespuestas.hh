#ifndef DTCALIFICACIONRESPUESTAS
#define DTCALIFICACIONRESPUESTAS

#include "./DTCalificacion.hh"
#include "./DTRespuestaEmpleado.hh"

#include <list>

using namespace std;

class DTCalificacionRespuestas{
    private: 
        DTCalificacion calificacion;
        list<DTRespuestaEmpleado> respuestas;
    public:
        DTCalificacionRespuestas(DTCalificacion,list<DTRespuestaEmpleado>);
        DTCalificacionRespuestas();
        ~DTCalificacionRespuestas();
        DTCalificacion getCalificacion();
        list<DTRespuestaEmpleado> getRespuestas();
};

#endif