#include <stdio.h>
#include "nodo.h"

int enunciado2(int totalClientes){
	int total=totalClientes;
	printf("Bienvenido nuevo alumno\n");
	if(total<10){
		total++;
		printf("%d",total);
		return total;
	}

	return total;
}

void registro(Cliente * clientes, int totalClientes){
	printf("Introduce tu nombre:\n");

	char strNom[30];
	fgets(strNom,30,stdin);
	sscanf(strNom, "%s", clientes[totalClientes-1].nombre);
	printf("%s", clientes[totalClientes-1].nombre);




	printf("Introduce tu Nick:\n");
	printf("Introduce tu contraseña:\n");

}

char opcion2Nombre(){

}
