/*
 * eleccProfesor.c

 *
 *  Created on: 27/04/2015
 *      Author: Alumno
 */

#include <stdio.h>
#include "nodo.h"

void verCitasProfesor(int totalCitas, int i){

	int j;

	for(j = 0; j < totalCitas; j++){
		if(profesores[i].dni == citas[j].dniProf){
			printf("Cita %d:\nDNI Cliente: %d\nDNI Profesor: %d\nMatricula: %d\n", totalCitas, citas[i].dniCl, citas[i].dniProf, citas[i].matricula);
		}
	}

}

void guardarCitasProfesor(int totalCitas, int i){

	FILE * f = fopen("citasGuardadas.txt", "w");
	int j;

	if(f == NULL){
		printf("El fichero no se ha abierto correctamente. No se ha podido guardar.\n");
	}
	else{
		for(j = 0; j < totalCitas; j++){

			if(profesores[i].dni == citas[j].dniProf){

				fprintf(f,"Cita %d:\nDNI Cliente: %d\nDNI Profesor: %d\nMatricula: %d\n", totalCitas, citas[i].dniCl, citas[i].dniProf, citas[i].matricula);
			}
		}

		printf("Fichero guardado correctamente!\n");
	}

	fclose(f);
}


