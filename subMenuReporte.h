#ifndef SUBMENUREPORTE_H_INCLUDED
#define SUBMENUREPORTE_H_INCLUDED

#include"reporteControladores.h"

#include"recuadro.h"

void reporte(){

    int num;
    char titulo7[50]= "      SUB-MENU REPORTES";

    recuadro(titulo7);

    cout<<endl;
    rlutil::locate(51, 5);
    cout<<" 1- Cant. pacientes atendidos en un intervalo."<<endl;
    rlutil::locate(51, 6);
    cout<<" 2- Cant. consultas de un paciente por DNI.   "<<endl;
    rlutil::locate(51, 7);
    cout<<" 3- Cant. consultas por especialidad.         "<<endl;
    rlutil::locate(51, 8);
    cout<<" 0- Volver.                                   "<<endl;
    rlutil::locate(51, 9);
    cin>>num;

   

    system("cls");

    switch(num){

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
