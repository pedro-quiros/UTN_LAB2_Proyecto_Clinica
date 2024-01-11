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

void Paciente::setEspecialista(int& valor) {
    cargarEntero(valor);
    while (valor < 1 || valor > 5) {
        cout << "[X] Entrada no valida. Ingrese un numero entre 1 y 5: ";
        cargarEntero(valor);
    }
    especialista = valor;
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

bool Paciente::cargarPaciente() {
    int numEspecialidad;
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs = archiEs.contarRegistros();

    rlutil::locate(51, 1);
    cout << " INGRESAR DATOS DEL PACIENTE: " << endl;
    if (!Persona::cargarPersona()) {
        return false;
    }
    system("cls");

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

    setEspecialista(numEspecialidad);
    system("cls");

    rlutil::locate(50, 1);
    cout << "ESPECIALISTAS" << endl;
    cout << endl;

    imprimirEncabezadoEspecialista();

    for (int i = 0; i < contEs; i++) {
        es = archiEs.leerRegistro(i);
        if (es.getEstado() && es.getEspecialidad() == numEspecialidad) {
            es.mostrarEspecialista();
        }
    }
    int matricula;
    cout << endl;
    cout << endl;
    cout << "INGRESAR LA MATRICULA DEL ESPECIALISTA: ";
    cargarEntero(matricula);

    int banderaMatricula = true;
    for (int i = 0; i < contEs; i++) {
        es = archiEs.leerRegistro(i);
        if (es.getEstado() && es.getIdMatricula() == matricula) {
            setIdMatricula(matricula);
            banderaMatricula = false;
        }
    }
    if (banderaMatricula) {
        system("cls");
        cout << "[X] Error, La matricula no se encuentra registrada en la base de datos." << endl;
        cout << endl;
        return false;
    }
    cout<<endl;
    if(!turnoAsignado.cargarTurno(matricula)){
        return false;
    }

    estado=true;
    return true;
}

 void Paciente::mostrarPaciente(){
    const int anchoColumna = 20;
    cout << left << setw(anchoColumna) << getNombre()
                 << setw(anchoColumna) << getApellido()
                 << setw(anchoColumna) << getDni()
                 << setw(anchoColumna) << getEspecialista()
                 << setw(15) << getIdMatricula()
                 << setw(anchoColumna);
    turnoAsignado.mostrarTurno();
 }





