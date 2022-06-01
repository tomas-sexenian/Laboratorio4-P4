#ifndef NOTIFICACIONESCONTROLLER
#define NOTIFICACIONESCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/Notificacion.hh"
#include "../cabezales/DTNotificacion.hh"

using namespace std;

class NotificacionesController{
    private:
        static NotificacionesController * instancia;
        NotificacionesController();
        list<Notificacion *> Notificacion;
    public:
		static NotificacionesController* getInstancia();
	    ~NotificacionesController();

        void subscribirEmpleado(string);
        void eliminarNotificaciones();
        void eliminarSubscripcion(string);
};
#endif