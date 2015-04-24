#include <stdio.h>
#include "nodo.h"

void enunciado(){
	printf("\n");
	printf("1: Registrarse\n");
	printf("2: Listar\n");
	printf("3: Acceder\n");
	printf("4: Salir\n");

}

char opcion(){
	char src;
	printf("Elige un numero de las opciones:\n");
	fflush(stdout);
	gets(&src);
	return src;
}
