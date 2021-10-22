/*Ejercicio 4: Crear un programa que permita el ingreso de una lista con una cantidad no determinada de países, sus
correspondientes capitales y el continente al que pertenecen y presente, previo ordenamiento de la lista por
países, el siguiente menú:
a) Dado un país, mostrar su capital.
b) Dada una capital, mostrar el país al que pertenece.
c) Añadir un nuevo país preservando el orden.
d) Dado el nombre de un país, eliminar sus datos.
e) Dado el nombre de un continente, eliminar todos los países que pertenecen al mismo.
f) Mostrar todos los países y sus capitales.*/
/*Se puede editar x2 jefe*/
/*DATOS DE ENTRADA*/

/*TAREAS*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CMAX 100
#define MAX 200

/*DEFINICION TIPO DE DATOS*/
typedef struct {
    char pais[CMAX];
    char capital[CMAX];
    char continente[CMAX];
}InfoPais;
typedef char TCadena [CMAX];
typedef InfoPais ListaPais[MAX];

/*TARES SOBRE EL REGISTRO*/
void MostrarCapital (ListaPais a, int b); /*1*/
void MostrarPais (ListaPais a, int b); /*1*/

/*TAREAS SOBRE LA LISTA DE REGISTROS*/
void CargarLista (ListaPais a, int *b); /*1*/
void OrdenarLista (ListaPais a, int b); /*3*/
int BuscarPaisNombre (ListaPais a, int b, char c[]); 
int BuscarCapitalNombre (ListaPais a, int b, char c[]); /*3*/
int BuscarContinente (ListaPais a, int b, char c[]);
void AgregarPais (ListaPais a, int *b); /*2*/
void EliminarPais (ListaPais a, int *b); /*2*/
void EliminarPorContinente (ListaPais a, int *b); /*2*/
void MostrarPaisCapital (ListaPais a, int b); /*1*/

/*OTROS*/
unsigned Menu();
void scanfString(TCadena s);

int main() 
{
    int eleccion,n;
    ListaPais L1;

    CargarLista(L1, &n);
    OrdenarLista(L1, n);

    do
    {
	eleccion = Menu();
	
	system ("cls");

	switch (eleccion)
	{
		case 1:
			MostrarCapital(L1, n);
			break;
		case 2:
			MostrarPais(L1, n);
			break;
		case 3:
			AgregarPais(L1, &n);
			break;
		case 4:
			EliminarPais(L1, &n);
			break;
		case 5:
			EliminarPorContinente(L1, n);
			break;
		case 6:
			MostrarPaisCapital(L1, n);
			break;
		default:
			if(eleccion != 7)
			{
				printf("Debe ingresar una opcion valida");
			}
			break;
        }
    }
    while (eleccion != 7);
    

    return 0;
}

void CargarLista (ListaPais a, int *b)
{
    int carga, i;

    *b = 0;
    i = 0;

    printf("________CARGA DE LISTA DE PAISES________");

    do
    {
		fflush(stdin);
        printf("\nIngrese el nombre del pais: "); scanfString(a[i].pais);
        printf("\nIngrese el nombre de la capital: "); scanfString(a[i].capital);
        printf("\nIngrese el nombre del continente: "); scanfString(a[i].continente);

        printf("\n\tPara continuar la carga ingrese 1\n"); 
	printf("\n\tPara finalizar la carga ingrese 0\n");
	printf("\nIngrese 0 o 1: "); scanf("%d", &carga);
		
	system("cls");

        *b += 1;
        i += 1;
    } 
    while (carga);
    
}

void OrdenarLista(ListaPais a, int b)
{
    int i, j;
	ListaPais aux;
	printf("\n\nORDENANDO LISTA...");
	for(i=0; i<b - 1; i++){
		for(j=i+1; j<b; j++){
			if(strcmp(a[i].pais , a[j].pais)==1){
				aux[i] = a[i];
				a[i] = a[j];
				a[j] = aux[i];
			}
		}
	}
	printf("\n\nLISTA ORDENADA");
}

int BuscarPaisNombre (ListaPais a, int b, char c[]) 
{
	int i, f, m, pos;
	pos=0;
	i=0;f=b; m=(i+f)/2;
	while ((i<=f)&&(strcmp(a[m].pais,c)!=0)){
		if (strcmp(a[m].pais,c)==-1)
			i=m+1;
		else 
			f=m-1;
		m=(i+f)/2;
	}
	if (i<=f || strcmp(a[m].pais,c) == 0)
		pos=m;
	else pos=0;
	return pos;
}

int BuscarCapitalNombre (ListaPais a, int b, char c[])
{
	int i, pos;

    pos = 0;
	i = 0;

    while (i <= b && strcmp(a[i].capital, c) != 0)
    {
        i += 1;
    }
    
    if (i <= b)
    {
        pos = i;
    }
    
    return pos;
}

void MostrarCapital (ListaPais a, int b)
{
    int pos;
    char Buscar [CMAX];
	
	fflush(stdin);

    printf("Ingrese el nombre del pais: "); scanfString(Buscar);

    pos = BuscarPaisNombre (a, b, Buscar);

	if (strcmp(a[pos].pais, Buscar) == 0)
	{
		printf("\nLa capital del pais ingresado es: %s", a[pos].capital);
	}
	else
	{
		printf("\nEse pais no se encuentra en la lista o el nombre es incorrecto");
	}
    
}

void MostrarPais (ListaPais a, int b)
{
    int pos;
    char Buscar [CMAX];
	
	fflush(stdin);

    printf("Ingrese el nombre de la capital: "); scanfString(Buscar);

    pos = BuscarCapitalNombre (a, b, Buscar);
	
	printf("\nPosicion= %d", pos);
	
	if (strcmp(a[pos].capital, Buscar) == 0)
	{
		printf("\nEl pais de la capital ingresada es: %s", a[pos].pais);
	}
	else
	{
		printf("\nEsa capital no se encuentra en la lista o el nombre es incorrecto");
	}
}	
    

void AgregarPais (ListaPais a, int *b)
{
int i;
	
	printf("\n\n________AGREGAR PAIS A LA LISTA________");
	
	for ( i = *b; i < *b + 1; i++)
	{
		fflush(stdin);
		printf("\nIngrese el nombre del pais : "); scanfString(a[i].pais);
		printf("\nIngrese el nombre de la capital: : "); scanfString(a[i].capital);
		printf("\nIngrese el nombre del continente  : "); scanfString(a[i].continente);
	}
	*b += 1;
}

void EliminarPais (ListaPais a, int *b)
{
	char Buscar[CMAX];
	int pos, i;

	fflush(stdin);
	
	printf("\nIngrese el nombre del pais que quiere eliminar: "); scanfString(Buscar);
	
	pos = BuscarPaisNombre (a, *b, Buscar);

	if (strcmp(a[pos].pais, Buscar) == 0)
	{
		for(i = *b; i < *b; i++)
		{ 
			strcpy(a[i].pais, a[i + 1].pais);	
		}
	
		*b= *b - 1;
	}
	else
	{
		printf("\nEse pais no se encuentra en la lista");
	}
}

/*void EliminarPorContinente (ListaPais a, int *b)
{
	int pos;
	char Buscar[CMAX];

	printf("\n\nIngrese el nombre del continente: "); scanfString(Buscar);
	
	pos = BuscarContinente (a, *b, Buscar);

	if (strcmp(a[pos].continente, Buscar) == 0)
	{
		for(i = *b; i < *b; i++)
		{ 
			strcpy(a[i].continente, a[i + 1].continente);	
		}
	
		*b= *b - 1;
	}
	else
	{
		printf("\nEse contienente no se encuentra en la lista");
	}
}*/

int BuscarContinente (ListaPais a, int b, char c[])
{
	int i, pos;

    pos = 0;

    while (i <= b && strcmp(a[i].continente, c) != 0)
    {
        i += 1;
    }
    
    if (i <= b)
    {
        pos = i;
    }
    
    return pos;
}


void MostrarPaisCapital (ListaPais a, int b)
{
	int i;
	
	printf("\nPais-Capital\n");
	
	for(i = 0; i < b; i++)
	{
		printf("\n%d) %s-%s", i, a[i].pais, a[i].capital);
		
	}

}

unsigned Menu()
{
    int e;

    printf("\n\n__________MENU DE OPCIONES__________");
		
	printf("\n\n1-Dado un país, mostrar su capital");
	printf("\n2-Dada una capital, mostrar el país al que pertenece");
	printf("\n3-Añadir un nuevo país preservando el orden");
	printf("\n4-Dado el nombre de un país, eliminar sus datos");
	printf("\n5-Dado el nombre de un continente, eliminar todos los países que pertenecen al mismo");
	printf("\n6-Mostrar todos los países y sus capitales");
		
	printf("\n\nIngrese '7' para salir");

    printf("\n\nEleccion: "); scanf("%d", &e);

    return e;
}

void scanfString(TCadena s)
{
	char c;
	int j;
	
	j = 0;
	
	while ( j < CMAX - 1 && (c = getchar()) != EOF && c != '\n')
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
