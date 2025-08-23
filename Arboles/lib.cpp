#include <cstdlib>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "lib.hpp"

using namespace std;

void menu()
{
   char opcion;
   int cont;
   int num_arbol;
   int tiempo = 0;

   Nodo *arbol_1 = NULL, *arbol_2 = NULL, *arbol_3 = NULL, *arbol_4 = NULL;
   string pasaporte;

   srand(time(NULL)); // Inicializar generador de números aleatorios

   do
   {
       cout << " ----------------------------------------------------------------------------------------------------------" << endl;
       cout << "| BIENVENIDO A LA SIMULACION DE UNA ADUANA DE PASAJEROS UTILIZANDO ARBOLES BINARIOS DE BUSQUEDA            |" << endl;
       cout << "|                                                                                                          |" << endl;
       cout << "| Joan Amoros Ramirez - Estructuras de Datos - Practica 2                                                  |" << endl;
       cout << "|                                                                                                          |" << endl;
       cout << "| A. Insertar un nuevo pasajero en el arbol                                                                |" << endl;
       cout << "| B. Buscar un pasajero del arbol                                                                          |" << endl;
       cout << "| C. Recorrer el arbol en anchura y en profundidad (preorden, inorden, postorden)                          |" << endl;
       cout << "| D. Borrar un pasajero del arbol                                                                          |" << endl;
       cout << "| E. Introducir un numero y generar dicha cantidad de pasajeros de cualquier tipo                          |" << endl;
       cout << "| F. Introducir un numero y generar al azar dicha cantidad de pasajeros de cualquier tipo, que se borraran |" << endl;
       cout << "| G. Iniciar la simulacion                                                                                 |" << endl;
       cout << "| H. Salir de la aplicacion                                                                                |" << endl;
       cout << "|                                                                                                          |" << endl;
       cout << "| Por favor, selecciona una opcion:                                                                        |" << endl;
       cout << " ----------------------------------------------------------------------------------------------------------" << endl;

       cin >> opcion;

       switch (opcion)
       {
            case 'A':
            case 'a':
            {
                cout << "Escribe un pasaporte: ";
                cin >> pasaporte;

                if(!EsPasaporteValido(pasaporte))
                {
                    cout << "Has escrito mal el pasaporte, vuelve a insertarlo." << endl;
                    break;
                }

                cout << "¿En que arbol quieres meter el pasaporte? (1-4): ";
                cin >> num_arbol;

                if(num_arbol < 1 || num_arbol > 4)
                {
                    cout << "Introduce un numero del 1 al 4, por favor." << endl;
                    break;
                }

                Nodo** arbol_actual = nullptr;
                switch(num_arbol)
                {
                    case 1: arbol_actual = &arbol_1; break;
                    case 2: arbol_actual = &arbol_2; break;
                    case 3: arbol_actual = &arbol_3; break;
                    case 4: arbol_actual = &arbol_4; break;
                }

                if(Busqueda(*arbol_actual, pasaporte))
                {
                    cout << "El pasaporte que has escrito ya esta en el arbol " << num_arbol << "." << endl;
                    break;
                }

                string nombre, pais;
                int tipo_ciudadano;

                cout << "Introduce el nombre del pasajero: ";
                cin >> nombre;

                cout << "Introduce la nacionalidad del pasajero: ";
                cin >> pais;

                cout << "Introduce el tipo de ciudadano (1-4): ";
                cin >> tipo_ciudadano;

                if(tipo_ciudadano < 1 || tipo_ciudadano > 4)
                {
                    cout << "Has introducido un tipo de ciudadano erroneo (debe ser 1-4)" << endl;
                    break;
                }

                InsertarNodoNuevo(*arbol_actual, pasaporte, nullptr, nombre, pais, tipo_ciudadano);
                cout << "Pasajero insertado correctamente en el arbol " << num_arbol << endl;
                break;
            }

            case 'B':
            case 'b':
            {
                cout << "Escribe el pasaporte que quieras buscar: ";
                cin >> pasaporte;

                if(!EsPasaporteValido(pasaporte))
                {
                    cout << "Has escrito mal el pasaporte." << endl;
                    break;
                }

                cout << "¿En que arbol quieres buscar el pasaporte? (1-4): ";
                cin >> num_arbol;

                if(num_arbol < 1 || num_arbol > 4)
                {
                    cout << "Introduce un numero del 1 al 4, por favor." << endl;
                    break;
                }

                Nodo* arbol_actual = nullptr;
                switch(num_arbol)
                {
                    case 1: arbol_actual = arbol_1; break;
                    case 2: arbol_actual = arbol_2; break;
                    case 3: arbol_actual = arbol_3; break;
                    case 4: arbol_actual = arbol_4; break;
                }

                Nodo* encontrado = BuscarNodo(arbol_actual, pasaporte);
                if(encontrado)
                {
                    cout << "El pasaporte " << pasaporte << " se encuentra en el arbol " << num_arbol << "." << endl;
                    cout << "Sus datos son:" << endl;
                    cout << "- Nombre: " << encontrado->nombre << endl;
                    cout << "- Pais: " << encontrado->pais << endl;
                    cout << "- Tipo de ciudadano: " << encontrado->tipo_ciudadano << endl;
                    cout << "- Estado pasaporte: " << (encontrado->estado_pasaporte ? "OK" : "KO") << endl;
                }
                else
                {
                    cout << "Pasaporte no encontrado" << endl;
                }
                break;
            }

            case 'C':
            case 'c':
            {
                cout << "¿Que arbol quieres imprimir por pantalla? (1-4): ";
                cin >> num_arbol;

                if(num_arbol < 1 || num_arbol > 4)
                {
                    cout << "Por favor, introduce un numero del 1 al 4." << endl;
                    break;
                }

                Nodo* arbol_actual = nullptr;
                switch(num_arbol)
                {
                    case 1: arbol_actual = arbol_1; break;
                    case 2: arbol_actual = arbol_2; break;
                    case 3: arbol_actual = arbol_3; break;
                    case 4: arbol_actual = arbol_4; break;
                }

                cout << "Recorrido en anchura: " << endl;
                RecorridoAnchura(arbol_actual);
                cout << "\nRecorrido en profundidad:" << endl;
                cout << "PREORDEN: ";
                PreOrden(arbol_actual);
                cout << "\nINORDEN: ";
                InOrden(arbol_actual);
                cout << "\nPOSTORDEN: ";
                PostOrden(arbol_actual);
                cout << endl;
                break;
            }

            case 'D':
            case 'd':
            {
                cout << "Escribe el pasaporte que quieras borrar: ";
                cin >> pasaporte;

                if(!EsPasaporteValido(pasaporte))
                {
                    cout << "Has escrito mal el pasaporte." << endl;
                    break;
                }

                cout << "¿De que arbol quieres borrar el pasaporte? (1-4): ";
                cin >> num_arbol;

                if(num_arbol < 1 || num_arbol > 4)
                {
                    cout << "Por favor, introduce un numero del 1 al 4." << endl;
                    break;
                }

                Nodo** arbol_actual = nullptr;
                switch(num_arbol)
                {
                    case 1: arbol_actual = &arbol_1; break;
                    case 2: arbol_actual = &arbol_2; break;
                    case 3: arbol_actual = &arbol_3; break;
                    case 4: arbol_actual = &arbol_4; break;
                }

                if(Busqueda(*arbol_actual, pasaporte))
                {
                    Eliminar(*arbol_actual, pasaporte);
                    cout << "Pasajero eliminado correctamente." << endl;
                }
                else
                {
                    cout << "El pasaporte que has escrito no existe en el arbol." << endl;
                }
                break;
            }

            case 'E':
            case 'e':
            {
                cout << "¿Cuantos pasajeros quieres introducir en el arbol? ";
                cin >> cont;

                cout << "¿En que arbol quieres meter los pasaportes aleatorios? (1-4): ";
                cin >> num_arbol;

                if(num_arbol < 1 || num_arbol > 4)
                {
                    cout << "Por favor, introduce un numero del 1 al 4." << endl;
                    break;
                }

                Nodo** arbol_actual = nullptr;
                switch(num_arbol)
                {
                    case 1: arbol_actual = &arbol_1; break;
                    case 2: arbol_actual = &arbol_2; break;
                    case 3: arbol_actual = &arbol_3; break;
                    case 4: arbol_actual = &arbol_4; break;
                }

                for(int a = 0; a < cont; a++)
                {
                    string pasaporte_aleatorio;
                    do {
                        pasaporte_aleatorio = GenerarPasaporteAleatorio();
                    } while(Busqueda(*arbol_actual, pasaporte_aleatorio));

                    string nombre = Generacion_Nombre();
                    string pais = Nacionalidades();
                    int tipo = num_arbol; // Asignar el tipo según el árbol
                    
                    InsertarNodoNuevo(*arbol_actual, pasaporte_aleatorio, nullptr, nombre, pais, tipo);
                }
                cout << cont << " pasajeros generados e insertados en el arbol " << num_arbol << endl;
                break;
            }

            case 'F':
            case 'f':
            {
                cout << "¿Cuantos pasajeros quieres eliminar del arbol? ";
                cin >> cont;

                cout << "¿De que arbol quieres eliminar los pasaportes aleatorios? (1-4): ";
                cin >> num_arbol;

                if(num_arbol < 1 || num_arbol > 4)
                {
                    cout << "Por favor, introduce un numero del 1 al 4." << endl;
                    break;
                }

                Nodo** arbol_actual = nullptr;
                switch(num_arbol)
                {
                    case 1: arbol_actual = &arbol_1; break;
                    case 2: arbol_actual = &arbol_2; break;
                    case 3: arbol_actual = &arbol_3; break;
                    case 4: arbol_actual = &arbol_4; break;
                }

                EliminarNodosAleatorios(*arbol_actual, cont);
                break;
            }

            case 'G':
            case 'g':
            {
                cout << "Iniciando simulacion por 60 segundos..." << endl;
                tiempo = 0;

                while(tiempo < 60)
                {
                    // Generar pasajero aleatorio
                    string pasaporte_sim = GenerarPasaporteAleatorio();
                    string nombre_sim = Generacion_Nombre();
                    string pais_sim = Nacionalidades();
                    int tipo_sim = GenerarTipoCiudadano();
                    
                    // Elegir árbol aleatorio para llegada
                    int arbol_llegada = 1 + rand() % 4;
                    Nodo** arbol_destino = nullptr;
                    
                    switch(arbol_llegada)
                    {
                        case 1: arbol_destino = &arbol_1; break;
                        case 2: arbol_destino = &arbol_2; break;
                        case 3: arbol_destino = &arbol_3; break;
                        case 4: arbol_destino = &arbol_4; break;
                    }

                    // Insertar pasajero si no existe
                    if(!Busqueda(*arbol_destino, pasaporte_sim))
                    {
                        InsertarNodoNuevo(*arbol_destino, pasaporte_sim, nullptr, nombre_sim, pais_sim, arbol_llegada);
                        cout << "EVENTO: LLEGA el pasajero con el pasaporte " << pasaporte_sim << " al ARBOL " << arbol_llegada << endl;
                    }

                    // Mostrar estado de los árboles
                    cout << "ABB 1: "; InOrden(arbol_1); cout << endl;
                    cout << "ABB 2: "; InOrden(arbol_2); cout << endl;
                    cout << "ABB 3: "; InOrden(arbol_3); cout << endl;
                    cout << "ABB 4: "; InOrden(arbol_4); cout << endl;

                    // Procesar salida aleatoria
                    int arbol_salida = 1 + rand() % 4;
                    Nodo** arbol_origen = nullptr;
                    
                    switch(arbol_salida)
                    {
                        case 1: arbol_origen = &arbol_1; break;
                        case 2: arbol_origen = &arbol_2; break;
                        case 3: arbol_origen = &arbol_3; break;
                        case 4: arbol_origen = &arbol_4; break;
                    }

                    if(*arbol_origen != nullptr)
                    {
                        // Obtener un pasaporte aleatorio del árbol
                        string pasaporte_salida = ObtenerPasaporteAleatorio(*arbol_origen);
                        if(!pasaporte_salida.empty())
                        {
                            bool estado = Estado_Pasaporte();
                            if(estado)
                            {
                                Eliminar(*arbol_origen, pasaporte_salida);
                                cout << "EVENTO: PROCESAMIENTO OK del pasajero con el pasaporte " << pasaporte_salida << " en el ARBOL " << arbol_salida << endl;
                            }
                            else
                            {
                                cout << "EVENTO: PROCESAMIENTO KO del pasajero con el pasaporte " << pasaporte_salida << " en el ARBOL " << arbol_salida << endl;
                            }
                        }
                    }

                    // Mostrar estado final
                    cout << "ABB 1: "; InOrden(arbol_1); cout << endl;
                    cout << "ABB 2: "; InOrden(arbol_2); cout << endl;
                    cout << "ABB 3: "; InOrden(arbol_3); cout << endl;
                    cout << "ABB 4: "; InOrden(arbol_4); cout << endl;
                    cout << "------------------------" << endl;

                    Sleep(5000); // Esperar 5 segundos
                    tiempo += 5;
                }

                cout << "Simulacion terminada." << endl;
                break;
            }

            case 'H':
            case 'h':
                cout << "Saliendo de la aplicacion..." << endl;
                break;

            default:
                cout << "Opcion no valida. Por favor selecciona una opcion valida." << endl;
                break;
       }

       if(opcion != 'H' && opcion != 'h')
       {
           cout << "\nPresiona Enter para continuar...";
           cin.ignore();
           cin.get();
       }

   } while(opcion != 'H' && opcion != 'h');
}

Nodo *CrearNodo(string pasaporte, Nodo *padre, string nombre, string pais, int tipo_ciudadano)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->pasaporte = pasaporte;
    nuevo_nodo->nombre = nombre;
    nuevo_nodo->pais = pais;
    nuevo_nodo->tipo_ciudadano = tipo_ciudadano;
    nuevo_nodo->estado_pasaporte = Estado_Pasaporte();
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

bool EsPasaporteValido(string pasaporte)
{
    if(pasaporte.size() != 9)
    {
        return false;
    }

    // Formato LLDDDDDLL
    if(isalpha(pasaporte[0]) && isalpha(pasaporte[1]) &&
       isdigit(pasaporte[2]) && isdigit(pasaporte[3]) && isdigit(pasaporte[4]) &&
       isdigit(pasaporte[5]) && isdigit(pasaporte[6]) &&
       isalpha(pasaporte[7]) && isalpha(pasaporte[8]))
    {
        return true;
    }

    return false;
}

void InsertarNodoNuevo(Nodo *&arbol, string pasaporte, Nodo *padre, string nombre, string pais, int tipo_ciudadano)
{
    if(arbol == NULL)
    {
        Nodo *nuevo_nodo = CrearNodo(pasaporte, padre, nombre, pais, tipo_ciudadano);
        arbol = nuevo_nodo;
    }
    else
    {
        if(pasaporte < arbol->pasaporte)
        {
            InsertarNodoNuevo(arbol->izq, pasaporte, arbol, nombre, pais, tipo_ciudadano);
        }
        else if(pasaporte > arbol->pasaporte)
        {
            InsertarNodoNuevo(arbol->der, pasaporte, arbol, nombre, pais, tipo_ciudadano);
        }
        // Si son iguales, no hacer nada (no permitir duplicados)
    }
}

bool Busqueda(Nodo *arbol, string pasaporte)
{
    if(arbol == NULL)
    {
        return false;
    }
    else if(arbol->pasaporte == pasaporte)
    {
        return true;
    }
    else if(pasaporte < arbol->pasaporte)
    {
        return Busqueda(arbol->izq, pasaporte);
    }
    else
    {
        return Busqueda(arbol->der, pasaporte);
    }
}

Nodo* BuscarNodo(Nodo *arbol, string pasaporte)
{
    if(arbol == NULL)
    {
        return nullptr;
    }
    else if(arbol->pasaporte == pasaporte)
    {
        return arbol;
    }
    else if(pasaporte < arbol->pasaporte)
    {
        return BuscarNodo(arbol->izq, pasaporte);
    }
    else
    {
        return BuscarNodo(arbol->der, pasaporte);
    }
}

void PreOrden(Nodo *arbol)
{
    if(arbol != NULL)
    {
        cout << arbol->pasaporte << " ";
        PreOrden(arbol->izq);
        PreOrden(arbol->der);
    }
}

void InOrden(Nodo *arbol)
{
    if(arbol != NULL)
    {
        InOrden(arbol->izq);
        cout << arbol->pasaporte << " ";
        InOrden(arbol->der);
    }
}

void PostOrden(Nodo *arbol)
{
    if(arbol != NULL)
    {
        PostOrden(arbol->izq);
        PostOrden(arbol->der);
        cout << arbol->pasaporte << " ";
    }
}

void RecorridoAnchura(Nodo *arbol)
{
    // Implementación simple de recorrido por niveles
    if(arbol == NULL) return;
    
    // Para simplificar, haremos un recorrido inorden
    cout << "Recorrido por anchura (simplificado): ";
    InOrden(arbol);
    cout << endl;
}

void Eliminar(Nodo *&arbol, string pasaporte)
{
    if(arbol == NULL)
    {
        return;
    }
    else if(pasaporte < arbol->pasaporte)
    {
        Eliminar(arbol->izq, pasaporte);
    }
    else if(pasaporte > arbol->pasaporte)
    {
        Eliminar(arbol->der, pasaporte);
    }
    else
    {
        EliminarNodo(arbol);
    }
}

void EliminarNodo(Nodo *&nodoEliminar)
{
    if(nodoEliminar->izq && nodoEliminar->der)
    {
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->pasaporte = menor->pasaporte;
        nodoEliminar->nombre = menor->nombre;
        nodoEliminar->pais = menor->pais;
        nodoEliminar->tipo_ciudadano = menor->tipo_ciudadano;
        nodoEliminar->estado_pasaporte = menor->estado_pasaporte;
        Eliminar(nodoEliminar->der, menor->pasaporte);
    }
    else if(nodoEliminar->izq)
    {
        Nodo *temp = nodoEliminar;
        nodoEliminar = nodoEliminar->izq;
        nodoEliminar->padre = temp->padre;
        delete temp;
    }
    else if(nodoEliminar->der)
    {
        Nodo *temp = nodoEliminar;
        nodoEliminar = nodoEliminar->der;
        nodoEliminar->padre = temp->padre;
        delete temp;
    }
    else
    {
        delete nodoEliminar;
        nodoEliminar = NULL;
    }
}

Nodo *minimo(Nodo *arbol)
{
    if(arbol == NULL)
    {
        return NULL;
    }
    if(arbol->izq)
    {
        return minimo(arbol->izq);
    }
    else
    {
        return arbol;
    }
}

string GenerarPasaporteAleatorio()
{
    string letras = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char aux[10];

    char letra1 = letras[rand() % 26];
    char letra2 = letras[rand() % 26];
    char letra3 = letras[rand() % 26];
    char letra4 = letras[rand() % 26];

    sprintf(aux, "%c%c%d%d%d%d%d%c%c", letra1, letra2, rand()%10, rand()%10, rand()%10, rand()%10, rand()%10, letra3, letra4);
    
    return string(aux);
}

string Generacion_Nombre()
{
    string nombres[] = {"Ana", "Carlos", "Maria", "Juan", "Laura", "Pedro", "Sofia", "Miguel", "Elena", "David",
                       "Carmen", "Antonio", "Isabel", "Francisco", "Pilar", "Manuel", "Teresa", "Jose", "Mercedes", "Luis"};
    
    return nombres[rand() % 20];
}

int GenerarTipoCiudadano()
{
    return 1 + rand() % 4;
}

string Nacionalidades()
{
    string paises[] = {"Espana", "Francia", "Italia", "Alemania", "Portugal", "ReinoUnido", "Suiza", "Noruega",
                      "Rusia", "China", "India", "Japon", "Australia", "Canada", "EEUU", "Mexico",
                      "Brasil", "Argentina", "Chile", "Marruecos", "Sudafrica"};
    
    return paises[rand() % 21];
}

bool Estado_Pasaporte()
{
    return (rand() % 2) == 0; // 50% probabilidad de ser true o false
}

void EliminarNodosAleatorios(Nodo *&arbol, int cantidad)
{
    for(int i = 0; i < cantidad && arbol != nullptr; i++)
    {
        string pasaporte = ObtenerPasaporteAleatorio(arbol);
        if(!pasaporte.empty())
        {
            Eliminar(arbol, pasaporte);
            cout << "Eliminado pasaporte: " << pasaporte << endl;
        }
    }
}

string ObtenerPasaporteAleatorio(Nodo *arbol)
{
    if(arbol == nullptr) return "";
    
    // Contar nodos
    int total = ContarNodos(arbol);
    if(total == 0) return "";
    
    // Seleccionar uno aleatorio
    int objetivo = rand() % total;
    return ObtenerPasaporteEnPosicion(arbol, objetivo);
}

int ContarNodos(Nodo *arbol)
{
    if(arbol == nullptr) return 0;
    return 1 + ContarNodos(arbol->izq) + ContarNodos(arbol->der);
}

string ObtenerPasaporteEnPosicion(Nodo *arbol, int &posicion)
{
    if(arbol == nullptr) return "";
    
    // Recorrido inorden para obtener el nodo en la posición especificada
    string resultado = ObtenerPasaporteEnPosicion(arbol->izq, posicion);
    if(!resultado.empty()) return resultado;
    
    if(posicion == 0) return arbol->pasaporte;
    posicion--;
    
    return ObtenerPasaporteEnPosicion(arbol->der, posicion);
}