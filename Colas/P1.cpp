#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include <cstdio> 

#include "lib.hpp"

using namespace std;

// Crear una cola vacía 
Cola Crear_Cola()
{
    Cola c = new struct LaCola;
    c->primero = new struct pasajero;
    c->primero->sig = NULL;
    c->ultimo = NULL;
    return c;
}

// Verificar si la cola está vacía
bool Cola_Vacia(Cola c)
{
    return (c->ultimo == NULL);
}

// Insertar pasajero manualmente
void Insertar_Pasaporte(Cola c, int tipo)
{
    string numero_pasaporte, nacionalidad;
    struct pasajero *nodo_aux = new struct pasajero;

    cout << "Numero de pasaporte (formato LLDDDDDLL): ";
    cin >> numero_pasaporte;
    nodo_aux->numero_pasaporte = numero_pasaporte;

    cout << "Nombre: ";
    cin >> nodo_aux->nombre;  

    cout << "Nacionalidad: ";
    cin >> nacionalidad;
    nodo_aux->nacionalidad = nacionalidad;

    nodo_aux->tipo_ciudadano = tipo;
    nodo_aux->estado_pasaporte = false; // se simulará después
    nodo_aux->sig = NULL;

    if (Cola_Vacia(c))
    {
        c->primero->sig = nodo_aux;
        c->ultimo = nodo_aux;
    }
    else
    {
        c->ultimo->sig = nodo_aux;
        c->ultimo = nodo_aux;
    }
}

// Eliminar el primer pasajero de la cola
void EliminarElemento(Cola c)
{
    if (Cola_Vacia(c))
    {
        cout << "Lo sentimos, no se puede eliminar un elemento ya que la cola se encuentra vacia." << endl;
        return;
    }

    struct pasajero* nodo_aux = c->primero->sig;
    string pasaporte = nodo_aux->numero_pasaporte;

    if (c->primero->sig == c->ultimo)
    {
        c->primero->sig = NULL;
        c->ultimo = NULL;
    }
    else
    {
        c->primero->sig = nodo_aux->sig;
    }

    delete nodo_aux;
    cout << "Pasajero eliminado: " << pasaporte << endl;
}

// Mostrar todos los pasajeros de la cola
void MostrarCola(Cola c)
{
    struct pasajero* nodo_aux = c->primero->sig;
    while (nodo_aux != NULL)
    {
        cout << nodo_aux->numero_pasaporte << " ";
        nodo_aux = nodo_aux->sig;
    }
    cout << endl;
}

// Consultar el primer pasajero en la cola
void VerCola(Cola c)
{
    if (Cola_Vacia(c))
    {
        cout << "La cola esta vacia" << endl;
    }
    else
    {
        cout << "Primer pasajero: " << c->primero->sig->numero_pasaporte << endl;
    }
}

// Generar nacionalidad aleatoria
string Nacionalidades()
{
    string paises[] = {
        "Espana", "Francia", "Italia", "Alemania", "Portugal",
        "ReinoUnido", "Suiza", "Noruega", "Rusia", "China",
        "India", "Japon", "Australia", "Canada", "EEUU",
        "Mexico", "Brasil", "Argentina", "Chile", "Marruecos", "Sudafrica"
    };
    int idx = rand() % 21;
    return paises[idx];
}

// Generar número de pasaporte aleatorio (formato LLDDDDDLL)
string Pasaporte()
{
    const string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char aux[11];
    char l1 = letras[rand() % 26];
    char l2 = letras[rand() % 26];
    char l3 = letras[rand() % 26];
    char l4 = letras[rand() % 26];
    int num = rand() % 100000;

    sprintf(aux, "%c%c%05d%c%c", l1, l2, num, l3, l4);
    return string(aux);
}

// Generar nombre aleatorio (de 20 caracteres)
string Generacion_Nombre()
{
    string nombre = "";
    for (int i = 0; i < 20; i++)
    {
        nombre += char('A' + rand() % 26);
    }
    return nombre;
}

// Estado del pasaporte
bool Estado_Pasaporte()
{
    return (rand() % 4 != 0); // 1 de cada 4 falla
}

// Insertar pasajero aleatorio y devolver su pasaporte
string Insertar_Pasaporte_Aleatorio(Cola c, int tipo)
{
    struct pasajero* nodo_aux = new struct pasajero;
    nodo_aux->nombre = Generacion_Nombre();
    nodo_aux->tipo_ciudadano = tipo;
    nodo_aux->nacionalidad = Nacionalidades();
    nodo_aux->estado_pasaporte = Estado_Pasaporte();
    nodo_aux->numero_pasaporte = Pasaporte(); 
    nodo_aux->sig = NULL;

    if (Cola_Vacia(c))
    {
        c->primero->sig = nodo_aux;
        c->ultimo = nodo_aux;
    }
    else
    {
        c->ultimo->sig = nodo_aux;
        c->ultimo = nodo_aux;
    }

    return nodo_aux->numero_pasaporte;
}

// Eliminar el primer pasajero y devolver su pasaporte
string EliminarElementoAleatorio(Cola c)
{
    if (Cola_Vacia(c))
    {
        return "________";
    }

    struct pasajero* nodo_aux = c->primero->sig;
    string pasaporte = nodo_aux->numero_pasaporte;

    if (c->primero->sig == c->ultimo)
    {
        c->primero->sig = NULL;
        c->ultimo = NULL;
    }
    else
    {
        c->primero->sig = nodo_aux->sig;
    }

    delete nodo_aux;
    return pasaporte;
}