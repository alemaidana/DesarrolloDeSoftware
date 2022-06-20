#include <iostream>
#include "funciones.h"

using namespace std;

class EcuacionIntermedio{
 	
    float termino_ind;
    float termino_ind2;
    float termino_ind3;
    float termino_ind4;
    float cp;
    float cp2;
    char operacion1;
    char operacion2;
    float bloque_uno;
    float bloque_dos;
   	Funciones funcion;
 
    public:
    	void resolver();

};

void EcuacionIntermedio::resolver(){
	
	    //titulo
    cout << "****************************************************" << endl;
    cout << "Resolver ecuaciones de primer grado nivel Intermedio" << endl;
    cout << "****************************************************" << endl; 
    
    cout << endl;
    
    //pedido de entrada de datos
    cout << "Introduce el termino con X: "; cin >> cp;
    cout << "introduce la operacion: "; cin >> operacion1;
    cout << "Introduce el primer termino independiente: "; cin >> termino_ind;
    cout << "Introduce el termino independiente divisor: "; cin >> termino_ind3;
    
    
    cout << "Introduce el termino con X: "; cin >> cp2;
    cout << "introduce la operacion: "; cin >> operacion2;
    cout << "Introduce el primer termino independiente: "; cin >> termino_ind2;
    cout << "Introduce el termino independiente divisor: "; cin >> termino_ind4;
        
    cout << endl;
    
    //ecuacion principal
    cout << "Ecuacion principal" << endl;;
	cout << cp << "X " << operacion1 << " " << termino_ind << " = " << cp2 << "X " << operacion2 << " " << termino_ind2 << endl;
    cout <<"------   ------" << endl;
    cout << "   " << termino_ind3 << "        " << termino_ind4 << endl;
     
    
    cout << endl;
	
	//segundo paso
	cout << "Primer paso" << endl;;
    cout << "(" << cp << " " << operacion1 << " " << termino_ind << ")" << ". " << termino_ind4 << " = " << "(" << cp2 << " " << operacion2 << " " << termino_ind2 << ")" << ". " << termino_ind3 << endl;
    

    float n_cp = termino_ind4 * cp;
    float n_ti = termino_ind4 * termino_ind;
        
    float n_cp2 = termino_ind3 * cp2;
    float n_ti2 = termino_ind3 * termino_ind2;
        
    cout << endl;
    
	cout << "Segundo paso" << endl;;
		
	if(n_ti < 0 and n_ti2 < 0){
		
		operacion1 = '-';
		operacion2 = '-';
		
		cout << n_cp << "X " << operacion1 << " " << n_ti << " = ";
		cout << n_cp2 << "X " << operacion2 << " " << n_ti2 << endl; 
		
		cout << endl;    		
		
		cout << "Tercer paso" << endl;
		
		funcion.calcularYa(n_cp, n_cp2, n_ti, n_ti2, operacion1, operacion2);

	}else if(n_ti < 0){
		
		operacion1 = '-';
		
		cout << n_cp << "X " << operacion1 << " " << n_ti << " = ";
		cout << n_cp2 << "X " << operacion2 << " " << n_ti2 << endl; 
    
		cout << endl;
		
		cout << "Tercer paso" << endl;
		
		funcion.calcularYa(n_cp, n_cp2, n_ti, n_ti2, operacion1, operacion2);
		
	}else if(n_ti2 < 0){
	
		operacion2 = '-';
		
		cout << n_cp << "X " << operacion1 << " " << n_ti << " = ";
		cout << n_cp2 << "X " << operacion2 << " " << n_ti2 << endl; 
    
		cout << endl;				
		
		cout << "Tercer paso" << endl;
		
		funcion.calcularYa(n_cp, n_cp2, n_ti, n_ti2, operacion1, operacion2);	
			
	}else{
		
		cout << n_cp << "X " << operacion1 << " " << n_ti << " = " << n_cp2 << "X " << operacion2 << " " << n_ti2 << endl; 
		
		cout << endl;
		
		cout << "Tercer paso" << endl;
		
		funcion.calcularYa(n_cp, n_cp2, n_ti, n_ti2, operacion1, operacion2);
	
		
	}
	
                    
    
    
 
    
}
	
	
	

