#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "fecha2.h" 
using namespace std;
 
class Persona{
    
    private:
        char nombre[20];
 	    char apellido[20];
        int codigo;
 	    char cargo[20];
        char genero[2];
        char telefono[20];
        char correo[20];
        char f_nac[20];
    public:
        Persona();      
        void ActualizarDatos(int, char[20], char[20], char[20], char[2],char[20],char[20],char[20]);
        void Imprimir();
        int obtenerCodigo();
    
};
 
//inicializamos el constructor de Persona
Persona::Persona(){
    
    this->codigo = 0;
    strcpy(this->nombre, "/0");
    strcpy(this->apellido, "/0");
    strcpy(this->cargo, "/0");
    strcpy(this->genero, "/0");
    strcpy(this->telefono, "/0");
    strcpy(this->correo, "/0");
    strcpy(this->f_nac, "/0");
}
 
void Persona::ActualizarDatos(int c, char n[20], char a[20], char ca[20],char g[20],char te[20], char co[20], char fn[20]){
    
    this->codigo = c;
    strcpy(this->nombre, n);
    strcpy(this->apellido, a);
    strcpy(this->cargo, ca);
    strcpy(this->genero, g);
    strcpy(this->telefono, te);
    strcpy(this->correo, co);
    strcpy(this->f_nac, fn);
}
 
void Persona::Imprimir(){
	
	cout << "-------------------------" << endl;
    cout << "Codigo:" << this->codigo << endl;
    cout << "Nombre:" << this->nombre << endl;
    cout << "Apellido:" << this->apellido << endl;
    cout << "Cargo:" << this->cargo << endl;
    cout << "Genero:" << this->genero << endl;
    cout << "Telefono:" << this->telefono << endl;
    cout << "Correo:" << this->correo << endl;
    cout << "Fecha nacimiento:" << this->f_nac << endl;
	cout << "-------------------------" << endl;
    cout << "" << endl;

}
 
int Persona::obtenerCodigo(){
    
    return this->codigo;
    
}
 
