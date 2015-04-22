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
//principal
void enunciado();//listado de las diferentes opciones iniciales
char opcion();//para introdicir la eleccion
void inicializarCoche(Vehiculo * coches);

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

//acceder
int enunciadoAcceder();
void comprobarCP(Cliente * clientes, Profesor *profesores, int totalClientes, int totalProfesores, int dni);
void entrarCliente(Cliente * clientes, Profesor *profesores, int totalClientes, int totalProfesores, int i);
void entrarProfesores(Cliente * clientes, Profesor * profesores, int totalClientes, int totalProfesores, int i);
void opcionesCliente(Cliente * clientes, Profesor * profesores, int totalClientes, int totalProfesores, int i);
void opcionesProfesor(Cliente * clientes, Profesor * profesores, int totalClientes, int totalProfesores, int i);

//eleccCliente
void pedirCita();

#endif
