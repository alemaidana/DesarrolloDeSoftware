#include <iostream>
#include "EcuacionSimple.h"
#include "EcuacionIntermedia.h"

 
using namespace std;

int main(){
	
	EcuacionSimple ecuacion_principiante;
	EcuacionIntermedio ecuacion_intermedio;
	
	int opcion = 0;
    
    while (opcion != 4){
    
        //titulo
        cout << "************************************" << endl;
        cout << "Resolver ecuaciones de primer grado" << endl;
        cout << "************************************" << endl;     
        
        cout << "1) Principiante" << endl;
        cout << "2) Intermedio" << endl;    
        cout << "3) Avanzado" << endl;
        cout << "4) Salir" << endl;
        
        cout << "Ingresa tu opcion: "; cin >> opcion;
  
  		switch(opcion){
            case 1:
            	ecuacion_principiante.pedidoDatos();
        		break;
        	case 2:
				ecuacion_intermedio.resolver();
				break;	
        		
  			
	}
	
	
	
}
	
	
	
	
}
