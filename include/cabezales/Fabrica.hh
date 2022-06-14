#ifndef FABRICA
#define FABRICA

#include "../controladores/CalificacionController.hh"
#include "../controladores/EstadiaController.hh"
#include "../controladores/HabitacionController.hh"
#include "../controladores/HostalController.hh"
#include "../controladores/NotificacionesController.hh"
#include "../controladores/ReservaController.hh"
#include "../controladores/SistemaController.hh"
#include "../controladores/UsuarioController.hh"


class Fabrica {
    public:
        static CalificacionController * getCalificacionController();
        static EstadiaController * getEstadiaController();
        static HabitacionController * getHabitacionController();
        static HostalController * getHostalController();
        static NotificacionesController * getNotificacionesController();
        static ReservaController * getReservaController();
        static SistemaController * getSistemaController();
        static UsuarioController * getUsuarioController();
};
#endif