#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

/*
4.- Escribir  un programa que dados 2 valores de entrada imprima siempre la división del mayor entre el menor.
*/


int main( ){

	//declaramos la variables de los numeros a ser ingresados y la division
	float numero1;
	float numero2;
	float division;
	
	//pedimos al usuario que ingrese el primer numero
	cout << "Ingrese el valor del primer numero: ";
	cin >> numero1;

	//pedimos al usuario que ingrese el segundo numero
	cout << "Ingrese el valor del segundo numero: ";
	cin >> numero2;

	//preguntamos cual es el mayor y a partir de ahi realizamos la operacion
	
	if(numero1 > numero2){
		
		//numero1 es mayor a numero 2 por lo que se procede a realizar la operacion
		division = numero1 / numero2;
		
		//mostramos por pantalla el resultado	
		cout << "La division del mayor por el menor es: " << division;
		
	}else if(numero2 > numero1){
		
		//numero2 es mayor a numero 1 por lo que se procede a realizar la operacion
		division = numero2 / numero1;
		
		//mostramos por pantalla el resultado	
		cout << "La division del mayor por el menor es: " << division;
		
	}else{
		
		//los numeros ingresados son iguales
		cout << "Los numeros son iguales";
		
	}
	
}

