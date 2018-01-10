//ingresar para determinar la cantidad
//funcion que valida si existen multiplos en las estructuras
//recursividad
//funcion que copia
//funcion push

#include "stdlib.h"
#include "stdio.h"
#include "conio.h"

class Pila
{
	private:
		int dato;
		Pila *siguiente;

	public:
		Pila();
		Pila(int, Pila *);

		int GetDato();
		void SetDato(int argumento);

		Pila* GetPila();
		void SetPila(Pila pila);

		IngresoPila(Pila *&, int valor);
		ImprimirPila(Pila *);


};

Pila::Pila()
{
}

Pila::Pila(int num, Pila *pila)
{
	dato = num;

}

int Pila::GetDato()
{
	return dato;
}

void Pila::SetDato(int argumento)
{
	dato = argumento;
}

Pila* Pila::GetPila()
{
	return siguiente;
}

void Pila::SetPila(Pila pila)
{
	siguiente = pila.siguiente;
}


Pila::IngresoPila( Pila *&pila, int valor)
{
	Pila *nuevo = new Pila();

	nuevo->dato = valor;
	nuevo->siguiente = pila;
	pila = nuevo;

}

Pila::ImprimirPila(Pila *pila)
{
	Pila *nuevo = new Pila();


	if(pila!= NULL)
	{
		printf("\n\nPIla:");
		do
		{
			nuevo = pila;
			printf("\n%d", nuevo->dato);
			pila = nuevo->siguiente;
		}while(pila!= NULL);
	}
	else
	{
		printf("\nPila Vacia");
	}

}

