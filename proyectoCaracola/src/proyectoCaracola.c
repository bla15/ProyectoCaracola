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
	int totalClientes = 0;
	int totalProfesores = 0;

	Cliente * clientes;
	Profesor * profesores;
	Vehiculo * vehiculos;

	clientes = (Cliente *) malloc (sizeof(Cliente) * MAX_LENGTH_ACL);
	profesores = (Profesor *) malloc (sizeof(Profesor) * MAX_LENGTH_APROF);
	vehiculos = (Vehiculo *) malloc (sizeof(Vehiculo) * MAX_LENGTH_ACH);

	inicializarCoche(vehiculos);

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
			// Aqui, si no se ha registrado ni cliente ni profesor, no podra acceder. tendremos que hacer un if con los dos totales
			// Que quieres listar?
			printf("Que quieres listar?\n1: Cliente\n2: Profesor\n3: Vehiculo\n");
			char opc = opcion();
			switch(opc){
			case '1':
				if(totalClientes == 0){
					printf("No se ha registrado ningun cliente todavía");
				}
				else{
					verCliente(clientes, totalClientes);
				}
			break;
			case '2':
				if(totalProfesores==0){
					printf("No se ha registrado ningun profesor todavía");
				}
				else{
					verProfesor(profesores, totalProfesores);
				}break;
			case '3':
				verVehiculo(vehiculos, MAX_LENGTH_ACH);break;
			}
		}
		else if(camino == '3'){
			// Acceder
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


}
