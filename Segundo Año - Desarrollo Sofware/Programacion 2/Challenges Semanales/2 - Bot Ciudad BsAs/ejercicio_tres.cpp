/*
EJERCICIO 3:
Observar BOTI del Gobierno de la ciudad de Buenos Aires, analizar como trabaja, explicarlo y desarrollar uno simple
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
//incluimos la libreria para usar la funcion rand() que nos genera numeros al azar, la usaremos para
//generar el numero de orden
#include <cstdlib>

using namespace std;

	class Bot{
		
		//Declaramos e inicializamos los arreglos tanto de hospitales como de especialidades 
		private:string hospitales[4] = {"Pirovano", "Tornu", "Zubizarreta","Fernandez"};
		private:string especialidad[4] = {"Traumatologia", "Pediatria", "Neurologia", "Medico Clinico"};
		private:string barrios[6] = {"Recoleta","Palermo","Belgrano","Villa Urquiza","Saavedra","Barrio Norte"};
		private:string bandas[4] = {"Tributo a Mozart", "Jorge Drexler", "Fito Paez", "Catupecu Machu"};
		private:string peliculas[6] = {"La Cienaga", "El Aura", "Relatos Salvajes", "El secreto de sus ojos", "Nueve Reinas", "Un Cuento Chino"};
		private:string gastronomia[4] = {"El Festival de Comida Armenia", "Pizza Party", "celebracion Hamburgesas para todos!!", "Foodtrucks de Tacos Mexicanos"};
	
		
		//Aqui declaramos los metodos que usaremos para este simple bot
		public:
			//Tendremos un menu que sera el eje del bot
			void Menu(void);
			//La primera opcion sera un metodo para pedir el turno
			void pedirTurno(void);
			//la segunda opcion sera un metodo para solicitar el arreglo de la vereda
			void arreglarVereda(void);
			//la tercera opcion sera un metodo para saber sobre donde salir y festivales
			void espectaculosGastronomia(void);
			//funciones auxiliares:
			void generarOrden(int, int);
	};
	
	int main(void){
		
		//inicalizamos el bot
		Bot boti;
		
		//Desplegamos el menu
		boti.Menu();	
		
		//finaliza el programa
		return 0;
	}
	
	/*
	generarOrden -> Esta funcion toma como dos parametros las opciones que hayamos elegido en la funcion pedirTurno(), 
	y nos devuelve un impresion en pantalla con un numero de orden generado en forma aleatoria y las opciones
	elegidas tanto como del hospital como de la especialidad
	*/
	
	void Bot::generarOrden(int opcion_uno, int opcion_dos){
		
		//Gracias a la funcion rand() generamos un numero al azar entre 0 y 300 
		int numeroDeOrden = rand() % 300+1;
		
		//La salida por pantalla del lugar de la atencion, la especialidad y la orden
		cout << "Su orden en el hospital " << hospitales[opcion_uno] << " en la especialidad " << especialidad[opcion_dos] << " con la orden " << numeroDeOrden << "\n"; 
			
	}
	
	/*
	pedirTurno() -> En este metodo permite elegir entre los hospitales y las especialides para poder conseguir un turno
	una vez que hayamos elegido las opciones deseadas llamara a generarOrden() para mostrar por pantalla la orden conseguida.
	Posterior a eso podemos seguir sacando turnos o volver al menu()
	
	*/
	void Bot::pedirTurno(){
		
		//Declaramos las opciones a elegir tanto del hospital como de la especializacion
		int opcionHospital;
		int opcionEspecialidad;
		//Declaramos nuestra condicion de salida del bucle
		int salir;
	
	//Usamos un ciclo while para ir explorando poco a poco las opciones, su condicion de salida
	//sera que la variable salir sea igual a 2, 
		while(salir != 2){
		
		cout << "Elija una opcion entre el listado de hospitales:  \n";
		
		//Recorremos el arreglo de hospitales mostrandole al usuario las opciones disponibles a elegir	
		for (int i = 0; i < 4; i++){
			cout << (i+1) << " - " << hospitales[i] << "\n";
		}
	
		cout << "\n";
	
		//pedimos al usuario que elija su hospital deseado
		cout << "Opcion: ";
		cin >> opcionHospital;
		
		cout << "\n";
		
		//Validamos que la opcion sea correcta para continuar con el proceso
		//de generar el turno
		if(opcionHospital > 0 && opcionHospital < 5){
		
		//Una vez que es valido proseguimos en el proceso de eleccion
		cout << "Elija una opcion entre el listado de especialidades: \n";
		
		//Recorremos el arreglo de especialidades mostrandole al usuario las opciones disponibles a elegir	
		for (int j = 0; j < 4; j++){
			cout << (j+1) << " - " << especialidad[j] << "\n";
		}
		
		cout << "\n";
		
		//pedimos al usuario que elija su especialidad deseada
		cout << "Opcion: ";
		cin >> opcionEspecialidad;
		cout << "\n";
		
				//Validamos que la opcion sea correcta para continuar con el proceso
				//de generar el turno
			if(opcionEspecialidad > 0 && opcionEspecialidad < 5){
		
				//Una vez ya teniendo todas las opciones generamos una orden usando el metodo generarOrden()
					generarOrden(opcionHospital - 1, opcionEspecialidad - 1);
			}else{
				//La opcion no fue valida por lo tanto se procede a preguntar de nuevo
				cout << "\nOPCION INCORRECTA INTENTELO NUEVAMENTE\n";
			
			}
			
		
		}else{
				//La opcion no fue valida por lo tanto se procede a preguntar de nuevo
				cout << "\nOPCION INCORRECTA INTENTELO NUEVAMENTE\n";
			
		}
		
		//Una vez generada la orden. Desplegamos un peque?o menu
		//para preguntar al usuario si quiere continuar o no
		cout << "\n";
		cout << "Desea continuar o salir\n\n";
		cout << "1 - Sacar otro turno\n";
		cout << "2 - Salir\n\n";
		
				cout << "Opcion: ";
				cin >> salir;
				cout << "\n";
		//Si la opcion es 2 salimos, de lo contrario podremos generar otra orden
		
		}
		
	}
	
	/*
	arreglarVereda() -> Este metodo lo unico que hara sera tomar 3 strings con los datos de direccion
	numero y codigo postal para poder enviar una cuadrilla a arreglar la vereda.
	*/
	
	void Bot::arreglarVereda(){
		
		//declaramos las variables strings de los datos
		string direccion, numero, codigoPostal;
		//creamos una variable aleatoria para que nos de un estimado de dias
		//al azar en que sera arreglada la vereda
		int diasDemora = rand() % 31+1;
		
		//pedimos al usuario que ingrese los datos
		cout << "Ingrese la direccion de su casa: \n";
		cin  >> direccion;
		cout << "Ingrese el numero de su casa: \n";
		cin  >> numero;
		cout << "Ingrese su Codigo Postal: \n";
		cin  >> codigoPostal;
		
		//una vez que los datos han sido cargados con exito se procede a mostrar un mensaje de exito de la operacion
		cout << "Una cuadrilla sera enviada a " << direccion << " " << numero << " con el codigo postal " << codigoPostal << " en un lapso de " << diasDemora << " dias."; 
		cout << "\n\nGracias por su informe\n\n";
	}
	
	/*
	espectaculosGastronomia() -> este metodo nos dara unas opciones para disfrutar en la semana
	nos guiaremos a partir de una eleccion y el boti jr nos recomendara la mejor opcion
	*/
	
	void Bot::espectaculosGastronomia(){
		
		//declaramos una variable eleccion para que nos guie en las opciones
		int eleccion = 4;
		//generamos un numero al azar para las peliculas y barrios entre 0 y 6
		int rand_barrios_peliculas = rand() % 6;
		//generamos un numero al azar para la musica y gastronomia entre 0 y 4
		int rand_musica_gastronomia = rand() % 4;
	
		//Creamos un menu para el usuario
		cout << "BA-Cultura\n";
		cout << "Ingrese su numero para saber el tipo de evento que prefiere\n\n";
				
			
				cout << "\n1- Gastronomia.\n";
				cout << "2- Cine.\n";
				cout << "3- Musica.\n";
				cout << "4- Salir\n";	
		
				cout << "\nElija una opcion: ";
				cin >> eleccion;
				cout << "\n";
		
			//Con un switch a partir de la eleccion del usuario nos dara
			//una recomendacion boti jr
			switch(eleccion){
				case 1:
					cout << "Esta semana puedes celebrar " << gastronomia[rand_musica_gastronomia] << " en " << barrios[rand_barrios_peliculas] << "\n\n";
					break;
				case 2:
					cout << "Esta semana puedes disfrutar " << peliculas[rand_barrios_peliculas] << " en cualquier cine de " << barrios[rand_barrios_peliculas] << "\n\n";	
					break;		
				case 3:
					cout << "Esta semana se presenta en vivo " << bandas[rand_musica_gastronomia] << " en el parque de " << barrios[rand_barrios_peliculas] << "\n\n";
					break;
				case 4:
					break;
				default:
					//en caso de no ingresar nada valido : mensaje de error al usuario
					cout << "\nOpcion no valida, intentalo otra vez ! Ten una buen semana!! \n\n";	
		}
		
		
		
	}
	
	
	void Bot::Menu(){
		
		//variable opcion que sera el eje de nuestro menu
		int opcion;
		
		//con un while podemos explorar las opciones que ingreso el usuario
		while(opcion != 4){
				
				cout << "BOTI jr - Ciudad de Buenos Aires\n";
				cout << "\n1- Pedir turno en el hospital.\n";
				cout << "2- Solicitar arreglo de vereda.\n";
				cout << "3- BA-Cultura: Espectaculos y gastronomia.\n";
				cout << "4- Salir\n";	
		
				cout << "\nElija una opcion: ";
				cin >> opcion;
				cout << "\n";
				
				//de acuerdo a la opcion del usuario entraremos en una funcion que nos hara 
				//entrar la opcion deseada
				switch(opcion){
					case 1:
						pedirTurno();
						break;
					case 2:
						arreglarVereda();
						break;
					case 3:
						 espectaculosGastronomia();	
						 break;	
				}	
				
		}
		
		cout << "Gracias por usar Boti jr";
		
	}

