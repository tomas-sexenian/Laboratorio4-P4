#ifndef ICONTROLADORESTADIA
#define ICONTROLADORESTADIA

#include <list>

/*  Nota: Revisar que estén todos los includes, y que ninguno de los presentes sobren. */

#include "../cabezales/DTInfoEstadia.hh"
#include "../cabezales/DTEstadia.hh"

using namespace std;

class IControladorEstadia {
    public:
       virtual void seleccionarEstadia(int,string) = 0;
       virtual DTInfoEstadia obtenerEstadia() = 0;
       virtual Estadia* finalizarEstadia() = 0;
       virtual void confirmarFinEstadia() = 0;
       virtual list<DTEstadia> obtenerTodasEstadiasHostal(string) = 0;
};

#endif