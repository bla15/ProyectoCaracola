#include <stdio.h>
#include "nodo.h"

int enunciadoAcceder(){
	int dni;
	char str[15];
	printf("Por favor introduce tu DNI: ");
	fgets(str,9,stdin);
	sscanf(str, "%d", &dni);
	clear_if_needed(str);

	return dni;
}
void comprobarCP(Cliente * clientes, Profesor *profesores, int totalClientes, int totalProfesores, int dni){
	int i=0;
	for(i=0; i < totalClientes; i++){
		if(clientes[i].dni == dni){
			printf("Bienvenido//Egunon señor/señora %s\n",clientes[i].nombre);
			entrarCliente(clientes, i);
		}
	}
	for(i=0; i < totalClientes; i++){
			if(profesores[i].dni == dni){
				printf("Bienvenido//Egunon señor/señora %s\n",profesores[i].nombre);
			}
		}
}

void entrarCliente(Cliente * clientes, int i){
	char str[20];
	char temp[20];
	int comp=0;

	printf("Inserte su contraseña:");
	fgets(str, 20, stdin);
	sscanf(str, "%d", temp);
	clear_if_needed(str);

	comp= strcmp(clientes[i].clave, temp);
	if(comp==0){
		printf("MAQUINAAAAAAAAAAAAAA EHHHHHHHHHHHHHHHHH!\n");
	}else{
		printf("Contraseña incorrecta!!\n");
		printf("%d\n",comp);
	}

}

void entrarProfesores(Profesor * profesores, int i){

}
