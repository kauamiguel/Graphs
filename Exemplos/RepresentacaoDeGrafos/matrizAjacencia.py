class Grafo:

    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = [[0]*self.vertices for i in range(vertices)]
        
    def adiciona_aresta(self, u, v):
        self.grafo[u-1][i-1] = 1 #Adiciona na matriz de adjacencias uma ligação de do vértice U com V
    
    def mostra_matriz(self):
        for i in range(self.vertices):
            print(self.grafo[i])

g = Grafo(4)
g.adiciona_aresta(1,2)
g.adiciona_aresta(3,4)
g.adiciona_aresta(1,4)
g.mostra_matriz()

