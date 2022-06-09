#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

//Clase fecha v 2.0 adaptada a la clase persona
//-Se procedio a quitar el metodo main()
//-Se adaptaron los metodos a la clase Persona 

class Fecha{
		//ingresamos las variables de dia, mes y año
		int dia, mes, anio;
		
	public:
		//declaramos los setters de las variables
		int setDia();
		int setMes();
		int setAnio();
		//creamos el metodo validar que nos va a verficar si el dia es correcto
		bool validarDia();
		//creamos el metodo validar que nos va a verficar si el mes es correcto		
		bool validarMes();
		//creamos el metodo validar que nos va a verficar si el año es correcto
		bool validarAnio();
		//creamos un menu principal para el usuario
		void Menu(void);
		//creamos un metodo para mostrar la fecha al usuario 
		void mostrarFecha();
};


//Setter del dia: aqui le damos un valor a la variable dia

int Fecha::setDia(){
	
	cout << "\nIngrese dia de nacimiento: ";
	
	cin >> dia;
	
	return dia;
	
}

//Setter del mes: aqui le damos un valor a la variable mes

int Fecha::setMes(){
	
	cout << "\nIngrese mes de nacimiento: ";
	
	cin >> mes;
	
	return mes;
	
}

//Setter del año: aqui le damos un valor a la variable año

int Fecha::setAnio(){
	
	cout << "\nIngrese anio de nacimiento: ";
	
	cin >> anio;
	
	return anio;
	
}

/*
validarDia():	
	Aqui haremos la validacion pertinente al dia
*/
bool Fecha::validarDia(){
		
		if ((dia <= 31) && (dia > 0)){
		
			//dia valido
		
			return true;
			
		}else{	
			
			//si el mes no es valido se le preguntara al usuario
			//hasta que se obtenga una fecha valida verificada
		
		cout << "Dia no valido. Intente de nuevo.";
			
			setDia();		
			validarDia();
			return true;
		}
	
		return false;
}

/*
validarMes();
	Con un switch preguntamos sobre el valor ingresado en mes,
	e iremos preguntando en el caso del mes que haya ingresado el usuario
	tratando las excepciones que son los meses con 30 -> Abril,Junio,Septiembre y Noviembre
	y Febrero -> que no puede ser mayor a 28
*/

bool Fecha::validarMes(){

	if((mes > 0) && (mes <= 12)){
			
				switch(mes){
					case 1:
							//mes valido
							return true;
					case 2:
						if(dia > 0 && dia <29){
							//mes valido
							return true;
						}else{
							cout << "Febrero es un mes de 28 dias\n";
							cout << "Por favor revise la fecha que quiere ingresar, y vuelva a intentarlo mas tarde \n\n";
							setDia();
							setMes();
							validarMes();
							return true;
						}
					case 3:
							//mes valido
							return true;
					case 4:
						if(dia > 0 && dia <=30){
							//mes valido
							return true;
						}else{
							cout << "Abril es un mes de 30 dias\n";
							cout << "Por favor revise la fecha que quiere ingresar, y vuelva a intentarlo mas tarde \n";
							setDia();
							setMes();
							validarMes();
							return true;
						}
					case 5:
							//mes valido
							return true;
					case 6:
						if(dia > 0 && dia <=30){
							//mes valido
							return true;
						}else{
							cout << "Junio es un mes de 30 dias\n";
							cout << "Por favor revise la fecha que quiere ingresar, y vuelva a intentarlo mas tarde \n";
							setDia();
							setMes();
							validarMes();
							return true;
						}
					case 7:
							//mes valido
							return true;
					case 8:
							//mes valido
							return true;
					case 9:
						if(dia > 0 && dia <=30){
							//mes valido
							return true;
						}else{
							cout << "Septiembre es un mes de 30 dias\n";
							cout << "Por favor revise la fecha que quiere ingresar, y vuelva a intentarlo mas tarde \n";
							setDia();
							setMes();
							validarMes();
							return true;
						}			
					case 10:
							//mes valido
							return true;
					case 11:
						if(dia > 0 && dia <=30){
							//mes valido
							return true;
						}else{
							cout << "Noviembre es un mes de 30 dias\n";
							cout << "Por favor revise la fecha que quiere ingresar, y vuelva a intentarlo mas tarde \n";
							setDia();
							setMes();
							validarMes();
							return true;
						}			
					
					case 12:
							//mes valido
							return true;
							
				}
			
	}else{
			//si el mes no es valido se le preguntara al usuario
			//hasta que se obtenga una fecha valida verificada
			cout << "Mes no valido. Intente de nuevo";
			setMes();		
			validarMes();
			return true;
		
	} 
	

	return false;
}

/*
validarAño():	
	Aqui haremos la validacion pertinente al año sin contar
	años biciestos, en un rango de 0 al 2080 como validos
*/
bool Fecha::validarAnio(){

	if ((anio > 0) && (anio < 2080)){
	
		//año valido
		
		return true;
		
	}else{

			//si el año no es valido se le preguntara al usuario
			//hasta que se obtenga una fecha valida verificada

	cout << "Anio no valido. Intente de nuevo.";

	setAnio();
	
	validarAnio();
	
	return true;
		
	}

	return false;

}


/*
mostrarFecha():
Aqui tomamos los datos que ingresa el usuario y evaluamos 
las condiciones que requieren los meses para que sean
validos o no.
*/
void Fecha::mostrarFecha(){

		cout << "\nLa fecha que ha ingresado es valida: \n";
		cout << dia << "/" << mes << "/" << anio << "\n";

}

void Fecha::Menu(){

		
	//Pedimos al usuario el dia
	setDia();
	validarDia();
	
	//Pedimos al usuario el mes	
	setMes();
	validarMes();	

	//Pedimos al usuario el año
	setAnio();
	validarAnio();

	//mostramos al usuario la fecha
	mostrarFecha();

}



