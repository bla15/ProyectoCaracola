#ifndef NODO_H_
#define _NODO_H_

//principal
void enunciado();//listado de las diferentes opciones iniciales
char opcion();//para introdicir la eleccion

//registro
void enunciado2();//listado de las opciones del registro
void registro();//para introducir los datos
char opcion2Nombre();

typedef struct{
	char dni;
	char nombre;
	char apellido;
	char telefono;
}Cliente;

typedef struct{
	char dni;
	char nombre;
	char apellido;
	char exp;
	char telefono;


}Profesor;

typedef struct{
	char matricula;
	char tipo;
	char color;

}Coche;
#endif
