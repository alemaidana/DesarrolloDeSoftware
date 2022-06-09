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
			int e, c;
			string n;
			cout << "Nombre:";
			cin >> n;
			cout << "Cedula:";
			cin >> c;
			cout << "Edad:";
			cin >> e;
			Persona nueva = Persona();
			nueva.ActualizarDatos(c, _strdup(n.c_str()),e);
			registro.Guardar(nueva);
			PA;
		
		
	}else if(opcion == 2){
		
			CL;
			cout << "DATOS";
			registro.Mostrar();
			PA;
		
	}else if(opcion == 3){
			
			CL;
			int id;
			cout << "Ingrese la cedula de la persona a modificar: ";
			cin >> id;
			registro.Modificar(id);
			PA;
			
	}else if(opcion == 4){		
			
			int id2;
			cout << "Ingrese la cedula de la persona a eliminar: ";
			cin >> id2;
			registro.Eliminar(id2);
			PA;
	}
	
	
	}
	
		
	
	
}
