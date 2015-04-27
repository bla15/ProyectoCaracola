#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodo.h"

#define MAX_LENGTH_ACL 10

int seguro(){//metodo que pregunta al usuario si esta dispuesto a borrar su persona de la base de datos
	char str[10];
	int num;
	printf("Vas a elminarte de nuestra base de datos, pulsa '1' si es correcto\n");
	fgets(str, 10, stdin);
	clear_if_needed(str);
	sscanf(str, "%d", &num);
	return num;
}

void eliminarCliente(int *totalClientes, int * totalCitas, int i){//metodo que elimina al cliente
	int z;
	int q;

	Cita * tempCitas = (Cita *) malloc (sizeof(Cita));

	//hacemos una copia del cliente en cuestion
	Cliente * tempClientes = (Cliente *) malloc (sizeof(Cliente));
	tempClientes->nombre= (char *) malloc(sizeof(clientes[i].nombre));
	tempClientes->apellido= (char *) malloc(sizeof(clientes[i].apellido));
	tempClientes->clave= (char *) malloc(sizeof(clientes[i].clave));

	strcpy(tempClientes->nombre,clientes[i].nombre);
	strcpy(tempClientes->apellido,clientes[i].apellido);
	strcpy(tempClientes->clave,clientes[i].clave);
	tempClientes->dni=clientes[i].dni;
	tempClientes->telefono=clientes[i].telefono;

	//primero borramos las citas asociadas a ese cliente
	if(*totalCitas>1){//comprobamos si hay mas de una cita en el array

		for(z=0;z<*totalCitas;z++){//buscamos, desplazamos y ponemos a null los componentes de esa cita
			if(clientes[i].dni==citas[z].dniCl){
				//tempCitas->dniCl=citas[z].dniCl;
				//tempCitas->dniProf=citas[z].dniProf;
				//tempCitas->matricula=citas[z].matricula;

				for(q=z+1;q<*totalCitas;q++){//Si hay una coincidencia desde ese punto corremos el array
					citas[q-1].dniCl=citas[q].dniCl;
					citas[q-1].dniProf=citas[q].dniProf;
					citas[q-1].matricula=citas[q].matricula;
				}

				citas[*totalCitas].dniCl=NULL;
				citas[*totalCitas].dniProf=NULL;
				citas[*totalCitas].matricula=NULL;
				(*totalCitas)--;
			}
		}

	}else{//si solo hay una cita en el array entra
		if(clientes[i].dni==citas[0].dniCl){//comprobamos si la cita guardada es de nuestro cliente
			//tempCitas->dniCl=citas[0].dniCl;
			//tempCitas->dniProf=citas[0].dniProf;
			//tempCitas->matricula=citas[0].matricula;

			citas[0].dniCl=NULL;
			citas[0].dniProf=NULL;
			citas[0].matricula=NULL;
			(*totalCitas)--;
		}

	}
	//ahora se borra el cliente en cuestion ya que no hay ninguna cita asociada a el

	if(*totalClientes>1){//si hay mas de un cliente


		for(z=i+1;z< *totalClientes;z++){//for que corre la lista de los clientes
			//liberamos ese cliente
			free(clientes[z-1].nombre);
			free(clientes[z-1].apellido);
			free(clientes[z-1].clave);
			clientes[z-1].dni= NULL;
			clientes[z-1].telefono= NULL;

			clientes[z-1].nombre= (char *) malloc(sizeof(clientes[z].nombre));
			clientes[z-1].apellido= (char *) malloc(sizeof(clientes[z].apellido));
			clientes[z-1].clave= (char *) malloc(sizeof(clientes[z].clave));

			strcpy(clientes[z-1].nombre,clientes[z].nombre);
			strcpy(clientes[z-1].apellido,clientes[z].apellido);
			strcpy(clientes[z-1].clave,clientes[z].clave);
			clientes[z-1].dni=clientes[z].dni;
			clientes[z-1].telefono=clientes[z].telefono;
		}
		//liberamos la memoria del ultimo elemento
		free(clientes[*totalClientes-1].nombre);
		free(clientes[*totalClientes-1].apellido);
		free(clientes[*totalClientes-1].clave);

		clientes[*totalClientes-1].dni= NULL;
		clientes[*totalClientes-1].telefono= NULL;
		//reducimos el numero de clientes en uno
		(* totalClientes)--;

	}else{

		free(clientes[i].nombre);
		free(clientes[i].apellido);
		free(clientes[i].clave);
		clientes[i].dni= NULL;
		clientes[i].telefono= NULL;
		//reducimos el numero de clientes en uno
		(* totalClientes)--;

	}


}
