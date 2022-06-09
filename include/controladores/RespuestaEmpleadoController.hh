#ifndef RESPUESTAEMPLEADOCONTROLLER
#define RESPUESTAEMPLEADOCONTROLLER

#include <list>
#include <map>

//VAN A TENER QUE HACER INCLUDE DE TODAS LAS DEPENDENCIAS DEL CONTROLADOR
//YO SOLO INCLUI LO QUE ALMACENA CADA CONTROLADOR Y LAS NECESARIAS PARA DECLARAR
//LAS OPERCIONES

#include "../cabezales/RespuestaEmpleado.hh"
#include "../cabezales/DTRespuestaEmpleado.hh"

using namespace std;

class RespuestaEmpleadoController{
    private:
        static RespuestaEmpleadoController * instancia;
        RespuestaEmpleadoController();
        map<string,RespuestaEmpleado*> respuestas;

        string comentario, emailEmpleado;
        DTFecha fecha;
    public:
		static RespuestaEmpleadoController* getInstancia();
	    ~RespuestaEmpleadoController();
        map<string,RespuestaEmpleado*> getRespuestas();
        void setRespuesta();

};
#endif