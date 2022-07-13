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
            
            
			int eleccion = 0;
            cout << "Ingrese una opcion para guardar: " << endl;
            cout << "1-Docentes" << endl;
            cout << "2-Alumnos" << endl;
            cout << "3-Particular" << endl;
            cout << "Elija: "; cin >> eleccion;
            
            if (eleccion == 1){
                
                CL;
                int c, le;
                Fecha fecha;
                Correo correo;
                Celular celular;
                Dni dni;
                string n,a,ca,dn,te,co,fn,ar;
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
                cout << "Ingrese Area:";
                cin >> ar;
                cout << "Ingrese Numero de Legajo:";
                cin >> le;
                
            Profesor nueva = Profesor();
            nueva.ActualizarProfesor(c, _strdup(n.c_str()),_strdup(a.c_str()),_strdup(ca.c_str()) , _strdup(dn.c_str()), _strdup(te.c_str()), _strdup(co.c_str()), _strdup(fn.c_str()), _strdup(ar.c_str()),le);
            registro.Guardar(nueva);
            PA;
                
            }else if(eleccion == 2){
                
                CL;
                int c, le;
                Fecha fecha;
                Correo correo;
                Celular celular;
                Dni dni;
                string n,a,ca,dn,te,co,fn,cu;
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
                cout << "Ingrese Curso:";
                cin >> cu;
                cout << "Ingrese Numero de Legajo:";
                cin >> le;
                
            Alumno nueva = Alumno();
            nueva.ActualizarAlumno(c, _strdup(n.c_str()),_strdup(a.c_str()),_strdup(ca.c_str()) , _strdup(dn.c_str()), _strdup(te.c_str()), _strdup(co.c_str()), _strdup(fn.c_str()), _strdup(cu.c_str()),le);
            registro.Guardar(nueva);
            PA;
                
                
            }else if(eleccion == 3){
                
                CL;
                int c, le;
                Fecha fecha;
                Correo correo;
                Celular celular;
                Dni dni;
                string n,a,ca,dn,te,co,fn,se;
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
                cout << "Ingrese Sector:";
                cin >> se;
                cout << "Ingrese Numero de Legajo:";
                cin >> le;
                
            Particular nueva = Particular();
            nueva.ActualizarParticular(c, _strdup(n.c_str()),_strdup(a.c_str()),_strdup(ca.c_str()) , _strdup(dn.c_str()), _strdup(te.c_str()), _strdup(co.c_str()), _strdup(fn.c_str()), _strdup(se.c_str()),le);
            registro.Guardar(nueva);
            PA;
                
                
            }        
                
        
        
    }else if(opcion == 2){
        
            CL;
            cout << "\t\t\t\t.-----------------------------." << endl;
            cout << "\t\t\t\t|Registro de Personal ISFT 220|" << endl;
            cout << "\t\t\t\t.-----------------------------." << "\n"<< endl;
            int opcion2 = 0;
            cout << "Visualizando personal del instituto: " << endl;
            registro.MostrarListado();
 
            PA;
        
    }else if(opcion == 3){
            
            CL;
            int id;
            cout << "\t\t\t\t.-----------------------------." << endl;
            cout << "\t\t\t\t|Registro de Personal ISFT 220|" << endl;
            cout << "\t\t\t\t.-----------------------------." << "\n"<< endl;            
            int opcion3 = 0;
            cout << "Ingrese una opcion para modificar: " << endl;
            cout << "1-Docentes " << endl;
            cout << "2-Alumnos " << endl;
            cout << "3-Particular " << endl;
            cout << "Elija: "; cin >> opcion3;
            if(opcion3 == 1){
			cout << "Ingrese el codigo de la persona a modificar: ";
            cin >> id;
            registro.ModificarProfesor(id);
            }else if(opcion3 == 2){
			cout << "Ingrese el codigo de la persona a modificar: ";
            cin >> id;
            registro.ModificarAlumno(id);
            }else if(opcion3 == 3){
            cout << "Ingrese el codigo de la persona a modificar: ";
            cin >> id;
            registro.ModificarParticular(id);
			}

            PA;
            
    }else if(opcion == 4){      
            
            int id2;
            cout << "\t\t\t\t.-----------------------------." << endl;
            cout << "\t\t\t\t|Registro de Personal ISFT 220|" << endl;
            cout << "\t\t\t\t.-----------------------------." << "\n"<< endl;
            int opcion3 = 0;
            cout << "Ingrese una opcion para eliminar: " << endl;
            cout << "1-Docentes " << endl;
            cout << "2-Alumnos " << endl;
            cout << "3-Particular " << endl;
            cout << "Elija: "; cin >> opcion3;
            if(opcion3 == 1){
			cout << "Ingrese el codigo de la persona a eliminar: ";
            cin >> id2;
            registro.EliminarProfesor(id2);
            }else if(opcion3 == 2){
			cout << "Ingrese el codigo de la persona a eliminar: ";
            cin >> id2;
            registro.EliminarAlumno(id2);
            }else if(opcion3 == 3){
            cout << "Ingrese el codigo de la persona a eliminar: ";
            cin >> id2;
            registro.EliminarParticular(id2);
			}
            PA;
    }
    
    
    }
    
        
    
    
}
