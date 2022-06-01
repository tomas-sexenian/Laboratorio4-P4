#ifndef DTNOTIFICACION
#define DTNOTIFICACION

#include <string>

using namespace std;

class DTNotificacion {
    private:
        string autor;
        int puntaje;
        string comentario;
    public:
        string getAutor();
	    int getPuntaje();
	    string getComentario();
        DTNotificacion();
        DTNotificacion(string,int,string);
        ~DTNotificacion();
};

#endif