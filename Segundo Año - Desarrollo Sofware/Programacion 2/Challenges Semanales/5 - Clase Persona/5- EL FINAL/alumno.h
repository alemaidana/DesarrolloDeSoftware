#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include "personita.h"
 
using namespace std;
 
class Alumno : public Persona {
 
    char curso[20];
    int legajo;
    
 
    public:
    Alumno();   
    void ActualizarAlumno(int, char[20], char[20], char[20], char[20],char[20],char[20],char[20],char[20], int);        
    void MostrarAlumno();
};
 
Alumno::Alumno(){
    
    this->codigo = 0;
    strcpy(this->nombre, "/0");
    strcpy(this->apellido, "/0");
    strcpy(this->cargo, "/0");
    strcpy(this->dni, "/0");
    strcpy(this->telefono, "/0");
    strcpy(this->correo, "/0");
    strcpy(this->f_nac, "/0");
    strcpy(this->curso, "/0");
    this->legajo = 0;
}
 
 
 
void Alumno::ActualizarAlumno(int c, char n[20], char a[20], char ca[20],char dn[20],char te[20], char co[20], char fn[20], char cu[20], int le){
    
    this->codigo = c;
    strcpy(this->nombre, n);
    strcpy(this->apellido, a);
    strcpy(this->cargo, ca);
    strcpy(this->dni, dn);
    strcpy(this->telefono, te);
    strcpy(this->correo, co);
    strcpy(this->f_nac, fn);
    strcpy(this->curso, cu);    
    this->legajo = le;  
        
}
 
void Alumno::MostrarAlumno(){
    
        cout << "-------------------------" << endl;
    cout << "Codigo:" << this->codigo << endl;
    cout << "Nombre:" << this->nombre << endl;
    cout << "Apellido:" << this->apellido << endl;
    cout << "Cargo:" << this->cargo << endl;
    cout << "Dni:" << this->dni << endl;
    cout << "Telefono:" << this->telefono << endl;
    cout << "Correo:" << this->correo << endl;
    cout << "Fecha nacimiento:" << this->f_nac << endl;
    cout << "Curso:" << this->curso << endl;
    cout << "Legajo:" << this->legajo << endl;
 
    cout << "-------------------------" << endl;
    cout << "" << endl;
 
 
}
