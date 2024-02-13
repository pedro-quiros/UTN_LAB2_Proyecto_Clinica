#ifndef ESPECIALISTA_H_INCLUDED
#define ESPECIALISTA_H_INCLUDED

#include"persona.h"

class Especialista:public Persona{
    private:
        int idMatricula;
        int especialidad; 
        bool estado;

    public:
        void setIdMatricula(int);
        void setEspecialidad(int& valor);
        void setEstado(bool);

        int getIdMatricula();
        int getEspecialidad();
        bool getEstado();

        bool cargarEspecialista();
        void mostrarEspecialista();
};

#endif // ESPECIALISTA_H_INCLUDED
