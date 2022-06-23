#ifndef FABRICA
#define FABRICA

#include "../interfaces/IControladorCalificacion.hh"
#include "../interfaces/IControladorEstadia.hh"
#include "../interfaces/IControladorHabitacion.hh"
#include "../interfaces/IControladorHostal.hh"
#include "../interfaces/IControladorNotificaciones.hh"
#include "../interfaces/IControladorReserva.hh"
#include "../interfaces/IControladorSistema.hh"
#include "../interfaces/IControladorUsuario.hh"

class IControladorEstadia;
class IControladorReserva;
class IControladorUsuario;
class IControladorCalificacion;
class IControladorNotificaciones;

class Fabrica {
    public:
        static IControladorCalificacion * getCalificacionController();
        static IControladorEstadia * getEstadiaController();
        static IControladorHabitacion * getHabitacionController();
        static IControladorHostal * getHostalController();
        static IControladorNotificaciones * getNotificacionesController();
        static IControladorReserva * getReservaController();
        static IControladorSistema * getSistemaController();
        static IControladorUsuario * getUsuarioController();
};
#endif
