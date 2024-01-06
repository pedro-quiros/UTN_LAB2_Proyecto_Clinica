#ifndef SUBMENUREPORTE_H_INCLUDED
#define SUBMENUREPORTE_H_INCLUDED

#include"reporteControladores.h"

#include"recuadro.h"

void reporte(){

    int opcion;
    char titulo[40] = "MENU REPORTES";
    recuadro(titulo);
    cout<<endl;
    rlutil::locate(51, 5);
    cout<<"1. Cant. pacientes atendidos en un intervalo de fechas."<<endl;
    rlutil::locate(51, 6);
    cout<<"2. Cant. consultas de un paciente por DNI."<<endl;
    rlutil::locate(51, 7);
    cout<<"3. Cant. consultas por Especialidad."<<endl;
    rlutil::locate(51, 8);
    cout<<"0. Volver."<<endl;
    rlutil::locate(51, 9);
    cout << "-------------------------------" << endl;
    rlutil::locate(51, 10);
    cout << char(175) << " OPCION: ";
    cargarEntero(opcion);

    system("cls");

    switch(opcion){

    case 1: pacientesPorAnio();
            break;
    case 2: cantidadDeConsultaPaciente();
            break;
    case 3: cantidadPorEspecialidad();
            break;
    default:
            break;
    }
}
#endif // SUBMENUREPORTE_H_INCLUDED
