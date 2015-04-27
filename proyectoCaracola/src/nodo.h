#ifndef NODO_H_
#define _NODO_H_


/* Aqui declararemos las estructuras; tanto de cliente, profesor, vehiculo y cita
 *
 */

typedef struct{
	int dni;
	char * clave;
	char * nombre;
	char * apellido;
	int telefono;
}Cliente;

typedef struct{
	int dni;
	char * clave;
	char * nombre;
	char * apellido;
	int exp;
	int telefono;


}Profesor;

typedef struct{
	int matricula;
	char * tipo;
	char * color;

}Vehiculo;

typedef struct{
	int matricula;
	int dniCl;
	int dniProf;

}Cita;

/* Aqui declaramos los punteros correspondientes a los arrays
 *
 */
Cliente * clientes;
Profesor * profesores;
Vehiculo * vehiculos;
Cita * citas;


//principal
void enunciado();//listado de las diferentes opciones iniciales
char opcion();//para introducir la eleccion

// proyectoCaracola
void inicializarCoche(Vehiculo * coches);
void crearVehiculo(Vehiculo * vehiculos, int index, char tipo [], char color []);

//registro
void enunciadoCliente();//listado de las opciones del registro del cliente
void enunciadoProfesor(); //listado de las opciones del registro del profesor
void registroClientes(Cliente * clientes, int totalClientes);//para introducir los datos del cliente
void registroProfesores(Profesor * profesores, int totalProfesores); //para introducir los datos del profesor
void clear_if_needed(char *str);

//listar
void verCliente(Cliente * clientes, int totalClientes);//listado de todos los clientes
void verProfesor(Profesor * profesores, int totalProfesores); //listado de todos los profesores
void verVehiculo(Vehiculo * vehiculos, int totalVehiculos); //listado de todos los vehiculos
void verCitas(Cita * citas, int totalCitas); //listado de todas las citas

//acceder
int enunciadoAcceder();
void comprobarCP(int *totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int dni);
void entrarCliente(int *totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i);
void entrarProfesores(int totalClientes, int totalProfesores, int * totalCitas, int i);
void opcionesCliente(int * totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i);
void opcionesProfesor(int totalClientes, int totalProfesores, int totalCitas, int i);

//eleccCliente
void pedirCita(int totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i);
int compDniProf(int dni, int totalProfesores);
int compMatr(int matricula, int totalVehiculos);
int compDniCita(int dni, int totalCitas);
int compMatrCita(int matricula, int totalCitas);

//borrarCliente
int seguro();
void eliminarCliente(int *totalClientes, int * totalCitas, int i);

//eleccProfesor
void verCitasProfesor(int totalCitas, int i);
void guardarCitasProfesor(int totalCitas, int i);



#endif
