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
void comprobarCP(int * totalClientes, int totalProfesores, int totalVehiculo, int * totalCitas, int dni){
	int i=0;
	int j=0;
	for(i=0; i < *totalClientes; i++){
		if(clientes[i].dni == dni){
			printf("Bienvenido//Egunon señor/señora %s\n",clientes[i].nombre);
			entrarCliente(totalClientes,totalProfesores, totalVehiculo, totalCitas, i);
		}
	}
	for(j=0; j < totalProfesores; j++){
			if(profesores[j].dni == dni){
				printf("Bienvenido//Egunon señor/señora %s\n",profesores[j].nombre);
				entrarProfesores(totalClientes,totalProfesores, totalCitas, j);
			}
		}
}

void entrarCliente(int* totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i){
	char str[20];
	char temp[20];
	int comp;

	printf("Inserte su contraseña:");
	fgets(str, 20, stdin);
	sscanf(str, "%s", temp);
	clear_if_needed(str);

	comp = strcmp(clientes[i].clave, temp);
	if(comp==0){
		printf("Contraseña CORRECTA\n\n");
		opcionesCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, i);
	}else{
		printf("Contraseña incorrecta!!\n");

	}

}

void entrarProfesores(int totalClientes, int totalProfesores, int * totalCitas, int i){
	char str[20];
	char temp[20];
	int comp;

	printf("Inserte su contraseña:\n");
	fgets(str, 20, stdin);
	sscanf(str, "%s", temp);
	clear_if_needed(str);

	comp = strcmp(profesores[i].clave, temp);
	if(comp==0){
		printf("Contraseña CORRECTA\n");
		opcionesProfesor(totalClientes, totalProfesores, *totalCitas, i);

	}else{
		printf("Contraseña incorrecta!!\n");

	}
}

void  opcionesCliente(int * totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i){
	char opc;

	printf("1: Para pedir cita\n");
	printf("2: Darse de baja\n");

	opc = opcion();


	switch(opc){
	case '1':
		// printf("pasa 1\n");
		pedirCita(*totalClientes, totalProfesores, totalVehiculos, totalCitas, i);
		break;
	case'2': // printf("pasa2\n");
		if(seguro()==1){
			eliminarCliente(totalClientes, totalCitas, i);



		}else{
			printf("Opcion cancelada\n");
		}
	break;
	}

}

void opcionesProfesor(int totalClientes, int totalProfesores, int totalCitas, int i){

	if(compDniCita(profesores[i].dni, totalCitas) == 0){

		printf("Estas son las citas pendientes que tienes:\n");
		verCitasProfesor(totalCitas, i);

		printf("Que quires hacer?\n1.Guardar\n2.Salir\n");

			char opc = opcion();

			if (opc == '1'){


				guardarCitasProfesor(totalCitas, i);
			}

	}
	else{
		printf("El profesor no tiene ninguna cita reservada");
	}










}
