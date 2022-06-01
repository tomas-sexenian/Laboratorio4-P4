#ifndef RESPUESTAEMPLEADO
#define RESPUESTAEMPLEADO

#include "./DTFecha.hh"
#include "./Calificacion.hh"
#include <string>

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
        void setCalificacion();

        RespuestaEmpleado();
        RespuestaEmpleado(string, DTFecha,Calificacion*);
        ~RespuestaEmpleado();

	
};

#endif