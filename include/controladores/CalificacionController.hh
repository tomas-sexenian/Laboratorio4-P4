#ifndef CALIFICACIONCONTROLLER
#define CALIFICACIONCONTROLLER

#include <list>
#include <map>
#include <iostream>
#include <stdexcept>


//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES


#include "../interfaces/IControladorCalificacion.hh"
#include "../cabezales/calificacion.hh"
#include "../cabezales/DTCalificacion.hh"
#include "../cabezales/DTRespuestaEmpleado.hh"
#include "../cabezales/RespuestaEmpleado.hh"
#include "../controladores/SistemaController.hh"
#include "../controladores/EstadiaController.hh"
#include "../controladores/UsuarioController.hh"
#include "../cabezales/Empleado.hh"
#include "../controladores/NotificacionesController.hh"
#include "../interfaces/IObserver.hh"


using namespace std;


class CalificacionController: public IControladorCalificacion {
    private:
        static CalificacionController * instancia;
        CalificacionController();
        map<int,Calificacion *> Calificaciones;
        multimap<Calificacion *,RespuestaEmpleado *> RespuestasEmpleados;

        list<IObserver*> observadores;
        void notificarEmpleado(Notificacion*);

        int puntaje,codigoReserva;
        string comentario;
        DTFecha fecha;
        Calificacion* calificacionRecordada;
        string respuesta;
    public:
		static CalificacionController* getInstancia();
	    virtual ~CalificacionController();
        map<int,Calificacion *> getCalificaciones();
        void setCalificacionRecordada(int,string);

        DTCalificacion obtenerDTCalificacionRecordada();
        list<DTRespuestaEmpleado> obtenerDTRespuestas();
        void ingresarComentario(string);
        void ingresarPuntaje(int);
        void ingresarFecha(DTFecha);
        void confirmarAltaCalificacion(int,string,bool);

        void ingresarRespuesta(string);
        void responderCalificacion(int,string,DTFecha,bool);

        list<IObserver*> getObservadores();
        void agregarObservador(string);
        void eliminarObservador(string);

        void LiberarMemoria();

};
#endif
