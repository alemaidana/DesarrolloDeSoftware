#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*
7.- Escribir un programa que pida la edad y el sexo y dependiendo si es hombre o mujer y si puede votar o no.
*/


int main( ){

	//declaramos las variables
	int edad;
	int sexo;

	//pedimos al usuario que ingrese su peso
	cout << "Ingrese su sexo: \n1- Varon\n2- Mujer\n";
	cin >> sexo;

	//pedimos al usuario que ingrese su edad	
	cout << "Ingrese su edad: ";
	cin >> edad;

	//preguntamos si es hombre o mujer y si entra en el rango de edad para votar
	if( (sexo == 1 || sexo == 2) && edad >=16){
	
		//condicion valida imprimimos por pantalla que puede votar
		cout << "Usted puede votar";
		
	}else{
		
		//condicion no valida imprimimos por pantalla que no puede votar		
		cout << "Usted no puede votar";
		
	}
	

}

