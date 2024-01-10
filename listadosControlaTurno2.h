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

//funciones
void consultaPacientePorMedico(){
    char titulo[40] = "PACIENTES POR ESPECIALISTA";
    recuadro(titulo);

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
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";
            es.mostrarEspecialista();
            cout<<"-----------------------------------------------------------";
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
    char titulo[40] = "PACIENTES POR DIA";

    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int dia;
    cout<<"INGRESAR EL DIA: ";
    cargarEntero(dia);

    cout<<endl;
    system("cls");

    recuadro(titulo);
    for(int i=0;i<contEs;i++){
        es = archiEs.leerRegistro(i);

        if(es.getEstado()){
            const int anchoColumna = 20;
            cout<<"\n\n";
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                          << setw(anchoColumna) << "MATRICULA"
                          << setw(anchoColumna) << "NOMBRE"
                          << setw(anchoColumna) << "APELLIDO"
                          << setw(15) << "DNI"
                          << setw(0) << "FECHA NACIMIENTO"
                          << "\n";
            es.mostrarEspecialista();
            cout<<"-----------------------------------------------------------";
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
    char titulo[40] = "PACIENTES POR ESPECIALIDAD";
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs = archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int numEspecialidad;

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
         return;
     }
 
    system("cls");
    recuadro(titulo);

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getEspecialidad()== numEspecialidad){

            const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";

            es.mostrarEspecialista();
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }
        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

             if(pa.getEstado() && es.getIdMatricula()==pa.getIdMatricula()
                && pa.getEspecialista()== numEspecialidad){

                    pa.mostrarPaciente();
                }
        }
    }
    cout<<endl;
}

void consultaHorariosOcupados(){
    char titulo[40] = "PACIENTES POR HORARIO";
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
    cout<<"INGRESAR DIA: ";
    cargarEntero(dia);

    cout<<"INGRESAR MES: ";
    cargarEntero(mes);

    cout<<"INGRESE HORA A CONSULTAR: ";
    cargarEntero(hora);

    cout<<endl;

    system("cls");
    recuadro(titulo);

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado()){

            const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";

            es.mostrarEspecialista();
            cout<<"-----------------------------------------------------------";
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
    char titulo[40] = "TURNOS POR DNI DEL PACIENTE";
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();
    
    int dni;
    cout<<"INGRESAR DNI A BUSCAR CONSULTA: ";
    cargarEntero(dni);

    system("cls");
    recuadro(titulo);

     for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado()){
            const int anchoColumna = 20;

            cout<<"\n\n";
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                          << setw(anchoColumna) << "MATRICULA"
                          << setw(anchoColumna) << "NOMBRE"
                          << setw(anchoColumna) << "APELLIDO"
                          << setw(15) << "DNI"
                          << setw(0) << "FECHA NACIMIENTO"
                          << "\n";
            es.mostrarEspecialista();
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }

        for(int j=0;j<contPa;j++){
             pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
               && pa.getDni()==dni){

               pa.mostrarPaciente();
            }
        }
     }
     cout<<endl;
}

void consultaEspecialistaDni(){
    char titulo[40] = "TURNOS POR DNI DEL ESPECIALISTA";
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    int dni;
    cout<<"INGRESAR DNI DEL ESPECIALISTA: ";
    cargarEntero(dni);

    system("cls");
    recuadro(titulo);
      for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getDni()==dni){
            const int anchoColumna = 20;
            cout<<"\n\n";
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";
            es.mostrarEspecialista();
            cout<<"-----------------------------------------------------------";
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
    char titulo[40] = "TURNOS POR MATRICULA DEL ESPECIALISTA";
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    int matricula;
    cout<<"INGRESAR MATRICULA DEL ESPECIALISTA: ";
    cargarEntero(matricula);
    system("cls");

   recuadro(titulo);

      for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        if(es.getEstado() && es.getIdMatricula()==matricula){
            const int anchoColumna = 20;
            cout<<"\n\n";
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
            cout << left << setw(anchoColumna) << "ESPECIALIDAD"
                         << setw(anchoColumna) << "MATRICULA"
                         << setw(anchoColumna) << "NOMBRE"
                         << setw(anchoColumna) << "APELLIDO"
                         << setw(15) << "DNI"
                         << setw(0) << "FECHA NACIMIENTO"
                         << "\n";
            es.mostrarEspecialista();
            cout<<"-----------------------------------------------------------";
            cout<<"-----------------------------------------------------------"<<endl;
        }

        for(int j=0;j<contPa;j++){
            pa= archiPa.leerRegistro(j);

            if(pa.getEstado() && pa.getIdMatricula()==es.getIdMatricula()
               && es.getIdMatricula()==matricula){
               pa.mostrarPaciente();
            }
        }
     }
     cout<<endl;
}

#endif // LISTADOSCONTROLATURNO2_H_INCLUDED
