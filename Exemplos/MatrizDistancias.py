#Matriz de distancia é aquela em que as restas tem pesos

class Grafo:

    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = [[0]*self.vertices for i in range(vertices)]
    
    def adiciona_aresta_direcionada(self, u, v, peso):
        #Grafo direcionado
        self.grafo[u-1][v-1] = peso
    
    def adiciona_aresta_nao_direcionada(self, u, v):
        self.grafo[u-1][v-1] = 1
        self.grafo[v-1][u-1] = 1
    
    def mostra_matriz(self):
        for i in range(self.vertices):
            print(self.grafo[i])

g = Grafo(4)
g.adiciona_aresta_nao_direcionada(1,2,4)
g.adiciona_aresta_nao_direcionada(3,4,5)
g.adiciona_aresta_nao_direcionada(1,4,8)
g.mostra_matriz()

