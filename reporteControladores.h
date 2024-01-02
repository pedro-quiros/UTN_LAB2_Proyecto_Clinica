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

    int mes,anio,hastaMes,hastaAnio,ma;

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

    cout<<endl;
    cout<<"INGRESAR MATRICULA DEL ESPECIALISTA: ";
    cin>>ma;
    cout<<"INGRESA DESDE QUE MES: ";
    cin>>mes;
    cout<<"INGRESA DESDE QUE ANIO: ";
    cin>>anio;
    cout<<"INGRESA HASTA QUE MES: ";
    cin>>hastaMes;
    cout<<"INGRESA HASTA QUE ANIO: ";
    cin>>hastaAnio;

    int cont=0;

    for(int i=0;i<contEs;i++){
        es= archiEs.leerRegistro(i);

        for(int j=0;j<contPa;j++){
            pa= archiPa.leerRegistro(j);

           if(es.getIdMatricula()==pa.getIdMatricula() && es.getIdMatricula()==ma
              && pa.getTurnoAsignado().getFechaTurno().getMes()>=mes
              && pa.getTurnoAsignado().getFechaTurno().getAnio()>=anio
              && pa.getTurnoAsignado().getFechaTurno().getDia()<=hastaMes
              && pa.getTurnoAsignado().getFechaTurno().getAnio()<=hastaAnio){

                cont++;
              }
        }
    }
    cout<<endl;
    cout<<"EN EL PERIODO INDICADO ATENDIO:  "<<cont<<endl;
    cout<<endl;

}

void cantidadDeConsultaPaciente(){
    Paciente pa;
    ArchivoPaciente archiPa("turno.dat");

    int contPa= archiPa.contarRegistros();

    cout<<endl;
    int num;
    cout<<"INGRESE EL DNI DEL PACIENTE: ";
    cin>>num;



    int cont=0;

    for(int i=0;i<contPa;i++){
        pa= archiPa.leerRegistro(i);

        if(pa.getDni()==num){

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

    cout<<endl;
    int num;

    rlutil::locate(50,1);
    cout<<"INGRESAR ESPECIALIDAD: "<<endl;
    rlutil::locate(55,3);
    cout<<"1- CLINICO. "<<endl;
    rlutil::locate(55,4);
    cout<<"2- UROLOGO. "<<endl;
    rlutil::locate(55,5);
    cout<<"3- GINECOLOGO. "<<endl;
    rlutil::locate(55,6);
    cout<<"4- CARDIOLOGO. "<<endl;
    rlutil::locate(55,7);
    cout<<"5- DERMATOLOGO. "<<endl;
    rlutil::locate(55,8);

    cin>>num;


    if(num<=0 || num>5){
        system("cls");
        cout<<"SALIENDO, MAL INGRESO..."<<endl;
        cout<<endl;
        return;
    }

    system("cls");

    int cont=0;

    cout<<"ESPECIALISTAS: "<<num<<endl;


    for(int j=0;j<contPa;j++){
        pa= archiPa.leerRegistro(j);

        if(pa.getEspecialista()==num && num!=0){

            cont++;
        }
    }
    cout<<endl;
    cout<<"LOS ESPECIALISTAS CON ESE NUMERO TUVIERON: "<<cont<<" CONSULTAS."<<endl;
    cout<<endl;
}


#endif // REPORTECONTROLADORES_H_INCLUDED
