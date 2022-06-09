#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

/*
5.- Escribir  un programa que lea de entrada 3 números y que indique cual es el mayor de ellos.
*/


int main( ){

	//declaramos la variables de los 3 numeros a ser ingresados
	float numero1;
	float numero2;
	float numero3;
	
	//pedimos al usuario que ingrese el primer numero
	cout << "Ingrese el valor del primer numero: ";
	cin >> numero1;

	//pedimos al usuario que ingrese el segundo numero
	cout << "Ingrese el valor del segundo numero: ";
	cin >> numero2;

	//pedimos al usuario que ingrese el tercer numero
	cout << "Ingrese el valor del tercer numero: ";
	cin >> numero3;


	//preguntamos cual es el mayor y a partir de ahi realizamos la operacion
	if((numero1 > numero2) && (numero1 > numero3)){
		
		//mostramos por pantalla que el numero 1 es el mayor	
		cout << "El mayor es: " << numero1;
		
	}else if((numero2 > numero1) && (numero2 > numero3)){
		
		//mostramos por pantalla que el numero 2 es el mayor	
		cout << "El mayor es: " << numero2;
		
	}else if((numero3 > numero1) && (numero3 > numero2)){
		
		//mostramos por pantalla que el numero 3 es el mayor	
		cout << "El mayor es: " << numero3;
		
	}else{
		
		//los numeros ingresados son iguales
		cout << "Los numeros son iguales";
		
	}
	
}

