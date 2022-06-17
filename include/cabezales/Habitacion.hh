#ifndef HABITACION
#define HABITACION

#include "./DTFecha.hh"
#include "./Hostal.hh"
#include "./Reserva.hh"

#include <string>
#include <map>

//Forward declarations
class Hostal;
class Reserva;

class Habitacion{
	private:
		int numero;
		float precio;
        int capacidad;
		Hostal* hostal;
		map<int, Reserva*> reservas;
	public:
		void setNumero (int);
		int getNumero ();
		void setPrecio(float);
		float getPrecio ();
        void setCapacidad(int);
		int getCapacidad ();
		Hostal* getHostal();
		void setHostal(Hostal*);
		map<int, Reserva*> getReservas();
		void setReserva(Reserva*);

        Habitacion();
        Habitacion(int, float, int,Hostal*,map<int, Reserva*>);
		~Habitacion();
        
		bool estaDisponible(DTFecha,DTFecha);

};

#endif
