#include <iostream>

using namespace std;

class Funciones{
	
	float x1 = 0;
	float x2 = 0;
	float tt1 = 0;
	float tt2 = 0;
	char operacion1;
	char operacion2;	

	public:
		Funciones();
		void calcularYa(float x1, float x2, float tt1, float tt2, char operacion1, char operacion2);
		void calcularFinal(float x, float tt);
	
};
	
Funciones::Funciones(){
	
}


void Funciones::calcularYa(float x1, float x2, float tt1, float tt2, char operacion1, char operacion2){
	
	   if( operacion1 == '-' and operacion2 == '-'){
	   		
	   	operacion1= '+';	
		operacion2= '+';
	   			   	
	   	cout << x1 << "X " << operacion1 <<  " " << x2 << "X = " << tt2  << " " << operacion2 << " " << tt1 << endl; 
        
    	cout << endl;
        
    	float tt = tt2 + tt1;
    	float x = x1 + x2;
		
		cout << "Cuarto paso" << endl;   
		
    	calcularFinal(x, tt);
	   	
	   	
	   }else if( operacion1 == '+' and operacion2 == '+'){
	   	
	   	//no hace falta verificar
	   	
		operacion1= '-';	
		operacion2= '-';
	   	
    	//en caso que todos sean positivos
		cout << x1 << "X " << operacion1 <<  " " << x2 << "X = " << tt2  << " " << operacion2 << " " << tt1 << endl; 
        
    	cout << endl;
        
    	float tt = tt2 - tt1;
    	float x = x1 - x2;
    
		cout << "Cuarto paso" << endl;   
    
		calcularFinal(x, tt);	
	   	
	   	
	   }else if(operacion2 == '-'){
	   
	   	operacion1= '+';
	   		
	   	cout << x1 << "X " << operacion1 <<  " " << x2 << "X = " << tt2  << " " << operacion2 << " " << tt1 << endl; 
        
    	cout << endl;
        
    	float tt = tt2 - tt1;
    	float x = x1 + x2;
		
		cout << "Cuarto paso" << endl;   
		
    	calcularFinal(x, tt);
	   	
	   	
	   }else if(operacion1= '-'){
	   		
		operacion2= '+';
	   		
	   	cout << x1 << "X " << operacion1 <<  " " << x2 << "X = " << tt2  << " " << operacion2 << " " << tt1 << endl; 
        
    	cout << endl;
        
    	float tt = tt2 + tt1;
    	float x = x1 - x2;
		
		cout << "Cuarto paso" << endl;   
		
    	calcularFinal(x, tt);

	   }else{
	   	
	   	cout << "No ha ingresado nada" << endl;
	   	
	   }
	   
 
	
}


void Funciones::calcularFinal(float x, float tt){
	
	
		cout << x << "X " << "= " << tt << endl; 
        
    	cout << endl; 
		
		cout << "Quinto paso" << endl;   
		
		cout << "X = " << tt << " / "<< x << endl;
		
		cout << endl; 
		
		cout << "Resultado final" << endl;
		
    	cout << "X = " << tt / x;
	   	
	
}
