#ifndef SUBMENUMODIFICAR_H_INCLUDED
#define SUBMENUMODIFICAR_H_INCLUDED

#include"archivoControladores.h"
#include"archivoControladoresEspecialista.h"
#include"recuadro.h"

void modificarTurnoEspecialista(){
    int opcion;
    char titulo[40] = "MENU MODIFICAR TURNO Y ESPECIALISTA";
    recuadro(titulo);

    rlutil::locate(51, 5);
    cout << "1. MODIFICAR Turno." << endl;
    rlutil::locate(51, 6);
    cout << "2. MODIFICAR datos de Especialista." << endl;
    rlutil::locate(51, 7);
    cout << "0. Volver." << endl;
    rlutil::locate(51, 8);
    cout << "-------------------------------" << endl;
    rlutil::locate(51, 9);
    cout << char(175) << " OPCION: ";
    cargarEntero(opcion);

    system("cls");

    switch(opcion){
    case 1: modificarTurno();
            break;
    case 2: modificarEspecialista();
            break;
    default:
            break;
    }
}

#endif // SUBMENUMODIFICAR_H_INCLUDED
