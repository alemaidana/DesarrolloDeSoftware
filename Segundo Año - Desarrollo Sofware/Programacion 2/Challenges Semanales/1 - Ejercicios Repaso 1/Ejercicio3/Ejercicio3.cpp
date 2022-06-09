#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;

/*
3.- Escribir  un programa que calcule el área de un círculo.
*/


int main( ){

	//declaramos la variables de base, altura y area
	float radio;
	float PI = 3.1416;
	
	//pedimos al usuario que ingrese el radio
	cout << "Ingrese el valor del radio: ";
	cin >> radio;

	//realizamos la operacion
	int area = PI * pow(radio, 2); 

	//imprimimos por pantalla el area del circulo
	cout << "El area del circulo es: " << area;
	
}

