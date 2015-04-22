#include <stdio.h>
#include "nodo.h"
#define MAX_LENGTH_CL 20


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
	char strNom[MAX_LENGTH_CL];
	char tempStr[MAX_LENGTH_CL];

	printf("Introduce tu nombre:\n");
	fgets(strNom,20,stdin);
	sscanf(strNom, "%s", tempStr);
	clear_if_needed(strNom);
	clientes[totalClientes-1].nombre = (char *) malloc (sizeof(char) * strlen(tempStr + 1));
	strcpy(clientes[totalClientes-1].nombre, tempStr);
	printf("%s", clientes[totalClientes-1].nombre);


	printf("Introduce tu DNI:\n");
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
