import math

class HeapMin:
    
    def __init__(self):
        self.nos = 0
        self.heap = []
        
    def tamanho(self):
        return self.nos
        
    def adiciona_no(self, u, indice):
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
                
    def mostraHeap(self):
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
            
    def algoritmoDjkistra(self, origem):
        #Lista com custo e de onde vem
        custo_vem = [[-1,0]for i in range(self.vertices)]
        custo_vem[origem - 1] = [0,origem - 1]
        h = HeapMin()
        h.adiciona_no(0,origem)
        
        while h.tamanho() > 0:
            
            distancia, indeiceDeOndeVem = h.remove_no()
            print(f'Distancia: {distancia}   indice onde vem: {indeiceDeOndeVem}')
            
            for i in range(self.vertices):
                if self.grafo[indeiceDeOndeVem - 1][i] != 0:
                    if custo_vem[i][0] == -1 or custo_vem[i][0] > self.grafo[indeiceDeOndeVem - 1][i] + distancia:
                        print(f'indice: {i}  Custo vem atual: {custo_vem[i][0]}')
                        print(f'Comparacao:  {custo_vem[i][0]} > {self.grafo[indeiceDeOndeVem - 1][i]} + {distancia}: ')
                        custo_vem[i] = [self.grafo[indeiceDeOndeVem - 1][i] + distancia,   indeiceDeOndeVem]
                        print(f'Custo vem atual: {custo_vem}')
                        h.adiciona_no(self.grafo[indeiceDeOndeVem - 1][i] + distancia , i + 1)
                        print(f'Heap : {h.mostraHeap()}')
                        print('\n')
                        
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
test = g.algoritmoDjkistra(1)  
print(test)
