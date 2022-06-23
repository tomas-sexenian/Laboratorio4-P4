#ifndef IOBSERVER
#define IOBSERVER

#include <string>
#include <list>
#include <utility>

#include "../cabezales/notificacion.hh" 

using namespace std; 

class IObserver {
    public: 
        virtual ~IObserver(){}
        virtual void notificar(Notificacion*) = 0;
        
};
#endif