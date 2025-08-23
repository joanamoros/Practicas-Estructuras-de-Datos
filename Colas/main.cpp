#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <string>
#include <cstdio>
#include "lib.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    char opcion;
    int tipo;

    Cola U = Crear_Cola(); // UE
    Cola B = Crear_Cola(); // Británicos
    Cola A = Crear_Cola(); // Acuerdos UE
    Cola E = Crear_Cola(); // Extracomunitarios

    // Inicializar semilla aleatoria 
    srand(time(NULL));

    cout << "Bienvenido a la simulacion en la aduana del aeropuerto" << endl;

    do
    {
        cout << "\n--- MENU PRINCIPAL ---" << endl;
        cout << "A: Introducir un pasajero en una cola" << endl;
        cout << "B: Sacar al primer pasajero de una cola" << endl;
        cout << "C: Imprimir todos los pasajeros de una cola" << endl;
        cout << "D: Consultar el primer pasajero de una cola" << endl;
        cout << "E: Iniciar simulacion automatica (60 segundos)" << endl;
        cout << "F: Salir de la aplicacion" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 'A':
            case 'a':
                cout << "En que cola desea introducir al pasajero? (1=UE, 2=Britanicos, 3=Acuerdos UE, 4=Extracomunitarios): ";
                cin >> tipo;
                if (tipo == 1) {
                    Insertar_Pasaporte(U, 1);
                } else if (tipo == 2) {
                    Insertar_Pasaporte(B, 2);
                } else if (tipo == 3) {
                    Insertar_Pasaporte(A, 3);
                } else if (tipo == 4) {
                    Insertar_Pasaporte(E, 4);
                } else {
                    cout << "Error: tipo de cola no valido. Debe ser 1, 2, 3 o 4." << endl;
                }
                break;

            case 'B':
            case 'b':
                cout << "De que cola desea eliminar al primer pasajero? (1-4): ";
                cin >> tipo;
                if (tipo == 1) {
                    EliminarElemento(U);
                } else if (tipo == 2) {
                    EliminarElemento(B);
                } else if (tipo == 3) {
                    EliminarElemento(A);
                } else if (tipo == 4) {
                    EliminarElemento(E);
                } else {
                    cout << "Error: tipo de cola no valido." << endl;
                }
                break;

            case 'C':
            case 'c':
                cout << "¿Que cola desea mostrar? (1-4): ";
                cin >> tipo;
                cout << "COLA " << tipo << ": ";
                if (tipo == 1) MostrarCola(U);
                else if (tipo == 2) MostrarCola(B);
                else if (tipo == 3) MostrarCola(A);
                else if (tipo == 4) MostrarCola(E);
                else cout << "Error: tipo no valido." << endl;
                break;

            case 'D':
            case 'd':
                cout << "¿Que cola desea consultar? (1-4): ";
                cin >> tipo;
                if (tipo == 1) VerCola(U);
                else if (tipo == 2) VerCola(B);
                else if (tipo == 3) VerCola(A);
                else if (tipo == 4) VerCola(E);
                else cout << "Error: tipo no valido." << endl;
                break;

            case 'E':
            case 'e':
                {
                    cout << "\n--- INICIANDO SIMULACION (60 segundos) ---\n";
                    cout << "Cada 5 segundos llegara un pasajero y se procesara uno.\n\n";

                    for (int segundo = 0; segundo < 60; segundo += 5)
                    {
                        Sleep(5);  // Espera 5 segundos 

                        // --- FASE 1: LLEGADA DE UN NUEVO PASAJERO ---
                        int cola_llegada = rand() % 4;
                        string pasaporte;

                        switch (cola_llegada)
                        {
                            case 0:
                                pasaporte = Insertar_Pasaporte_Aleatorio(U, 1);
                                cout << "EVENTO: Llega pasajero " << pasaporte << " a COLA 1 (UE)" << endl;
                                break;
                            case 1:
                                pasaporte = Insertar_Pasaporte_Aleatorio(B, 2);
                                cout << "EVENTO: Llega pasajero " << pasaporte << " a COLA 2 (Britanicos)" << endl;
                                break;
                            case 2:
                                pasaporte = Insertar_Pasaporte_Aleatorio(A, 3);
                                cout << "EVENTO: Llega pasajero " << pasaporte << " a COLA 3 (Acuerdos UE)" << endl;
                                break;
                            case 3:
                                pasaporte = Insertar_Pasaporte_Aleatorio(E, 4);
                                cout << "EVENTO: Llega pasajero " << pasaporte << " a COLA 4 (Extracomunitarios)" << endl;
                                break;
                        }

                        // --- FASE 2: PROCESAMIENTO DE UN PASAJERO ---
                        int cola_salida = rand() % 4;
                        Cola c_salida = nullptr;
                        string nombre_cola;

                        switch (cola_salida)
                        {
                            case 0: c_salida = U; nombre_cola = "1"; break;
                            case 1: c_salida = B; nombre_cola = "2"; break;
                            case 2: c_salida = A; nombre_cola = "3"; break;
                            case 3: c_salida = E; nombre_cola = "4"; break;
                        }

                        if (!Cola_Vacia(c_salida))
                        {
                            struct pasajero* p = c_salida->primero->sig;
                            string pasaporte_salida = p->numero_pasaporte;

                            if (p->estado_pasaporte)
                            {
                                EliminarElemento(c_salida);
                                cout << "EVENTO: Procesamiento OK pasajero " << pasaporte_salida << endl;
                            }
                            else
                            {
                                // Sacar y volver a insertar al final
                                string pas = EliminarElementoAleatorio(c_salida);
                                Insertar_Pasaporte_Aleatorio(c_salida, p->tipo_ciudadano);
                                cout << "EVENTO: Procesamiento KO pasajero " << pasaporte_salida << " (vuelve a la cola)" << endl;
                            }
                        }
                        else
                        {
                            cout << "EVENTO: Intento de procesar COLA " << nombre_cola << ", pero esta vacia." << endl;
                        }

                        // --- MOSTRAR ESTADO ACTUAL DE LAS COLAS ---
                        cout << "COLA 1: "; MostrarCola(U);
                        cout << "COLA 2: "; MostrarCola(B);
                        cout << "COLA 3: "; MostrarCola(A);
                        cout << "COLA 4: "; MostrarCola(E);
                        cout << "----------------------------------------" << endl;
                    }

                    cout << "--- SIMULACION FINALIZADA ---" << endl;
                }
                break;

            case 'F':
            case 'f':
                cout << "Saliendo de la aplicacion. ¡Hasta pronto!" << endl;
                break;

            default:
                cout << "Opcion no valida. Por favor, seleccione A, B, C, D, E o F." << endl;
                break;
        }

    } while (opcion != 'F' && opcion != 'f');

    system("PAUSE");
    return EXIT_SUCCESS;
}