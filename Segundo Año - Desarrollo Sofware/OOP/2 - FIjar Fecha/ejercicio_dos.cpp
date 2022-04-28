#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Fecha{
	
		int dia, mes, anio;
	
	public:
		void Iniciar(void);
		void Fijar(int, int, int);
		void Mostrar(void);
};



int main( int argc, char *argv[ ], char *envp[ ] ){

	Fecha fecha;
	
	fecha.Iniciar();
	fecha.Fijar(3, 5, 2003);
	fecha.Mostrar();

}

void Fecha::Iniciar(){
	
	dia = 0;
	mes = 0;
	anio = 0;
	
}

void Fecha::Fijar(int d, int m, int a){
	
	dia = d;
	mes = m;
	anio = a;
}

void Fecha::Mostrar(){
	
	cout << "La fecha es: \n";
	cout << dia << "/" << mes << "/" << anio << "\n";
} 
