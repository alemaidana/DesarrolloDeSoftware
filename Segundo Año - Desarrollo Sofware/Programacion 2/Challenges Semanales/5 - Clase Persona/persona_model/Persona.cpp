//Crud.cpp : programa que contiene el main, todo empieza y termina aca
#include "Persona.h"
#include <iostream>
#include <cstring>
#include <string>
//clase Persona 

using namespace std;

//inicializamos el constructor de Persona
Persona::Persona(){
	
	this->cedula = 0;
	this->edad = 0;
	strcpy(this->nombre, "/0");
	
}

void Persona::ActualizarDatos(int c, char n[20], int e){
	
	this->cedula = c;
	this->edad = e;
	strcpy(this->nombre, n);
}

void Persona::Imprimir(){
	
	cout << "Nombre:" << this->nombre << endl;
	cout << "Cedula:" << this->cedula << endl;
	cout << "Edad:" << this->edad << endl;	
}

int Persona::obtenerCedula(){
	
	return this->cedula;
	
}
