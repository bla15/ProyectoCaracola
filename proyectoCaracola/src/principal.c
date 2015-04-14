#include <stdio.h>
#include "nodo.h"

void enunciado(){
	printf("\n");
	printf("1: Registrarse\n");
	printf("2: Acceder\n");
	printf("3: Para salir\n");
}

char opcion(){
	char src;
	printf("Elige un numero de las opciones:\n");
	fflush(stdout);
	gets(&src);
	return src;
}
