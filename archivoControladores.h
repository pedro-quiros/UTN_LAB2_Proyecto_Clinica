#ifndef ARCHIVOCONTROLADORES_H_INCLUDED
#define ARCHIVOCONTROLADORES_H_INCLUDED

#include"paciente.h"
#include"archivoClassPacientess.h"
#include"especialista.h"
#include"archivoClassEspecialista.h"
#include <iomanip>
#include"rlutil.h"
#include"validaciones.h"
#include"recuadro.h"
//funciones prototipos
void altaTurno();
bool mostrarTodosPacientes();
void bajaLogicaTurno();
void modificarTurno();
void listaDeMedico();

//funciones
void altaTurno(){
     Paciente p, pa;
     ArchivoPaciente archiPa("turno.dat");
     int contPa= archiPa.contarRegistros();

     if(!p.cargarPaciente()){
         return;
     }

     bool bandera=true;
     for(int i=0;i<contPa;i++){
        pa= archiPa.leerRegistro(i);
        if(pa.getEstado() && pa.getIdMatricula()==p.getIdMatricula()
           && pa.getTurnoAsignado().getFechaTurno().getDia()==
           p.getTurnoAsignado().getFechaTurno().getDia()
           && pa.getTurnoAsignado().getFechaTurno().getMes()==
           p.getTurnoAsignado().getFechaTurno().getMes()
           && pa.getTurnoAsignado().getFechaTurno().getAnio()==
           p.getTurnoAsignado().getFechaTurno().getAnio()
           && pa.getTurnoAsignado().getHoraTurno().getHora()==
           p.getTurnoAsignado().getHoraTurno().getHora()
           && pa.getTurnoAsignado().getHoraTurno().getMinuto()==
           p.getTurnoAsignado().getHoraTurno().getMinuto()
           ){
                cout << "[X] Ha ocurrido un error, los datos no se guardaron." << endl;
                cout << endl;
                bandera=false;
                return;
        }
        if(pa.getEstado() && pa.getDni()==p.getDni()
           && pa.getTurnoAsignado().getFechaTurno().getDia()==
           p.getTurnoAsignado().getFechaTurno().getDia()
           && pa.getTurnoAsignado().getFechaTurno().getMes()==
           p.getTurnoAsignado().getFechaTurno().getMes()
           && pa.getTurnoAsignado().getFechaTurno().getAnio()==
           p.getTurnoAsignado().getFechaTurno().getAnio()
           && pa.getTurnoAsignado().getHoraTurno().getHora()==
           p.getTurnoAsignado().getHoraTurno().getHora()
           && pa.getTurnoAsignado().getHoraTurno().getMinuto()==
           p.getTurnoAsignado().getHoraTurno().getMinuto()
           ){
                cout << "[X] Ha ocurrido un error, los datos no se guardaron." << endl;
                cout << endl;
                bandera=false;
                return;
        }
     }
     if(bandera){
        archiPa.grabarRegistro(p);
        system("cls");
        cout << "[OK] El Turno se genero satisfactoriamente." << endl;
        cout<<endl;
     }
}


bool mostrarTodosPacientes(){
    Paciente e;
    FILE *p;

    p=fopen("turno.dat","rb");
    if(p==NULL){
      return false;
    }
    imprimirEncabezadoPaciente();

    while(fread(&e,sizeof e,1,p)==1){
        if(e.getEstado()){
            e.mostrarPaciente();
        }
    }
    cout<<endl;
    fclose(p);
    return true;
}

void bajaLogicaTurno(){
    int dni;
    cout<<"INGRESE DNI DEL PACIENTE: ";
    cargarEntero(dni);
    system("cls");

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    rlutil::locate(50,1);
    cout<<"TURNO A CANCELAR: "<<endl;
    cout<<endl;

    imprimirEncabezadoPaciente();

    bool bandera=true;

    for(int i=0;i<contPa;i++){
       pa= archiPa.leerRegistro(i);
       if(pa.getEstado() && pa.getDni()==dni){
         pa.mostrarPaciente();
         bandera=false;
      }
   }
   if(bandera){
       system("cls");
       cout << "[X] Error, El DNI no se encuentra registrado en la base de datos." << endl;
       cout<<endl;
       return;
   }
   cout<<"\n\n";

   int opcion,dia,mes,hora,minuto;
   cout<<"INGRESAR QUE TURNO DESEA CANCELAR: "<<endl;
   cout<<"DIA: ";
   cargarEntero(dia);
   cout<<"MES: ";
   cargarEntero(mes);
   cout << endl;
   cout<<"HORA: ";
   cargarEntero(hora);
   cout<<"MINUTOS: ";
   cargarEntero(minuto);
   cout << endl;
   cout << endl;
   cout << "DESEA CANCELAR EL TURNO?" << endl;
   cout << "1. Si." << endl;
   cout << "0. No." << endl;
   cout << "-------------------------------" << endl;
   cout << char(175) << " OPCION: ";
   cargarEntero(opcion);
   
   bool bandera1=true;

   for(int i=0;i<contPa;i++){
      pa= archiPa.leerRegistro(i);
      if(opcion==1 && pa.getDni()==dni
        && pa.getTurnoAsignado().getFechaTurno().getDia()==dia
        && pa.getTurnoAsignado().getFechaTurno().getMes()==mes
        && pa.getTurnoAsignado().getHoraTurno().getHora()==hora
        && pa.getTurnoAsignado().getHoraTurno().getMinuto()==minuto){

        pa.setEstado(false);

         if(archiPa.sobreEscribir(pa,i)){
            system("cls");
            cout << "[OK] El Turno se dio de baja correctamente." << endl;
            cout << endl;
            bandera1=false;
         }
      }
   }
   if(bandera1){
       system("cls");
       cout << "[X] El Turno no fue dado de baja." << endl;
       cout<<endl;
       return;
    }
}

void modificarTurno(){
    int dni;
    cout << "INGRESE DNI DEL PACIENTE: ";
    cargarEntero(dni);
    cout << endl;
    system("cls");

    Paciente pa,p;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    rlutil::locate(50,1);
    cout<<"PACIENTE A MODIFICAR TURNO: "<<endl;
    cout<<endl;
    imprimirEncabezadoPaciente();

    bool bandera=true;

    for(int i=0;i<contPa;i++){
        pa= archiPa.leerRegistro(i);
        
        if(pa.getEstado() && pa.getDni()==dni){
            pa.mostrarPaciente();
            bandera=false;
      }
   }
   if(bandera){
       system("cls");
       cout << "[X] Error, El DNI no se encuentra registrado en la base de datos." << endl;
       cout<<endl;
       return;
   }
   cout<<"\n\n";

   int opcion,dia,mes,hora,minuto;
   cout<<"INGRESAR QUE TURNO DESEA MODIFICAR: "<<endl;
   cout<<"DIA: ";
   cargarEntero(dia);
   cout<<"MES: ";
   cargarEntero(mes);
   cout << endl;
   cout<<"HORA: ";
   cargarEntero(hora);
   cout<<"MINUTOS: ";
   cargarEntero(minuto);
   cout << endl;
   cout << endl;
   cout << "DESEA MODIFICAR EL TURNO?" << endl;
   cout << "1. Si." << endl;
   cout << "0. No." << endl;
   cout << "-------------------------------" << endl;
   cout << char(175) << " OPCION: ";

   cargarEntero(opcion);

   if (opcion != 1) {
       system("cls");
       cout << "[X] Error, saliendo del sistema." << endl;
       cout << endl;
       return;
   }

   bool bandera2=false;
   int pos;

   for(int i=0;i<contPa;i++){
      pa= archiPa.leerRegistro(i);

      if(opcion==1 && pa.getDni()==dni
        && pa.getTurnoAsignado().getFechaTurno().getDia()==dia
        && pa.getTurnoAsignado().getFechaTurno().getMes()==mes
        && pa.getTurnoAsignado().getHoraTurno().getHora()==hora
        && pa.getTurnoAsignado().getHoraTurno().getMinuto()==minuto){

        system("cls");
         if(!p.cargarPaciente()){
           return;
           }

         pos=i;
         bandera2=true;
      }
   }

    if(bandera2){
        bool bandera=true;

        for(int j=0;j<contPa;j++){
            pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==p.getIdMatricula()
               && pa.getTurnoAsignado().getFechaTurno().getDia()==
               p.getTurnoAsignado().getFechaTurno().getDia()
               && pa.getTurnoAsignado().getFechaTurno().getMes()==
               p.getTurnoAsignado().getFechaTurno().getMes()
               && pa.getTurnoAsignado().getFechaTurno().getAnio()==
               p.getTurnoAsignado().getFechaTurno().getAnio()
               && pa.getTurnoAsignado().getHoraTurno().getHora()==
               p.getTurnoAsignado().getHoraTurno().getHora()
               && pa.getTurnoAsignado().getHoraTurno().getMinuto()==
               p.getTurnoAsignado().getHoraTurno().getMinuto()
            ){
                cout << "[X] Ha ocurrido un error, los datos no se guardaron." << endl;
                cout<<endl;
                bandera=false;
                return;
        }

        if(pa.getEstado() && pa.getDni()==p.getDni()
           && pa.getTurnoAsignado().getFechaTurno().getDia()==
           p.getTurnoAsignado().getFechaTurno().getDia()
           && pa.getTurnoAsignado().getFechaTurno().getMes()==
           p.getTurnoAsignado().getFechaTurno().getMes()
           && pa.getTurnoAsignado().getFechaTurno().getAnio()==
           p.getTurnoAsignado().getFechaTurno().getAnio()
           && pa.getTurnoAsignado().getHoraTurno().getHora()==
           p.getTurnoAsignado().getHoraTurno().getHora()
           && pa.getTurnoAsignado().getHoraTurno().getMinuto()==
           p.getTurnoAsignado().getHoraTurno().getMinuto()
           ){
           cout << "[X] Ha ocurrido un error, los datos no se guardaron." << endl;
           cout<<endl;
           bandera=false;
           return;
           }
        }
        if(bandera){
           archiPa.sobreEscribir(p,pos);
           system("cls");
           cout << "[OK] Los datos se guardaron correctamente." << endl;
           cout<<endl;
        }
    }
}

void listaDeMedico(){
    Especialista e;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();
    imprimirEncabezadoEspecialista();

    for(int i=0;i<contEs;i++){
        e= archiEs.leerRegistro(i);
            if(e.getEstado()){
                e.mostrarEspecialista();
            }
    }
    cout<<endl;
}

#endif // ARCHIVOCONTROLADORES_H_INCLUDED
