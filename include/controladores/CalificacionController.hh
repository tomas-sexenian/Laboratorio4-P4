#ifndef CALIFICACIONCONTROLLER
#define CALIFICACIONCONTROLLER

#include <list>
#include <map>
#include <iostream>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES


#include "../interfaces/IControladorCalificacion.hh"
#include "../cabezales/calificacion.hh"
#include "../cabezales/DTCalificacion.hh"
#include "../cabezales/RespuestaEmpleado.hh"
#include "../controladores/SistemaController.hh"
#include "../controladores/EstadiaController.hh"

using namespace std;

class CalificacionController: public IControladorCalificacion {
    private:
        static CalificacionController * instancia;
        CalificacionController();
        map<int,Calificacion *> Calificaciones;
        multimap<Calificacion *,RespuestaEmpleado *> RespuestasEmpleados;

        int puntaje,codigoReserva;
        string comentario;
        DTFecha fecha;
        Calificacion* calificacionRecordada;
        string respuesta;
    public:
		static CalificacionController* getInstancia();
	    ~CalificacionController();
        map<int,Calificacion *> getCalificaciones();
        Calificacion * getCalificacionRecordada();
        void setCalificacionRecordada(int,string);

        void ingresarComentario(string);
        void ingresarPuntaje(int);
        void ingresarFecha(DTFecha);
        void confirmarAltaCalificacion(int,string);

        void ingresarRespuesta(string);
        void responderCalificacion(int,string,DTFecha);
};
#endif
