#include <stdio.h>
#include "nodo.h"

void pedirCita(int totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i){
	verProfesor(profesores, totalProfesores);
	verVehiculo(vehiculos, totalVehiculos);

	char str[20];
	int dni;
	int matricula;
	int j;
	int k;

	printf("Introduce el DNI del profesor para la cita: ");
	fgets(str, 9, stdin);
	sscanf(str, "%d", &dni);
	clear_if_needed(str);

	printf("Introduce la matricula del vehiculo para la cita");
	fgets(str, 5, stdin);
	sscanf(str, "%d", &matricula);
	clear_if_needed(str);

	// HACER QUE EL LO DE ABAJO COMPRUEBE TANTO LA MATRICULA COMO EL PROFESOR. EN ESTOS MOMENTOS SOLO COMPRUEBA EL DNI DEL PROFESOR



	for(j = 0; j < totalProfesores; j++){


		if(profesores[j].dni == dni){ // Esta en profesores
			//printf("pasa\n\n");
			//printf("%d\n\n", *totalCitas);

			if(*totalCitas == 0){

				// Ver si esta libre matricula
				for(k = 0; k < totalVehiculos; k++){
					if(vehiculos[k].matricula == matricula){ // Esta en vehiculos
						citas[0].dniProf = dni;
						citas[0].dniCl = clientes[i].dni;
						citas[0].matricula = matricula;
						(*totalCitas)++;
					}

					// IMPRIMIR SI LA MATRICULA NO ESTA DISPONIBLE.


				}




				// printf("dniProfesor: %d ; dniCliente: %d ; matricula: %d", citas[0].dniProf, citas[0].dniCl, citas[0].matricula);


			}
			else{
				for(k = 0; k < *totalCitas; k++){
					// printf("Posicion k: DNIProf: %d ; DNICl: %d ; matricula: %d", citas[k].dniProf, citas[k].dniCl, citas[k].matricula);
					if(profesores[j].dni != citas[k].dniProf){
						citas[*totalCitas].dniProf = profesores[j].dni;
						citas[*totalCitas].matricula = 1822;

					}
					else{
						printf("El profesor seleccionado ya esta ocupado.\n");
					}
				}
			}

	}

	}









	// Aqui pedir y luego ver que tanto el DNI y la matricula existen y QUE AMBOS ESTAN LIBRES (RECORRER EL ARRAY DE CITAS)



}
