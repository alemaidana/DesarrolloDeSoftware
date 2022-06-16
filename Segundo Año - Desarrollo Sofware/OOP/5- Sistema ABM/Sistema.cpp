#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int filas_max = 10;

string NombreProducto[filas_max] = {};
string IDproducto[filas_max] = {};

void abrirArchivo(){

	string linea;
	ifstream miArchivo ("Productos.txt");
	
	if(miArchivo.is_open()){
		
		int i = 0;
		
		while (getline(miArchivo, linea)){
			
		int l = linea.length();
		
		IDproducto[i] = linea.substr(0,3);
		NombreProducto[i] = linea.substr(4, 1 - 4);	
		
		i++;	
			
		}
		
	}else{
		
		cout << "No se puede abrir el archivo" << endl;
		
	}
	
}

void crearProducto(){

	char id_prod[5];	
	char nombre[50];
	
	cin.ignore();
		
	cout << "ID del producto: ";
	cin.getline(id_prod,5);
		
	cout <<	"Nombre del producto: ";
	cin.getline(nombre,50);
	
	for(int i = 0; i < filas_max; i++){
		
		/*
		\0 is the NULL character, you can find it in your 
		ASCII table, it has the value 0.
		It is used to determinate the end of C-style strings.
		
		si esta vacia
		*/
		if(IDproducto[i] == "\0"){
			
			IDproducto[i] = id_prod;
			NombreProducto[i] = nombre;
			
			break;
			
		}
		
		
	}
	
}

void buscarProducto(string elemento){
	
	system("CLS");
	
	cout << "Productos Disponibles" << endl;
	cout << "==============================" << endl;
	
	int contador = 0;
	
	for(int i = 0; i < filas_max; i++){
		
		if(IDproducto[i] == elemento){
			
			contador++;

			cout << "Nro  |   ID   |    NOMBRE  " << endl << "------------------------------\n";

			cout << " " << contador << "       " << IDproducto[i] << "       " << NombreProducto[i] << endl;

			break;
		}
		
		
	}
	
	if(contador == 0){
		
		cout << "El elemento buscado no existe. Intentelo nuevamente" << endl;
	}
	
	
	cout << "=========================" << endl;

	
}

void actualizarProducto(string elemento){

	char id_producto[5];	
	char nombre_nuevo[50];

	int contador = 0;
	
	for(int i = 0; i < filas_max; i++){
		
		if(IDproducto[i] == elemento){
			
		contador++;
			
		cout << "Nombre del producto: ";	
		cin.getline(nombre_nuevo, 50);
		
		NombreProducto[i] = nombre_nuevo;
		
		cout << "Actualizacion de producto exitosa! " << endl;
		
		break;	
			
		}
		
		
	}
	
		if(contador == 0){
		
		cout << "No se ha encontrado ese elemento, intentelo nuevamente." << endl;
	}

	
}

void borrarProducto(string elemento){

	int contador = 0;
	
	for(int i = 0; i < filas_max; i++){
		
		if(IDproducto[i] == elemento){
			
			contador++;
			
			NombreProducto[i]= "";
			IDproducto[i] ="";
			
			cout << "Producto borrado con exito!!" << endl;
			cout << "Presione ENTER para continuar" << endl;
			break;
		}
		
		
	}
	
	if(contador == 0){
		
		cout << "El id del producto no existe. Intentelo de nuevo " << endl;
	}
	
}

void mostrarProductos(){

	system("CLS");
	cout << "Productos Disponibles" << endl;
	cout << "==============================" << endl;
	
	int contador = 0;
	
	cout << "Nro  |   ID   |    NOMBRE  " << endl << "------------------------------\n";
	
	for(int i = 0; i < filas_max; i++){
		
		if(IDproducto[i] != "\0"){
			
			contador++;
			cout << " " << contador << "       " << IDproducto[i] << "       " << NombreProducto[i] << endl;
			
		}
		
		
	}
	
	if(contador == 0){
		
		cout << "No se han encontrado productos" << endl; 
		
	}
	
	
	cout << "=========================" << endl;
	
	
}

void guardarEnArchivo(){
	
	ofstream miArchivo;
	miArchivo.open("Productos.txt");
	
	for (int i = 0; i < filas_max; i++){
		
		if(IDproducto[i] == "\0"){
			
			break;
			
		}else{
			
		miArchivo << IDproducto[i] + " , " + NombreProducto[i] << endl; 	
			
		}
		
	}
	
}	


int main(){
	
	int opcion;
	string prodID;
	system("CLS");
	abrirArchivo();
	
	do {
		cout << "Menu\n";	
		cout << "1 - Crear Producto" << endl;
		cout << "2 - Modificar Producto" << endl;
		cout << "3 - Borrar Producto" << endl;		
		cout << "4 - Buscar Producto" << endl;
		cout << "5 - Mostrar todos los productos" << endl;
		cout << "6 - Salir y guardar el archivo" << endl;	
	
		cout << "\nSeleccion su opcion: ";
		cin >> opcion;
	
		switch(opcion){
		case 1: 
			crearProducto();
			system("CLS");
			break;
		case 2:
			cin.ignore();
			cout << "Buscar por id: ";
			getline(cin, prodID);	
			actualizarProducto(prodID);
			system("CLS");
			break;
		case 3:
			cin.ignore();
			cout << "Borrar por id: ";
			getline(cin, prodID);	
			borrarProducto(prodID);
			cin.ignore();
			system("CLS");
			break;
		case 4:
			cin.ignore();
			cout << "Buscar por id: ";
			getline(cin, prodID);	
			buscarProducto(prodID);
			break;
		case 5:
			mostrarProductos();
			break;
		
	}
	
	
		
	}while(opcion != 6);

	
	guardarEnArchivo();
	cout << "Saliendo.. guardando el archivo!" << endl;

	
	return 0; 
	
	
}	

