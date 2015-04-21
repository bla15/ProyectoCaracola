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
	char strNom[2];

	printf("Introduce tu nombre:\n");
	fflush(stdout);
	fgets(strNom,2,stdin);
	sscanf(strNom, "%c", &((*clientes).nombre));
	clear_if_needed(strNom);
	printf("%c", (*clientes).nombre);
	fflush(stdout);

	printf("Introduce tu Nick:\n");
	printf("Introduce tu contraseña:\n");

}

char opcion2Nombre(){

}

void clear_if_needed(char *str)
{
	if (str[strlen(str) - 1] != '\n')
	{
		int c;
    	while ( (c = getchar()) != EOF && c != '\n');
    }
}
