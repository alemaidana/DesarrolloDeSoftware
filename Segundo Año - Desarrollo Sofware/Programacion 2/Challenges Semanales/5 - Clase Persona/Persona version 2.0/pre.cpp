#include <iostream>
#include "fecha2.h"
#include <string>

using namespace std;

int main(){

	char arr[20];
	
	Fecha fecha;
	
	fecha.Menu();
	
	string fec= fecha.dameFecha(); 

	strcpy(arr, fec.c_str());
	
	cout << arr;
	
	
}
