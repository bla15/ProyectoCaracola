#ifndef NODO_H_
#define _NODO_H_




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

Cliente * clientes;
Profesor * profesores;
Vehiculo * vehiculos;
Cita * citas;


//principal
void enunciado();//listado de las diferentes opciones iniciales
char opcion();//para introdicir la eleccion

// proyectoCaracola
void inicializarCoche(Vehiculo * coches);
void crearVehiculo(Vehiculo * vehiculos, int index, char tipo [], char color []);

//registro
void enunciadoCliente();//listado de las opciones del registro
void enunciadoProfesor();
void registroClientes(Cliente * clientes, int totalClientes);//para introducir los datos
void registroProfesores(Profesor * profesores, int totalProfesores);
char opcion2Nombre();
void clear_if_needed(char *str);

//listar
void verCliente(Cliente * clientes, int totalClientes);
void verProfesor(Profesor * profesores, int totalProfesores);
void verVehiculo(Vehiculo * vehiculos, int totalVehiculos);
void verCitas(Cita * citas, int totalCitas);

//acceder
int enunciadoAcceder();
void comprobarCP(int *totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int dni);
void entrarCliente(int *totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i);
void entrarProfesores(int totalClientes, int totalProfesores, int * totalCitas, int i);
void opcionesCliente(int * totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i);
void opcionesProfesor(int totalClientes, int totalProfesores, int * totalCitas, int i);

//eleccCliente
void pedirCita(int totalClientes, int totalProfesores, int totalVehiculos, int * totalCitas, int i);
int compDniProf(int dni, int totalProfesores);
int compMatr(int matricula, int totalVehiculos);
int compDniCita(int dni, int totalCitas);
int compMatrCita(int matricula, int totalCitas);

//borrarCliente
int seguro();
void eliminarCliente(int *totalClientes, int * totalCitas, int i);


#endif
