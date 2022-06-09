#ifndef CLASE_PERSONA_H
#define CLASE_PERSONA_H
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "fecha2.h"

using namespace std;

class Persona{
	private:
		//ingresamos las variables de los datos de la persona
		string nombre, apellido, genero, dni, celular, correo, fn;
		
	public:		
		//setters
		void setNombre();
		void setApellido();
		void setGenero();
		void setDni();
		void setCelular();
		void setCorreo();
		
		//getters
		string getNombre();
		string getApellido();
		string getGenero();
		string getDni();
		string getCelular();
		string getCorreo();
		string getFn();

		//Metodos
		//creamos el metodo validar que nos va a verficar si la fecha de nacimiento es correcta		
		void validarFechaNacimiento();
		//creamos el metodo validar que nos va a verficar si el numero de dni es correcto
		bool validarDni();
		//creamos el metodo validar que nos va a verficar si el numero de celular es correcto
		bool validarCelular();
		//creamos el metodo validar que nos va a verficar si el correo es correcto
		bool validarCorreo();

};




void Persona::setNombre(){
	
	cout << "Ingrese nombre:";
	
	cin >> nombre; 
	
	this->nombre = nombre;
	
}

void Persona::setApellido(){
	
	cout << "Ingrese apellido:";
	
	cin >> apellido; 
	
	this->apellido = apellido;
	
}

void Persona::setGenero(){
	
	cout << "Ingrese genero:";
	
	cin >> genero; 
	
	this->genero = genero;
	
	
}

void Persona::setDni(){
	
	cout << "Ingrese Dni:";
	
	cin >> dni; 
	
	this->dni = dni;
	
}

void Persona::setCelular(){
	
	cout << "Ingrese Celular:";
	
	cin >> celular; 
	
	this->celular = celular;
	
}

void Persona::setCorreo(){
	
	cout << "Ingrese Correo:";
	
	cin >> correo; 
	
	this->correo = correo;
	
	
}


string Persona::getNombre(){
	
	return this->nombre;
}


string Persona::getApellido(){
	
	return this->apellido;
}


string Persona::getGenero(){
	
	return this->genero;
}


string Persona::getDni(){
	
	return this->dni;
}


string Persona::getCelular(){
	
	return this->celular;
}


string Persona::getCorreo(){
	
	return this->correo;
}



void Persona::validarFechaNacimiento(){
	
	//importamos de la clase fecha sus metodos para validar los datos
	//ya la misma clase hara todo el trabajo por nosotros
	
	Fecha fecha;
	
	fecha.setDia();
	fecha.setMes();
	fecha.setAnio();
	
	fecha.validarDia();
	fecha.validarMes();
	fecha.validarAnio();
	
	//fecha.mostrarFecha();
	fn = fecha.dameFecha();

}

string Persona::getFn(){
	
	return fn;
}


bool Persona::validarDni(){
	
	//preguntamos el largo del dni si concuerda con los estandares de nuestro pais
	if(dni.length() > 7 && dni.length() < 10){

			//correcto, el dni cuenta con los caracteres solicitados			
			cout << "\nDni valido\n";
			
			return true;

	}else{
			
			//si no cumple los requerimientos no es valido el dni
			cout << "\nDni no valido\n";
			
			return false;
	}
	
	
}


bool Persona::validarCelular(){
	
	//preguntamos si el telefono tiene 10 caracteres
	if(celular.length() == 10){

			//correcto, el celular cuenta con 10 caracteres
			cout << "\nCelular con 10 numeros, numero de celular valido\n";		
			
			return true;
	}else{
	
			//si no cumple los requerimientos no es valido el telefono
			cout << "\nTelefono no valido\n";
			
			return false;

	}

}

//En esta version simple validar correo solo nos dira q
bool Persona::validarCorreo(){
	
	//caracteres a encontrar
	char arroba = '@';
	char punto = '.';
	
	//banderas por si encontramos 
	bool busqueda_arroba = false;
	bool busqueda_punto = false;


	//buscamos cuantas arrobas y puntos hay en el correo electronico introducido	
	for(int i = 0 ; i < correo.length(); i++){
		
		//buscamos el arroba
		if(correo[i] == arroba){
				
		//encontre un '@'		
			busqueda_arroba = true;	
			
		}
		
		//buscamos los puntos
		if(correo[i] == punto){
	
		//encontre un '.'		
		busqueda_punto = true;	
			
		}
		
	}
	
	if ( busqueda_arroba && busqueda_punto ){
		
		//si esto es correcto es valida la direccion
		cout << "\nDireccion de correo valida\n";
		
		//aqui vemos en que posicion de la direccion esta
		cout << "\narroba en la posicion: " << correo.find("@");
		cout << "\npuntos en la posicion: " << correo.find(".");
		
		return true;
		
	}else{
		
		//si no cumple los requerimientos no es valida la direccion
		cout << "\nDireccion de correo no valida\n";
		
		return false;
	}
	
}



#endif
