#include <cstdlib>
#include <iostream>
#include <time.h>
#include "lib.hpp"


using namespace std;


Cola Crear_Cola(void)
{
	struct pasajero *nodo_aux, *nodo_aux2;

	Cola c = new struct LaCola;

	c->primero = new struct pasajero;
	c->ultimo = new struct pasajero;

	c->ultimo = NULL;
	c->primero->sig = NULL;

	return(c);
}


bool Cola_Vacia (Cola c)
{
    if(c->ultimo == NULL)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}


void Insertar_Pasaporte (Cola c, int tipo)
{
    int tipo_ciudadano;
    char nombre[20];
    string nacionalidad, numero_pasaporte;
    bool aux;

    struct pasajero *nodo_aux;

    nodo_aux = new struct pasajero;
    nodo_aux->tipo_ciudadano = tipo;

    cout << "Numero del pasaporte: ";
    cin >> numero_pasaporte;
    nodo_aux->numero_pasaporte = numero_pasaporte;

    cout << "Pais: ";
    cin >> nacionalidad;
    nodo_aux->nacionalidad = nacionalidad;

    nodo_aux->estado_pasaporte = false;


    if(Cola_Vacia(c))
    {
        c->primero->sig = nodo_aux;
        nodo_aux->sig = NULL;
        c->ultimo = nodo_aux;
    }
    else
    {
        c->ultimo->sig = nodo_aux;
        c->ultimo = nodo_aux;
        c->ultimo->sig = NULL;
    }

}


void EliminarElemento (Cola c)
{
    struct pasajero *nodo_aux;

    nodo_aux = new struct pasajero;

    if(Cola_Vacia(c))
    {
        cout << "Lo sentimos, no se puede eliminar un elemento ya que la cola se encuentra vacia." << endl;
    }
    else
    {
        if(c->primero->sig == c->ultimo)
		{
			c->primero->sig = NULL;
			c->ultimo = NULL;
			delete(c->primero->sig);
		}
		else
		{
			c->primero->sig = nodo_aux;
			c->primero = nodo_aux->sig;
			delete(nodo_aux);
		}
    }
}


void MostrarCola (Cola c)
{
    struct pasajero *nodo_aux;

    nodo_aux = new struct pasajero;

    nodo_aux = c->primero->sig;

    while(nodo_aux != NULL)
    {
        cout << nodo_aux->numero_pasaporte << " ";
        nodo_aux = nodo_aux->sig;
    }

    cout << endl;
}


void VerCola (Cola c)
{
	if(Cola_Vacia(c))
	{
		cout << "La cola esta vacia\n";
	}
	else
	{
		struct pasajero *nodo_aux;

		nodo_aux = new struct pasajero;

		nodo_aux = c->primero->sig;

		while(nodo_aux != NULL)
		{
			if(nodo_aux->sig == NULL)
			{
				cout << nodo_aux->numero_pasaporte << endl;
			}

			nodo_aux=nodo_aux->sig;

		}
	}
}


string Nacionalidades()
{
    string pais;

    int i;
    i = 1 + rand()%21;

    switch(i)
    {
        case 1:
            pais = "Espana";
        break;

        case 2:
            pais = "Francia";
        break;

        case 3:
            pais = "Italia";
        break;

        case 4:
            pais = "Alemania";
        break;

        case 5:
            pais = "Portugal";
        break;

        case 6:
            pais = "ReinoUnido";
        break;

        case 7:
            pais = "Suiza";
        break;

        case 8:
            pais = "Noruega";
        break;

        case 9:
            pais = "Rusia";
        break;

        case 10:
            pais = "China";
        break;

        case 11:
            pais = "India";
        break;

        case 12:
            pais = "Japon";
        break;

        case 13:
            pais = "Australia";
        break;

        case 14:
            pais = "Canada";
        break;

        case 15:
            pais = "EEUU";
        break;

        case 16:
            pais = "Mexico";
        break;

        case 17:
            pais = "Brasil";
        break;

        case 18:
            pais = "Argentina";
        break;

        case 19:
            pais = "Chile";
        break;

        case 20:
            pais = "Marruecos";
        break;

        case 21:
            pais = "Sudafrica";
        break;
    }
}


string Pasaporte()
{
    string pasaporte;

    string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char aux[9];

    char letra1 = letras[rand()%25];
    char letra2 = letras[rand()%25];
    char letra3 = letras[rand()%25];
    char letra4 = letras[rand()%25];

    sprintf(aux, "%c%c%d%d%d%d%d%c%c", letra1, letra2, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, letra3, letra4);
    pasaporte = aux;

    return (pasaporte);

}


int Tipo_Pasajero()
{
    int num;

    num = 1 + rand()%4;

    return (num);
}


char* Generacion_Nombre()
{
    char strrnd[20];

    srand(time(NULL));

    for(int i=0; i <= 19; i++)
    {
        strrnd[i] = 33 + rand() % (126 - 33);
    }

    return (strrnd);
}


bool Estado_Pasaporte()
{
    int probabilidad;

    probabilidad = 1 + rand()%4;

    if(probabilidad == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}


string Insertar_Pasaporte_Aleatorio (Cola c, int tipo)
{
    char *nombre;
    int tipo_ciudadano;
    string numero_pasaporte, nacionalidad;

    struct pasajero *nodo_aux;
    nodo_aux = new struct pasajero;

    nodo_aux->nombre = Generacion_Nombre();
    nodo_aux->tipo_ciudadano = tipo;
    nodo_aux->numero_pasaporte = Pasaporte();
    nodo_aux->nacionalidad = Nacionalidades();
    nodo_aux->estado_pasaporte = Estado_Pasaporte();

    if(Cola_Vacia(c))
    {
        c->primero->sig = nodo_aux;
        nodo_aux->sig = NULL;
        c->ultimo = nodo_aux;
    }
    else
    {
        c->ultimo->sig = nodo_aux;
        c->ultimo = nodo_aux;
        c->ultimo->sig = NULL;
    }

    return (numero_pasaporte);
}


string EliminarElementoAleatorio (Cola c)
{
    struct pasajero *nodo_aux;
    string pasaporte = "________";

    nodo_aux = new struct pasajero;
    nodo_aux = c->primero->sig;

    if(Cola_Vacia(c))
    {
        return (pasaporte);
    }
    else
    {
        if(c->primero->sig == NULL)
        {
            c->ultimo = NULL;
            c->primero->sig = NULL;
            pasaporte = c->primero->sig->numero_pasaporte;
            delete (c->primero->sig);

            return (pasaporte);
        }
        else
        {
            c->primero->sig = nodo_aux;
            pasaporte = nodo_aux->numero_pasaporte;
            c->primero = nodo_aux->sig;
            delete (nodo_aux);

            return (pasaporte);
        }
    }
}


string RecorrerCola (Cola c)
{
    struct pasajero *nodo_aux;
	string pasaporte = "________";

	nodo_aux = new struct pasajero;

	if(Cola_Vacia(c))
	{
		return (pasaporte);
	}
	else
	{
		if(c->primero->sig == NULL)
		{
			pasaporte = c->ultimo->numero_pasaporte;
			return (pasaporte);
		}
		else
		{
			c->primero->sig = nodo_aux;
			pasaporte = nodo_aux->numero_pasaporte;
			c->primero->sig = nodo_aux->sig;
			c->ultimo = nodo_aux;
			c->ultimo->sig = NULL;
			return (pasaporte);
		}
	}
}
