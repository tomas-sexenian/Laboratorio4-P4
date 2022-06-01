#ifndef DTRESPUESTAEMPLEADO
#define DTRESPUESTAEMPLEADO

#include "./DTRespuestaEmpleado.hh"
#include "./DTFecha.hh"

#include <string>

using namespace std;

class DTRespuestaEmpleado{
    private: 
        string emailEmpleado;
        string comentario;
        DTFecha fecha;
    public:
        DTRespuestaEmpleado(string,string,DTFecha);
        DTRespuestaEmpleado();
        ~DTRespuestaEmpleado();
        string getEmailEmpleado();
        string getComentario();
        DTFecha getFecha();
};

#endif