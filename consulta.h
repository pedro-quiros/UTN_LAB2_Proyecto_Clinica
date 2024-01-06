#ifndef CONSULTA_H_INCLUDED
#define CONSULTA_H_INCLUDED

#include"listadosControlaTurno2.h"

#include"recuadro.h"

void consulta(){

    int opcion;
    char titulo[40]= "MENU CONSULTAS";

    recuadro(titulo);

    cout<<endl;
    rlutil::locate(51, 5);
    cout<<"1. Pacientes por especialista."<<endl;
    rlutil::locate(51, 6);
    cout<<"2. Pacientes por dia."<<endl;
    rlutil::locate(51, 7);
    cout<<"3. Pacientes por especialidad."<<endl;
    rlutil::locate(51, 8);
    cout<<"4. Pacientes por Dia/Mes/Hora."<<endl;
    rlutil::locate(51, 9);
    cout<<"5. Turnos por DNI del Pacientes."<<endl;
    rlutil::locate(51, 10);
    cout<<"6. Turnos por DNI del Especialista."<<endl;
    rlutil::locate(51, 11);
    cout<<"7. Turnos por MATRICULA del Especialista."<<endl;
    rlutil::locate(51, 12);
    cout<<"0. Volver.                                "<<endl;
    rlutil::locate(51, 13);
    cout << "-------------------------------" << endl;
    rlutil::locate(51, 14);
    cout << char(175) << " OPCION: ";
    cargarEntero(opcion);


    system("cls");

    switch(opcion){

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
    default:
            break;
    }

}



#endif // CONSULTA_H_INCLUDED
