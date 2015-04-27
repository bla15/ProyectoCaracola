/*
 ============================================================================
 Name        : proyectoCaracola.c

 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Fichero principal: main del proyecto
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

// Definicion de la longitud maxima de los arrays de profesor, ciente, vehiculo y citas
#define MAX_LENGTH_APROF 5
#define MAX_LENGTH_ACL 10
#define MAX_LENGTH_ACH 10
#define MAX_LENGTH_ACIT 5


int main(void) {

	setvbuf(stdout, 0, _IONBF, 0);

	char camino=0;
	// Declaracion de las variables que iran controlando cuantos clientes, profesores o citas se han registrado.
	int totalClientes = 0;
	int totalProfesores = 0;
	int totalCitas = 0;

	// Reservamos el espacio de memoria para los 4 arrays
	clientes = (Cliente *) malloc (sizeof(Cliente) * MAX_LENGTH_ACL);
	profesores = (Profesor *) malloc (sizeof(Profesor) * MAX_LENGTH_APROF);
	vehiculos = (Vehiculo *) malloc (sizeof(Vehiculo) * MAX_LENGTH_ACH);
	citas = (Cita *) malloc (sizeof(Cita) * MAX_LENGTH_ACIT);


	inicializarCoche(vehiculos); // Llamada para inicializar los vehiculos por defecto


	do{
		printf("\n");
		printf("Bienvenido a la autoescuela Caracola!!!");
		enunciado();

		camino=opcion();

		if(camino=='1'){ // Opcion 1: Registro

			printf("1: Registrar como Cliente\n2: Registrar como Profesor\n");
			char opc = opcion();

			if(opc == '1'){ // Registro como cliente

				if(totalClientes< MAX_LENGTH_ACL){ // No se ha llegado al limite
					enunciadoCliente();
					totalClientes++;
					registroClientes(clientes, totalClientes);
				}else{ // Se ha llegado al limite
					printf("Has llenado el limite de clientes\n");
				}

			}
			else if(opc == '2'){ // Registro como profesor
				if(totalProfesores < MAX_LENGTH_APROF){ // No se ha llegado al limite
					totalProfesores++;
					registroProfesores(profesores, totalProfesores);

				}
				else{ // Se ha llegado al limite
					printf("Has llenado el limite de profesores\n");
				}
			}



		}

		else if(camino=='2'){ // Opcion 2: Listar
			char opc;

			do{


				printf("Que quieres listar?\n1: Cliente\n2: Profesor\n3: Vehiculo\n4: Citas\n5: Salir\n");
				opc= opcion();
				switch(opc){
				case '1': // Listar clientes
					if(totalClientes == 0){
						printf("No se ha registrado ningun cliente todavía\n");
						printf("\n");
					}
					else{
						printf("TOTAL CLIENTES: %d\n",totalClientes);
						verCliente(clientes, totalClientes);
					}
					break;
				case '2': // Listar profesores
					if(totalProfesores==0){
						printf("No se ha registrado ningun profesor todavía\n");
						printf("\n");
					}
					else{
						printf("TOTAL PROFESORES: %d\n", totalProfesores);
						verProfesor(profesores, totalProfesores);
					}break;
				case '3': // Listar vehiculos
					printf("TOTAL VEHICULOS: 10\n");
					verVehiculo(vehiculos, MAX_LENGTH_ACH);break;
				case '4': // Listar citas
					if(totalCitas == 0){
						printf("No se ha reservado ninguna cita todavia\n\n");
					}
					else{
						printf("TOTAL CITAS: %d\n", totalCitas);
						verCitas(citas, totalCitas);
					}
				}
			}while(opc!='5');
		}
		else if(camino == '3'){ // Opcion 3: Acceder

			if(totalClientes+totalProfesores==0){
				printf("No hay ningun dato registrado\n");
			}else{
				int dni = enunciadoAcceder();
				// Comprobacion si el dni insertado pertenece a cliente, profesor o es incorrecto
				comprobarCP(&totalClientes, totalProfesores, MAX_LENGTH_ACH, &totalCitas, dni);

			}

		}

	}while(camino!='4'); // Opcion 4: Salir

	// Liberamos la memoria
	// Clientes
	int i;

	for(i = 0; i < totalClientes; i++){

		free(clientes[i].nombre);
		free(clientes[i].apellido);
		free(clientes[i].clave);
	}

	free(clientes);

	// Profesores
	for(i = 0; i < totalProfesores; i++){

		free(profesores[i].nombre);
		free(profesores[i].apellido);
		free(profesores[i].clave);
	}

	free(profesores);

	// Vehiculos
	for(i = 0; i < MAX_LENGTH_ACH; i++){

		free(vehiculos[i].tipo);
		free(vehiculos[i].color);
	}

	free(vehiculos);

	// Citas

	free(citas);

	printf("Agur/Adios");




}

void inicializarCoche(Vehiculo * vehiculos){ // Inicializacion de los vehiculos con valoes predeterminados

	vehiculos[0].matricula = 1822;
	crearVehiculo(vehiculos, 0, "camion", "rojo");


	vehiculos[1].matricula = 2435;
	crearVehiculo(vehiculos, 1, "coche", "verde");


	vehiculos[2].matricula = 9175;
	crearVehiculo(vehiculos, 2, "coche", "azul");


	vehiculos[3].matricula = 6837;
	crearVehiculo(vehiculos, 3, "moto", "rosa");


	vehiculos[4].matricula = 7142;
	crearVehiculo(vehiculos, 4, "camion", "negro");


	vehiculos[5].matricula = 3485;
	crearVehiculo(vehiculos, 5, "barco", "blanco");


	vehiculos[6].matricula = 0371;
	crearVehiculo(vehiculos, 6, "helicoptero", "gris");


	vehiculos[7].matricula = 5377;
	crearVehiculo(vehiculos, 7, "moto", "amarillo");


	vehiculos[8].matricula = 0067;
	crearVehiculo(vehiculos, 8, "avion", "gris");


	vehiculos[9].matricula = 8989;
	crearVehiculo(vehiculos, 9, "coche", "azul marino");


}

void crearVehiculo(Vehiculo * vehiculos, int index, char tipo[], char color[]){ // Creacion de vehiculos
	char aTipo[20];
	char aColor[20];
	int i;
	int j;

	for(i = 0; i < strlen(tipo) + 1; i++){
		aTipo[i] = tipo[i];
	}

	for(j = 0; j < strlen(color) + 1; j++){
		aColor[j] = color[j];
	}

	vehiculos[index].tipo = (char *) malloc (sizeof(char) * (strlen(aTipo) + 1));
	vehiculos[index].color = (char *) malloc (sizeof(char) * (strlen(aColor) + 1));

	strcpy(vehiculos[index].tipo, aTipo);
	strcpy(vehiculos[index].color, aColor);
}
