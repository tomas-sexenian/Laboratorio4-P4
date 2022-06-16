#ifndef CALIFICACION
#define CALIFICACION

#include "./DTFecha.hh"
#include "./Estadia.hh"
#include "./RespuestaEmpleado.hh"
#include <string>
#include <list>

using namespace std;

class Calificacion{
	private:
                int puntaje;
                string comentario;
                DTFecha fecha;
                Estadia* estadia;
                list<RespuestaEmpleado*> respuestas;
	public:
                int getPuntaje();
                void setPuntaje(int);
                string getComentario();
                void setComentario(string);
                DTFecha getFecha();
                void setFecha(DTFecha);

                Estadia* getEstadia();
                void setEstadia(Estadia*);
                list<RespuestaEmpleado*> getRespuestas();
                void setRespuesta(RespuestaEmpleado*);

                Calificacion();
                Calificacion(int, string, DTFecha,Estadia*,list<RespuestaEmpleado*>);
                ~Calificacion();
};

#endif