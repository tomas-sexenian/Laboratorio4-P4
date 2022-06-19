#ifndef NOTIFICACIONESCONTROLLER
#define NOTIFICACIONESCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES


#include "../interfaces/IControladorNotificaciones.hh"
#include "../cabezales/notificacion.hh"
#include "../cabezales/DTNotificacion.hh"

using namespace std;

class NotificacionesController: public IControladorNotificaciones {
    private:
        static NotificacionesController * instancia;
        NotificacionesController();
        list<Notificacion *> Notificaciones;
        
        string autor;
        int puntaje;
        string comentario;
    public:
		static NotificacionesController* getInstancia();
	    ~NotificacionesController();
        list<Notificacion *> getNotificaciones();
        void setNotificacion();

        void subscribirEmpleado(string);
        void eliminarNotificaciones();
        void eliminarSubscripcion(string);

        void eliminarNotificaciones();
};
#endif
