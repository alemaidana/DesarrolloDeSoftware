#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Persona{

	string nombre, apellido, fechaNac, genero, celular, correo;

	public:
		void cargarDatos();
		void validarNombreApelllidoYGenero();
		bool validarCelular();
		bool validarCorreo();
		
};

int main( ){

	Persona persona;
	
	persona.cargarDatos();

}

void Persona::validarNombreApelllidoYGenero(){
	
	cout << "\nIngresar el nombre de la persona: ";
	cin >> nombre;
	
	cout << "\nIngresar el apellido de la persona: ";
	cin >> apellido;
	
	cout << "\nIngresar el genero de la persona: ";
	cin >> genero;
		
	
}


bool Persona::validarCelular(){
	
	if(celular.length() == 10){

		cout << "Valido";
		
	 	return true; 
			
	}
	
		return false;
	
}

bool Persona::validarCorreo(){
	
	int arroba = correo.find("@");
	
	int punto = correo.find(".");
	
	if(arroba > 0 && punto > 0){
		
		cout << "Valido";
		
		return true;
		
	}else{
		
		return false;
	}	
	
}

void Persona::cargarDatos(){
	
	cout << "Ingrese los datos de la persona: \n\n";
	
	validarNombreApelllidoYGenero();
	
	cout << "\nIngrese su numero de celular\n<con 15 seguido de 8 digitos, ejemplo: 1533445566>: ";
	cin >> celular;
	validarCelular();
	
	cout << "\nIngrese su correo electronico: \n";
	cin >> correo;
	validarCorreo();
}

