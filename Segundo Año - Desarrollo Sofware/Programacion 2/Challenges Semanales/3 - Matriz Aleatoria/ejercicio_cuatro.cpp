/*
EJERCICIO 4:
Crear matriz con numero aleatorios y mostrarlos en forma de matriz
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
//incluimos la libreria para usar la funcion rand() que nos genera numeros al azar
#include <cstdlib>

using namespace std;


int main(void){
	
	//Declaramos la matriz de 5 x 5
	int matriz_random[5][5];
	
	
	//usamos un primer for para recorrer las filas
	for(int i = 0; i < 5; i++){
		
		
		//usamos un segundo for para las columnas
		for(int j = 0; j < 5; j++){
			
			//rellenamos la matriz en sus respectivas posiciones
			//con un valor aleatorio entre el 0 y el 10
			matriz_random[i][j] = rand() % 10 + 1;
			
			//imprimimos la matriz
			cout << "[" << matriz_random[i][j] << "] ";
			
		}
		
		//por cada vuelta damos un salto de linea
		//para mejorar el formato de la salida
		cout << "\n";
		
	}
	
	
	return 0;
}
