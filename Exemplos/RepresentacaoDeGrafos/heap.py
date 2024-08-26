class HeapMax:
    
    def __init__(self):
        self.nos  = 0
        self.heap = []
        
    def adiciona_no(self, u):
        self.heap.append(u)
        self.nos += 1
        filho = self.nos
        
        while True:
            if filho == 1: #Se o filho for o pai, para
                break
            pai = filho // 2 #Verifica quem é o pai do filho
            
            if self.heap[pai -1] >= self.heap[filho -1]:
                break
            else:
                self.heap[pai-1], self.heap[filho-1] = self.heap[filho-1], self.heap[pai-1]
                filho = pai
                
    def mostra_no(self):
        print(self.heap)
        
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

h.mostra_no()

        