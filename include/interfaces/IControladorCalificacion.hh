#ifndef ICONTROLADORCALIFICACION
#define ICONTROLADORCALIFICACION

#include <list>
#include <string>


/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../cabezales/DTFecha.hh"
#include "../cabezales/DTCalificacion.hh"
#include "../cabezales/DTNotificacion.hh"
#include "../cabezales/DTRespuestaEmpleado.hh"
#include "./IObserver.hh"


using namespace std;

class DTNotificacion;

class IControladorCalificacion {
    public:
        virtual void ingresarComentario(string) = 0;
        virtual void ingresarPuntaje(int) = 0;
        virtual void ingresarFecha(DTFecha) = 0;
        virtual void confirmarAltaCalificacion(int,string,bool) = 0;

        virtual void ingresarRespuesta(string) = 0;
        virtual void responderCalificacion(int,string,DTFecha,bool) = 0;
        virtual void setCalificacionRecordada(int,string) = 0;
        virtual DTCalificacion obtenerDTCalificacionRecordada() = 0;
        virtual list<DTRespuestaEmpleado> obtenerDTRespuestas() = 0;
        virtual void LiberarMemoria() = 0;

        virtual list<IObserver*> getObservadores() = 0;
        virtual void agregarObservador(string) = 0;
        virtual void eliminarObservador(string) = 0;
};

#endif