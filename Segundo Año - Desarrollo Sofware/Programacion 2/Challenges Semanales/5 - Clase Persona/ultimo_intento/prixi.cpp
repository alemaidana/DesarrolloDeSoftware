#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>

using namespace std;

bool verifica(string ced){
	
	ifstream leer("Personitas.txt", ios::in);
	
	string nombre;
	string apellido;
	string cedula;
	
	leer >> nombre;
	
	while(!leer.eof()){
		
		leer >> apellido;
		leer >> cedula;
		
		if(cedula == ced){
			
			leer.close();
			

			
			cout << "Clave ya existe" << endl;
			
			system("pause");
						
			return false;
			
		}
		
		leer >> nombre;
		
	}
	
	leer.close();
	
	return true;
	
}


void agregar(ofstream &es){
	system("cls");
	
	string nombre;
	string apellido;
	string cedula;
	
	es.open("Personitas.txt", ios::out | ios::app);
	
	cout << "Nombre: ";cin >> nombre;
	cout << "Apellido: ";cin >> apellido;	
	cout << "Cedula: ";cin >> cedula;	
	
	if(verifica(cedula)){
		
		es << nombre << " " << apellido << " " << cedula << endl;
			
	}
	
	
	es.close();
	
}
	

void verRegistros(ifstream &lectura){
	
	system("cls");
	
	string nombre;
	string apellido;
	string cedula;
	
	lectura.open("Personitas.txt", ios::in);
	
	if(lectura.is_open()){
	
		lectura >> nombre;
		
		while(!lectura.eof()){
			
			lectura >> apellido;	
			lectura >> cedula;
			
			cout << "Nombre-------:" << nombre << endl;
			cout << "Apellido-------:" << apellido << endl;
			cout << "Cedula-------:" << cedula << endl;	
			cout << "---------------------------------" << endl;	
			lectura >> nombre;
			
		}
		
		lectura.close();
		
	}else{
		
		cout << "Error al abrir el registro" << endl;
	}
	
	system("pause");
	
}

void buscarPersonas(ifstream &lectura){
	
	system("cls");
		
	lectura.open("Personitas.txt", ios::in);
	
	bool encontrado = false;
	
	string nombre;
	string apellido;
	string cedula;
	string cedula_auxiliar;
	
	cout << "Ingrese la cedula: "; cin >> cedula_auxiliar;
	
	lectura >> nombre;
	
	while(!lectura.eof() and !encontrado){
		
		lectura >> apellido;	
		lectura >> cedula;
		
		if(cedula == cedula_auxiliar){
			
		cout << "Nombre-------:" << nombre << endl;
		cout << "Apellido-------:" << apellido << endl;
		cout << "Cedula-------:" << cedula << endl;	
		cout << "---------------------------------" << endl;	
		
			encontrado = true;
		}
		
		
		lectura >> nombre;
		
		
		
	}
	
	lectura.close();
	
	if(!encontrado){
		
		cout << "No existe ese registro" << endl;
		
	}
	
	system("pause");
	
}

void modificar(ifstream &lectura){
	
	system("cls");
	
	string nombre;
	string apellido;
	string cedula;
	string cedula_auxiliar;
	string nombre_auxiliar;
	
	lectura.open("Personitas.txt", ios::in);
	
	ofstream aux("auxiliar.txt", ios::out);
	
	if(lectura.is_open()){
		
		cout << "Ingrese cedula a modificar: "; cin >> cedula_auxiliar;
		
		lectura >> nombre;
		
		while(!lectura.eof()){
			
			lectura >> apellido;
			lectura >> cedula;
		
			if(cedula == cedula_auxiliar){
				
				cout << "Nuevo nombre: "; cin >> nombre_auxiliar;
				
				aux << nombre_auxiliar << " " << apellido << " " << cedula << endl;
			}else{
				
				aux << nombre << " " << apellido << " " << cedula << endl;
				
			}
			
			
			lectura >> nombre;
		
		}
		
		lectura.close();
		aux.close();
			
		
	}else
		
		cout << "Error al tratar de modificar el registro" << endl;
		remove("Personitas.txt");
		rename("auxiliar.txt", "Personitas.txt");
		
	
	
	
	
}


void eliminar(ifstream &lectura){
	
		system("cls");
	
	string nombre;
	string apellido;
	string cedula;
	string cedula_auxiliar;
	string nombre_auxiliar;
	
	lectura.open("Personitas.txt", ios::in);
	
	ofstream aux("auxiliar.txt", ios::out);
	
	if(lectura.is_open()){
		
		cout << "Ingrese cedula a borrar: "; cin >> cedula_auxiliar;
		
		lectura >> nombre;
		
		while(!lectura.eof()){
			
			lectura >> apellido;
			lectura >> cedula;
		
			if(cedula == cedula_auxiliar){
				
				cout << "Registro eliminado" << endl;
				Sleep(1500);
			
			}else{
				
				aux << nombre << " " << apellido << " " << cedula << endl;
				
			}
			
			
			lectura >> nombre;
		
		}
		
		lectura.close();
		aux.close();
			
		
	}else
		
		cout << "Error al tratar de modificar el registro" << endl;
		remove("Personitas.txt");
		rename("auxiliar.txt", "Personitas.txt");
		
	
	
	
	
}


int main(){
	
	ofstream Esc;
	ifstream Lec;
	
	int opcion = 0;
	
	while (opcion != 6){
	
	system("cls");
	
	cout << "| REGISTRO EMPLEADOS ISFT 220 AMET |\n";
	
	cout << "1 - Insertar\n";
	cout << "2 - Mostrar\n";
	cout << "3 - Buscar\n";
	cout << "4 - Modificar\n";
	cout << "5 - Eliminar\n";
	cout << "6 - Salir\n";
					
	cout << "\nElija una opcion: ";
	cin >> opcion;

	system("cls");

	if(opcion == 1){
			agregar(Esc);	
	}else if(opcion == 2){
			verRegistros(Lec);
	}else if(opcion == 3){
			buscarPersonas(Lec);
	}else if(opcion == 4){
			modificar(Lec);
	}else if(opcion == 5){
			eliminar(Lec);
	}
}

}
