#pragma once
#include "personita.h"
#include "alumno.h"
#include "particular.h"
#include "profesor.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>
 
using namespace std;
 
class Registro{
    
    private:
        fstream archivo;
    public:
        void Guardar(Profesor);
        void Guardar(Alumno);
        void Guardar(Particular);
        void MostrarProfesor();
        void MostrarAlumno();
        void MostrarParticular();
        void MostrarListado();
        void ModificarProfesor(int);
        void ModificarAlumno(int);
        void ModificarParticular(int);
        void EliminarProfesor(int);
        void EliminarAlumno(int);
        void EliminarParticular(int);
};
 
void Registro::Guardar(Profesor profesor){
    
    this->archivo.open("Personas.bin", ios::out | ios::app | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al guardar. Intentelo nuevamente.";
        
    }else{
        
        this->archivo.write((char*)&profesor, sizeof(Profesor));
        this->archivo.close();
        cout << "Guardado Correctamente" << endl;
        
    }   
    
    
}
 
 
void Registro::Guardar(Alumno alumno){
    
    this->archivo.open("Personas.bin", ios::out | ios::app | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al guardar. Intentelo nuevamente.";
        
    }else{
        
        this->archivo.write((char*)&alumno, sizeof(Alumno));
        this->archivo.close();
        cout << "Guardado Correctamente" << endl;
        
    }   
    
    
}
 
 
void Registro::Guardar(Particular particular){
    
    this->archivo.open("Personas.bin", ios::out | ios::app | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al guardar. Intentelo nuevamente.";
        
    }else{
        
        this->archivo.write((char*)&particular, sizeof(Particular));
        this->archivo.close();
        cout << "Guardado Correctamente" << endl;
        
    }   
    
    
}
 
 
void Registro::MostrarProfesor(){
    
    Profesor mostrar_profesor = Profesor();
    this->archivo.open("Personas.bin", ios::in | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al mostrar. Intentelo nuevamente.";
        
    }else{
    
            while(!this->archivo.eof()){
                
                this->archivo.read((char*)&mostrar_profesor, sizeof(Profesor));
                
                if(!this->archivo.eof()){
                    
                    mostrar_profesor.MostrarProfesor();
                    
                }
                
                
            }
    
            
            this->archivo.close();
    
    }
}
 
 
void Registro::MostrarAlumno(){
    
    Alumno mostrar_alumnos = Alumno();
    this->archivo.open("Personas.bin", ios::in | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al mostrar. Intentelo nuevamente.";
        
    }else{
    
            while(!this->archivo.eof()){
                
                this->archivo.read((char*)&mostrar_alumnos, sizeof(Alumno));
                
                if(!this->archivo.eof()){
                    
                    mostrar_alumnos.MostrarAlumno();
                    
                }
                
                
            }
    
            
            this->archivo.close();
    
    }
}
 
void Registro::MostrarParticular(){
    
    Particular mostrar_particular = Particular();
    this->archivo.open("Personas.bin", ios::in | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al mostrar. Intentelo nuevamente.";
        
    }else{
    
            while(!this->archivo.eof()){
                
                this->archivo.read((char*)&mostrar_particular, sizeof(Particular));
                
                if(!this->archivo.eof()){
                    
                    mostrar_particular.MostrarParticular();
                    
                }
                
                
            }
    
            
            this->archivo.close();
    
    }
}
 

void Registro::MostrarListado(){
    
    Particular mostrar_particular = Particular();
    this->archivo.open("Personas.bin", ios::in | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al mostrar. Intentelo nuevamente.";
        
    }else{
    
            while(!this->archivo.eof()){
                
                this->archivo.read((char*)&mostrar_particular, sizeof(Particular));
                
                if(!this->archivo.eof()){
                    
                    mostrar_particular.MostrarParticular();
                    
                }
                
                
            }
    
            
            this->archivo.close();
    
    }
}
 
 
void Registro::ModificarProfesor(int id){
    
    bool encontrado = false;
    Profesor aux;
    ifstream lectura;
    ofstream escritura;
    lectura.open("Personas.bin", ios::in | ios::binary);
    escritura.open("temp.bin", ios::app | ios::binary); 
    
    if(escritura.fail() || escritura.fail()){
        
        cout << "Error al modificar. Intentelo nuevamente.";
        
    }else{
        
        
        while(lectura.read((char*)&aux, sizeof(aux))){
            
            if(aux.obtenerCodigo() == id){
                
                encontrado = true;
                
                int c, le;
                Fecha fecha;
                Correo correo;
                Celular celular;
                Dni dni;
                string n,a,ca,dn,te,co,fn,ar;
                cout << "Ingrese Codigo:";
                cin >> c;
                cout << "Ingrese Nombre:";
                cin >> n;
                cout << "Ingrese Apellido:";
                cin >> a;
                cout << "Ingrese Cargo:";
                cin >> ca;
                dni.solicitarDocumento();
                dn = dni.dameDocumento();
                celular.solicitarCelular();
                te = celular.dameCelular();
                correo.solicitarCorreo();
                co = correo.dameCorreo();
                fecha.Menu();
                fn = fecha.dameFecha(); 
                cout << "Ingrese Area:";
                cin >> ar;
                cout << "Ingrese Numero de Legajo:";
                cin >> le;
                
            aux.ActualizarProfesor(c, _strdup(n.c_str()),_strdup(a.c_str()),_strdup(ca.c_str()) , _strdup(dn.c_str()), _strdup(te.c_str()), _strdup(co.c_str()), _strdup(fn.c_str()), _strdup(ar.c_str()),le);
            
                
             escritura.write((char*)&aux, sizeof(aux));
                
                
            }else{
                
                escritura.write((char*)&aux, sizeof(aux));
                
            }
            
        }
        
        lectura.close();
        escritura.close();      
        
        remove("Personas.bin");
        
        if(rename("temp.bin", "Personas.bin")){
            cout << "Error";
        }
        
        if(!encontrado){
            
            cout << "No existe ese codigo";
            
        }else{
            
            cout << "Modificado correctamente";
            
        }
        
    }
    
}

void Registro::ModificarAlumno(int id){
    
    bool encontrado = false;
    Alumno aux;
    ifstream lectura;
    ofstream escritura;
    lectura.open("Personas.bin", ios::in | ios::binary);
    escritura.open("temp.bin", ios::app | ios::binary); 
    
    if(escritura.fail() || escritura.fail()){
        
        cout << "Error al modificar. Intentelo nuevamente.";
        
    }else{
        
        
        while(lectura.read((char*)&aux, sizeof(aux))){
            
            if(aux.obtenerCodigo() == id){
                
                encontrado = true;
                
                int c, le;
                Fecha fecha;
                Correo correo;
                Celular celular;
                Dni dni;
                string n,a,ca,dn,te,co,fn,cu;
                cout << "Ingrese Codigo:";
                cin >> c;
                cout << "Ingrese Nombre:";
                cin >> n;
                cout << "Ingrese Apellido:";
                cin >> a;
                cout << "Ingrese Cargo:";
                cin >> ca;
                dni.solicitarDocumento();
                dn = dni.dameDocumento();
                celular.solicitarCelular();
                te = celular.dameCelular();
                correo.solicitarCorreo();
                co = correo.dameCorreo();
                fecha.Menu();
                fn = fecha.dameFecha(); 
                cout << "Ingrese Curso:";
                cin >> cu;
                cout << "Ingrese Numero de Legajo:";
                cin >> le;
                
            aux.ActualizarAlumno(c, _strdup(n.c_str()),_strdup(a.c_str()),_strdup(ca.c_str()) , _strdup(dn.c_str()), _strdup(te.c_str()), _strdup(co.c_str()), _strdup(fn.c_str()), _strdup(cu.c_str()),le);
                
             escritura.write((char*)&aux, sizeof(aux));
                
                
            }else{
                
                escritura.write((char*)&aux, sizeof(aux));
                
            }
            
        }
        
        lectura.close();
        escritura.close();      
        
        remove("Personas.bin");
        
        if(rename("temp.bin", "Personas.bin")){
            cout << "Error";
        }
        
        if(!encontrado){
            
            cout << "No existe ese codigo";
            
        }else{
            
            cout << "Modificado correctamente";
            
        }
        
    }
    
}


void Registro::ModificarParticular(int id){
    
    bool encontrado = false;
    Particular aux;
    ifstream lectura;
    ofstream escritura;
    lectura.open("Personas.bin", ios::in | ios::binary);
    escritura.open("temp.bin", ios::app | ios::binary); 
    
    if(escritura.fail() || escritura.fail()){
        
        cout << "Error al modificar. Intentelo nuevamente.";
        
    }else{
        
        
        while(lectura.read((char*)&aux, sizeof(aux))){
            
            if(aux.obtenerCodigo() == id){
                
                encontrado = true;
            	
				int c, le;
                Fecha fecha;
                Correo correo;
                Celular celular;
                Dni dni;
                string n,a,ca,dn,te,co,fn,se;
                cout << "Ingrese Codigo:";
                cin >> c;
                cout << "Ingrese Nombre:";
                cin >> n;
                cout << "Ingrese Apellido:";
                cin >> a;
                cout << "Ingrese Cargo:";
                cin >> ca;
                dni.solicitarDocumento();
                dn = dni.dameDocumento();
                celular.solicitarCelular();
                te = celular.dameCelular();
                correo.solicitarCorreo();
                co = correo.dameCorreo();
                fecha.Menu();
                fn = fecha.dameFecha(); 
                cout << "Ingrese Sector:";
                cin >> se;
                cout << "Ingrese Numero de Legajo:";
                cin >> le;
                
            aux.ActualizarParticular(c, _strdup(n.c_str()),_strdup(a.c_str()),_strdup(ca.c_str()) , _strdup(dn.c_str()), _strdup(te.c_str()), _strdup(co.c_str()), _strdup(fn.c_str()), _strdup(se.c_str()),le);
            
             escritura.write((char*)&aux, sizeof(aux));
                
                
            }else{
                
                escritura.write((char*)&aux, sizeof(aux));
                
            }
            
        }
        
        lectura.close();
        escritura.close();      
        
        remove("Personas.bin");
        
        if(rename("temp.bin", "Personas.bin")){
            cout << "Error";
        }
        
        if(!encontrado){
            
            cout << "No existe ese codigo";
            
        }else{
            
            cout << "Modificado correctamente";
            
        }
        
    }
    
}
 
void Registro::EliminarProfesor(int id){
    
    bool encontrado = false;
    Profesor aux;
    ifstream lectura;
    ofstream escritura;
    lectura.open("Personas.bin", ios::in | ios::binary);
    escritura.open("temp.bin", ios::app | ios::binary); 
    
    if(escritura.fail() || escritura.fail()){
        
        cout << "Error al eliminar. Intentelo nuevamente.";
        
    }else{
        
        
        while(lectura.read((char*)&aux, sizeof(aux))){
            
            if(aux.obtenerCodigo() != id){
                
 
                escritura.write((char*)&aux, sizeof(aux));
                
                
            }else{
                
                encontrado = true;
                
            }
            
        }
        
        lectura.close();
        escritura.close();      
        
        remove("Personas.bin");
        
        if(rename("temp.bin", "Personas.bin")){
            cout << "Error";
        }
        
        if(!encontrado){
            
            cout << "No existe ese codigo";
            
        }else{
            
            cout << "Modificado correctamente";
            
        }
        
    }
    
    
    
}


void Registro::EliminarAlumno(int id){
    
    bool encontrado = false;
    Alumno aux;
    ifstream lectura;
    ofstream escritura;
    lectura.open("Personas.bin", ios::in | ios::binary);
    escritura.open("temp.bin", ios::app | ios::binary); 
    
    if(escritura.fail() || escritura.fail()){
        
        cout << "Error al eliminar. Intentelo nuevamente.";
        
    }else{
        
        
        while(lectura.read((char*)&aux, sizeof(aux))){
            
            if(aux.obtenerCodigo() != id){
                
 
                escritura.write((char*)&aux, sizeof(aux));
                
                
            }else{
                
                encontrado = true;
                
            }
            
        }
        
        lectura.close();
        escritura.close();      
        
        remove("Personas.bin");
        
        if(rename("temp.bin", "Personas.bin")){
            cout << "Error";
        }
        
        if(!encontrado){
            
            cout << "No existe ese codigo";
            
        }else{
            
            cout << "Modificado correctamente";
            
        }
        
    }
    
    
    
}


void Registro::EliminarParticular(int id){
    
    bool encontrado = false;
    Particular aux;
    ifstream lectura;
    ofstream escritura;
    lectura.open("Personas.bin", ios::in | ios::binary);
    escritura.open("temp.bin", ios::app | ios::binary); 
    
    if(escritura.fail() || escritura.fail()){
        
        cout << "Error al eliminar. Intentelo nuevamente.";
        
    }else{
        
        
        while(lectura.read((char*)&aux, sizeof(aux))){
            
            if(aux.obtenerCodigo() != id){
                
 
                escritura.write((char*)&aux, sizeof(aux));
                
                
            }else{
                
                encontrado = true;
                
            }
            
        }
        
        lectura.close();
        escritura.close();      
        
        remove("Personas.bin");
        
        if(rename("temp.bin", "Personas.bin")){
            cout << "Error";
        }
        
        if(!encontrado){
            
            cout << "No existe ese codigo";
            
        }else{
            
            cout << "Modificado correctamente";
            
        }
        
    }
    
    
    
}
