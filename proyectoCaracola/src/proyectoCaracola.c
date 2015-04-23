/*
 ============================================================================
 Name        : proyectoCaracola.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

#define MAX_LENGTH_APROF 5
#define MAX_LENGTH_ACL 10
#define MAX_LENGTH_ACH 10

int main(void) {

	setvbuf(stdout, 0, _IONBF, 0);

	char camino=0;
	// Cambiar esto cuando quitemos el primer cliente y profesor. Los dos a 0
	int totalClientes = 1;
	int totalProfesores = 1;

	Cliente * clientes;
	Profesor * profesores;
	Vehiculo * vehiculos;

	clientes = (Cliente *) malloc (sizeof(Cliente) * MAX_LENGTH_ACL);
	profesores = (Profesor *) malloc (sizeof(Profesor) * MAX_LENGTH_APROF);
	vehiculos = (Vehiculo *) malloc (sizeof(Vehiculo) * MAX_LENGTH_ACH);

	inicializarCoche(vehiculos);
	// Inicializacion para hacer pruebas mas rapidamente
	clientes[0].dni = 1;
	clientes[0].nombre = "Borja";
	clientes[0].apellido = "Lopez";
	clientes[0].clave = "Alonso";
	clientes[0].telefono = 1;
	// Esto no lo podemos hacer

	profesores[0].dni = 2;
	profesores[0].nombre = "Mireia";
	profesores[0].apellido = "Igartua";
	profesores[0].clave = "Imaz";
	profesores[0].telefono = 1;
	profesores[0].exp = 5;

	// Lo que podemos hacer: Listar (clientes, profesores, coches) ; Borrar ;

	do{
		printf("\n");
		printf("Bienvenido a la autoescuela Caracola!!!");
		enunciado();
		camino=opcion();

		if(camino=='1'){

			printf("1: Registrar como Cliente\n2: Registrar como Profesor\n");
			char opc = opcion();

			if(opc == '1'){

				if(totalClientes< MAX_LENGTH_ACL){
					enunciadoCliente();
					totalClientes++;
					registroClientes(clientes, totalClientes);
				}else{
					printf("Has llenado el limite de clientes\n");
				}

			}
			else if(opc == '2'){
				if(totalProfesores < MAX_LENGTH_APROF){
					totalProfesores++;
					registroProfesores(profesores, totalProfesores);

				}
				else{
					printf("Has llenado el limite de profesores\n");
				}
			}



		}

		else if(camino=='2'){
			char opc;
			// Aqui, si no se ha registrado ni cliente ni profesor, no podra acceder. tendremos que hacer un if con los dos totales
			// Que quieres listar?
			do{


				printf("Que quieres listar?\n1: Cliente\n2: Profesor\n3: Vehiculo\n4: Salir\n");
				opc= opcion();
				switch(opc){
				case '1':
					if(totalClientes == 0){
						printf("No se ha registrado ningun cliente todavía\n");
						printf("\n");
					}
					else{
						verCliente(clientes, totalClientes);
					}
					break;
				case '2':
					if(totalProfesores==0){
						printf("No se ha registrado ningun profesor todavía\n");
						printf("\n");
					}
					else{
						verProfesor(profesores, totalProfesores);
					}break;
				case '3':
					verVehiculo(vehiculos, MAX_LENGTH_ACH);break;
				}
			}while(opc!='4');
		}
		else if(camino == '3'){
			// Acceder
			if(totalClientes+totalProfesores==0){
				printf("No hay ningun dato registrado\n");
			}else{
				int dni = enunciadoAcceder();

				comprobarCP(clientes, profesores, totalClientes, totalProfesores, dni);

			}

		}
		else if(camino == '4'){
			// Borrar
		}

	}while(camino!='5');
	printf("Agur/Adios");


}

void inicializarCoche(Vehiculo * vehiculos){

	vehiculos[0].matricula = 1822;
	vehiculos[0].tipo = "camion";
	vehiculos[0].color = "rojo";
	// Esto en si no se puede hacer, ya que el literal desaparece al cabo del tiempo
	// Meter valores por strcpy. Hacer una funcion (crear o asi) y meter el tipo y color literales

	vehiculos[1].matricula = 2435;
	vehiculos[1].tipo = "coche";
	vehiculos[1].color = "verde";


	vehiculos[2].matricula = 9175;
	vehiculos[2].tipo = "coche";
	vehiculos[2].color = "azul";


	vehiculos[3].matricula = 6837;
	vehiculos[3].tipo = "moto";
	vehiculos[3].color = "rosa";


	vehiculos[4].matricula = 7142;
	vehiculos[4].tipo = "camion";
	vehiculos[4].color = "negro";


	vehiculos[5].matricula = 3485;
	vehiculos[5].tipo = "barco";
	vehiculos[5].color = "blanco";


	vehiculos[6].matricula = 0371;
	vehiculos[6].tipo = "helicóptero";
	vehiculos[6].color = "gris";


	vehiculos[7].matricula = 5377;
	vehiculos[7].tipo = "moto";
	vehiculos[7].color = "amarillo";


	vehiculos[8].matricula = 0067;
	vehiculos[8].tipo = "avión";
	vehiculos[8].color = "gris";


	vehiculos[9].matricula = 8989;
	vehiculos[9].tipo = "coche";
	vehiculos[9].color = "azul marino";

	// PARA BORRAR ARRAYS: CREAR OTRO ARRAY DE UNA POSICION MENOS Y DESTRUIR EL ANTERIOR. MARCAR COMO NO EN USO (DNI = 0);
	// FUNCION REALLOC: COPIA LA MEMORIA DE UN ARRAY A OTRO SITIO. CPLUSPLUS.COM


}
