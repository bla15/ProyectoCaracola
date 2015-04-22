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

#define MAX_LENGTH_APROF	5
#define MAX_LENGTH_ACL 10

int main(void) {

	setvbuf(stdout, 0, _IONBF, 0);

	char camino=0;
	int totalClientes = 0;

	Cliente * clientes;
	Profesor * profesores;

	clientes = (Cliente *) malloc (sizeof(Cliente) * MAX_LENGTH_ACL);
	profesores = (Profesor *) malloc (sizeof(Profesor) * MAX_LENGTH_APROF);

	do{
		printf("\n");
		printf("Bienvenido a la autoescuela Caracola!!!");
		enunciado();
		camino=opcion();

		if(camino=='1'){
			totalClientes = enunciado2(totalClientes);
			registro(clientes, totalClientes);



		}

	}while(camino!='3');
	printf("Agur/Adios");

}
