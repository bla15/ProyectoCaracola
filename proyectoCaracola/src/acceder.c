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
	int j=0;
	for(i=0; i < totalClientes; i++){
		if(clientes[i].dni == dni){
			printf("Bienvenido//Egunon señor/señora %s\n",clientes[i].nombre);
			entrarCliente(clientes, profesores,totalClientes,totalProfesores, i);
		}
	}
	for(j=0; j < totalProfesores; j++){
			if(profesores[j].dni == dni){
				printf("Bienvenido//Egunon señor/señora %s\n",profesores[j].nombre);
				entrarProfesores(clientes, profesores,totalClientes,totalProfesores, j);
			}
		}
}

void entrarCliente(Cliente * clientes, Profesor * profesores, int totalClientes, int totalProfesores, int i){
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
		opcionesCliente(clientes, profesores, totalClientes, totalProfesores, i);
	}else{
		printf("Contraseña incorrecta!!\n");

	}

}

void entrarProfesores(Cliente * clientes, Profesor * profesores, int totalClientes, int totalProfesores, int i){
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

void  opcionesCliente(Cliente * clientes, Profesor * profesores, int totalClientes, int totalProfesores, int i){
	char opc;
	do{
	printf("1: Para pedir cita\n");
	printf("2: Darse de baja\n");
	printf("3: Salir\n");
	opc = opcion();


	switch(opc){
	case '1':
		printf("pasa 1\n");
		pedirCita();
		break;
	case'2': printf("pasa2\n");
	break;
	}

	}while(opc!='3');
}
