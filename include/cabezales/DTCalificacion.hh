#ifndef DTCALIFICACION
#define DTCALIFICACION

#include "./DTFecha.hh"

#include <string>

using namespace std;

class DTCalificacion {
    private:
        int puntaje;
        string comentario;
        DTFecha fecha;
    public:
        DTCalificacion();
        DTCalificacion(int,string,DTFecha);
        ~DTCalificacion();
        int getPuntaje();
        string getComentario();
        DTFecha getFecha();
};

#endif