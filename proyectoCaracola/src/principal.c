#include <stdio.h>
#include "nodo.h"

void enunciado(){ // Enunciado del menu principal
	printf("\n");
	printf("1: Registrarse\n");
	printf("2: Listar\n");
	printf("3: Acceder\n");
	printf("4: Salir\n");


}

char opcion(){ // Funcion que usamos para leer la opcion que ha seleccionado el usuario
	char src;
	printf("Elige un numero de las opciones:\n");
	fflush(stdout);
	gets(&src);
	return src;
}
