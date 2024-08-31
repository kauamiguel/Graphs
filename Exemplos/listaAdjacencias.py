class Grafo:
    
    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = [[] for i in range(vertices)]

    def adiciona_aresta(self,u, v):
        self.grafo[u-1].append(v)
        
    def mostrar_lista(self):
        for i in range(self.vertices):
            print(f'{i+1}:', end='  ')
            for j in self.grafo[i]:
                print(f'{j} -> ', end='')
            print('')


g = Grafo(4)    
g.adiciona_aresta(1,3)
g.adiciona_aresta(2,4)
g.adiciona_aresta(1,4)
g.mostrar_lista()
