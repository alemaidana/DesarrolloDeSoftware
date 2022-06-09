#pragma once
#include "Persona.h"
#include <Windows.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

class Registro{
	
	private:
		fstream archivo;
	public:
		void Guardar(Persona);
		void Mostrar();
		void Modificar(int);
		void Eliminar(int);
		
};
