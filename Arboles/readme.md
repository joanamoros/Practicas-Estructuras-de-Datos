# Simulación de aduana de pasajeros - Árboles binarios de búsqueda

## Descripción del proyecto

Este proyecto implementa una simulación de una aduana de pasajeros utilizando **Árboles Binarios de Búsqueda (ABB)** en C++. El sistema permite gestionar hasta 4 colas de procesamiento diferentes, cada una representada por un árbol binario independiente.

**Autor:** Joan Amorós Ramírez  
**Asignatura:** Estructuras de Datos - Práctica 2

## Características principales

### Gestión de pasajeros
- **Formato de pasaporte:** LLDDDDDLL (2 letras + 5 dígitos + 2 letras)
- **Datos por pasajero:** Pasaporte, nombre, nacionalidad, tipo de ciudadano (1-4), estado del pasaporte (OK/KO)
- **4 árboles independientes** para simular diferentes colas de procesamiento

### Funcionalidades del sistema

#### A. Inserción de pasajeros
- Insertar manualmente un nuevo pasajero en cualquiera de los 4 árboles
- Validación automática del formato de pasaporte
- Prevención de duplicados

#### B. Búsqueda de pasajeros  
- Búsqueda por número de pasaporte en cualquier árbol
- Visualización completa de los datos del pasajero encontrado

#### C. Recorridos del árbol
- **Recorrido en anchura** (por niveles)
- **Recorridos en profundidad:**
  - Preorden (Raíz → Izquierda → Derecha)
  - Inorden (Izquierda → Raíz → Derecha) 
  - Postorden (Izquierda → Derecha → Raíz)

#### D. Eliminación de pasajeros
- Eliminación individual por número de pasaporte
- Mantenimiento de las propiedades del ABB tras la eliminación

#### E. Generación masiva de pasajeros
- Generación automática de N pasajeros aleatorios
- Datos generados: pasaportes válidos, nombres, nacionalidades y tipos de ciudadano
- Inserción en el árbol seleccionado

#### F. Eliminación masiva aleatoria  
- Eliminación de N pasajeros seleccionados aleatoriamente
- Útil para pruebas y limpieza de datos

#### G. Simulación en tiempo real
- **Duración:** 60 segundos con eventos cada 5 segundos
- **Eventos simulados:**
  - Llegada de pasajeros aleatorios a colas aleatorias
  - Procesamiento con estado OK (eliminación) o KO (permanece)
- **Visualización:** Estado de los 4 árboles después de cada evento

## Estructura del proyecto

```
Arboles/
├── main.cpp    # Función principal
├── lib.cpp     # Implementación de todas las funciones
├── lib.hpp     # Declaraciones y estructura de datos
└── README.md   
```

### Estructura de datos principal

```cpp
struct Nodo {
    string pasaporte;        // Formato: LLDDDDDLL
    string nombre;           // Nombre del pasajero  
    string pais;            // Nacionalidad
    int tipo_ciudadano;     // Tipo 1-4
    bool estado_pasaporte;  // true=OK, false=KO
    Nodo *der;              // Hijo derecho
    Nodo *izq;              // Hijo izquierdo  
    Nodo *padre;            // Nodo padre
};
```

## Compilación y ejecución

### Compilación
```bash
g++ -o main main.cpp lib.cpp
```

### Ejecución
```bash
./main
```
