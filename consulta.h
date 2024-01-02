#ifndef CONSULTA_H_INCLUDED
#define CONSULTA_H_INCLUDED

#include"listadosControlaTurno2.h"

#include"recuadro.h"

void consulta(){

    int num;
    char titulo6[50]= "   SUB-MENU CONSULTAS";

    recuadro(titulo6);

    cout<<endl;
    rlutil::locate(51, 5);
    cout<<"   1- Consultas pacientes por medico.       "<<endl;
    rlutil::locate(51, 6);
    cout<<"   2- Consultas por dia.                     "<<endl;
    rlutil::locate(51, 7);
    cout<<"   3- consultas por especialidad.            "<<endl;
    rlutil::locate(51, 8);
    cout<<"   4- Consulta dia/mes/hora turnos todas/Esp."<<endl;
    rlutil::locate(51, 9);
    cout<<"   5- Consultas por DNI/Pac.                 "<<endl;
    rlutil::locate(51, 10);
    cout<<"   6- Consultas por DNI del Especialista.    "<<endl;
    rlutil::locate(51, 11);
    cout<<"   7- Consultas por MATRICULA Especialista.  "<<endl;
    rlutil::locate(51, 12);
    cout<<"   8- Consulta (libre/ocup.) por MATR.D,M,A,HORA,M. "<<endl;
    rlutil::locate(51, 13);
    cout<<"   0- Volver.                                "<<endl;
    rlutil::locate(51, 14);
    cin>>num;

    
    system("cls");

    switch(num){

    case 1: consultaPacientePorMedico();
            break;
    case 2: consultaPorDia();

            break;
    case 3: consultaPorEspecialidad();
            break;
    case 4: consultaHorariosOcupados();
            break;
    case 5: consultaPorDni();
            break;
    case 6: consultaEspecialistaDni();
            break;
    case 7: consultaPorMatriculaES();
            break;
    case 8: consultaPorMatriculaDiaHora();
            break;
    default:
            break;
    }

}



#endif // CONSULTA_H_INCLUDED
