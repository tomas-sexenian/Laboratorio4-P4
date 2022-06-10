#ifndef USUARIOCONTROLLER
#define USUARIOCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../interfaces/IControladorUsuario.hh"
#include "../cabezales/Usuario.hh"
#include "../cabezales/Empleado.hh"
#include "../cabezales/DTUsuario.hh"
#include "../cabezales/DTInfoUsuario.hh"
#include "../cabezales/DTFecha.hh"
#include "../../include/TipoUsuario.hh"
#include "../../include/TipoCargo.hh"

using namespace std;

class UsuarioController: public IControladorUsuario {
    private:
        static UsuarioController * instancia;
        UsuarioController();
        map<string,Usuario *> Usuarios;

        string nombre,email,contrasenia;
        bool esFinger;
        TipoCargo cargo;
        TipoUsuario tipo;
	Usuario * usuarioIniciar;
        map<string,Usuario*> usuarios;
        map<string,Hostal*> hostales;
        map<string,Habitacion*> habitaciones;
        Hostal * hostalIniciar;
        Habitacion * habitacionIniciar; 
	
    public:
        static UsuarioController* getInstancia();
        ~UsuarioController();
        map<string,Usuario *> getUsuarios();
        void setUsuario();

        DTInfoUsuario seleccionarUsuario(string);
        void confirmarConsulta();
        //void ingresarEmpleado(Empleado);
	
	Usuario * getUsuarioIniciar();

        void ingresarDatosUsuario(Usuario*);
        void ingresarCargo(TipoCargo);
        void ingresarEsFinger(bool);
        void ingresarNuevoEmail(string);
        void confirmarAltaUsuario();
        void cancelarAltaUsuario();   

        void ingresarDatosHostal(Hostal*);
        void confirmarAltaHostal();

        Hostal * getHostalIniciar();
        Habitacion * getHabitacionIniciar();
        map<string,Hostal*> getHostales();
        map<string,Habitacion*> getHabitaciones();

        void ingresarDatosHabitacion(Habitacion*);
        void confirmarAltaHabitacion();
        void cancelarAltaHabitacion();

        ~UsuarioController();
};
#endif
