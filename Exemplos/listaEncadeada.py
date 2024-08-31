class No:
    
    def __init__(self, valor) :
        self.valor = valor
        self.proximo = None
    
    def obterValorDoNo(self):
        return self.valor
    
    def setProximo(self, proximo):
        self.proximo = proximo
        
    def obterProximo(self):
        return self.proximo
    
    
no1 = No(4)
no2 = No(7)

