#ifndef NODO_H_
#define _NODO_H_


typedef struct{
	int dni;
	char * nombre;
	char * apellido;
	int telefono;
}Cliente;

typedef struct{
	int dni;
	char * nombre;
	char * apellido;
	char * exp;
	int telefono;


}Profesor;

typedef struct{
	int matricula;
	char * tipo;
	char * color;

}Coche;
//principal
void enunciado();//listado de las diferentes opciones iniciales
char opcion();//para introdicir la eleccion

//registro
int enunciado2(int totalClientes);//listado de las opciones del registro
void registro(Cliente * clientes, int totalClientes);//para introducir los datos
char opcion2Nombre();
void clear_if_needed(char *str);


#endif
