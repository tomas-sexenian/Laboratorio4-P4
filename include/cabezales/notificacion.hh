#ifndef NOTIFICACION
#define NOTIFICACION

#include <string>

using namespace std;


class Notificacion{
    private:
        string autor,comentario;
        int puntaje;

    public:
        Notificacion();
        Notificacion(string,int,string);
        ~Notificacion();
        string getAutor();
        void setAutor(string);
        string getComentario();
        void setComentario(string);
        int getPuntaje();
        void setPuntaje(int);
};

#endif