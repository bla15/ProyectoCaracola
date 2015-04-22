#include <stdio.h>
#include "nodo.h"

void verPantalla(Cliente * clientes, int totalClientes){
	int i;
	for(i=0; i<totalClientes; i++){
		printf("El cliente %d\n",i+1);
		printf("Se llama: %s\n",clientes[i].nombre);
		printf("DNI: %d \n", clientes[i].dni);
		printf("Contraseña: %s \n", clientes[i].clave);
	}
}
