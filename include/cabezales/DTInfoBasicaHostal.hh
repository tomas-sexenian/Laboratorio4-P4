#ifndef DTINFOBASICAHOSTAL
#define DTINFOBASICAHOSTAL

#include <string>
#include <list>

#include "./DTCalificacion.hh"

using namespace std;

class DTInfoBasicaHostal{
    private: 
        string nombre;
        string direccion;
        string telefono;
        float promedioCalificaciones;
        list<DTCalificacion> calificaciones;
    public:
        DTInfoBasicaHostal(string,string,string,float,list<DTCalificacion>);
        DTInfoBasicaHostal();
        ~DTInfoBasicaHostal();
        string getNombre();
        string getDireccion();
        string getTelefono();
        float getPromedioCalificaciones();
        list<DTCalificacion> getCalificaciones();
};

#endif