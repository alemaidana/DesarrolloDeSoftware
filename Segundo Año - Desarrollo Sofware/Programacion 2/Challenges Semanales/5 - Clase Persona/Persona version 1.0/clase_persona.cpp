#include <iostream>
#include <string.h>
#include <stdio.h>
#include "fecha2.h"

using namespace std;

/*
Clase Persona version 1.0: 
		-Se importo la clase Fecha que automaticamente valida la fecha por nostros
		-Los metodos realizan simples verificaciones tales como que los datos tengan cierto rango de caracteres
		-A medida que se van ingresando datos se van mostrando mensajes si los datos son validos o no
		 salvo por el metodo de la clase Fecha que ya esta pre cargado para no dejar avanzar con errores.
*/

class Persona{
		//ingresamos las variables de los datos de la persona
		string nombre, apellido, genero, dni, celular, correo;
		
	public:		
		//Metodos
		//creamos el metodo cargar datos
		void cargarDatos();
		//creamos el metodo validar que nos va a verficar si nombre, apellido y genero es correcto
		void validarNombreApellidoGenero();
		//creamos el metodo validar que nos va a verficar si la fecha de nacimiento es correcta		
		void validarFechaNacimiento();
		//creamos el metodo validar que nos va a verficar si el numero de dni es correcto
		bool validarDni();
		//creamos el metodo validar que nos va a verficar si el numero de celular es correcto
		bool validarCelular();
		//creamos el metodo validar que nos va a verficar si el correo es correcto
		bool validarCorreo();

};

int main(){
	
	//creamos un objeto persona
	Persona persona;
	//cargamos los datos de usuario
	persona.cargarDatos();
	
}


void Persona::validarNombreApellidoGenero(){
	
	//Pedimos al usuario el nombre de la persona
	cout << "\nIngresar Nombre de la persona: ";
	cin >> nombre;

	//Pedimos al usuario el apellido de la persona	
	cout << "\nIngresar Apellido de la persona: ";
	cin >> apellido;
	
	//Pedimos al usuario el genero de la persona
	cout << "\nIngresar Genero de la persona: ";
	cin >> genero;
	
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
	
	fecha.mostrarFecha();
	
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

void Persona::cargarDatos(){
	
		cout << "Ingrese los datos de la persona \n";
	
		//Validamos el nombre el apellido y el genero
		validarNombreApellidoGenero();
		
		//validamos la fecha de nacimiento
		validarFechaNacimiento();
		
		//pedimos al usuario que ingrese el dni
		cout << "\nIngrese su numero de documento: ";
		cin >> dni;	
		//validamos si los numeros son correctos
		validarDni();
		
		//pedimos al usuario que ingrese su telefono celular
		cout << "\nIngrese su numero de celular <con 15 seguido de 8 digitos: ejemplo 1522225555>: ";
		cin >> celular;
		//validamos el telefono celular
		validarCelular();
	
		//pedimos al usuario su correo
		cout << "\nIngrese su Correo: ";
		cin >> correo;
		//validamos el correo
		validarCorreo();
	
	
}
