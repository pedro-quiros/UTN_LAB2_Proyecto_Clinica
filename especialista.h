#ifndef ESPECIALISTA_H_INCLUDED
#define ESPECIALISTA_H_INCLUDED

#include"persona.h"

class Especialista:public Persona{
    private:
        int idMatricula;
        int especialidad;  //1-clinico 2-urologo 3-ginecologo 4-cardiologo 5-dermatologo
        bool estado;

    public:
        void setIdMatricula(int);
        void setEspecialidad(int);
        void setEstado(bool);

        int getIdMatricula();
        int getEspecialidad();
        bool getEstado();

        bool cargarEspecialista();
        void mostrarEspecialista();
};



#endif // ESPECIALISTA_H_INCLUDED
