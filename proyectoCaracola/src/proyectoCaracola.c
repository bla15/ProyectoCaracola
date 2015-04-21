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

#define MAX_LENGTH	5

int main(void) {
	char camino=0;
	int totalAlumnos=0;

	Cliente clientes[10];
	Profesor profesores[MAX_LENGTH];
	do{
		printf("\n");
		printf("Bienvenido a la autoescuela Caracola!!!");
		enunciado();
		camino=opcion();

		if(camino=='1'){
			enunciado2();
			registro();

		}

	}while(camino!='3');
	printf("Agur/Adios");

}
