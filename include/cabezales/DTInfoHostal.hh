#ifndef DTINFOHOSTAL
#define DTINFOHOSTAL

#include <string>
#include <list>

using namespace std;

class DTInfoHostal{
    private: 
        list<string> comentarios;
        float promedioCalificaciones;
    public:
        DTInfoHostal(list<string>,float);
        DTInfoHostal();
        ~DTInfoHostal();
        list<string> getComentarios();
        float getPromedioCalificaciones();
};

#endif