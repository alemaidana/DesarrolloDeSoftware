//Crud.cpp : programa que contiene el main, todo empieza y termina aca

#include <iostream>
#include "Registro.h"

#define CL system("cls")
#define PA system("pause")

using namespace std;

//Clase persona: todos los datos

int main(){
	
	Registro registro;
	
	int opcion = 0;
	
	while (opcion != 5){
	
	CL;
	
	cout << "| REGISTRO EMPLEADOS ISFT 220 AMET |\n";
	
	cout << "1 - Insertar\n";
	cout << "2 - Mostrar\n";
	cout << "3 - Modificar\n";
	cout << "4 - Eliminar\n";
	cout << "5 - Salir\n";
					
	cout << "\nElija una opcion: ";
	cin >> opcion;
	
	if(opcion == 1){
		
			CL;
			int c;
			string n, a, g, d, ce, co, fn;
			cout << "Codigo:";
			cin >> c;
			cout << "Nombre:";
			cin >> n;
			cout << "Apellido:";
			cin >> a;
			cout << "Genero:";
			cin >> g;
			cout << "Dni:";
			cin >> d;
			cout << "Celular:";
			cin >> ce;
			cout << "Correo:";
			cin >> co;
			cout << "Fecha Nacimiento:";
			cin >> fn;
			Persona nueva = Persona();
			nueva.actualizarPersona(c,n,a,g,d,ce,co,fn);
			registro.Guardar(nueva);
			PA;
		
		
	}else if(opcion == 2){
		
			CL;
			cout << "DATOS \n";
			registro.Mostrar();
			PA;
		
	}else if(opcion == 3){
		
			CL;
			int id;
			cout << "Ingrese la codigo de la persona a modificar: ";
			cin >> id;
			registro.Modificar(id);
			PA;	
	}else{

		cout << "No ha ingresado nada";
}

}


}
