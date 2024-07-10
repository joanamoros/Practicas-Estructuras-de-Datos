#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string.h>

#include "lib.hpp"


using namespace std;


int main (int argc, char *argv[])
{
    char opcion;
    int tipo;
    int contador;

    Cola U, B, A, E; // U = UE , B = Britanicos , A = Acuerdos UE , E = Extracomunitarios //

    cout << "Bienvenido a la simulacion en la aduana del aeropuerto" << endl;

    cout << "Por favor, seleccione una opcion: " << endl;

    cout << "A: Introducir un pasajero en una cola" << endl;

    cout << "B: Sacar al primer pasajero de la cola" << endl;

    cout << "C: Imprimir una cola por pantalla" << endl;

    cout << "D: Consultar que pasajero esta esperando en cualquier cola" << endl;

    cout << "E: Iniciar la simulacion" << endl;

    cout << "F: Salir de la aplicacion" << endl;

    cin >> opcion;

    U = Crear_Cola(); // Cola 1
    B = Crear_Cola(); // Cola 2
    A = Crear_Cola(); // Cola 3
    E = Crear_Cola(); // Cola 4


    while(opcion !='F')
    {
        switch(opcion)
        {
            case 'A':

                cout << "¿En que cola quieres introducir al pasajero?" << endl;
                cin >> tipo;

                if(tipo == 1)
                {
                    Insertar_Pasaporte (U, tipo);
                }
                else if(tipo == 2)
                {
                    Insertar_Pasaporte (B, tipo);
                }
                else if(tipo == 3)
                {
                    Insertar_Pasaporte (A, tipo);
                }
                else if(tipo == 4)
                {
                    Insertar_Pasaporte (E, tipo);
                }
                else
                {
                    cout << "Error, vuelve a introducir un numero entre 1 y 4." << endl;
                }

            break;


            case 'B':

                cout << "¿De que cola quieres extraer al pasajero?" << endl;
                cin >> tipo;

                if(tipo == 1)
                {
                    EliminarElemento (U);
                }
                else if(tipo == 2)
                {
                    EliminarElemento (B);
                }
                else if(tipo == 3)
                {
                    EliminarElemento (A);
                }
                else if(tipo == 4)
                {
                    EliminarElemento (E);
                }
                else
                {
                    cout << "Error, vuelve a introducir un numero entre 1 y 4." << endl;
                }

            break;


            case 'C':

                cout << "¿Que cola desea que le mostremos?" << endl;
                cin >> tipo;

                if(tipo == 1)
                {
                    MostrarCola (U);
                }
                else if(tipo == 2)
                {
                    MostrarCola (B);
                }
                else if(tipo == 3)
                {
                    MostrarCola (A);
                }
                else if(tipo == 4)
                {
                    MostrarCola (E);
                }
                else
                {
                    cout << "Error, vuelve a introducir un numero entre 1 y 4." << endl;
                }

            break;


            case 'D':

                cout << "¿Que cola desea consultar?" << endl;
                cin >> tipo;

                if(tipo == 1)
                {
                    VerCola (U);
                }
                else if(tipo == 2)
                {
                    VerCola (B);
                }
                else if(tipo == 3)
                {
                    VerCola (A);
                }
                else if(tipo == 4)
                {
                    VerCola (E);
                }
                else
                {
                    cout << "Error, vuelve a introducir un numero entre 1 y 4." << endl;
                }

            break;


            case 'E':

                do
                {
                    int random, exit;
                    string numero_pasaporte;
                    srand (time(NULL));
                    random = 1 + rand() %4;

                    switch (random)
                    {
                        case 1:
                            Insertar_Pasaporte_Aleatorio(U, 1);
                            cout<<"EVENTO: LLEGA un pasajero "<<numero_pasaporte<<"a la COLA 1\n"<<endl;
                            break;

                        case 2:
                            Insertar_Pasaporte_Aleatorio(B, 2);
                            cout<<"EVENTO: LLEGA un pasajero "<<numero_pasaporte<<"a la COLA 2\n"<<endl;
                            break;

                        case 3:
                            Insertar_Pasaporte_Aleatorio(A, 3);
                            cout<<"EVENTO: LLEGA un pasajero "<<numero_pasaporte<<"a la COLA 3\n"<<endl;
                            break;

                        case 4:
                            Insertar_Pasaporte_Aleatorio(E, 4);
                            cout<<"EVENTO: LLEGA un pasajero "<<numero_pasaporte<<"a la COLA 4\n"<<endl;
                            break;
                    }

                    cout << "COLA 1: ";	MostrarCola(U);
                    cout << "COLA 2: "; MostrarCola(B);
                    cout << "COLA 3: "; MostrarCola(A);
                    cout << "COLA 4: "; MostrarCola(E);


                    if(Estado_Pasaporte() == true)
                    {
                        srand(time(NULL));
                        exit = 1 + rand()%4;

                        switch(exit)
                        {
                            case 1:
                                EliminarElemento(U);
                                cout<<"EVENTO: PROCESAMIENTO OK del PASAJERO "<<numero_pasaporte<<endl;
                                break;

                            case 2:
                                EliminarElemento(B);
                                cout<<"EVENTO: PROCESAMIENTO OK del PASAJERO "<<numero_pasaporte<<endl;
                                break;

                            case 3:
                                EliminarElemento(A);
                                cout<<"EVENTO: PROCESAMIENTO OK del PASAJERO "<<numero_pasaporte<<endl;
                                break;

                            case 4:
                                EliminarElemento(E);
                                cout<<"EVENTO: PROCESAMIENTO OK del PASAJERO "<<numero_pasaporte<<endl;
                                break;

                        }
                        cout << "COLA 1: ";	MostrarCola(U);
                        cout << "COLA 2: "; MostrarCola(B);
                        cout << "COLA 3: "; MostrarCola(A);
                        cout << "COLA 4: "; MostrarCola(E);
                    }
                    else
                    {
                        switch(exit)
                        {
                            case 1:
                                RecorrerCola(U);
                                cout<<"EVENTO: PROCESAMIENTO KO del PASAJERO "<<numero_pasaporte<<endl;
                                break;

                            case 2:
                                RecorrerCola(B);
                                cout<<"EVENTO: PROCESAMIENTO KO del PASAJERO "<<numero_pasaporte<<endl;
                                break;

                            case 3:
                                RecorrerCola(A);
                                cout<<"EVENTO: PROCESAMIENTO KO del PASAJERO "<<numero_pasaporte<<endl;
                                break;

                            case 4:
                                RecorrerCola(E);
                                cout<<"EVENTO: PROCESAMIENTO KO del PASAJERO "<<numero_pasaporte<<endl;
                                break;

                        }
                        cout << "COLA 1: ";	VerCola(U);
                        cout << "COLA 2: ";	VerCola(B);
                        cout << "COLA 3: ";	VerCola(A);
                        cout << "COLA 4: ";	VerCola(E);
                    }

                    contador++;

                }while(contador != 60);

                system("PAUSE");

            break;


            default:

                cout << "Ha seleccionado mal la opcion" << endl;

            break;
        }

        cout << "Seleccione otra opcion" << endl;

        cin >> opcion;
    }

    system("PAUSE");
    return EXIT_SUCCESS;
}
