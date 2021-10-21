/*Ejercicio 4: Crear un programa que permita el ingreso de una lista con una cantidad no determinada de países, sus
correspondientes capitales y el continente al que pertenecen y presente, previo ordenamiento de la lista por
países, el siguiente menú:
a) Dado un país, mostrar su capital.
b) Dada una capital, mostrar el país al que pertenece.
c) Añadir un nuevo país preservando el orden.
d) Dado el nombre de un país, eliminar sus datos.
e) Dado el nombre de un continente, eliminar todos los países que pertenecen al mismo.
f) Mostrar todos los países y sus capitales.*/
/*Se puede editar*/
/*DATOS DE ENTRADA*/

/*TAREAS*/

#include <stdio.h>
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
void BuscarNombre (ListaPais a, int b, int *c); /*3*/
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

    printf("\n\n________CARGA DE LISTA DE PAISES________");

    do
    {
        printf("\n\nIngrese el nombre del pais: "); scanfString(a[i].pais);
        printf("\nIngrese el nombre de la capital: "); scanfString(a[i].capital);
        printf("\nIngrese el nombre del continente"); scanfString(a[i].continente);

        printf("Para continuar la carga ingrese 1"); scanf("%d", carga);

        *b += 1;
        i += 1;
    } 
    while (carga);
    
}

void OrdenarLista(ListaPais a, int b)
{
    printf("\n\nORDENANDO LISTA...");



    printf("\n\nLISTA ORDENADA");
}

void BuscarNombre (ListaPais a, int b, int *c) 
{

}

void MostrarCapital (ListaPais a, int b)
{
    printf("Ingrese el nombre del pais: "); scanfString();

    BuscarNombre ();
}

void MostrarPais (ListaPais a, int b)
{
    printf("Ingrese el nombre de la capital : "); scanfString();

    BuscarNombre ();
}

void AgregarPais (ListaPais a, int *b)
{

}

void EliminarPais (ListaPais a, int *b)
{
    printf("Ingrese el nombre del pais al cual quiere borrar los datos : "); scanfString();

    BuscarNombre ();
}

void EliminarPorContinente (ListaPais a, int *b)
{
    printf("\n\nIngrese el nombre del continente: "); scanfString();

    if ()
    {
        EliminarPais();
    }
}

void MostrarPaisCapital (ListaPais a, int b)
{

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
