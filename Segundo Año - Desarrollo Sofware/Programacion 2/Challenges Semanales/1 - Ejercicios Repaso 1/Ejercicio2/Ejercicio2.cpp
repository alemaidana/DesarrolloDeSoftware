#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*
2.- Escribir  un programa que calcule el área de un triángulo recibiendo como entrada el valor de base y altura.
*/


int main( ){

	//declaramos las variables de base, altura y area
	float base;
	float altura;
	float area;

	//pedimos al usuario que ingrese la base
	cout << "Ingrese el valor de la base: ";
	cin >> base;

	//pedimos al usuario que ingrese la altura	
	cout << "Ingrese el valor de la altura: ";
	cin >> altura;

	//realizamos la operacion
	area = (base * altura) / 2;

	//imprimimos por pantalla el area del triangulo
	cout << "El area del triangulo es: " << area;
	
}

