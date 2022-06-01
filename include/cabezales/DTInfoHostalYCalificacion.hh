#ifndef DTINFOHOSTALYCALIFICACION
#define DTINFOHOSTALYCALIFICACION

#include "./DTHostal.hh"

using namespace std;

class DTInfoHostalYCalificacion{
    private: 
        DTHostal hostal;
        float promedioCalificaciones;
    public:
        DTInfoHostalYCalificacion(DTHostal,float);
        DTInfoHostalYCalificacion();
        ~DTInfoHostalYCalificacion();
        DTHostal getHostal();
        float getPromedioCalificaciones();
};

#endif