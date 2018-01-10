#include "Pila.h"
#include "Cola.h"

bool EncontrarPila(Pila *, int multiplo);
bool Multiplo(int A, int B);
void ReemplazarPila(Pila *&pila, int multiplo);
int GenerarPrimos();
int ComprobarNumerosPila(Pila *pila);

int ComprobarNumerosCola(Cola *inicio, Cola *fin);
bool EncontrarCola(Cola *inicio, int multiplo);
void ReemplazarCola(Cola *&inicio, Cola *&fin, int multiplo);

main()
{
	//variables locales
	char a[1];
	int numero=0, i, primo=1;



	// pilas y colas
	//Cola *cola = new Cola();
	Pila *pila;
	pila = NULL;

	Cola *inicio;
	Cola *fin;
	inicio = fin = NULL;



	do
	{
		printf("\n\nIngrese el valor:");
		scanf("%d", &numero);

		pila->IngresoPila(pila, numero);

		fflush(stdin);
		printf("\nDesea ingresar un nuevo valor? (y == ACEPTAR)\n");
		gets(a);
		fflush(stdin);


	}while(a[0]=='y');

	printf("\n\n");
	pila->ImprimirPila(pila);

	/*
	if(Encontrar(pila, 2))
	{
		printf("\nSI HAY");
	}*/

	primo=2;

	do
    {
        do
        {
            ReemplazarPila(pila, primo);
            pila->ImprimirPila(pila);
        }while(EncontrarPila(pila, primo));

        primo++;

    }while( ComprobarNumerosPila(pila)!= 0 );



/*
//COLAS
do
	{
		printf("\n\nIngrese el valor:");
		scanf("%d", &numero);

		inicio->IngresoCola(inicio, fin, numero);

		fflush(stdin);
		printf("\nDesea ingresar un nuevo valor? (y == ACEPTAR)\n");
		gets(a);
		fflush(stdin);


	}while(a[0]=='y');

	printf("\n\n");
	inicio->ImprimirCola(inicio);

/*
	if(EncontrarCola(pila, 2))
	{
		printf("\nSI HAY");
	}
*/
	primo=2;
/*
	do
    {
        do
        {
            ReemplazarCola(inicio, fin, primo);
            inicio->ImprimirCola(inicio);
        }while(EncontrarCola(inicio, primo));

        primo++;

    }while( ComprobarNumerosCola(inicio, fin)!= 0 );



*/

}

bool Multiplo(int A, int B)
{
	if( (A%B)==0 )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool EncontrarPila(Pila *pila, int multiplo)
{
	Pila *nuevo = new Pila();
	int cont=0;

	if(pila!= NULL)
	{
		do
		{
			nuevo = pila;
			if( Multiplo(nuevo->GetDato(), multiplo) )
			{
					cont++;
			}
			pila = nuevo->GetPila();
		}while(pila!= NULL);
	}

	if(cont!=0) return true;
	else return false;

}

void ReemplazarPila(Pila *&pila, int multiplo)
{
	Pila *nuevo = new Pila();
	Pila *nuevo2 = new Pila();
	nuevo = pila;
	nuevo2 = NULL;

	if(pila!= NULL)
	{
		do
		{
			nuevo = pila;
			if( Multiplo(nuevo->GetDato(), multiplo) )
			{
					nuevo->SetDato(nuevo->GetDato() / multiplo);
			}
			nuevo2->IngresoPila(nuevo2, nuevo->GetDato());
			pila = nuevo->GetPila();
		}while(pila!= NULL);
		pila = nuevo2;
	}

}

int ComprobarPrimos(int x)
{
	int cont=0;

	for(int i=1; i<=x; i++)
	{
		if(x%i == 0)
		{
			cont++;
		}
	}

	if(cont==2) return true;
	else return false;
}

int ComprobarNumerosPila(Pila *pila)
{
    Pila *nuevo = new Pila();
	int cont=0;

	if(pila!= NULL)
	{
		do
		{
			nuevo = pila;
			if( nuevo->GetDato() != 1 )
			{
					cont++;
			}
			pila = nuevo->GetPila();
		}while(pila!= NULL);
	}

	if(cont==0) return 0;
	else return cont;
}

int ComprobarNumerosCola(Cola *inicio, Cola *fin)
{
    Cola *nuevo = new Cola();
	int cont=0;

	if(inicio!= NULL)
	{
		do
		{
			nuevo = inicio;
			if( nuevo->GetDato() != 1 )
			{
					cont++;
			}
			inicio = nuevo->GetCola();
		}while(inicio!= NULL);
	}

	if(cont==0) return 0;
	else return cont;
}


bool EncontrarCola(Cola *inicio, int multiplo)
{
	Cola *nuevo = new Cola();
	int cont=0;

	if(inicio!= NULL)
	{
		do
		{
			nuevo = inicio;
			if( Multiplo(nuevo->GetDato(), multiplo) )
			{
                cont++;
			}
			inicio = nuevo->GetCola();
		}while(inicio!= NULL);
	}

	if(cont!=0) return true;
	else return false;

}

void ReemplazarCola(Cola *&inicio, Cola *&fin, int multiplo)
{
    Cola *inicio2 = new Cola();
    Cola *fin2 = new Cola();

    Cola *inicio3 = new Cola();
    Cola *fin3 = new Cola();

    inicio2 = inicio3 = fin2 = fin3 = NULL;

    inicio2 = inicio;
    fin2 = fin;
	//Pila *nuevo = new Pila();
	//Pila *nuevo2 = new Pila();
	//nuevo = pila;
	//nuevo2 = NULL;

	if(inicio2!= NULL)
	{
		do
		{
			inicio2 = inicio;
			if( Multiplo(inicio2->GetDato(), multiplo) )
			{
                inicio2->SetDato(inicio2->GetDato() / multiplo);
			}
			inicio3->IngresoCola(inicio3, fin3, inicio2->GetDato());
			inicio = inicio->GetCola();
		}while(inicio!= NULL);
		inicio = inicio3;
	}

}



