#ifndef ICONTROLADORCALIFICACION
#define ICONTROLADORCALIFICACION

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../cabezales/Calificacion.hh"

using namespace std;

class IControladorCalificacion {
    public:

        virtual void ingresarComentario(string) = 0;
        virtual void ingresarPuntaje(int) = 0;
        virtual void confirmarAltaCalificacion() = 0;
       

        virtual ~IControladorCalificacion() {};

};


#endif
