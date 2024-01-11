#include<iostream>
#include<cstring>
#include <iomanip>
#include <limits>

using namespace std;
#include"turno.h"
#include"paciente.h"
#include"archivoClassPacientess.h"
#include"rlutil.h"
#include "validaciones.h"
#include "fecha.h"


void Turno::setFechaTurno(Fecha fe){
    fechaTurno=fe;
}

void Turno::setHoraTurno(Hora ho){
    horaTurno=ho;
}

Fecha Turno::getFechaTurno(){
    return fechaTurno;
}

Hora Turno::getHoraTurno(){
    return horaTurno;
}

bool Turno::cargarTurno(int matricula){
    Paciente p;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    int dia,mes;

    cout<<"INGRESE EL DIA DEL POSIBLE TURNO: ";
    cargarEntero(dia);
 
    cout<<"INGRESE EL MES: ";
    cargarEntero(mes);

    cout<<endl;

    system("cls");

    bool bandera=true;

    rlutil::locate(50,1);
    cout<<"TURNOS OCUPADOS:"<<endl;
    cout<<endl;

    const int anchoColumna = 20;

    cout << left << setw(anchoColumna) << "NOMBRE"
              << setw(anchoColumna) << "APELLIDO"
              << setw(anchoColumna) << "DNI"
              << setw(anchoColumna) << "ESPECIALISTA"
              << setw(15) << "MATRICULA"
              << setw(anchoColumna) << "TURNO DIA"
              << setw(anchoColumna) << "HORA"
              << "\n";

    for(int i=0;i<contPa;i++){
        p = archiPa.leerRegistro(i);

        if(p.getEstado() && p.getTurnoAsignado().getFechaTurno().getDia()==dia
           && p.getTurnoAsignado().getFechaTurno().getMes()==mes
           && p.getIdMatricula()==matricula){
           p.mostrarPaciente();
           bandera=false;
        }
    }
    if(bandera){
        system("cls");
        cout<<"SIN TURNOS ASIGNADOS..."<<endl;
        cout << endl;
    }
    cout << endl;
    cout << endl;

    system("pause");
    system("cls");

    rlutil::locate(50, 1);
    cout<<"INGRESE FECHA DEL TURNO (DD/MM/YYYY): "<<endl;
    if(!fechaTurno.cargarFecha()){
        return false;
    }

    cout<<endl;
    system("pause");
    system("cls");

    rlutil::locate(50, 1);
    cout<<"INGRESE HORA DEL TURNO (HH:MM): "<<endl;
    if(!horaTurno.cargarHora()){
        return false;
    }
    return true;
}

void Turno::mostrarTurno(){
    const int anchoColumna = 15;

     cout << left << setw(0) << fechaTurno.getDia() << "/"
          << fechaTurno.getMes() << "/"
          << setw(anchoColumna) << fechaTurno.getAnio();

     cout << left << setw(0) << horaTurno.getHora() << ":"
          << horaTurno.getMinuto() << "\n";
}

