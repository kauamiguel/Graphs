import math

class HeapMin:
    
    def __init__(self):
        self.nos = 0
        self.heap = []
        
    def tamanho(self):
        return self.nos
        
    def adicionar_no(self, u, indice):
        #O indice serve para identificar qual no está relacionado com a distância U
        self.heap.append([u,indice])
        self.nos += 1
        filho = self.nos 
        
        while True:
            if filho == 1:
                break
            
            pai = filho // 2
            
            #Usa a coluna 0 pois é nessa posição da sublista que contém a distância U
            if self.heap[pai - 1][0] <= self.heap[filho - 1][0]:
                break
            else:
                self.heap[pai - 1], self.heap[filho -1] = self.heap[filho -1], self.heap[pai -1]
                filho = pai
                
    def mostra_heap(self):
        print(self.heap)
        
    def remove_no(self):
        primeiroElemento = self.heap[0]
        self.heap[0] = self.heap[self.nos - 1]
        self.heap.pop()
        self.nos -= 1
        
        pai = 1
        
        while True:
            filho = 2 * pai
            
            if filho > self.nos:
                break
                
            if filho + 1 <= self.nos:
                if self.heap[filho + 1 - 1][0] < self.heap[filho - 1][0]:
                    filho += 1
                    
            if self.heap[pai - 1][0] <= self.heap[filho - 1][0]:
                break
            else:
                self.heap[pai - 1], self.heap[filho -1] = self.heap[filho -1], self.heap[pai -1]
                pai = filho
        return primeiroElemento
    
class Grafo:
    
    def __init__(self, vertices):
        self.vertices = vertices
        self.grafo = [[0] * vertices for i in range(vertices)]
        
    def adiciona_aresta(self, u, v, peso):
        self.grafo[u-1][v-1] = peso
        self.grafo[v-1][u-1] = peso
    
    def mostra_matriz(self):
        for i in range(self.vertices):
            print(self.grafo[i])
            
    def algoritmo_dijkstra(self, origem):
        custo_vem = [[-1,0] for i in range(self.vertices)]
        custo_vem[origem - 1] = [0, origem]
        
        #Adiciona a origem no heap que tem custo 0 pra chegar nela mesma
        heap = HeapMin()
        heap.adicionar_no(0, origem)
        
        while heap.tamanho() > 0 :
            
            distancia, vertice = heap.remove_no()
              
              #Adiciona toda a linha do vertice para ver os caminhos que ele tem
            for i in range(self.vertices):
                if self.grafo[vertice - 1][i] != 0:
                    if custo_vem[i][0] == -1 or custo_vem[i][0] > distancia + self.grafo[vertice - 1][i]:
                        custo_vem[i] = [distancia + self.grafo[vertice - 1][i], vertice]
                        heap.adicionar_no(distancia + self.grafo[vertice - 1][i], i+1)
        
        return custo_vem

g = Grafo(7)     
g.adiciona_aresta(1,2,5)
g.adiciona_aresta(1,3,6)
g.adiciona_aresta(1,4,10)
g.adiciona_aresta(2,5,13)
g.adiciona_aresta(3,4,3)
g.adiciona_aresta(3,5,11)
g.adiciona_aresta(3,6,6)
g.adiciona_aresta(4,5,6)
g.adiciona_aresta(4,6,4)
g.adiciona_aresta(5,7,3)
g.adiciona_aresta(6,7,8)

r = g.algoritmo_dijkstra(1)
print(r)

