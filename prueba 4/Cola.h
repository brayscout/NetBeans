#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

class Cola
{
	private:
		int dato;
		Cola *siguiente;

	public:
		Cola();
		Cola(int, Cola *);

        int GetDato();
		void SetDato(int argumento);

		Cola* GetCola();
		void SetCola(Cola cola);

		void IngresoCola(Cola *&, Cola *&, int valor);
		void ImprimirCola(Cola *);


};


Cola::Cola()
{

}

int Cola::GetDato()
{
	return dato;
}

void Cola::SetDato(int argumento)
{
	dato = argumento;
}

Cola* Cola::GetCola()
{
	return siguiente;
}

void Cola::SetCola(Cola Cola)
{
	siguiente = Cola.siguiente;
}


void Cola::IngresoCola( Cola *&inicio, Cola *&fin, int valor)
{
	Cola *nuevo = new Cola();

	nuevo->dato = valor;
	nuevo->siguiente = NULL;
	if(inicio == NULL)
    {
        inicio = nuevo;
    }
    else
    {
        fin->siguiente = nuevo;
    }
	fin = nuevo;

}

void Cola::ImprimirCola( Cola *inicio )
{
	Cola *nuevo = new Cola();


	if(inicio!= NULL)
	{
		printf("\n\nCola:");
		do
		{
			nuevo = inicio;
			printf("\n%d", nuevo->dato);
			inicio = inicio->siguiente;
		}while(inicio!= NULL);
	}
	else
	{
		printf("\nCola Vacia");
	}

}
