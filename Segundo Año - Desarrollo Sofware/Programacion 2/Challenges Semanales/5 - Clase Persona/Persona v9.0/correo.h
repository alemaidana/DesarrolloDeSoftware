#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Correo{
	
	string correo;
	
	public:
		void solicitarCorreo();
		string dameCorreo();
	
	
};

void Correo::solicitarCorreo(){


	bool correcto = false;
	
	string email;

	while (!correcto){

	cout << "Ingrese correo electronico: ";
	cin >> email;

		//caracteres a encontrar
	char arroba = '@';
	char punto = '.';
	
	//banderas por si encontramos 
	bool busqueda_arroba = false;
	bool busqueda_punto = false;


	//buscamos cuantas arrobas y puntos hay en el correo electronico introducido	
	for(int i = 0 ; i < email.length(); i++){
		
		//buscamos el arroba
		if(email[i] == arroba){
				
		//encontre un '@'		
			busqueda_arroba = true;	
			
		}
		
		//buscamos los puntos
		if(email[i] == punto){
	
		//encontre un '.'		
		busqueda_punto = true;	
			
		}
		
	}
	
	if ( busqueda_arroba && busqueda_punto ){
		
		//si esto es correcto es valida la direccion
		cout << "Direccion de correo valida\n";
		
		//aqui vemos en que posicion de la direccion esta
		//cout << "\nArroba en la posicion: " << correo.find("@");
		//cout << "\nPunto en la posicion: " << correo.find(".");
		
		correo = email;
		
		correcto = true;

		
	}else{
		
		//si no cumple los requerimientos no es valida la direccion
		cout << "Direccion de correo no valida\n";
		
	}

}
	
	
}
	
string Correo::dameCorreo(){
	
	return this->correo;
	
}
