#include "clase_persona.h"
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Registro{
	
	private:
		//fstream archivo;
		fstream fichero;
	public:
		void Guardar(Persona);
		void Mostrar();
		void Modificar(int id);
};

void Registro::Guardar(Persona persona){

 ofstream fichero ("people.txt", ios::app);
  if (fichero.is_open())
  {
	fichero << persona.getCodigo() << " " << persona.getNombre() << " " <<  persona.getApellido() << " " << persona.getGenero() << " " << persona.getCelular() << " " << persona.getCorreo() << " " << persona.getFn() << endl; 

	
    fichero.close(); 	
	
  }
  
  else cout << "Unable to open file";
	
}

	
void Registro::Mostrar(){
	
  string line;
  ifstream fichero ("people.txt");
  if (fichero.is_open())
  {
    while ( getline (fichero,line) )
    {
      cout << line << '\n';
    }
    fichero.close();
  }

  else cout << "Unable to open file"; 

      

}

	
void Registro::Modificar(int id){
	
	bool encontrado = false;
	Persona aux;
	ifstream lectura;
	ofstream escritura;
	lectura.open("people.txt", ios::in);
	escritura.open("temp.txt", ios::app);	
	
	if(escritura.fail() || escritura.fail()){
		
		cout << "Eror. Intentelo mas tarde";
		
	}else{
		
		
		while(lectura.read((char*)&aux, sizeof(aux))){
			
			if(aux.getCodigo() == id){
				
				encontrado = true;
				int c;
			string n, a, g, d, ce, co, fn;
			cout << "Codigo:";
			cin >> c;
			cout << "Nombre:";
			cin >> n;
			cout << "Apellido:";
			cin >> a;
			cout << "Genero:";
			cin >> g;
			cout << "Dni:";
			cin >> d;
			cout << "Celular:";
			cin >> ce;
			cout << "Correo:";
			cin >> co;
			cout << "Fecha Nacimiento:";
			cin >> fn;
			Persona nueva = Persona();
			aux.actualizarPersona(c,n,a,g,d,ce,co,fn);
			escritura.write((char*)&aux, sizeof(aux));
				
				
			}else{
				
				escritura.write((char*)&aux, sizeof(aux));
				
			}
			
		}
		
		lectura.close();
		escritura.close();		
		
		remove("people.txt");
		
		if(rename("temp.txt", "people.txt")){
			cout << "Error";
		}
		
		if(!encontrado){
			
			cout << "No existe ese codigo";
			
		}else{
			
			cout << "Modificado correctamente";
			
		}
		
	}
	
}	

