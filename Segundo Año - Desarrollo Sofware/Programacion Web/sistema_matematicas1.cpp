#include <iostream>
 
using namespace std;
 
class Ecuacion{
    
    public:
        
        void resolverEcuacion(float, char, float, float, float);
        void resolverEcuacionMid(float, char, float, float, float, float, float);
};
 
int main(){
    
    //declaramos las variables
    float ti, ti2, ti3, ti4, cp, bl;
    char operacion;
    Ecuacion eq;
    
    cout << endl;
    
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
                    //pedido de entrada de datos
                    cout << "Introduce el termino con X: "; cin >> cp;
                    cout << "introduce la operacion: "; cin >> operacion;
                    cout << "Introduce el primer termino independiente: "; cin >> ti;
                    cout << "Introduce el segundo termino independiente: "; cin >> ti2;
        
                    cout << endl;               
                    
                    eq.resolverEcuacion(cp,operacion,ti,ti2,bl);    
                    break;
            
        }           
 
}
        
    
    
}
 
void Ecuacion::resolverEcuacion(float cp, char operacion, float termino_ind, float termino_ind2, float bloque_uno){
 
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
 
void Ecuacion::resolverEcuacionMid(float cp, char operacion, float termino_ind, float termino_ind2, float termino_ind3, float termino_ind4,float bloque_uno){
