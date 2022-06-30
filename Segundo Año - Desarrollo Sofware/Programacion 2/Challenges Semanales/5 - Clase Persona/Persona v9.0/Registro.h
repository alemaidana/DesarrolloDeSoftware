#pragma once
#include "personita.h"
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
        void Guardar(Persona);
        void Mostrar();
        void Modificar(int);
        void Eliminar(int);
        
};
 
void Registro::Guardar(Persona persona){
    
    this->archivo.open("Personas.bin", ios::out | ios::app | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al guardar. Intentelo nuevamente.";
        
    }else{
        
        this->archivo.write((char*)&persona, sizeof(Persona));
        this->archivo.close();
        cout << "Guardado Correctamente" << endl;
        
    }   
    
    
}
 
void Registro::Mostrar(){
    
    Persona mostrar = Persona();
    this->archivo.open("Personas.bin", ios::in | ios::binary);
    
    if(this->archivo.fail()){
        
        cout << "Error al mostrar. Intentelo nuevamente.";
        
    }else{
    
            while(!this->archivo.eof()){
                
                this->archivo.read((char*)&mostrar, sizeof(Persona));
                
                if(!this->archivo.eof()){
                    
                    mostrar.Imprimir();
                    
                }
                
                
            }
    
            
            this->archivo.close();
    
    }
}
 
 
void Registro::Modificar(int id){
    
    bool encontrado = false;
    Persona aux;
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
                Fecha fecha;
                Correo correo;
                Celular celular;
                Dni dni;
				int c;
	            string n,a,ca,dn,te,co,fn;
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
	 
                aux.ActualizarDatos(c, _strdup(n.c_str()),_strdup(a.c_str()),_strdup(ca.c_str()), _strdup(dn.c_str()), _strdup(te.c_str()), _strdup(co.c_str()), _strdup(fn.c_str()));
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
 
void Registro::Eliminar(int id){
    
    bool encontrado = false;
    Persona aux;
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
