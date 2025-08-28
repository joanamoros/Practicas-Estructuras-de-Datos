# Simulador de colas de aduana aeroportuaria

## Descripción

Este proyecto simula el sistema de colas de control de pasaportes en la aduana de un aeropuerto. Los pasajeros se organizan en cuatro colas diferentes según su nacionalidad y tipo de ciudadanía, permitiendo gestionar el flujo de personas de manera eficiente.

## Características principales

### Tipos de colas
1. **Cola 1 - UE**: Ciudadanos de la Unión Europea
2. **Cola 2 - Británicos**: Ciudadanos británicos
3. **Cola 3 - Acuerdos UE**: Ciudadanos de países con acuerdos especiales con la UE
4. **Cola 4 - Extracomunitarios**: Ciudadanos de países fuera de la UE

### Estructura de datos
- **Pasajero**: Cada pasajero contiene:
  - Número de pasaporte (formato LLDDDDDLL)
  - Nombre (20 caracteres aleatorios)
  - Nacionalidad
  - Tipo de ciudadano (1-4)
  - Estado del pasaporte (válido/inválido)

### Funcionalidades
- **Gestión manual**: Insertar y eliminar pasajeros manualmente
- **Consulta de colas**: Ver el estado actual de cualquier cola
- **Simulación automática**: Proceso de 60 segundos que simula llegadas y procesamientos
- **Generación aleatoria**: Creación automática de pasajeros con datos aleatorios

## Compilación y ejecución

### Compilación
```bash
g++ -o main main.cpp P1.cpp
```

### Ejecución
```bash
./main
```

## Estructura del proyecto

```
Colas/
├── main.cpp      # Programa principal con menú interactivo
├── P1.cpp        # Implementación de las funciones de cola
├── lib.hpp       # Definiciones de estructuras y prototipos
└── README.md     
```

## Uso del programa

Al ejecutar el programa, se presenta un menú con las siguientes opciones:

- **A**: Introducir un pasajero manualmente en una cola específica
- **B**: Eliminar el primer pasajero de una cola
- **C**: Mostrar todos los pasajeros de una cola
- **D**: Consultar el primer pasajero de una cola
- **E**: Iniciar simulación automática de 60 segundos
- **F**: Salir de la aplicación

### Simulación automática

La simulación automática ejecuta un ciclo de 60 segundos donde cada 5 segundos:

1. **Llegada**: Un pasajero aleatorio llega a una cola aleatoria
2. **Procesamiento**: Se intenta procesar un pasajero de una cola aleatoria
   - Si el pasaporte es válido: el pasajero sale del sistema
   - Si el pasaporte es inválido: el pasajero vuelve al final de la cola
3. **Estado**: Se muestra el estado actual de todas las colas

## Algoritmos implementados

### Generación de datos aleatorios
- **Pasaportes**: Formato LLDDDDDLL (2 letras + 5 dígitos + 2 letras)
- **Nacionalidades**: 21 países predefinidos
- **Estado del pasaporte**: 75% de probabilidad de ser válido
- **Nombres**: Cadenas de 20 caracteres aleatorios
