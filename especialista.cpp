#include<iostream>
#include<cstring>
#include <limits>
#include <iomanip>

using namespace std;
#include"especialista.h"
#include"rlutil.h"

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


bool Especialista::cargarEspecialista(){
    int num1,num2;

    rlutil::locate(50,1);
    cout<<"ALTA DE ESPECIALISTA:"<<endl;
    rlutil::locate(20,3);
    cout<<"INGRESAR EL NUMERO DE MATRICULA: ";
    rlutil::locate(55,3);
    cin>>num1;


    setIdMatricula(num1);

    cout<<endl;
    system("pause");
    system("cls");

    rlutil::locate(50,1);
    cout<<"INGRESAR ESPECIALIDAD: "<<endl;
    rlutil::locate(55,3);
    cout<<"1-CLINICO. "<<endl;
    rlutil::locate(55,4);
    cout<<"2-UROLOGO. "<<endl;
    rlutil::locate(55,5);
    cout<<"3-GINECOLOGO. "<<endl;
    rlutil::locate(55,6);
    cout<<"4-Cardiologo. "<<endl;
    rlutil::locate(55,7);
    cout<<"5-Dermatologo. "<<endl;
    rlutil::locate(55,8);
    cin>>num2;



    if(num2<=0 || num2>5){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return false;
    }

    setEspecialidad(num2);

    cout<<endl;
    system("pause");
    system("cls");

    rlutil::locate(50,1);
    cout<<"INGRESAR LOS DATOS DEL ESPECIALISTA: "<<endl;
    if(!Persona::cargarPersona()){
        return false;
    }
    estado=true;

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
