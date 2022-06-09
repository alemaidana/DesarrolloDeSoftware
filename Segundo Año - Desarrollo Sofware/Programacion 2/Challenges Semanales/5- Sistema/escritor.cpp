#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool escribir_cabecera(string campo_uno, string campo_dos, string campo_tres);

int main(){
	
	bool escribir = escribir_cabecera("Nombre", "Apellido", "Notas");
	bool nombre = escribir_cabecera("Gabriel", "Lorens", "10");
	
	return 0;
	
}

bool escribir_cabecera(string campo_uno, string campo_dos, string campo_tres){
	
	ofstream ar;
	ar.open("nombres.csv");
	ar << campo_uno << ";" << campo_dos << ";" << campo_tres << endl;
	ar.close();

	return true;

}
