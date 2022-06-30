#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Dni{
	
	string dni;
	
	public:
		void solicitarDocumento();
		string dameDocumento();
	
	
};

void Dni::solicitarDocumento(){


	bool correcto = false;
	
	string documento;

	while (!correcto){

	cout << "Ingrese dni: ";
	cin >> documento;

	//preguntamos el largo del dni si concuerda con los estandares de nuestro pais
	if(documento.length() > 7 && documento.length() <= 10){

			//correcto, el dni cuenta con los caracteres solicitados			
			cout << "Dni valido. Contiene entre 8 y 10 caracteres.\n";
			
			dni = documento;
			
			correcto = true;


	}else{
			
			//si no cumple los requerimientos no es valido el dni
			cout << "Dni no valido. Intentelo de nuevo por favor\n";
			
	}	
		
	}
	
}
	
	
	
string Dni::dameDocumento(){
	
	return this->dni;
	
}
