#ifndef REPORTECONTROLADORES_H_INCLUDED
#define REPORTECONTROLADORES_H_INCLUDED

#include"archivoClassEspecialista.h"
#include"especialista.h"
#include"archivoClassPacientess.h"
#include"paciente.h"

//Prototipos funciones
void pacientesPorAnio();
void cantidadDeConsultaPaciente();
void cantidadPorEspecialidad();

void pacientesPorAnio(){
    Especialista es;
    ArchivoEspecialista archiEs("especialista.dat");

    int contEs= archiEs.contarRegistros();

    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    int mes,anio,hastaMes,hastaAnio,matricula;

    rlutil::locate(50, 1);
    cout<<"ESPECIALISTAS: "<<endl;
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

         if (es.getEstado()){
            es.mostrarEspecialista();
        }
    }

    cout << endl;
    cout<<"INGRESAR MATRICULA DEL ESPECIALISTA: ";
    cargarEntero(matricula);
    cout << endl;
    cout<<"INGRESA DESDE QUE MES: ";
    cargarEntero(mes);
    cout<<"INGRESA DESDE QUE ANIO: ";
    cargarEntero(anio);
    cout<<endl;
    cout<<"INGRESA HASTA QUE MES: ";
    cargarEntero(hastaMes);
    cout<<"INGRESA HASTA QUE ANIO: ";
    cargarEntero(hastaAnio);

    int cont=0;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        for(int j=0;j<contPa;j++){
            pa= archiPa.leerRegistro(j);

           if(es.getIdMatricula()==pa.getIdMatricula() && es.getIdMatricula()==matricula
              && pa.getTurnoAsignado().getFechaTurno().getMes()>=mes
              && pa.getTurnoAsignado().getFechaTurno().getAnio()>=anio
              && pa.getTurnoAsignado().getFechaTurno().getDia()<=hastaMes
              && pa.getTurnoAsignado().getFechaTurno().getAnio()<=hastaAnio){
              cont++;
              }
        }
    }
    cout<<endl;
    cout << endl;
    cout<<"EN EL PERIODO INDICADO ATENDIO: "<<cont<<" PACIENTES."<<endl;
    cout<<endl;
}

void cantidadDeConsultaPaciente(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int dni;
    cout<<"INGRESE EL DNI DEL PACIENTE: ";
    cargarEntero(dni);

    int cont=0;

    for(int i=0;i<contPa;i++){
        pa= archiPa.leerRegistro(i);

        if(pa.getDni()==dni){

            cont++;
        }
    }
    cout<<endl;
    cout<<"CANTIDAD DE CONSULTAS: "<<cont<<endl;
    cout<<endl;
}

void cantidadPorEspecialidad(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();
    cout << endl;
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

    int cont=0;
    cout<<"ESPECIALIDAD: "<<numEspecialidad<<endl;

    for(int j=0;j<contPa;j++){
        pa= archiPa.leerRegistro(j);

        if(pa.getEspecialista()==numEspecialidad && numEspecialidad!=0){
            cont++;
        }
    }
    cout<<endl;
    cout<<"LOS ESPECIALISTAS CON ESE NUMERO TUVIERON: "<<cont<<" CONSULTAS."<<endl;
    cout<<endl;
}

#endif // REPORTECONTROLADORES_H_INCLUDED
