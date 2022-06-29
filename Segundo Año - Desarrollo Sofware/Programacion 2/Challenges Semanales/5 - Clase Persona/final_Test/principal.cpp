#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include "persona.h"

using namespace std;

bool verifica(int cod){
	
	ifstream leer("Legajo.txt", ios::in);
	
	string nombre;
	string apellido;
	int codigo;
	string genero;
	string dni;
	string celular;
	string correo;
	string fecha_nac;
	
	leer >> nombre;
	
	while(!leer.eof()){
		
		leer >> apellido;
		leer >> codigo;
		
		if(codigo == cod){
			
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
	
	cin.ignore();
	
	Persona persona;
	
	string nombre;
	string apellido;
	int codigo;
	string genero;
	string dni;
	string celular;
	string correo;
	string fecha_nac;
	
	char resp;
	
	es.open("Legajo.txt", ios::out | ios::app);
	
	cout << "Nombre: ";cin >> nombre;
	cout << "Apellido: ";cin >> apellido;	
	cout << "Codigo: ";cin >> codigo;	
	cout << "Genero: ";cin >> genero;
	cout << "Dni: ";cin >> dni;	
	cout << "Celular: ";cin >> celular;
	cout << "Correo: ";cin >> correo;
	cout << "Fecha Nacimiento: ";cin >> fecha_nac;
	
	
	persona.setNombre(nombre);
	persona.setApellido(apellido);
	persona.setCodigo(codigo);
	persona.setGenero(genero);
	persona.setDni(dni);	
	persona.setCelular(celular);
	persona.setCorreo(correo);
	persona.setFechaNacimiento(fecha_nac);

	if(verifica(codigo)){
		
		es << persona.getNombre() << " " << persona.getApellido() << " " << persona.getCodigo() << " " << persona.getGenero() << " "<< persona.getDni() << " " << persona.getCelular() << " " << persona.getCorreo() << " " << persona.getFn()<< endl;
			
	}
	
	
	es.close();
	
}
	

void verRegistros(ifstream &lectura){
	
	system("cls");
	
	string nombre;
	string apellido;
	int codigo;
	string genero;
	string dni;
	string celular;
	string correo;
	string fecha_nac;
	
	lectura.open("Legajo.txt", ios::in);
	
	if(lectura.is_open()){
	
		lectura >> nombre;
		
		while(!lectura.eof()){
			
			lectura >> apellido;	
			lectura >> codigo;
			lectura >> genero;
			lectura >> dni;
			lectura >> celular;
			lectura >> correo;
			lectura >> fecha_nac;
			
			cout << "---------------------------------" << endl;	
			cout << "Nombre-------:" << nombre << endl;
			cout << "Apellido-------:" << apellido << endl;
			cout << "Codigo-------:" << codigo << endl;	
			cout << "Genero-------:" << genero << endl;
			cout << "Dni-------:" << dni << endl;
			cout << "Celular-------:" << celular << endl;	
			cout << "Correo-------:" << correo << endl;
			cout << "Fecha_nac-------:" << fecha_nac << endl;	
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
		
	lectura.open("Legajo.txt", ios::in);
	
	bool encontrado = false;
	
	string nombre;
	string apellido;
	int codigo;
	int codigo_auxiliar;
	string genero;
	string dni;
	string celular;
	string correo;
	string fecha_nac;
	
	cout << "Ingrese el codigo: "; cin >> codigo_auxiliar;
	
	lectura >> nombre;
	
	while(!lectura.eof() and !encontrado){
		
			lectura >> apellido;	
			lectura >> codigo;
			lectura >> genero;
			lectura >> dni;
			lectura >> celular;
			lectura >> correo;
			lectura >> fecha_nac;
		
		if(codigo == codigo_auxiliar){
			
			cout << "---------------------------------" << endl;	
			cout << "Nombre-------:" << nombre << endl;
			cout << "Apellido-------:" << apellido << endl;
			cout << "Codigo-------:" << codigo << endl;	
			cout << "Genero-------:" << genero << endl;
			cout << "Dni-------:" << dni << endl;
			cout << "Celular-------:" << celular << endl;	
			cout << "Correo-------:" << correo << endl;
			cout << "Fecha_nac-------:" << fecha_nac << endl;	
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

/*

void modificar(ifstream &lectura){
	
	system("cls");
	
	string nombre;
	string apellido;
	int codigo;
	int codigo_auxiliar;
	string genero;
	string dni;
	string celular;
	string correo;
	string correo_auxiliar;
	string fecha_nac;

	
	lectura.open("Legajo.txt", ios::in);
	
	ofstream aux("auxiliar.txt", ios::out);
	
	if(lectura.is_open()){
		
		cout << "Ingrese codigo a modificar: "; cin >> codigo_auxiliar;
		
		lectura >> nombre;
		
		while(!lectura.eof()){
			
			lectura >> apellido;	
			lectura >> codigo;
			lectura >> genero;
			lectura >> dni;
			lectura >> celular;
			lectura >> correo;
			lectura >> fecha_nac;
			
			if(codigo == codigo_auxiliar){
				
				cout << "Nuevo Correo electronico: "; cin >> correo_auxiliar;
				
				aux << nombre << " " << apellido << " " << codigo << " " << genero << " " << dni << " " << celular << " " << correo_auxiliar << " " << fecha_nac << endl;
				
			}else{
				
				aux << nombre << " " << apellido << " " << codigo << " " << genero << " " << dni << " " << celular << " " << correo_auxiliar << " " << fecha_nac << endl;
				
			}
			
			
			lectura >> nombre;
		
		}
		
		lectura.close();
		aux.close();
			
		
	}else
		
		cout << "Error al tratar de modificar el registro" << endl;
		remove("Legajo.txt");
		rename("auxiliar.txt", "Legajo.txt");
	
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

*/
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
			cin.ignore();
			agregar(Esc);	
	}else if(opcion == 2){
			//verRegistros(Lec);
	}else if(opcion == 3){
			//buscarPersonas(Lec);
	}else if(opcion == 4){
//			modificar(Lec);
	}else if(opcion == 5){
			//eliminar(Lec);
	}
}

}
