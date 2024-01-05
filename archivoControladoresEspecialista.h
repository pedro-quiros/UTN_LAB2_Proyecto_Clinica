#ifndef ARCHIVOCONTROLADORESESPECIALISTA_H_INCLUDED
#define ARCHIVOCONTROLADORESESPECIALISTA_H_INCLUDED

#include"especialista.h"
#include"archivoClassEspecialista.h"
#include "validaciones.h"

//funciones prototipos
void altaEspecialista();
void bajaLogicaEspecialista();
void modificarEspecialista();

void altaEspecialista(){
    Especialista e,esp;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    if(!e.cargarEspecialista()){
        return;
    }

    bool bandera=true;

     for(int i=0;i<contEs;i++){
        esp= archiEs.leerRegistro(i);

        if(esp.getEstado() && esp.getIdMatricula()==e.getIdMatricula()){
            system("cls");
            cout << "[X] Error, La matricula ya se encuentra registrada." << endl;
            cout<<endl;
            bandera=false;
                return;
        }
     }

     if(bandera){
        archiEs.grabarRegistro(e);
        cout<<endl;
        cout<<"SE GUARDO CORRECTAMENTE."<<endl;
        cout<<endl;
     }
}


void bajaLogicaEspecialista(){
    int numMatricula;
    rlutil::locate(51, 1);
    cout << "ESPECIALISTA A DAR DE BAJA: " << endl;
    cout << endl;

    cout << "INGRESAR EL NUMERO DE MATRICULA: ";
    cargarEntero(numMatricula);

   Especialista es;
   ArchivoEspecialista archiEs("especialista.dat");

   int contEs= archiEs.contarRegistros();

   const int anchoColumna = 20;

   system("cls");

   rlutil::locate(50,1);
   cout<<"ESPECIALISTA A DAR DE BAJA: "<<endl;
   cout<<endl;

   cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                 << setw(anchoColumna) << "MATRICULA"
                 << setw(anchoColumna) << "NOMBRE"
                 << setw(anchoColumna) << "APELLIDO"
                 << setw(15) << "DNI"
                 << setw(0) << "FECHA NACIMIENTO"
                 << "\n";

    bool bandera=true;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getIdMatricula()==numMatricula){
           es.mostrarEspecialista();
           bandera=false;
        }
    }
    if(bandera){
       system("cls");
       cout << "[X] Error, La matricula no existe." << endl;
       cout<<endl;
       return;
    }

   int opc;
   rlutil::locate(50, 7);
   cout << "DESEA BORRAR ESPECIALISTA?" << endl;
   rlutil::locate(51, 8);
   cout << "1. Si." << endl;
   rlutil::locate(51, 9);
   cout << "0. No." << endl;
   rlutil::locate(51, 10);
   cout << "-------------------------------" << endl;
   rlutil::locate(51, 11);
   cout << char(175) << " OPCION: ";

   cargarEntero(opc);
 
   if (opc != 1) {
       system("cls");
       cout << "[X] Error, saliendo del sistema." << endl;
       cout << endl;
       return;
   }

   bool bandera1=true;

   for(int i=0;i<contEs;i++){
      es= archiEs.leerRegistro(i);

      if(opc==1 && es.getIdMatricula()==numMatricula){
         es.setEstado(false);
         if(archiEs.sobreEscribir(es,i)){
             cout << "[OK] Se dio de baja correctamente." << endl;
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

void modificarEspecialista(){
      int numero;
      cout<<endl;
      cout<<" MATRICULA DEL ESPECIALISTA A MODIFICAR: ";
      cin>>numero;

    system("cls");

    Especialista e,es;
    ArchivoEspecialista archiEs("especialista.dat");

   int contEs= archiEs.contarRegistros();

   const int anchoColumna = 20;

   system("cls");

   rlutil::locate(50,1);
   cout<<"ESPECIALISTA A MODIFICAR: "<<endl;
   cout<<endl;

   cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                 << setw(anchoColumna) << "MATRICULA"
                 << setw(anchoColumna) << "NOMBRE"
                 << setw(anchoColumna) << "APELLIDO"
                 << setw(15) << "DNI"
                 << setw(0) << "FECHA NACIMIENTO"
                 << "\n";

    bool bandera=true;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getIdMatricula()==numero){
           es.mostrarEspecialista();
           bandera=false;
        }
    }
    if(bandera){
       cout<<endl;
       system("cls");
       cout << "[X] Error, No existe la matricula." << endl;
       cout<<endl;

   return;
   }
   int opc;
   rlutil::locate(50, 7);
   cout << "DESEA MODIFICAR ESPECIALISTA?" << endl;
   rlutil::locate(51, 8);
   cout << "1. Si." << endl;
   rlutil::locate(51, 9);
   cout << "0. No." << endl;
   rlutil::locate(51, 10);
   cout << "-------------------------------" << endl;
   rlutil::locate(51, 11);
   cout << char(175) << " OPCION: ";

   cargarEntero(opc);

   system("cls");

   if(opc!=1){
      system("cls");
      cout << "[X] Error, saliendo del sistema." << endl;
      cout<<endl;
      return;
   }

    if(!e.cargarEspecialista()){
        return;
    }

    bool bandera1=true;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(opc==1 && es.getEstado() && es.getIdMatricula()==e.getIdMatricula() &&
           es.getIdMatricula()==numero){

          if(archiEs.sobreEscribir(e,i)){
               cout<<"SE MODIFICO EL ESPECIALISTA... "<<endl;
               bandera1=false;
               cout<<endl;
        }
      }
   }
   if(bandera1){
        cout<<"NO SE MODIFICO... "<<endl;
        cout<<endl;
    }
}


#endif // ARCHIVOCONTROLADORESESPECIALISTA_H_INCLUDED
