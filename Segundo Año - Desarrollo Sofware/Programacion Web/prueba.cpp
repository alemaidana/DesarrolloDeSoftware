#include <iostream>
#include "funciones.h"


using namespace std;

int main(){
	
	Funciones f;	
	
	float x1 = 0;
	float x2 = 0;
	float tt1 = 0;
	float tt2 = 0;
	char operacion1;
	char operacion2;	

	

	cout << "Prueba con ambos negativos" << endl;
	cout << "------------------------" << endl;
	x1= 1;
	x2= 3;
	tt1 = 4;
	tt2= 8;
	f.calcularYa(x1, x2, tt1, tt2, '-', '-');
	
	cout << "               " << endl;
	cout << "               " << endl;
	cout << "               " << endl;

	
	cout << "Prueba con ambos positivos" << endl;
	cout << "------------------------" << endl;
	x1= 10;
	x2= 2;
	tt1 = 3;
	tt2= 12;
	f.calcularYa(x1, x2, tt1, tt2, '+','+');

	cout << "               " << endl;
	cout << "               " << endl;
	cout << "               " << endl;

	
	cout << "Prueba con x2 negativo" << endl;
	cout << "------------------------" << endl;
	x1= 1;
	x2= 2;
	tt1 = 3;
	tt2= 12;
	f.calcularYa(x1, x2, tt1, tt2, '+', '-');

	
	cout << "               " << endl;
	cout << "               " << endl;
	cout << "               " << endl;


	cout << "Prueba con tt1 negativo" << endl;
	cout << "------------------------" << endl;
	x1= 1;
	x2= 3;
	tt1 = 4;
	tt2= 8;
	f.calcularYa(x1, x2, tt1, tt2, '-', '+');
	

	
}
