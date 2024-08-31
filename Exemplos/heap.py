class HeapMax:
    
    def __init__(self):
        self.nos  = 0
        self.heap = []
        
    def adiciona_no(self, u):
        self.heap.append(u)
        self.nos += 1
        filho = self.nos
        
        while True:
            if filho == 1: #Se o filho for o pai (Nesse caso começa em 1), para
                break
            pai = filho // 2 #Verifica quem é o pai do filho
            
            if self.heap[pai -1] >= self.heap[filho -1]:
                break
            else:
                self.heap[pai-1], self.heap[filho-1] = self.heap[filho-1], self.heap[pai-1]
                # Nesse caso o algoritmo vai de baixo pra cima
                filho = pai
                
    def mostra_no(self):
        print(self.heap)
        
    def remove_no(self):
        self.heap[0] = self.heap[self.nos - 1] # O ultimo elemento vai para a primeira posicao
        self.heap.pop()
        self.nos -= 1
        
        pai = 1
        
        while True:
            filho = 2 * pai
            
            if filho > self.nos: #Caso nao tenha filhos (Buscando um filho maior que a quantidade de nos)
                 break
            
            if filho+1 <= self.nos: #Ja sabemos que existe filho a esquerda, agora desejo saber se existe a direita
                if self.heap[(filho+1) - 1] > self.heap[filho - 1]: #Filho a direita maior que esquerda?
                    filho += 1 #Assume o indice do maior filho do vertice atual
            
            if  self.heap[pai - 1] > self.heap[filho - 1]:
                break
            else:
                self.heap[pai - 1], self.heap[filho - 1] = self.heap[filho - 1], self.heap[pai - 1]
                #Nesse caso o algoritmo vai de cima pra baixo, pois ja sabemos que os filhos
                #superiores são maiores que todos os nos, portanto o objetivo e colocar a
                #nova raiz no lugar certo
                pai = filho        
        
h = HeapMax()

h.adiciona_no(17)
h.adiciona_no(36)
h.adiciona_no(25)
h.adiciona_no(7)
h.adiciona_no(3)
h.adiciona_no(100)
h.adiciona_no(1)
h.adiciona_no(2)
h.adiciona_no(19)
h.remove_no()

h.mostra_no()

        