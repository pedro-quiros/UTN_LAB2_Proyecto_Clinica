#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

#include"persona.h"
#include"turno.h"

class Paciente:public Persona{
    protected:
        int especialista;
        int idMatricula;
        Turno turnoAsignado;
        bool estado;

    public:

        void setEspecialista(int);
        void setIdMatricula(int);
        void setTurnoAsignado(Turno);
        void setEstado(bool);

        int getEspecialista();
        int getIdMatricula();
        Turno getTurnoAsignado();
        bool getEstado();

        bool cargarPaciente();
        void mostrarPaciente();

};




#endif // PACIENTE_H_INCLUDED
