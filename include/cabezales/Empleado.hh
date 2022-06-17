#ifndef EMPLEADO
#define EMPLEADO

#include "./Usuario.hh"
#include "./notificacion.hh"
#include "./Hostal.hh"
#include "./RespuestaEmpleado.hh"
#include "../../include/TipoCargo.hh"
#include <string>
#include <list>

//Forward declarations
class Hostal;

using namespace std;

class Empleado: public Usuario {
    private:
        TipoCargo cargo;
        list<Notificacion*> notificaciones;
        Hostal* hostal;
        list<RespuestaEmpleado*> respuestas;
    public:
        TipoCargo getCargo();
        void setCargo(TipoCargo);
        list<Notificacion*> getNotificaciones();
        void setNotificacion(Notificacion*);
        Hostal* getHostal();
        void setHostal(Hostal*);
        list<RespuestaEmpleado*> getRespuestas();
        void setRespuesta(RespuestaEmpleado*);

        void notificar();
        bool EsEmpleado();

        Empleado();
        Empleado(string,string,string,TipoCargo,list<Notificacion*>,Hostal*,list<RespuestaEmpleado*>);
        ~Empleado();
};

#endif
