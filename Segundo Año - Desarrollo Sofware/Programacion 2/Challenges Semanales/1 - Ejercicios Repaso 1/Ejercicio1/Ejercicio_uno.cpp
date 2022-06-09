#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*
1.- Escribir un programa que permita leer la edad y peso de una persona y posteriormente imprimirla.
*/


int main( ){

	//declaramos las variables
	int edad;
	float peso;

	//pedimos al usuario que ingrese su peso
	cout << "Ingrese su peso: ";
	cin >> peso;

	//pedimos al usuario que ingrese su edad	
	cout << "Ingrese su edad: ";
	cin >> edad;

	//imprimimos por pantalla la edad y el peso
	cout << "Su peso es " << peso << " kg, y su edad es " << edad  << " años.";
	
}

