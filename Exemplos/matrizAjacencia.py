class Grafo:

    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = [[0]*self.vertices for i in range(vertices)]
        
    def adiciona_aresta_direcionada(self, u, v):
        #Grafo direcionado
        self.grafo[u-1][v-1] = 1 #Adiciona na matriz de adjacencias uma ligação de do vértice U com V
    
    def adiciona_aresta_nao_direcionada(self, u, v):
        self.grafo[u-1][v-1] = 1
        self.grafo[v-1][u-1] = 1
    
    def mostra_matriz(self):
        for i in range(self.vertices):
            print(self.grafo[i])

g = Grafo(4)
g.adiciona_aresta_nao_direcionada(1,2)
g.adiciona_aresta_nao_direcionada(3,4)
g.adiciona_aresta_nao_direcionada(1,4)
g.mostra_matriz()

