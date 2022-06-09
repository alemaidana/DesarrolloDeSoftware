#include <iostream>
#include <fstream>

using namespace std;

int main(){
	
	ofstream miArchivo;
	miArchivo.open("dosito.csv");
	
	char limite = ';';
	
	
	miArchivo << "Nota1" << limite << "Nota2" << limite << "Nota3" << endl;
	
	for(int i = 0; i < 20; i++){
		
		miArchivo << i << limite << i*i << limite << i + 3 << endl;
		
	}
	
	miArchivo.close();
}
