#ifndef DTINFOEMPLEADO
#define DTINFOEMPLEADO

#include <string>

#include "../cabezales/Empleado.hh"
#include "../../include/TipoCargo.hh"

using namespace std;

class DTInfoEmpleado{
    private: 
        string hostal;
        TipoCargo cargo;
    public:
        DTInfoEmpleado(string,TipoCargo);
        DTInfoEmpleado(Empleado);
        DTInfoEmpleado();
        ~DTInfoEmpleado();
        string getHostal();
        TipoCargo getCargo();
};

#endif