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
void MostrarCapital (ListaPais a, int b); 
void MostrarPais (ListaPais a, int b); 

/*TAREAS SOBRE LA LISTA DE REGISTROS*/
void CargarLista (ListaPais a, int *b); 
void OrdenarLista (ListaPais a, int b); 
/*
int BuscarPaisNombre (ListaPais a, int b, int *c); 
int BuscarCapitalNombre (ListaPais a, int b, int *c); /
void AgregarPais (ListaPais a, int *b); 
void EliminarPais (ListaPais a, int *b); 
void EliminarPorContinente (ListaPais a, int *b); */
void MostrarPaisCapital (ListaPais a, int b); 


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
        printf("\n\nIngrese el nombre del pais: "); scanfString(a[i].pais);
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
		
	printf("\n\n1-Dado un pais, mostrar su capital");
	printf("\n2-Dada una capital, mostrar el pais al que pertenece");
	printf("\n3-Agregar un nuevo pais preservando el orden");
	printf("\n4-Dado el nombre de un pais, eliminar sus datos");
	printf("\n5-Dado el nombre de un continente, eliminar todos los paises que pertenecen al mismo");
	printf("\n6-Mostrar todos los paises y sus capitales");
		
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
