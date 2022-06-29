#include "clase_persona.h"
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Registro{
	
	private:
		fstream archivo;
	public:
		void Guardar(Persona);
		void Mostrar();
};

void Registro::Guardar(Persona persona){
	
	this->archivo.open("Personas.bin", ios::out | ios::app | ios::binary);
	
	if(this->archivo.fail()){
		
		cout << "Error en el guardado";
		
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
		
		cout << "Error al mostrar la persona";
		
	}else{
	
			while(!this->archivo.eof()){
				
				this->archivo.read((char)&mostrar, sizeof(Persona));
				
				if(!this->archivo.eof()){
					
					mostrar.Imprimir();
					
				}
				
				
			}
	
			
			this->archivo.close();
	
	}
}

	
	
}
