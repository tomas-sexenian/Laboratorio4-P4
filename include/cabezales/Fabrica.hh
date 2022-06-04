#ifndef FABRICA
#define FABRICA

#include "../controladores/AltaDeHabitacionController.hh"
#include "../controladores/AltaDeHostalController.hh"
#include "../controladores/AltaDeUsuarioController.hh"
#include "../controladores/CalificacionController.hh"
#include "../controladores/EmpleadoController.hh"
#include "../controladores/EstadiaController.hh"
#include "../controladores/HabitacionController.hh"
#include "../controladores/HostalController.hh"
#include "../controladores/HuespedController.hh"
#include "../controladores/NotificacionesController.hh"
#include "../controladores/ReservaController.hh"
#include "../controladores/RespuestaEmpleadoController.hh"
#include "../controladores/SistemaController.hh"
#include "../controladores/UsuarioController.hh"


class Fabrica {
    public:
        AltaDeHabitacionController * getAltaDeHabitacionController();
        AltaDeHostalController * getAltaDeHostalController();
        AltaDeUsuarioController * getAltaDeUsuarioController();
        CalificacionController * getCalificacionController();
        EmpleadoController * getEmpleadoController();
        EstadiaController * getEstadiaController();
        HabitacionController * getHabitacionController();
        HostalController * getHostalController();
        HuespedController * getHuespedController();
        NotificacionesController * getNotificacionesController();
        ReservaController * getReservaController();
        RespuestaEmpleadoController * getRespuestaEmpleadoController();
        SistemaController * getSistemaController();
        UsuarioController * getUsuarioController();
};
#endif