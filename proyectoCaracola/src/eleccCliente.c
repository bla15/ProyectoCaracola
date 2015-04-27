#include <stdio.h>
#include "nodo.h"

void pedirCita(int totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i){//metodo para reservar citas

	verProfesor(profesores, totalProfesores);
	verVehiculo(vehiculos, totalVehiculos);



	char str[20];
	int dni;
	int matricula;


	printf("Introduce el DNI del profesor para la cita: ");//pide que metamos el dni de un profesor
	fgets(str, 9, stdin);
	sscanf(str, "%d", &dni);
	clear_if_needed(str);

	printf("Introduce la matricula del vehiculo para la cita: ");//pide la matricula de un coche
	fgets(str, 5, stdin);
	sscanf(str, "%d", &matricula);
	clear_if_needed(str);

	if(compDniProf(dni, totalProfesores) && compMatr(matricula, totalVehiculos)){ // Los datos introducidos son correctos
		if(*totalCitas == 0){ // Primera vez que se pide una cita

			citas[0].dniProf = dni;
			citas[0].dniCl = clientes[i].dni;
			citas[0].matricula = matricula;
			(*totalCitas)++;

			printf("Cita reservada.\n");


		}
		else{
			if(compDniCita(dni, *totalCitas) && compMatrCita(matricula, *totalCitas)){ // Los datos introducidos estan libres
				printf("DNI en cita: %d\n", compDniCita(dni, *totalCitas));

				citas[*totalCitas].dniProf = dni;
				citas[*totalCitas].dniCl = clientes[i].dni;
				citas[*totalCitas].matricula = matricula;
				(*totalCitas)++;

				printf("Cita reservada.\n");
			}
			else{
				printf("El profesor y/o vehiculo seleccionado ya esta ocupado.\n\n");
			}

		}
	}
	else{
		printf("DNI y/o matricula insertados incorrectos.\n\n");
	}



}


int compDniProf(int dni, int totalProfesores){//metodo que comprueba si el dni del profesor es valido y devuelve un int

	int i;
	int bool = 0; // false

	for(i = 0; i < totalProfesores; i++){
		if(profesores[i].dni == dni){
			bool++; // true
		}

	}

	if(bool == 0){
		return bool;
	}
	else{
		return 1;
	}
}

int compMatr(int matricula, int totalVehiculos){//para compobar si la matricula es valida
	int i;
	int bool = 0;

	for(i = 0; i < totalVehiculos; i++){
		if(vehiculos[i].matricula == matricula){
			bool++;
		}
	}

	if(bool == 0){
		return bool;
	}
	else{
		return 1;
	}
}

int compDniCita(int dni, int totalCitas){//comprueba el dni de la cita y devuelve un int

	int i;
	int bool = 0;

	for(i = 0; i < totalCitas; i++){
		if(citas[i].dniProf == dni){
			bool++;
		}
	}

	if(bool == 0){
		return 1; // Puede sonar contradictorio, pero no lo es: Si todos los dnis son distintos, devuelve 1, porque señal de que ese profesor esta libre
	}
	else{
		return 0;
	}

}

int compMatrCita(int matricula, int totalCitas){//comprueba la matricula de la cita con lass demas matriculas de las citas

	int i;
	int bool = 0;

	for(i = 0; i < totalCitas; i++){
		if(citas[i].matricula == matricula){
			bool++;
		}
	}

	if(bool == 0){
		return 1;
	}
	else{
		return 0;
	}
}
