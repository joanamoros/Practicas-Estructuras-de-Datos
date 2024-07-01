from queue import PriorityQueue

class Graph:
    def __init__(tabla, vertices):
        tabla.j = vertices #j: número de vértices en el grafo
        tabla.nuevo = [[-1 for filas in range(vertices)] for columnas in range(vertices)]
        tabla.visitado = [] #contendrá los vértices visitados

    def add_edge(tabla, i, j, precio): #función que añadirá un vértice al grafo
        tabla.nuevo[i][j] = precio
        tabla.nuevo[j][i] = precio
       
    def dijkstra(tabla, vertice_nuevo):
        M = {j:float('inf') for j in range(tabla.j)} #Creamos una matriz cuadrada del tamaño de los vértices
        M[vertice_nuevo] = 0 #La distancia de un vértice a sí mismo es 0
   
        pq = PriorityQueue()
        pq.put((0, vertice_nuevo))
   
        while not pq.empty():
            (cost, vertice_actual) = pq.get()
            tabla.visitado.append(vertice_actual)
   
            for vecino in range(tabla.j): #1º) Calculamos los nodos accesibles desde el camino previo de menor coste.
                if tabla.nuevo[vertice_actual][vecino] != -1:
                    coste = tabla.nuevo[vertice_actual][vecino]
                    if vecino not in tabla.visitado:
                        coste_antiguo = M[vecino]
                        coste_nuevo = M[vertice_actual] + coste
                        if coste_nuevo < coste_antiguo: #2º) Seleccionamos el nodo de menor coste que no haya sido recorrido.
                            pq.put((coste_nuevo, vecino)) 
                            M[vecino] = coste_nuevo
        return M
   
   
g = Graph(8) #La matriz es de 8x8 porque hay 8 ciudades en total

#Ciudad 0: Alicante (será nuestro punto de partida)
#Ciudad 1: Barcelona
#Ciudad 2: París
#Ciudad 3: Atenas
#Ciudad 4: Burdeos
#Ciudad 5: Cork
#Ciudad 6: Budapest
#Ciudad 7: Ciudad de México (CDMX)

g.add_edge(0, 4, 78) 
g.add_edge(0, 5, 142)
g.add_edge(1, 2, 46)
g.add_edge(1, 4, 34)
g.add_edge(1, 6, 68)
g.add_edge(1, 7, 485)
g.add_edge(2, 1, 46)
g.add_edge(2, 3, 76)
g.add_edge(2, 5, 112)
g.add_edge(3, 2, 76)
g.add_edge(3, 4, 146)
g.add_edge(3, 6, 38)
g.add_edge(4, 0, 78)
g.add_edge(4, 1, 34)
g.add_edge(4, 3, 146)
g.add_edge(5, 0, 142)
g.add_edge(6, 1, 68)
g.add_edge(6, 3, 38)
g.add_edge(7, 1, 485)

D = g.dijkstra(0)


print("El precio del vuelo de Alicante a Budapest es de", D[6], "€ (pasando por Burdeos y Barcelona)")
print("El precio del vuelo de Alicante a CDMX es de", D[7], "€ (pasando por Burdeos y Barcelona)")
print("El precio del vuelo de Alicante a Barcelona es de", D[1], "€ (pasando por Burdeos)")
print("El precio del vuelo de Alicante a París es de", D[2], "€ (pasando por Burdeos y Barcelona)")