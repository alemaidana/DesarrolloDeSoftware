#include <iostream>
#include <string>
#include <fstream>
 
using namespace std;
 
//numero maximo de filas
const int filas_max = 10;
 
//variables del tipo 
string NombreProducto[filas_max] = {};
string IDproducto[filas_max] = {};
string PrecioProducto[filas_max] = {};

 
/*
Metodo crearProducto() -> va a crear el producto en cuestion para luego ser modificado
eliminado o ser buscado, tomara un id, un nombre y un precio
*/
void crearProducto(){
 
    //declaramos los atributos del producto
    char id_prod[5];    
    char nombre[50];
    char precio[5];
    
    cin.ignore();
    
    //pedimos por teclado que se ingresen los datos
        
    cout << "ID del producto: ";
    cin.getline(id_prod,5);
        
    cout << "Nombre del producto: ";
    cin.getline(nombre,50);
    
    cout << "Precio del producto: ";
    cin.getline(precio,5);
    
    //cargamos los productos al arreglo propio
    for(int i = 0; i < filas_max; i++){
        
        /*
        Lo primero es comprobar si el arreglo esta vacio
        
        "\0" ---> is the NULL 
        
        */
        if(IDproducto[i] == "\0"){
            
            IDproducto[i] = id_prod;
            NombreProducto[i] = nombre;
            PrecioProducto[i] = precio;
            
            break;
            
        }
        
        
    }
    
}
 
/*
Metodo buscarProducto() -> vamos a buscar mediante la coincidencia del paramentro 
elemento a ver si coincide con el id del producto a modo
de consulta para traerlo a la pantalla
*/
 
void buscarProducto(string elemento){
    
    //borramos la pantalla
    system("CLS");
    
    cout << "Productos Disponibles" << endl;
    cout << "==============================" << endl;
    
    //usamos una variable contador a modo de busqueda 
    int contador = 0;
    
    //realizamos una busqueda en todas las filas
    for(int i = 0; i < filas_max; i++){
        
        //si el id del producto coincide con el elemento que buscamos
        if(IDproducto[i] == elemento){
            
            
            //si hay match, el contador se le suma uno, lo traemos a pantalla y lo mostramos
            contador++;
 
            cout << "Nro  |   ID   |    NOMBRE  |         PRECIO" << endl << "------------------------------\n";
 
            cout << " " << contador << "       " << IDproducto[i] << "       " << NombreProducto[i] << "             " << PrecioProducto[i] << endl;
 
            break;
        }
        
        
    }
    
    //si el contador es igual a 0 lo que quiere decir que no lo encontro
    if(contador == 0){
        
        cout << "El elemento buscado no existe. Intentelo nuevamente" << endl;
    }
    
    
    cout << "=========================" << endl;
 
    
}
 
/*
Metodo actualizarProducto() -> mediante el paramentro de busqueda al igual
que en el metodo buscar al encontrar el id nos permite modificar el precio
*/
 
void actualizarProducto(string elemento){
 
    //atributo a buscar
    char precio_nuevo[5];
    
    //variable contador de guia
    int contador = 0;
    
    //realizamos una busqueda en todas las filas
    for(int i = 0; i < filas_max; i++){
        
        //si el id del producto coincide con el elemento que buscamos
        if(IDproducto[i] == elemento){
        
        //si hay match, el contador se le suma uno, y editamos con una carga
        //manual el producto    
        contador++;
            
        cout << "Precio del producto: ";    
        cin.getline(precio_nuevo, 5);
        
        //el producto en el indice encontrado tendra el nuevo valor
        //ingresado
        PrecioProducto[i] = precio_nuevo;
        
        //una vez que se actualizo el producto se le da un mensaje exitoso al usuario
        cout << "Actualizacion de producto exitosa! " << endl;
        
        break;  
            
        }
        
        
    }
    
    //si el contador es igual a 0 lo que quiere decir que no lo encontro
        if(contador == 0){
        
        cout << "No se ha encontrado ese elemento, intentelo nuevamente." << endl;
    }
 
    
}
 
 
/*
Metodo borrarProducto() -> mediante el paramentro de busqueda al igual
que en los metodos anteriores buscara y al encontrar el id nos permite borrar
el producto
*/
 
void borrarProducto(string elemento){
 
    //variable contador de guia
    int contador = 0;
 
    //realizamos una busqueda en todas las filas
    for(int i = 0; i < filas_max; i++){
 
        //si el id del producto coincide con el elemento que buscamos       
        if(IDproducto[i] == elemento){
 
            //si hay match, el contador se le suma y el producto se borra
            
            contador++;
            
            NombreProducto[i]= "";
            IDproducto[i] ="";
            PrecioProducto[i] = "";
            
            //mensaje de exito asi volvemos al menu
            cout << "Producto borrado con exito!!" << endl;
            cout << "Presione ENTER para continuar" << endl;
            break;
        }
        
        
    }
    //si el contador es igual a 0 lo que quiere decir que no lo encontro    
    if(contador == 0){
        
        cout << "El id del producto no existe. Intentelo de nuevo " << endl;
    }
    
}
 
/*
Metodo mostrarProducto() -> mediante el paramentro de busqueda al igual
que en los metodos anteriores buscara y al encontrar el id nos permite borrar
el producto
*/
 
void mostrarProductos(){
 
    //mostramos al usuario todos los productos disponibles
    system("CLS");
    cout << "Productos Disponibles" << endl;
    cout << "========================================" << endl;
    
    //usamos una variable contador como guia
    int contador = 0;
    
    cout << "Nro  |   ID   |    NOMBRE  |  PRECIO" << endl << "----------------------------------------\n";
    
    //buscamos en todas las filas
    for(int i = 0; i < filas_max; i++){
        
        //si IDproducto no esta vacio
        if(IDproducto[i] != "\0"){
            
            //imprime en pantalla todos los productos que hayamos cargado
            contador++;
            cout << " " << contador << "       " << IDproducto[i] << "       " << NombreProducto[i] << "           " << PrecioProducto[i] << endl;
            
        }
        
        
    }
    
    //si contador es igual a 0 quiere decir que no se han cargado productos
    if(contador == 0){
        
        cout << "No se han encontrado productos" << endl; 
        
    }
    
    
    cout << "========================================" << endl;
    
    
}
 
/*
Metodo guardar en Archivo() -> nos va a guardar todos los cambios que hayamos hecho en 
el sistema para luego exportarlos a un archivo csv
*/
 
void guardarEnArchivo(){
    
    //creamos el archivo de flujo de salida
    ofstream miArchivo;
    miArchivo.open("Productos.csv");
    
    //ponemos un encabezado al documento
    miArchivo << "CODIGO" << " ; " << "NOMBRE" << " ; " << "PRECIO" << endl;    
    
    //buscamos en todas las filas
    for (int i = 0; i < filas_max; i++){
        
        //si el id es null o sea que no se
        //cargo nada sale
        if(IDproducto[i] == "\0"){
            
            break;
            
        }else{
        
        //en cambio si el archivo tiene datos escritos
        //que los exporte al archivo de flujo   
        miArchivo << IDproducto[i]  + " ; " +  NombreProducto[i]  + " ; " +  PrecioProducto[i] << endl;     
            
        }
        
    }
    
}   
 
/*
Metodo principal: aqui se desarrolla el menu principal donde podemos
dar de alta, baja, modificar, eliminar, mostrar y terminar el archivo
*/
int main(){
    //opcion para la eleccion del menu
    int opcion;
    //paramentro de busqueda del id para los metodos
    string prodID;
    //borra la pantalla
    system("CLS");
    //crea el archivo
    //abrirArchivo();
    
    //creamos el menu el cual se repetira indefinidamente hasta
    //que presionemos el 6 que sera la condicion de salida
    do {
    	cout << "************************************" << endl;
        cout << "	SUPERMERCADO DIA%"<< endl;  
    	cout << "************************************" << endl;
        cout << "1 - Crear Producto" << endl;
        cout << "2 - Modificar Precio" << endl;
        cout << "3 - Borrar Producto" << endl;      
        cout << "4 - Buscar Producto" << endl;
        cout << "5 - Mostrar todos los productos" << endl;
        cout << "6 - Salir y guardar el archivo" << endl;   
    
        //pedimos al usuario que seleccione la opcion deseada
        cout << "\nSeleccion su opcion: ";
        cin >> opcion;
        
        //mediante un switch evaluamos los casos que ingreso
        //el usuario
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
    
    
        
    }while(opcion != 6);//condicion de salida
 
    //llamamos al metodo para que nos guarde el archivo
    guardarEnArchivo();
    cout << "Saliendo.. guardando el archivo en csv!" << endl;
 
    
    return 0; 
    
    
}   
