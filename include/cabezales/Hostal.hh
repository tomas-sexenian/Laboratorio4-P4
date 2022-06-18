#ifndef HOSTAL
#define HOSTAL

#include "./Huesped.hh"
#include "./Habitacion.hh"
#include "./Empleado.hh"
#include "./DTFecha.hh"
#include "./DTCalificacion.hh"

#include <string>
#include <map>

#include "Fabrica.hh"

//Forward declarations
class Habitacion;
class Empleado;

using namespace std;


class Hostal{
    private:
        string nombre, direccion;
        string telefono;
        map<int, Habitacion*> habitaciones;
        map<string, Empleado*> empleados;

    public:
        Hostal();
        Hostal(string,string,string,map<int, Habitacion*>,map<string, Empleado*>);
        ~Hostal();
        string getNombre();
        void setNombre(string);
        string getDireccion();
        void setDireccion(string);
        string getTelefono();
        void setTelefono(string);
        map<int, Habitacion*> getHabitaciones();
        void setHabitacion(Habitacion*);
        map<string, Empleado*> getEmpleados();
        void setEmpleado(Empleado*);

       
};

#endif
