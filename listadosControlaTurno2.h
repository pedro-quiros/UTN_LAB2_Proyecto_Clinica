#ifndef LISTADOSCONTROLATURNO2_H_INCLUDED
#define LISTADOSCONTROLATURNO2_H_INCLUDED

#include"especialista.h"
#include"archivoClassEspecialista.h"
#include"paciente.h"
#include"archivoClassPacientess.h"


//funciones prototipos
void consultaPacientePorMedico();
void consultaPorDia();
void consultaPorEspecialidad();
void consultaHorariosOcupados();
void consultaPorDni();
void consultaEspecialistaDni();
void consultaPorMatriculaES();
void consultaPorMatriculaDiaHora();


void consultaPacientePorMedico(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();


    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if (es.getEstado()){

            const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;

            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";

            es.mostrarEspecialista();
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(es.getEstado() && es.getIdMatricula()==pa.getIdMatricula()){

                    pa.mostrarPaciente();
            }
        }
    }
    cout<<endl;
}

void consultaPorDia(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int dia;
    cout<<"INGRESAR EL DIA: ";
    cin>>dia;

    cout<<endl;

    system("cls");

    if(dia<=0 || dia>31){
        cout<<"SALIO..."<<endl;
        cout<<endl;
        return;
    }

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado()){

             const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;

             cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                          << setw(anchoColumna) << "MATRICULA"
                          << setw(anchoColumna) << "NOMBRE"
                          << setw(anchoColumna) << "APELLIDO"
                          << setw(15) << "DNI"
                          << setw(0) << "FECHA NACIMIENTO"
                          << "\n";

            es.mostrarEspecialista();
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

             if(pa.getEstado() && es.getIdMatricula()==pa.getIdMatricula()
                && pa.getTurnoAsignado().getFechaTurno().getDia()==dia){

                    pa.mostrarPaciente();
                }
        }
    }
    cout<<endl;
}

void consultaPorEspecialidad(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int esp;
    rlutil::locate(50, 1);
    cout<<"INGRESAR NUMERO DE ESPECIALIDAD: "<<endl;
    rlutil::locate(55, 3);
    cout<<"1-CLINICO. "<<endl;
    rlutil::locate(55, 4);
    cout<<"2-UROLOGO. "<<endl;
    rlutil::locate(55, 5);
    cout<<"3-GINECOLOGO. "<<endl;
    rlutil::locate(55, 6);
    cout<<"4-CARDIOLOGO. "<<endl;
     rlutil::locate(55, 7);
    cout<<"5-DERMATOLOGO. "<<endl;
    rlutil::locate(55, 8);
    cin>>esp;



     if(esp<=0 || esp>5){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return;
    }

    system("cls");

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getEspecialidad()==esp){

            const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;

            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";

            es.mostrarEspecialista();
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }
        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

             if(pa.getEstado() && es.getIdMatricula()==pa.getIdMatricula()
                && pa.getEspecialista()==esp){

                    pa.mostrarPaciente();
                }
        }
    }
    cout<<endl;
}

void consultaHorariosOcupados(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int dia,mes,hora;

    rlutil::locate(45, 1);
    cout<<"INGRESA DIA/MES/HORA LISTADO DE TODAS LAS CONSULTAS: "<<endl;
    rlutil::locate(40, 3);
    cout<<"INGRESAR DIA: ";
    rlutil::locate(55, 3);
    cin>>dia;




     if(dia<=0 || dia>31){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return;
    }

    int esp3=4;
    rlutil::locate(40, esp3);
    cout<<"INGRESAR MES: ";
    rlutil::locate(55, esp3);
    cin>>mes;
    esp3++;


     if(mes<=0 || mes>12){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return;
    }

    rlutil::locate(40, esp3);
    cout<<"INGRESE HORA A CONSULTAR: ";
    rlutil::locate(67, esp3);
    cin>>hora;
    esp3++;



     if(hora<0 || hora>24){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return;
    }

    cout<<endl;

    system("cls");

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado()){

            const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;

            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";

            es.mostrarEspecialista();
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

             if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
                && pa.getTurnoAsignado().getFechaTurno().getDia()==dia
                && pa.getTurnoAsignado().getFechaTurno().getMes()==mes
                && pa.getTurnoAsignado().getHoraTurno().getHora()==hora){

                    pa.mostrarPaciente();
                }
        }
    }
    cout<<endl;
}

void consultaPorDni(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();


    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int num;
    cout<<"INGRESAR DNI A BUSCAR CONSULTA: ";
    cin>>num;

    system("cls");

     for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado()){

             const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;

             cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                          << setw(anchoColumna) << "MATRICULA"
                          << setw(anchoColumna) << "NOMBRE"
                          << setw(anchoColumna) << "APELLIDO"
                          << setw(15) << "DNI"
                          << setw(0) << "FECHA NACIMIENTO"
                          << "\n";

            es.mostrarEspecialista();
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
               && pa.getDni()==num){

               pa.mostrarPaciente();
            }
        }
     }
     cout<<endl;
}

void consultaEspecialistaDni(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();


    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int dni;
    cout<<"INGRESAR DNI DEL ESPECIALISTA: ";
    cin>>dni;



    system("cls");

      for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getDni()==dni){

            const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;

            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";

            es.mostrarEspecialista();
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
               && es.getDni()==dni){

               pa.mostrarPaciente();
            }
        }
     }
     cout<<endl;
}

void consultaPorMatriculaES(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();


    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int matri;
    cout<<"INGRESAR MATRICULA DEL ESPECIALISTA: ";
    cin>>matri;

    system("cls");

      for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getIdMatricula()==matri){

            const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;

            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";

            es.mostrarEspecialista();
            cout<<"--------------------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
               && es.getIdMatricula()==matri){

               pa.mostrarPaciente();
            }
        }
     }
     cout<<endl;
}

void consultaPorMatriculaDiaHora(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();


    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

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

        if(es.getEstado()){
           es.mostrarEspecialista();
        }
    }

    cout<<endl;
    int matri,dia,mes,anio,hora,minuto;
    cout<<"INGRESAR MATRICULA DEL ESPECIALISTA: ";
    cin>>matri;


    cout<<"INGRESAR DIA POSIBLE TURNO: ";
    cin>>dia;

    cout<<"INGRESAR MES POSIBLE TURNO: ";
    cin>>mes;


    cout<<"INGRESAR ANIO POSIBLE TURNO: ";
    cin>>anio;



    cout<<"INGRESAR HORA POSIBLE TURNO: ";
    cin>>hora;


    cout<<"INGESAR MINUTOS POSIBLE TURNO: ";
    cin>>minuto;


    cout<<endl;

    bool bandera= true;

        for(int i=0;i<contEs;i++){
            es= archiEs.leerRegistro(i);

            for(int j=0;j<contPa;j++){
                 pa= archiPa.leerRegistro(j);

                if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
                   && es.getIdMatricula()==matri
                   && pa.getTurnoAsignado().getFechaTurno().getDia()==dia
                   && pa.getTurnoAsignado().getFechaTurno().getMes()==mes
                   && pa.getTurnoAsignado().getFechaTurno().getAnio()==anio
                   && pa.getTurnoAsignado().getHoraTurno().getHora()==hora
                   && pa.getTurnoAsignado().getHoraTurno().getMinuto()==minuto){

                 cout<<" DIA Y HORARIO OCUPADOS... "<<endl;
                 bandera=false;

                }
            }
        }
        if(bandera){
            cout<<" DIA Y HORA LIBRES..."<<endl;
        }
  cout<<endl;
}

#endif // LISTADOSCONTROLATURNO2_H_INCLUDED
