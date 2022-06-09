#include "clase_persona.h"
#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>




using namespace std;

class Registro{
	
	public:
	//creamos el metodo cargar datos
	string cargarDatos();
};


int main(){
	
	Registro registro;
	
	cout << registro.cargarDatos();
	
}


string Registro::cargarDatos(){
	
		Persona nueva;
		
		nueva.setNombre();
		
		nueva.setApellido();
		
		nueva.validarFechaNacimiento();
		
		return nueva.getNombre() + " " + nueva.getApellido() + " " + nueva.getFn();
}

