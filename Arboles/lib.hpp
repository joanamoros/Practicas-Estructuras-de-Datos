#ifndef LIB_HPP
#define LIB_HPP

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

struct Nodo
{
    string pasaporte;
    string nombre;
    string pais;
    int tipo_ciudadano;
    bool estado_pasaporte;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

// Función principal del menú
void menu();

// Funciones de creación y validación
Nodo *CrearNodo(string pasaporte, Nodo *padre, string nombre = "", string pais = "", int tipo_ciudadano = 1);
bool EsPasaporteValido(string pasaporte);

// Funciones de inserción
void InsertarNodoNuevo(Nodo *&arbol, string pasaporte, Nodo *padre, string nombre, string pais, int tipo_ciudadano);

// Funciones de búsqueda
bool Busqueda(Nodo *arbol, string pasaporte);
Nodo* BuscarNodo(Nodo *arbol, string pasaporte);

// Funciones de recorrido
void PreOrden(Nodo *arbol);
void InOrden(Nodo *arbol);
void PostOrden(Nodo *arbol);
void RecorridoAnchura(Nodo *arbol);

// Funciones de eliminación
void Eliminar(Nodo *&arbol, string pasaporte);
void EliminarNodo(Nodo *&nodoEliminar);
Nodo *minimo(Nodo *arbol);

// Funciones de generación aleatoria
string GenerarPasaporteAleatorio();
string Generacion_Nombre();
int GenerarTipoCiudadano();
string Nacionalidades();
bool Estado_Pasaporte();

// Funciones auxiliares para la simulación
void EliminarNodosAleatorios(Nodo *&arbol, int cantidad);
string ObtenerPasaporteAleatorio(Nodo *arbol);
int ContarNodos(Nodo *arbol);
string ObtenerPasaporteEnPosicion(Nodo *arbol, int &posicion);

#endif