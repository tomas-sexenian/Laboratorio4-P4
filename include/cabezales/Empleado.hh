#ifndef EMPLEADO
#define EMPLEADO

#include "./Usuario.hh"
#include "./notificacion.hh"
#include "./Hostal.hh"
#include "./RespuestaEmpleado.hh"
#include "../../include/TipoCargo.hh"
#include "../interfaces/IObserver.hh"
#include <string>
#include <list>

//Forward declarations
class Hostal;
class RespuestaEmpleado;

using namespace std;

class Empleado: public Usuario, public IObserver {
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

        void notificar(Notificacion*);

        Empleado();
        Empleado(string,string,string,TipoCargo,list<Notificacion*>,Hostal*,list<RespuestaEmpleado*>);
        ~Empleado();

       
};

    
    




#endif
