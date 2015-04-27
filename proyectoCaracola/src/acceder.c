#include <stdio.h>
#include "nodo.h"

int enunciadoAcceder(){//funcion que pregunta el dni al acceder y lo devuelve en el return
	int dni;
	char str[15];
	printf("Por favor introduce tu DNI: ");
	fgets(str,9,stdin);
	sscanf(str, "%d", &dni);
	clear_if_needed(str);

	return dni;
}
void comprobarCP(int * totalClientes, int totalProfesores, int totalVehiculo, int * totalCitas, int dni){//funcion que comprueba si el dni introucido en enunciadoAcceder es de un profesor o de un cliente
	int i=0;
	int j=0;
	for(i=0; i < *totalClientes; i++){//se comprueban los clientes
		if(clientes[i].dni == dni){
			printf("Bienvenido//Egunon señor/señora %s\n",clientes[i].nombre);
			entrarCliente(totalClientes,totalProfesores, totalVehiculo, totalCitas, i);
		}
	}
	for(j=0; j < totalProfesores; j++){//se comprueban los profesores
			if(profesores[j].dni == dni){
				printf("Bienvenido//Egunon señor/señora %s\n",profesores[j].nombre);
				entrarProfesores(totalClientes,totalProfesores, totalCitas, j);
			}
		}
}

void entrarCliente(int* totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i){//metodo que salta si eres cliente y te pregunta la contraseña
	char str[20];
	char temp[20];
	int comp;

	printf("Inserte su contraseña:");
	fgets(str, 20, stdin);
	sscanf(str, "%s", temp);
	clear_if_needed(str);

	comp = strcmp(clientes[i].clave, temp);
	if(comp==0){//si es verdadera la contraseña
		printf("Contraseña CORRECTA\n\n");
		opcionesCliente(totalClientes, totalProfesores, totalVehiculos, totalCitas, i);
	}else{//si es falsa la contraseña
		printf("Contraseña incorrecta!!\n");

	}

}

void entrarProfesores(int totalClientes, int totalProfesores, int * totalCitas, int i){//si eres profesor te pregunta la contraseña
	char str[20];
	char temp[20];
	int comp;

	printf("Inserte su contraseña:\n");
	fgets(str, 20, stdin);
	sscanf(str, "%s", temp);
	clear_if_needed(str);

	comp = strcmp(profesores[i].clave, temp);
	if(comp==0){//si es verdadera la contraseña
		printf("Contraseña CORRECTA\n");
		opcionesProfesor(totalClientes, totalProfesores, *totalCitas, i);

	}else{//si es falsa la contraseña
		printf("Contraseña incorrecta!!\n");

	}
}

void  opcionesCliente(int * totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i){//metodo que posibilita el acceder a diferentes funciones si eres cliente
	char opc;

	printf("1: Para pedir cita\n");
	printf("2: Darse de baja\n");

	opc = opcion();


	switch(opc){
	case '1'://si pulsas uno
		// printf("pasa 1\n");
		pedirCita(*totalClientes, totalProfesores, totalVehiculos, totalCitas, i);
		break;
	case'2'://si pulsas dos
		// printf("pasa2\n");
		if(seguro()==1){
			eliminarCliente(totalClientes, totalCitas, i);



		}else{
			printf("Opcion cancelada\n");
		}
	break;
	}

}

void opcionesProfesor(int totalClientes, int totalProfesores, int totalCitas, int i){//metodo que posibilita el acceder a diferentes funciones si eres profesor

	if(compDniCita(profesores[i].dni, totalCitas) == 0){//si hay citas entra

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
