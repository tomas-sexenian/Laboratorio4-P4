#ifndef ICONTROLADORSISTEMA
#define ICONTROLADORSISTEMA

#include <list>

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../cabezales/DTFecha.hh"

using namespace std;

class IControladorSistema {
    public:
        virtual DTFecha obtenerFechaActual() = 0;
        virtual void modificarFecha(int, int, int, int, int) = 0;
};

#endif