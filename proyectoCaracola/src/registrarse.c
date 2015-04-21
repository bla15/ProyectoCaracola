#include <stdio.h>
#include "nodo.h"

int enunciado2(int totalClientes){
	int total=totalClientes;
	printf("Bienvenido nuevo alumno\n");
	if(total<10){
		registro();
		total++;
		printf("%d",total);
		return total;
	}

	return total;
}

void registro(){
	printf("Introduce tu nombre:\n");
	printf("Introduce tu Nick:\n");
	printf("Introduce tu contraseña:\n");

}

char opcion2Nombre(){

}
