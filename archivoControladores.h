#ifndef ARCHIVOCONTROLADORES_H_INCLUDED
#define ARCHIVOCONTROLADORES_H_INCLUDED

#include"paciente.h"
#include"archivoClassPacientess.h"

#include"especialista.h"
#include"archivoClassEspecialista.h"

#include <iomanip>
#include"rlutil.h"

//funciones prototipos
void altaTurno();
bool mostrarTodosPacientes();
void bajaLogicaTurno();
void modificarTurno();
void listaDeMedico();

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
                cout<<endl;
                cout<<"NO SE GUARDO..."<<endl;
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
                cout<<endl;
                cout<<"NO SE GUARDO..."<<endl;
                cout<<endl;
                bandera=false;
                return;
        }

     }
     if(bandera){
        archiPa.grabarRegistro(p);
        cout<<endl;
        cout<<"SE GUARDO CORRECTAMENTE..."<<endl;
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

   const int anchoColumna = 20;

    cout << left << setw(anchoColumna) << "NOMBRE"
              << setw(anchoColumna) << "APELLIDO"
              << setw(anchoColumna) << "DNI"
              << setw(anchoColumna) << "ESPECIALISTA"
              << setw(15) << "MATRICULA"
              << setw(anchoColumna) << "TURNO DIA"
              << setw(anchoColumna) << "HORA"
              << "\n";

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
    int numero;
    cout<<endl;
    cout<<"TURNO A DAR DE BAJA INGRESE DNI: ";
    cin>>numero;
    cout<<endl;

   system("cls");

   Paciente pa;
   ArchivoPaciente archiPa("turno.dat");

   int contPa= archiPa.contarRegistros();

   const int anchoColumna = 20;

   rlutil::locate(50,1);
   cout<<"PACIENTE A BORRAR: "<<endl;
   cout<<endl;

   cout << left << setw(anchoColumna) << "NOMBRE"
                << setw(anchoColumna) << "APELLIDO"
                << setw(anchoColumna) << "DNI"
                << setw(anchoColumna) << "ESPECIALISTA"
                << setw(15) << "MATRICULA"
                << setw(anchoColumna) << "TURNO DIA"
                << setw(anchoColumna) << "HORA"
                << "\n";

   bool bandera=true;

   for(int i=0;i<contPa;i++){
      pa= archiPa.leerRegistro(i);

      if(pa.getEstado() && pa.getDni()==numero){

        pa.mostrarPaciente();
        bandera=false;
      }
   }
    if(bandera){
     cout<<endl;
     cout<<"NO EXISTE EL DNI."<<endl;
     cout<<endl;

   return;
   }
   cout<<"\n\n";
   int opc,dia,mes,hora,minuto;

   cout<<"                       INGRESAR QUE TURNO DESEA BORRAR: "<<endl;
   cout<<"DIA: ";
   cin>>dia;



   cout<<"MES: ";
   cin>>mes;



   cout<<"HORA: ";
   cin>>hora;


   cout<<"MINUTOS: ";
   cin>>minuto;



   cout<<endl;
   cout<<"DESEA BORRARLO OPC= 1 / NO OPC= 0: ";
   cin>>opc;


   system("cls");

   if(opc!=1){
      system("cls");
      cout<<"SALIO..."<<endl;
      cout<<endl;
      return;
   }

   bool bandera1=true;

   for(int i=0;i<contPa;i++){
      pa= archiPa.leerRegistro(i);

      if(opc==1 && pa.getDni()==numero
        && pa.getTurnoAsignado().getFechaTurno().getDia()==dia
        && pa.getTurnoAsignado().getFechaTurno().getMes()==mes
        && pa.getTurnoAsignado().getHoraTurno().getHora()==hora
        && pa.getTurnoAsignado().getHoraTurno().getMinuto()==minuto){

         pa.setEstado(false);

         if(archiPa.sobreEscribir(pa,i)){
            cout<<"SE DIO DE BAJA... "<<endl;
            bandera1=false;
            cout<<endl;
         }
      }
   }
   if(bandera1){
        cout<<"NO SE PUDO DAR DE BAJA... "<<endl;
        cout<<endl;
    }
}


void modificarTurno(){
      int numero;
      cout<<endl;
      cout<<"DNI QUE DESEA MODIFICAR TURNO: ";
      cin>>numero;


    cout<<endl;
    system("cls");

   Paciente pa,p;
   ArchivoPaciente archiPa("turno.dat");

   int contPa= archiPa.contarRegistros();

   rlutil::locate(50,1);
   cout<<"PACIENTE A MODIFICAR/TURNO: "<<endl;
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

   bool bandera=true;

   for(int i=0;i<contPa;i++){
      pa= archiPa.leerRegistro(i);

      if(pa.getEstado() && pa.getDni()==numero){

        pa.mostrarPaciente();
        bandera=false;
      }
   }
   if(bandera){
     system("cls");
     cout<<endl;
     cout<<"NO EXISTE EL DNI."<<endl;
     cout<<endl;
   return;
   }
   cout<<"\n\n";
   int opc,dia,mes,hora,minuto;

   cout<<"                       INGRESAR QUE TURNO DESEA MODIFICAR: "<<endl;
   cout<<"DIA: ";
   cin>>dia;



   cout<<"MES: ";
   cin>>mes;


   cout<<"HORA: ";
   cin>>hora;



   cout<<"MINUTOS: ";
   cin >> minuto;


   cout<<endl;
   cout<<"DESEA MODIFICARLO OPC= 1 / NO OPC= 0: ";
   cin>>opc;


    cout<<endl;

   if(opc!=1){
      system("cls");
      cout<<"SALIO..."<<endl;
      cout<<endl;
      return;
   }

   bool bandera2=false;
   int pos;

   for(int i=0;i<contPa;i++){
      pa= archiPa.leerRegistro(i);

      if(opc==1 && pa.getDni()==numero
        && pa.getTurnoAsignado().getFechaTurno().getDia()==dia
        && pa.getTurnoAsignado().getFechaTurno().getMes()==mes
        && pa.getTurnoAsignado().getHoraTurno().getHora()==hora
        && pa.getTurnoAsignado().getHoraTurno().getMinuto()==minuto){

        system("cls");
         if(!p.cargarPaciente()){
           return;
           }
         //esto agrege
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
                cout<<endl;
                cout<<"NO SE GUARDO..."<<endl;
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
           cout<<endl;
           cout<<"NO SE GUARDO..."<<endl;
           cout<<endl;
           bandera=false;
           return;
           }
        }
        if(bandera){
          archiPa.sobreEscribir(p,pos);
          cout<<"SE MODIFICO EL TURNO... "<<endl;
          cout<<endl;
        }
    }
}



void listaDeMedico(){
    Especialista e;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    const int anchoColumna = 20;

    cout << left << setw(anchoColumna) << "ESPECIALIDAD"
              << setw(anchoColumna) << "MATRICULA"
              << setw(anchoColumna) << "NOMBRE"
              << setw(anchoColumna) << "APELLIDO"
              << setw(15) << "DNI"
              << setw(0) << "FECHA NACIMIENTO"
              << "\n";

    for(int i=0;i<contEs;i++){
        e= archiEs.leerRegistro(i);

            if(e.getEstado()){

                e.mostrarEspecialista();
            }
    }
    cout<<endl;
}

#endif // ARCHIVOCONTROLADORES_H_INCLUDED
