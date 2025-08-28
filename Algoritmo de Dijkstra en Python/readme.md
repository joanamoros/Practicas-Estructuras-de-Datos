# Algoritmo de Dijkstra para optimización de rutas de vuelo

## Descripción del proyecto

Este proyecto implementa el **algoritmo de Dijkstra** en Python para encontrar las rutas de vuelo más económicas desde Alicante hacia diferentes destinos europeos y americanos. El programa calcula automáticamente las escalas necesarias para minimizar el coste total del viaje.

## Objetivo

Encontrar el camino más barato para viajar desde **Alicante** a cualquier destino disponible, considerando que:
- Los precios son de **ida y vuelta**
- Se pueden realizar **escalas** en ciudades intermedias
- El objetivo es **minimizar el coste total**, no el número de escalas

## Ciudades y conexiones disponibles

El grafo incluye las siguientes 8 ciudades:

| ID | Ciudad | Conexiones directas |
|----|--------|-------------------|
| 0  | **Alicante** (Origen) | Burdeos (78€), Cork (142€) |
| 1  | Barcelona | París (46€), Burdeos (34€), Budapest (68€), CDMX (485€) |
| 2  | París | Barcelona (46€), Atenas (76€), Cork (112€) |
| 3  | Atenas | París (76€), Burdeos (146€), Budapest (38€) |
| 4  | Burdeos | Alicante (78€), Barcelona (34€), Atenas (146€) |
| 5  | Cork | Alicante (142€), París (112€) |
| 6  | Budapest | Barcelona (68€), Atenas (38€) |
| 7  | Ciudad de México | Barcelona (485€) |

## Resultados obtenidos

| Destino | Coste mínimo | Ruta óptima |
|---------|--------------|-------------|
| **Budapest** | 180€ | Alicante → Burdeos → Barcelona → Budapest |
| **Ciudad de México** | 597€ | Alicante → Burdeos → Barcelona → Ciudad de México |
| **Barcelona** | 112€ | Alicante → Burdeos → Barcelona |
| **París** | 158€ | Alicante → Burdeos → Barcelona → París |


## Algoritmo de Dijkstra

### Funcionamiento
1. **Inicialización**: Establece distancia infinita a todos los nodos excepto el origen (0)
2. **Cola de prioridad**: Utiliza PriorityQueue para procesar nodos por coste mínimo
3. **Relajación**: Actualiza distancias cuando encuentra un camino más barato
4. **Exploración**: Marca nodos como visitados y explora vecinos no visitados
