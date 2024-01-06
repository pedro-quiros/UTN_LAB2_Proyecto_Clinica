#ifndef ARCHIVOCLASSESPECIALISTA_H_INCLUDED
#define ARCHIVOCLASSESPECIALISTA_H_INCLUDED

class ArchivoEspecialista{
private:
    char nombre[30];
public:
    ArchivoEspecialista(const char *n){
        strcpy(nombre, n);
    }
    Especialista leerRegistro(int pos){
        Especialista reg;
        //reg.setCategoria(-1);
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Especialista);
    }
    bool grabarRegistro(Especialista reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        bool escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }
    bool sobreEscribir(Especialista e,int pos){
         FILE *p;
         p=fopen(nombre,"rb+");
         if(p==NULL){
            return false;
         }
        fseek(p,sizeof e*pos,0);
        bool escribio = fwrite(&e,sizeof e,1,p);
        fclose(p);
        return escribio;
    }
};

#endif // ARCHIVOCLASSESPECIALISTA_H_INCLUDED
