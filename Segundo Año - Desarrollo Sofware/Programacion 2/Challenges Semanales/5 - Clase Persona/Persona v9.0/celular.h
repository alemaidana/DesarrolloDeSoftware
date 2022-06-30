#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Celular{
	
	string celular;
	
	public:
		void solicitarCelular();
		string dameCelular();
	
	
};

void Celular::solicitarCelular(){


	bool correcto = false;
	
	string telefono_celular;

	while (!correcto){

	cout << "Ingrese numero de celular: ";
	cin >> telefono_celular;

	//preguntamos si el telefono tiene 10 caracteres
	if(telefono_celular.length() == 10){

			//correcto, el celular cuenta con 10 caracteres
			cout << "Celular con 10 numeros, numero de celular valido\n";		
			
			celular = telefono_celular;
			
			correcto = true;
			
	}else{
	
			//si no cumple los requerimientos no es valido el telefono
			cout << "Telefono no valido. Recuerde que debe contener 10 caracteres.";
			

	}
	
}
	
	
}
	
string Celular::dameCelular(){
	
	return this->celular;
	
}
