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
		int cod;
		string nombre, apellido, genero, dni, celular, correo, fn;
		
	public:
		Persona();		
		//setters
		void setCodigo(int codigo);
		void setNombre(string nombre);
		void setApellido(string apellido);
		void setGenero(string genero);
		void setDni(string dni);
		void setCelular(string celular);
		void setCorreo(string correo);
		void setFechaNacimiento(string fecha);
		
		//getters
		int getCodigo();
		string getNombre();
		string getApellido();
		string getGenero();
		string getDni();
		string getCelular();
		string getCorreo();
		string getFechaNacimiento();
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
		//actualizar los datos
		void actualizarPersona(int codigo, string nombre, string apellido, string genero, string dni, string celular, string correo, string fecha_nacimiento);
		//imprime los datos
		void Imprimir();
};

Persona::Persona(){
	
	this->cod = 0;
	this->nombre = "";
	this->apellido = "";
	this->genero = "";
	this->dni = "";
	this->celular = "";
	this->correo = "";
	this->fn = "";
	
}


void Persona::setCodigo(int codigo){
	
	this->cod = codigo;
}


void Persona::setNombre(string nombre){
	
	this->nombre = nombre;
	
}

void Persona::setApellido(string apellido){
	
	this->apellido = apellido;
	
}

void Persona::setGenero(string genero){
	
	this->genero = genero;
	
	
}

void Persona::setDni(string dni){
	
	this->dni = dni;
	
}

void Persona::setCelular(string celular){
		
	this->celular = celular;
	
}

void Persona::setCorreo(string correo){
	
	this->correo = correo;
		
}

void Persona::setFechaNacimiento(string fecha){
	
	this->fn = fecha;	
}


int Persona::getCodigo(){
	
	return this->cod;
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


void Persona::actualizarPersona(int codigo, string nombre, string apellido, string genero, string dni, string celular, string correo, string fecha_nacimiento){
	
	this->cod = codigo;
	this->nombre = nombre;
	this->apellido = apellido;
	this->genero = genero;
	this->dni = dni;
	this->celular = celular;
	this->correo = correo;
	this->fn = fecha_nacimiento;
	
}

void Persona::Imprimir(){
	
	cout << "Codigo:" << this->cod << endl;
	cout << "Nombre:" << this->nombre << endl;
	cout << "Apellido:" << this->apellido << endl;
	cout << "Genero:" << this->genero << endl;
	cout << "Dni:" << this->dni << endl;
	cout << "Celular:" << this->celular << endl;
	cout << "Correo:" << this->correo << endl;
	cout << "Fecha nacimiento:" << this->fn << endl;
	
}




#endif
