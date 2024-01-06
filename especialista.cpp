#include<iostream>
#include<cstring>
#include <limits>
#include <iomanip>

using namespace std;
#include"especialista.h"
#include"rlutil.h"
#include "validaciones.h"


void Especialista::setIdMatricula(int ma){
    idMatricula=ma;
}
void Especialista::setEspecialidad(int e){
    if(0<e && e<=5){
        especialidad=e;
    }
    else{especialidad=0;}
}
void Especialista::setEstado(bool e){
      estado=e;
}

int Especialista::getIdMatricula(){
    return idMatricula;
}

int Especialista::getEspecialidad(){
    return especialidad;
}

bool Especialista::getEstado(){
    return estado;
}
bool Especialista::cargarEspecialista() {
    int numMatricula, numEspecialidad;

    rlutil::locate(50, 1);
    cout << "ALTA DE ESPECIALISTA:" << endl;
    cout << endl;
    cout << "INGRESAR EL NUMERO DE MATRICULA: ";
    cargarEntero(numMatricula);
    setIdMatricula(numMatricula);

    system("cls");

    rlutil::locate(50, 1);
    cout << "INGRESAR ESPECIALIDAD: " << endl;
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


    if (numEspecialidad <= 0 || numEspecialidad > 5) {
        system("cls");
        cout << "[X] Opcion no valida. Saliendo del sistema." << endl;
        return false;
    }

    setEspecialidad(numEspecialidad);

    system("cls");

    rlutil::locate(50, 1);
    cout << "INGRESAR LOS DATOS DEL ESPECIALISTA: " << endl;
    if (!Persona::cargarPersona()) {
        return false;
    }
    estado = true;

    return true;
}

void Especialista::mostrarEspecialista(){

     const int anchoColumna = 20;

        cout << left << setw(anchoColumna) << especialidad
                     << setw(anchoColumna) << idMatricula
                     << setw(anchoColumna) << Persona::getNombre()
                     << setw(anchoColumna) << Persona::getApellido()
                     << setw(anchoColumna) << Persona::getDni()
                     << setw(0) << Persona::getFecha().getDia()<<"/"
                     << setw(0) << Persona::getFecha().getMes()<<"/"
                     << setw(0) << Persona::getFecha().getAnio()
                     << "\n";
}
