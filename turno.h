#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED

#include"hora.h"
#include"fecha.h"

class Turno{
    private:
        Fecha fechaTurno;
        Hora horaTurno;
    public:
        void setFechaTurno(Fecha);
        void setHoraTurno(Hora);
        Fecha getFechaTurno();
        Hora getHoraTurno();
        bool cargarTurno(int);
        void mostrarTurno();
};

#endif // TURNO_H_INCLUDED
