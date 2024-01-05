#include<iostream>
#include<cstring>
#include <limits>
#include <iomanip>

using namespace std;

#include"rlutil.h"
#include"paciente.h"
#include"archivoClassPacientess.h"

#include"especialista.h"
#include"archivoClassEspecialista.h"
#include "validaciones.h"

void Paciente::setEspecialista(int e){
     especialista=e;
}
void Paciente::setIdMatricula(int m){
     idMatricula=m;
}
void Paciente::setTurnoAsignado(Turno t){
    turnoAsignado=t;
}

void Paciente::setEstado(bool e){
    estado=e;
}

int Paciente::getEspecialista(){
    return especialista;
}

int Paciente::getIdMatricula(){
    return idMatricula;
}

Turno Paciente::getTurnoAsignado(){
    return turnoAsignado;
}

bool Paciente::getEstado(){
    return estado;
}

bool Paciente::cargarPaciente(){
    int numEspecialidad;
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    rlutil::locate(51, 1);
    cout<<" INGRESAR DATOS DEL PACIENTE: "<<endl;

    if(!Persona::cargarPersona()){
        return false;
    }

    system("cls");
    /*
    int num1;

    rlutil::locate(50, 1);
    cout<<" INGRESA NUMERO DE LA ESPECIALIDAD PARA EL TURNO: "<<endl;
    rlutil::locate(40, 3);
    cout<<"1- CLINICO. "<<endl;
    rlutil::locate(40, 4);
    cout<<"2- UROLOGO. "<<endl;
    rlutil::locate(40, 5);
    cout<<"3- GINECOLOGO. "<<endl;
    rlutil::locate(40, 6);
    cout<<"4- CARDIOLOGO. "<<endl;
    rlutil::locate(40, 7);
    cout<<"5- DERMATOLOGO."<<endl;
    rlutil::locate(40, 8);
    cin>>num1;

    system("cls");
    */
    rlutil::locate(50, 1);
    cout << "INGRESAR ESPECIALIDAD PARA EL TURNO: " << endl;
    rlutil::locate(51, 3);
    cout << "1. Clinico." << endl;
    rlutil::locate(51, 4);
    cout << "2. Urologo." << endl;
    rlutil::locate(51, 5);
    cout << "3. Ginecologo." << endl;
    rlutil::locate(51, 6);
    cout << "4. Cardiologo." << endl;
    rlutil::locate(51, 7);
    cout << "5. Dermatologo." << endl;
    rlutil::locate(51, 8);
    cout << "-------------------------------" << endl;
    rlutil::locate(51, 9);
    cout << char(175) << " OPCION: ";
    cargarEntero(numEspecialidad);

    system("cls");

    if(numEspecialidad<=0 || numEspecialidad>5){
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return false;
    }

    setEspecialista(numEspecialidad);

    rlutil::locate(50, 1);
    cout<<"ESPECIALISTAS"<<endl;
    cout<<endl;

    const int anchoColumna = 20;

    cout << left << setw(anchoColumna) << "ESPECIALIDAD"
              << setw(anchoColumna) << "MATRICULA"
              << setw(anchoColumna) << "NOMBRE"
              << setw(anchoColumna) << "APELLIDO"
              << setw(15) << "DNI"
              << setw(0) << "FECHA NACIMIENTO"
              << "\n";

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

       if(es.getEstado() && es.getEspecialidad()==numEspecialidad){
            es.mostrarEspecialista();
        }
    }
    int ma;
    cout<<endl;
    cout<<"INGRESAR LA MATRICULA DEL ESPECIALISTA: ";
    cin>>ma;



    int banderaMatricula= true;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

       if(es.getEstado() && es.getIdMatricula()==ma){
            setIdMatricula(ma);
            banderaMatricula=false;
        }
    }
    if(banderaMatricula){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return false;
    }

    cout<<endl;

    if(!turnoAsignado.cargarTurno(ma)){
        return false;
    }
    estado=true;

    cout<<endl;
    return true;
}

 void Paciente::mostrarPaciente(){
    // Configurar ancho de columna para una presentación ordenada
    const int anchoColumna = 20;

        cout << left << setw(anchoColumna) << getNombre()
                  << setw(anchoColumna) << getApellido()
                  << setw(anchoColumna) << getDni()
                  << setw(anchoColumna) << getEspecialista()
                  << setw(15) << getIdMatricula()
                  << setw(anchoColumna);

        turnoAsignado.mostrarTurno();
 }





