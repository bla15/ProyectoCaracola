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
		printf("MAQUINAAAAAAAAAAAAAA UEHHHHHHHHHHHHHHHHH!\n");
	}else{
		printf("Contraseña incorrecta!!\n");

	}
}

void  opcionesCliente(int * totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i){
	char opc;
	do{
	printf("1: Para pedir cita\n");
	printf("2: Darse de baja\n");
	printf("3: Salir\n");
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
	}while(opc!='3');
}
