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
        int telefono;
        float promedioCalificaciones;
        list<DTCalificacion> calificaciones;
    public:
        DTInfoBasicaHostal(string,string,int,float,list<DTCalificacion>);
        DTInfoBasicaHostal();
        ~DTInfoBasicaHostal();
        string getNombre();
        string getDireccion();
        int getTelefono();
        float getPromedioCalificaciones();
        list<DTCalificacion> getCalificaciones();
};

#endif