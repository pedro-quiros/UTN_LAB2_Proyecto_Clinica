#ifndef ARCHIVOCONTROLADORESESPECIALISTA_H_INCLUDED
#define ARCHIVOCONTROLADORESESPECIALISTA_H_INCLUDED

#include"especialista.h"
#include"archivoClassEspecialista.h"

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
                cout<<endl;
                cout<<"ERROR, MATRICULA YA EXISTENTE."<<endl;
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
    int numero;
    cout<<endl;
    cout<<"ESPECIALISTA A DAR DE BAJA INGRESE MATRICULA: ";
    cin>>numero;
    cout<<endl;



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

        if(es.getEstado() && es.getIdMatricula()==numero){

           es.mostrarEspecialista();
           bandera=false;
        }
    }
    if(bandera){
       system("cls");
       cout<<endl;
       cout<<"NO EXISTE LA MATRICULA."<<endl;
       cout<<endl;

   return;
   }
   int opc;
   cout<<endl;
   cout<<"DESEA BORRAR ESPECILISTA OPC= 1 / NO OPC= 0: ";
   cin>>opc;


    cout<<endl;

   system("cls");

   if(opc!=1){
      cout<<"SALIO..."<<endl;
      cout<<endl;
      return;
   }

   bool bandera1=true;

   for(int i=0;i<contEs;i++){
      es= archiEs.leerRegistro(i);

      if(opc==1 && es.getIdMatricula()==numero){

         es.setEstado(false);

         if(archiEs.sobreEscribir(es,i)){
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
       cout<<"NO EXISTE LA MATRICULA."<<endl;
       cout<<endl;

   return;
   }
   int opc;
   cout<<endl;
   cout<<"DESEA MODIFICAR ESPECILISTA OPC= 1 / NO OPC= 0: ";
   cin>>opc;


    cout<<endl;

   system("cls");

   if(opc!=1){
      system("cls");
      cout<<"SALIO..."<<endl;
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
