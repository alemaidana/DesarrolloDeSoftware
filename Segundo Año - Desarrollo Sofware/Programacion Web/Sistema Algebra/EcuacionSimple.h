#include <iostream>

using namespace std;

class EcuacionSimple{
    
    float ti, ti2, ti3, ti4, cp, bl;
 	char operacion;
 
    public:
    	void pedidoDatos();
        void resolverEcuacion(float, char, float, float, float);



};
 
void EcuacionSimple::pedidoDatos(){
	
	cout << "Introduce el termino con X: "; cin >> cp;
    cout << "introduce la operacion: "; cin >> operacion;
    cout << "Introduce el primer termino independiente: "; cin >> ti;
    cout << "Introduce el segundo termino independiente: "; cin >> ti2;
        
    cout << endl;               
                    
    resolverEcuacion(cp,operacion,ti,ti2,bl);
	
	
	
} 
 
 
 
void EcuacionSimple::resolverEcuacion(float cp, char operacion, float termino_ind, float termino_ind2, float bloque_uno){
 
    //ecuacion principal
    cout << cp << "X " << operacion << " " << termino_ind << " = " << termino_ind2 << endl; 
 
    // segundo paso chequeamos la operacion
    
    cout << endl;
        
    if(operacion == '+'){
        
        operacion = '-';
        
        cout << cp << "X " << " = " << termino_ind2 << " " << operacion << " " << termino_ind << endl; 
    
        bloque_uno = termino_ind2 - termino_ind;
        
        cout << endl;
        
        cout << cp << "X" << " = " << bloque_uno << endl;
        
        cout << endl;
        
        cout << "X = " << bloque_uno << " / " << cp << endl;
        
        cout << endl;
        
        cout << "X = " << bloque_uno / cp << endl;
        
        cout << endl;
        
                
    }else{
        
        operacion = '+';
        
        cout << cp << "X " << " = " << termino_ind2 << " " << operacion << " " << termino_ind << endl; 
    
        bloque_uno = termino_ind2 + termino_ind;
        
        cout << endl;
        
        cout << cp << "X" << " = " << bloque_uno << endl;
        
        cout << endl;
        
        cout << "X = " << bloque_uno << " / " << cp << endl;
        
        cout << endl;
        
        cout << "X = " << bloque_uno / cp << endl;
        
        cout << endl;
        
        
    }
    
    
}

