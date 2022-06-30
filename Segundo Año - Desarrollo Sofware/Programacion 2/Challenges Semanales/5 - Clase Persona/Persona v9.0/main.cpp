//Crud.cpp : programa que contiene el main, todo empieza y termina aca
 
#include <iostream>
#include "Registro.h"
 
#define CL system("cls")
#define PA system("pause")
 
using namespace std;
 
//Clase persona: todos los datos
 
int main(){
    
    Registro registro;
    
    int opcion = 0;
    
    while (opcion != 5){
    
    CL;
    cout << "\t\t\t\t.----------------------------------. " << endl;
    cout << "\t\t\t\t| SISTEMA EMPLEADOS ISFT 220 AMET  |\n";
    cout << "\t\t\t\t.----------------------------------. " << endl;
    cout << "\t\t\t\t|1 - Insertar Persona              |\n";
    cout << "\t\t\t\t|2 - Mostrar Persona               |\n";
    cout << "\t\t\t\t|3 - Modificar Persona             |\n";
    cout << "\t\t\t\t|4 - Eliminar Persona              |\n";
    cout << "\t\t\t\t|5 - Salir                         |\n";
    cout << "\t\t\t\t.----------------------------------. " << endl;                
    cout << "\nElija una opcion: ";
    cin >> opcion;
    
    if(opcion == 1){
        
            	CL;
            	int c;
            	Fecha fecha;
				Correo correo;
            	Celular celular;
            	Dni dni;
	        	string n,a,ca,dn,te,co,fn;
	            cout << "Ingrese Codigo:";
	            cin >> c;
	            cout << "Ingrese Nombre:";
	            cin >> n;
	            cout << "Ingrese Apellido:";
	            cin >> a;
		        cout << "Ingrese Cargo:";
	            cin >> ca;
	            dni.solicitarDocumento();
	            dn = dni.dameDocumento();
	            celular.solicitarCelular();
	            te = celular.dameCelular();
	            correo.solicitarCorreo();
	            co = correo.dameCorreo();
				fecha.Menu();
            	fn = fecha.dameFecha(); 
 
            Persona nueva = Persona();
            nueva.ActualizarDatos(c, _strdup(n.c_str()),_strdup(a.c_str()),_strdup(ca.c_str()) , _strdup(dn.c_str()), _strdup(te.c_str()), _strdup(co.c_str()), _strdup(fn.c_str()));
            registro.Guardar(nueva);
            PA;
        
        
    }else if(opcion == 2){
        
            CL;
            cout << "\t\t\t\t.-----------------------------." << endl;
            cout << "\t\t\t\t|Registro de Personal ISFT 220|" << endl;
            cout << "\t\t\t\t.-----------------------------." << "\n"<< endl;
            registro.Mostrar();
            PA;
        
    }else if(opcion == 3){
            
            CL;
            int id;
            cout << "\t\t\t\t.-----------------------------." << endl;
            cout << "\t\t\t\t|Registro de Personal ISFT 220|" << endl;
            cout << "\t\t\t\t.-----------------------------." << "\n"<< endl;            
            cout << "Ingrese el codigo de la persona a modificar: ";
            cin >> id;
            registro.Modificar(id);
            PA;
            
    }else if(opcion == 4){      
            
            int id2;
            cout << "\t\t\t\t.-----------------------------." << endl;
            cout << "\t\t\t\t|Registro de Personal ISFT 220|" << endl;
            cout << "\t\t\t\t.-----------------------------." << "\n"<< endl;
            cout << "Ingrese el codigo de la persona a eliminar: ";
            cin >> id2;
            registro.Eliminar(id2);
            PA;
    }
    
    
    }
    
        
    
    
}
