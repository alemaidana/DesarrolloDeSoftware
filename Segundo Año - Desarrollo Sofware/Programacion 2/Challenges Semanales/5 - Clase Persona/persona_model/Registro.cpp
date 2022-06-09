#include "Registro.h"

void Registro::Guardar(Persona persona){
	
	this->archivo.open("Personas.bin", ios::out | ios::app | ios::binary);
	
	if(this->archivo.fail()){
		
		cout << "ERRor";
		
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
		
		cout << "ERRor";
		
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


void Registro::Modificar(int id){
	
	bool encontrado = false;
	Persona aux;
	ifstream lectura;
	ofstream escritura;
	lectura.open("Personas.bin", ios::in | ios::binary);
	escritura.open("temp.bin", ios::app | ios::binary);	
	
	if(escritura.fail() || escritura.fail()){
		
		cout << "Erorr";
		
	}else{
		
		
		while(lectura.read((char*)&aux, sizeof(aux))){
			
			if(aux.obtenerCedula() == id){
				
				encontrado = true;
				int e, c;
				string n;
				cout << "Nombre";
				cin >> n;
				cout << "Cedula";
				cin >> c;
				cout << "Edad";
				cin >> e;
				aux.ActualizarDatos(c, _strdup(n.c_str()),e);
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
		
		cout << "Erorr";
		
	}else{
		
		
		while(lectura.read((char*)&aux, sizeof(aux))){
			
			if(aux.obtenerCedula() != id){
				

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
