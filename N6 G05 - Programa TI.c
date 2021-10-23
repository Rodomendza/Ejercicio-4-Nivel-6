#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 15
#define CMAX 100

/*Definicion de tipo de dato*/
typedef char TCadena[CMAX];
typedef struct {
    char nombre [CMAX]; /*definicion correcta: TCadena nombre;*/
    int edad;
    long int telefono;
}InfoPaciente;
typedef InfoPaciente Lista [MAX];/*Si trabajan con 15 pacientes diarios porque el tama�o es 100*/


/*Protocolos de funciones y modulos*/
void scanfString(TCadena s, int tam);
void CargarLista(Lista a, int *b); 
void AgregarPaciente(Lista a, int *b); 
void EliminarPaciente(Lista a, int *b);
void MostrarPaciente(Lista a, int b);
void ModificarPaciente(Lista a, int b);
void OrdenarLista(Lista a, int b);
void MostrarLista(Lista a, int b);
void BuscarPaciente(Lista a, int *b, int *c, int d); /*Este es un m�dulo local*/


/*Cuerpo Principal del programa*/

int main(int argc, char **argv)
{
	int n, eleccion;
	
    Lista l1;

	n = 0;

    printf("__________CARGA DE DATOS DE LO 5 PRIMEROS PACIENTES__________");

    CargarLista(l1, &n);
	
	do
	{   /*la selecci�n de la operaci�n a realizar debe ser un modulo, en general 
		se llama menu*/     
		
		printf("\n\n__________MENU DE OPCIONES__________");
		
		printf("\n\n1-Agregar paciente nuevo (El maximo de pacientes es 15)");
		printf("\n2-Eliminar paciente dado un nombre");
		printf("\n3-Mostrar un paciente dado un nombre");
		printf("\n4-Modificar dato de paciente dado un nombre");
		printf("\n5-Ordenar lista por edad de forma descendente");
		printf("\n6-Mostrar lista");
		
		printf("\n\nIngrese '7' para salir");
		
		printf("\n\nEleccion: "); scanf("%d", &eleccion);
		
		system("cls");
		
		switch (eleccion)
		{
		case 1:
			if(n != MAX)
			{
				AgregarPaciente(l1, &n);
			}
			else
			{
				printf("La lista esta llena");
			}
            break;
		case 2: /*Si se realiza el control de tama�o de la lista se debe realizar para todas las operaciones*/
			EliminarPaciente(l1, &n);
            break;
		case 3:
            MostrarPaciente(l1, n);
			break;
		case 4:
			ModificarPaciente(l1, n);
			break;
		case 5:
			OrdenarLista(l1, n);
			break;
		case 6:
			MostrarLista(l1, n);
			break;
		default:
			if(eleccion != 7)
			{
				printf("Debe ingresar una opcion valida");
			}
			break;
		}
	}
	while(eleccion != 7);
	
	return 0;
}

void CargarLista(Lista a, int *b)
{
    int i;
	
    for ( i = 0; i < 5; i++)
    {
		fflush(stdin);/*Esto es un modulo del registro*/
        printf("\nIngrese el nombre del paciente %d : ", i); scanfString(a[i].nombre, CMAX);
        printf("\nIngrese la edad del paciente %d : ", i); scanf("%d", &a[i].edad);
        printf("\nIngrese el numero de telefono del paciente %d : ", i); scanf("%ld", &a[i].telefono);
    }
	
	*b = 5;
}  

void AgregarPaciente(Lista a, int *b)
{
    int i;

    for ( i = *b; i < *b + 1; i++)
    {
        fflush(stdin);/*Esto es un modulo del registro*/
        printf("\nIngrese el nombre del paciente %d : ", i); scanfString(a[i].nombre);
        printf("\nIngrese la edad del paciente %d : ", i); scanf("%d", &a[i].edad);
        printf("\nIngrese el numero de telefono del paciente %d : ", i); scanf("%ld", &a[i].telefono);
    }
	
	*b += 1;
}
/*Ese modulo es una funcion*/
void BuscarPaciente(Lista a, int *b, int *c, int d)/*Esta es la posici�n correcta de este modulo*/
{
	int i;
	char nombre_paciente[CMAX];/*definicion correcta: TCadena nombre_paciente;*/
	
	printf("\nIngrese el nombre del paciente: "); 
	fflush(stdin);
	scanfString(nombre_paciente);/*Falta el tama�o*/
	
	for(i=0;i<d;i++){
		if(strcmp(nombre_paciente, a[i].nombre)==0){ /*deberia usar un modulo compara dos registros por nombres*/
			*b = 1; 
			*c = i; 
			break; 
		}
	} 
}

void EliminarPaciente(Lista a, int *b)
{
	int contador,encontro,posicion; 
	
	encontro = 0; 
	posicion = 0; 
	
	BuscarPaciente(a, &encontro, &posicion, *b);/*mal la definici�n del modulo buscar*/

	if(encontro==1){
		for(contador = posicion; contador < *b; contador++){ /*debe ser un modulo este codigo*/
			strcpy(a[contador].nombre, a[contador + 1].nombre);	
		}
		
		printf("\n\nDatos del paciente %d borrados", posicion);
		*b= *b - 1;
	}
	else
	   printf("\n No se encontro ese nombre \n");

}

void MostrarPaciente(Lista a, int b)
{
	int encontro,posicion; 
	
	encontro = 0; 
	posicion = 0; 
	
	BuscarPaciente(a, &encontro, &posicion, b);

	if(encontro==1)
	{/*deberia usar un modulo mostrar registro*/
		printf("\n\n________Datos del Paciente %d_________", posicion);
		printf("\n\nEl nombre del paciente es : %s", a[posicion].nombre);
		printf("\nLa edad del paciente es : %d", a[posicion].edad);
		printf("\nEl telefono del paciente es : %ld", a[posicion].telefono);
	}
	else
	   printf("\n No se encontro ese nombre \n");
}

void ModificarPaciente(Lista a, int b)
{
	int encontro,posicion; 
	
	encontro = 0; 
	posicion = 0; 

	BuscarPaciente(a, &encontro, &posicion, b);

	if(encontro==1)
	{
		fflush(stdin);/*deberia usar un modulo modificar registro*/
		printf("\n\n________Datos del Paciente %d_________", posicion);
		printf("\n\nEl nombre del paciente es : %s", a[posicion].nombre);
		printf("\nNuevo Nombre: "); scanfString(a[posicion].nombre);
		printf("\nLa edad del paciente es : %d", a[posicion].edad);
		printf("\nNueva edad: "); scanf("%d", &a[posicion].edad);
		printf("\nEl telefono del paciente es : %ld", a[posicion].telefono);
		printf("\nNuevo telefono: "); scanf("%ld", &a[posicion].telefono);
	}
	else
	   printf("\n No se encontro ese nombre \n");
}

void OrdenarLista(Lista a, int b)
{
    int i, j;
    InfoPaciente aux;
	for(i=0; i<b - 1; i++)
	{
		for(j=i+1; j<b; j++)
		{
			if((a[i].edad) < (a[j].edad)) /*deberia usar un modulo Compara dos registros por edad*/
			{
				aux=a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
}

void MostrarLista(Lista a, int b)
{
	int i;
	
	for(i = 0; i < b; i++)
	{
		printf("\n\n________Datos del Paciente %d_________", i);
		printf("\n\nEl nombre del paciente es : %s", a[i].nombre);
		printf("\nLa edad del paciente es : %d", a[i].edad);
		printf("\nEl telefono del paciente es : %ld", a[i].telefono);
		
	}
}


void scanfString(TCadena s, int tam)
{
	char c;
	int j;
	
	j = 0;
	
	while ( j < tam - 1 && (c = getchar()) != EOF && c != '\n')
	{
		s[j] = c;
		j++;
	}
	
	s[j] = '\0';
	
	while (c != EOF && c != '\n')
	{
		c = getchar();
	}
}
