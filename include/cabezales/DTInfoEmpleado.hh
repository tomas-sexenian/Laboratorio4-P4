#ifndef INFOEMPLEADO
#define INFOEMPLEADO

#include <string>

#include "../../include/TipoCargo.hh"

using namespace std;

class DTInfoEmpleado{
    private: 
        string hostal;
        TipoCargo cargo;
    public:
        DTInfoEmpleado(string,TipoCargo);
        DTInfoEmpleado();
        ~DTInfoEmpleado();
        string getHostal();
        TipoCargo getCargo();
};

#endif