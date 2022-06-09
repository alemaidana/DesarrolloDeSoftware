#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*
8.- Realice un programa que calcule la nómina salarial neto, de unos obreros cuyo trabajo se paga en horas. 
	El cálculo se realiza de la siguiente forma:
- Las primeras 35 horas a una tarifa fija.
- Las horas extras se pagan a 1.5 más de la tarifa fija.
- Los impuestos a deducir de los trabajadores varian, segun el sueldo mensual 
  si el sueldo es menos a $20,000.00 el sueldo es libre de impuesto y si es al contrario se cobrará un 20% de impuesto.
*/


int main( ){

	//declaramos las constantes
	int VALOR_HORA = 400;

	//declaramos las variables 
	float sueldo, horas, sueldo_extra, impuesto, sueldo_impuesto;
	
	//pedimos al usuario que ingrese las horas	
	cout << "Ingrese la cantidad de horas: ";
	cin >> horas;
	
	//preguntamos si son menos a 35
	if (horas <= 35){
		
		sueldo = horas * VALOR_HORA;
		
	}else{
		
		sueldo_extra = (VALOR_HORA * 1.5) * (horas - 35);
		
		sueldo = ( 35 * VALOR_HORA) + sueldo_extra;
		
	}

	//corroboramos que el sueldo sea menor a 20 mil para estar libre de impuestos
	if(sueldo < 20000){
		
		cout << "Su sueldo es menor a $20.000, usted esta libre de impuesto, su sueldo es: " << sueldo;
		
	}else{
		
		//como no es menor se procede a cobrar impuesto del 20%
		
		impuesto = sueldo * 0.20;
		
		sueldo_impuesto = sueldo - impuesto;
		
		cout << "Su sueldo es mayor a $20.000 no se encuentra libre del impuesto del 20%, por lo tanto es: " << sueldo_impuesto;
		
	}
	
}

