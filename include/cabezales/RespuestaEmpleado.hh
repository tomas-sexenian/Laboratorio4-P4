#ifndef RESPUESTAEMPLEADO
#define RESPUESTAEMPLEADO

#include "./DTFecha.hh"
#include "./calificacion.hh"
#include <string>

//Forward declarations
class Calificacion;

using namespace std;

class RespuestaEmpleado{
	private:
                string comentario;
                DTFecha fecha;
		Calificacion* calificacion;
	public:
                string getComentario();
                void setComentario(string);
                DTFecha getFecha();
                void setFecha(DTFecha);
                Calificacion* getCalificacion();
                void setCalificacion(Calificacion*);

                RespuestaEmpleado();
                RespuestaEmpleado(string, DTFecha,Calificacion*);
                ~RespuestaEmpleado();
};

#endif
