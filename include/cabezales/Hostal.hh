#ifndef HOSTAL
#define HOSTAL

#include "./Huesped.hh"
#include "./Habitacion.hh"
#include "./Empleado.hh"
#include "./DTFecha.hh"

#include <string>
#include <map>

using namespace std;


class Hostal{
    private:
        string nombre, direccion;
        int telefono;
        map<int, Habitacion*> habitaciones;
        map<string, Empleado*> empleados;

    public:
        Hostal();
        Hostal(string,string,int,map<int, Habitacion*>,map<string, Empleado*>);
        ~Hostal();
        string getNombre();
        void setNombre(string);
        string getDireccion();
        void setDireccion(string);
        int getTelefono();
        void setTelefono(int);
        map<int, Habitacion*> getHabitaciones();
        void setHabitacion(Habitacion*);
        map<string, Empleado*> getEmpleados();
        void setEmpleado(Empleado*);

        float obtenerPromedioCalificaciones();
};

#endif
