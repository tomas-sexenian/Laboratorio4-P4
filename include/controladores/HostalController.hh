#ifndef HOSTALCONTROLLER
#define HOSTALCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorHostal.hh"
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

        string nombre, direccion;
        int telefono;
    public:
		static HostalController* getInstancia();
	    ~HostalController();
        map<string,Hostal*> getHostales();
        void setHostal();
        
        list<DTHostal> obtenerTodosHostales();
        list<DTHostal> obtenerTop3Hostales();
        DTInfoBasicaHostal obtenerInfoBasicaHostal(string);
        list<DTHabitacion> obtenerHabitacionesHostal(string);
        list<DTReserva> obtenerReservasHostal(string);
        void seleccionarHostal(string);
        DTInfoHostal verDetalles(string);
        void confirmarConsulta();
        list<DTInfoHostalYCalificacion> obtenerTodosHostalesYPromCalificacion();
	void ingresarDatosHostal(Hostal*);
        void confirmarAltaHostal();
        Hostal * getHostalIniciar();
        map<string,Hostal*> getHostales();
        
};

#endif
