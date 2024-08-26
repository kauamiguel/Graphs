class Grafo:
    
    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = [[0] * self.vertices for i in range(self.vertices)]
        
        
    def adicionar_aresta(self, u, v):
        self.grafo[u-1][v-1] += 1
        
        # Teste para verificar um laço para não adicionar duas vezes
        if u != v:
            self.grafo[v-1][u-1] += 1    
        
        
    def mostrar_grafo(self):
        for i in range(self.vertices):
            print(self.grafo[i])
            
    def eh_euleriano(self):
        contador  = 0
        for i in  range(self.vertices):
            grau  = 0
            for j in range(self.vertices):
                #  A posicao i == j é a diagonal principal e significa a ligação de um vertice
                #  com ele mesmo, onde o grau dessa ligação é sempre dois caso exista
                if i == j:
                    grau = grau + 2 * self.vertices[i][j]
                else:
                    grau += self.vertices[i][j]
            
            if grau % 2 != 0:
                contador += 1
                
            if contador == 0:
                print('Grafo euleriano')
            if contador == 2:
                print('Grafo semi euleriano')
            if contador > 2:
                print('Grafo nao euleriano')
                
                
g = Grafo(4)
g.adicionar_aresta(1,2)
g.adicionar_aresta(3,4)
g.adicionar_aresta(2,3)

g.mostrar_grafo()