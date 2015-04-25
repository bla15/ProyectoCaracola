#include <stdio.h>
#include "nodo.h"

void verCliente(Cliente * clientes, int totalClientes){
	int i;
	for(i=0; i<totalClientes; i++){
		printf("El cliente %d\n",i+1);
		printf("Se llama: %s\n",clientes[i].nombre);
		printf("DNI: %d \n", clientes[i].dni);
		printf("Contraseña: %s \n", clientes[i].clave);
		printf("\n");
	}
}
void verProfesor(Profesor * profesores, int totalProfesores){
	int i;
	for(i=0; i<totalProfesores; i++){
		printf("El profesor %d\n",i+1);
				printf("Se llama: %s\n",profesores[i].nombre);
				printf("DNI: %d \n", profesores[i].dni);
				//printf("Contraseña: %s \n", profesores[i].clave);
				printf("\n");
	}
}
void verVehiculo(Vehiculo * vehiculos, int totalVehiculos){
	int i;

		for(i = 0; i < totalVehiculos; i++){
			printf("Matricula: %d\ntipo: %s\ncolor: %s\n\n", vehiculos[i].matricula, vehiculos[i].tipo, vehiculos[i].color);
		}

		//Esto da error. Por que? NO SE PUEDE PONER INT I = 0 DENTRO DE UN FOR
}

void verCitas(Cita * citas, int totalCitas){
	int i;

	for(i = 0; i < totalCitas; i++){
		printf("Cita %d:\nDNI Cliente: %d\nDNI Profesor: %d\nMatricula: %d\n", totalCitas, citas[i].dniCl, citas[i].dniProf, citas[i].matricula);
	}
}
