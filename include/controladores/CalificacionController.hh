#ifndef CALIFICACIONCONTROLLER
#define CALIFICACIONCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/Calificacion.hh"
#include "../cabezales/DTCalificacion.hh"

using namespace std;

class CalificacionController{
    private:
        static CalificacionController * instancia;
        CalificacionController();
        map<int,Calificacion *> Calificacion;
    public:
		static CalificacionController* getInstancia();
	    ~CalificacionController();

        void ingresarComentario(string);
        void ingresarPuntaje(int);
        void confirmarAltaCalificacion();
        void elegirComentario();
        void altaComentarios();
};
#endif