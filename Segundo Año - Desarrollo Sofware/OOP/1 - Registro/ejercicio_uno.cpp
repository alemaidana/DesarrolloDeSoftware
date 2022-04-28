#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Registro{
	
			char nombre[50];
			char telefono[50];
	
	public:
			void Iniciar(void);
			void EntradaDatos(void);
			void SalidaDatos(void);
			
}registro1;


int main( int argc, char *argv[ ], char *envp[ ] ){
	
		Registro registro2;
		
		registro1.Iniciar();
		registro2.Iniciar();
		
		registro1.EntradaDatos();
		registro2.EntradaDatos();
		
		registro1.SalidaDatos();
		registro2.SalidaDatos();
		
		return 0;
}

void Registro::Iniciar(){
	
		strcpy(nombre, "");
		strcpy(telefono, "");
	
}

void Registro::EntradaDatos(){
		
		cout<<"\nNombre: ";
		cin >> nombre;
		cout<<"\nTelefono: ";
		cin >> telefono;

}

void Registro::SalidaDatos(){
	
		cout << "\nNombre: \t" << nombre << "\n";
		cout << "\nTelefono: \t" << telefono << "\n";
}
