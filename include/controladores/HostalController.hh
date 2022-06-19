#ifndef HOSTALCONTROLLER
#define HOSTALCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorHostal.hh"
#include "../controladores/EstadiaController.hh"
#include "../cabezales/Hostal.hh"
#include "../cabezales/DTHostal.hh"
#include "../cabezales/DTInfoBasicaHostal.hh"
#include "../cabezales/DTHabitacion.hh"
#include "../cabezales/DTReserva.hh"
#include "../cabezales/DTInfoHostal.hh"
#include "../cabezales/DTInfoHostalYCalificacion.hh"

using namespace std;

class HostalController : public IControladorHostal {
    private:
        static HostalController * instancia;
        HostalController();
        map<string,Hostal*> Hostales;

        //Memoria
        string nombre, direccion;
        string telefono;
    public:
		static HostalController* getInstancia();
	    ~HostalController();
        map<string,Hostal*> getHostales();
        Hostal *hostalSeleccionado;
        
        list<DTHostal> obtenerTodosHostales();
        list<DTHostal> obtenerTop3Hostales();
        DTInfoBasicaHostal obtenerInfoBasicaHostal();
        list<DTHabitacion> obtenerHabitacionesHostal();
        void seleccionarHostal(string);
        DTInfoHostal verDetalles();
        void confirmarConsulta();
        list<DTInfoHostalYCalificacion> obtenerTodosHostalesYPromCalificacion();
        list<DTCalificacion> obtenerCalificaciones();
        list<string> obtenerComentarios();
        float obtenerPromedioCalificaciones();
        //Lo que antes era AltaHostal
        void ingresarDatosHostal(string,string,string);
        void confirmarAltaHostal();
        void cancelarAltaHostal();

        void eliminarHostales();
};

#endif