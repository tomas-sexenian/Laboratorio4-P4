#ifndef DTRESPUESTAEMPLEADO
#define DTRESPUESTAEMPLEADO

#include "./DTFecha.hh"

#include <string>

using namespace std;

class DTRespuestaEmpleado{
    private: 
        string comentario;
        DTFecha fecha;
    public:
        DTRespuestaEmpleado(string,DTFecha);
        DTRespuestaEmpleado();
        ~DTRespuestaEmpleado();
        string getComentario();
        DTFecha getFecha();
};

#endif