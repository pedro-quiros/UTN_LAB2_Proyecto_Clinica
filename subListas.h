#ifndef SUBLISTAS_H_INCLUDED
#define SUBLISTAS_H_INCLUDED

#include"listadosControladores.h"
#include"listadosControlaTurno2.h"
#include"recuadro.h"

void subMenuLista(){
    int opcion;
    char titulo[40] = "MENU LISTAS";
    recuadro(titulo);

    cout << endl;
    rlutil::locate(51, 5);
    cout << "1. LISTAR TODOS LOS TURNOS." << endl;
    rlutil::locate(51, 6);
    cout << "2. Listar turnos por Apellido de Paciente." << endl;
    rlutil::locate(51, 7);
    cout << "3. Listar turnos por DNI de Paciente." << endl;
    rlutil::locate(51, 8);
    cout << "4. Listar turnos de Pacientes menores de edad." << endl;
    rlutil::locate(51, 9);
    cout << "5. Listar por Especialistas." << endl;
    rlutil::locate(51, 10);
    cout << "0. Volver." << endl;
    rlutil::locate(51, 11);
    cout << "-------------------------------" << endl;
    rlutil::locate(51, 12);
    cout << char(175) << " OPCION: ";
    cargarEntero(opcion);

    system("cls");

    switch(opcion){
    case 1: mostrarTodosPacientes();
            break;
    case 2: listaPorApellido();
            break;
    case 3: listarPorDni();
            break;
    case 4: listarMenores();
            break;
    case 5: listaDeMedico();
            break;
    default:
            break;
    }
}

#endif // SUBLISTAS_H_INCLUDED
