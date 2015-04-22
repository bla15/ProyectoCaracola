#include <stdio.h>
#include "nodo.h"
#define MAX_LENGTH_CL 20


void enunciadoCliente(){

	printf("Bienvenido, nuevo cliente\n");

}

void enunciadoProfesor(){
	printf("Bienvenido, nuevo profesor\n");
}

void registroClientes(Cliente * clientes, int totalClientes){
	char strNom[MAX_LENGTH_CL];
	char tempStr[MAX_LENGTH_CL];
	int dni;


	printf("Introduce tu nombre:\n");
	fgets(strNom,20,stdin);
	sscanf(strNom, "%s", tempStr);
	clear_if_needed(strNom);
	clientes[totalClientes-1].nombre = (char *) malloc (sizeof(char) * strlen(tempStr + 1));
	strcpy(clientes[totalClientes-1].nombre, tempStr);
	// printf("%s", clientes[totalClientes-1].nombre);


	printf("Introduce tu DNI:\n");
	fgets(strNom,9,stdin);
	sscanf(strNom,"%d", &dni);
	clear_if_needed(strNom);
	clientes[totalClientes-1].dni = dni;
	// printf("%d", clientes[totalClientes-1].dni);

	printf("Introduce tu contraseña:\n");
	fgets(strNom,20,stdin);
	sscanf(strNom, "%s", tempStr);
	clear_if_needed(strNom);
	clientes[totalClientes-1].clave = (char *) malloc (sizeof(char) * strlen(tempStr + 1));
	strcpy(clientes[totalClientes-1].clave, tempStr);
	// printf("%s", clientes[totalClientes-1].clave);

	printf("Introduce tu telefono:\n");
	fgets(strNom, 10, stdin);
	sscanf(strNom, "%d", &dni);
	clear_if_needed(strNom);
	clientes[totalClientes-1].telefono =dni;
	//printf("%d", clientes[totalClientes-1].telefono);
	printf("Cliente registrado!\n");

}

void registroProfesores(Profesor * profesores, int totalProfesores){
	char strNom[MAX_LENGTH_CL];
	char tempStr[MAX_LENGTH_CL];
	int dni;

	printf("Introduce tu nombre:\n");
	fgets(strNom,20,stdin);
	sscanf(strNom, "%s", tempStr);
	clear_if_needed(strNom);
	profesores[totalProfesores-1].nombre = (char *) malloc (sizeof(char) * strlen(tempStr + 1));
	strcpy(profesores[totalProfesores-1].nombre, tempStr);
	// printf("%s", clientes[totalClientes-1].nombre);

	printf("Introduce tu DNI:\n");
	fgets(strNom,9,stdin);
	sscanf(strNom,"%d", &dni);
	clear_if_needed(strNom);
	profesores[totalProfesores-1].dni = dni;
	// printf("%d", clientes[totalClientes-1].dni);

	printf("Introduce tu contraseña:\n");
	fgets(strNom,20,stdin);
	sscanf(strNom, "%s", tempStr);
	clear_if_needed(strNom);
	profesores[totalProfesores-1].clave = (char *) malloc (sizeof(char) * strlen(tempStr + 1));
	strcpy(profesores[totalProfesores-1].clave, tempStr);
	// printf("%s", clientes[totalClientes-1].clave);

	printf("Introduce tu telefono:\n");
	fgets(strNom, 10, stdin);
	sscanf(strNom, "%d", &dni);
	clear_if_needed(strNom);
	profesores[totalProfesores-1].telefono =dni;
	//printf("%d", clientes[totalClientes-1].telefono);

	printf("Introduce tus años de experiencia:\n");
	fgets(strNom, 4, stdin);
	sscanf(strNom, "%d", &dni);
	clear_if_needed(strNom);
	profesores[totalProfesores-1].exp=dni;

	printf("Profesor registrado!\n");


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
