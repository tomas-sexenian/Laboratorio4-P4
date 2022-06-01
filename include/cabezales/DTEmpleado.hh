#ifndef DTEMPLEADO
#define DTEMPLEADO

#include "./DTUsuario.hh"
#include "../../include/TipoCargo.hh"

class DTEmpleado: public DTUsuario {
    private: 
        TipoCargo cargo;
    public:
        DTEmpleado();
        DTEmpleado(string,string,string,TipoCargo);
        ~DTEmpleado();
        TipoCargo getCargo();
};

#endif