#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "dni.h"
#include "celular.h"
#include "correo.h"


using namespace std;

int main(){
	
	Correo correo;
	
	correo.solicitarCorreo();
	
	string mail = correo.dameCorreo();
	
	cout << mail;
	
}
