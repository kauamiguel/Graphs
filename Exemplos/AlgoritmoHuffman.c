#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 256

typedef struct no {
    unsigned char caractere;
    int frequencia;
    struct no *esq, *dir, *proximo;
} No;

typedef struct lista {
    No *inicio;
    int tamanho;
} Lista;

// Funções para gerenciar a tabela de frequência
void inicializarTabela(unsigned int tabela[]) {
    for (int i = 0; i < TAM; i++) {
        tabela[i] = 0;
    }
}

void preencherTabela(unsigned char texto[], unsigned int tabela[]) {
    int i = 0;
    while (texto[i] != '\0') {
        tabela[texto[i]]++;
        i++;
    }
}

void imprimirTabela(unsigned int tabela[]) {
    for (int i = 0; i < TAM; i++) {
        if (tabela[i] > 0) {
            printf("%d    %d    %c\n", i, tabela[i], i);
        }
    }
}

// Funções para gerenciar a lista ordenada de frequências
void criarLista(Lista *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

void inserirOrdenado(Lista *lista, No *no) {
    No *aux;

    if (lista->inicio == NULL) {
        lista->inicio = no;
    } else if (no->frequencia < lista->inicio->frequencia) {
        no->proximo = lista->inicio;
        lista->inicio = no;
    } else {
        aux = lista->inicio;
        while (aux->proximo != NULL && aux->proximo->frequencia <= no->frequencia) {
            aux = aux->proximo;
        }
        no->proximo = aux->proximo;
        aux->proximo = no;
    }
    lista->tamanho++;
}

void preencherLista(unsigned int tabela[], Lista *lista) {
    No *novoNode;
    for (int i = 0; i < TAM; i++) {
        if (tabela[i] != 0) {
            novoNode = (No *)malloc(sizeof(No));
            if (novoNode) {
                novoNode->caractere = i;
                novoNode->frequencia = tabela[i];
                novoNode->dir = NULL;
                novoNode->esq = NULL;
                novoNode->proximo = NULL;
                inserirOrdenado(lista, novoNode);
            }
        }
    }
}

void imprimirLista(Lista *lista) {
    No *aux = lista->inicio;
    while (aux) {
        printf("Caractere: %c  Frequencia: %d\n", aux->caractere, aux->frequencia);
        aux = aux->proximo;
    }
}

// Funções para criar a árvore de Huffman
No* removerNoInicial(Lista *lista) {
    No *aux = NULL;
    if (lista->inicio) {
        aux = lista->inicio;
        lista->inicio = aux->proximo;
        lista->tamanho--;
    }
    return aux;
}

No* gerarArvoreHuffman(Lista *lista) {
    No *primeiro, *segundo, *novo;
    while (lista->tamanho > 1) {
        primeiro = removerNoInicial(lista);
        segundo = removerNoInicial(lista);
        novo = (No *)malloc(sizeof(No));
        if (novo) {
            novo->caractere = '+';
            novo->frequencia = primeiro->frequencia + segundo->frequencia;
            novo->esq = primeiro;
            novo->dir = segundo;
            novo->proximo = NULL;
            inserirOrdenado(lista, novo);
        }
    }
    return lista->inicio;
}

void imprimirArvore(No *raiz, int profundidade) {
    if (raiz->esq == NULL && raiz->dir == NULL) {
        printf("Folha: %c   Profundidade: %d\n", raiz->caractere, profundidade);
    } else {
        imprimirArvore(raiz->esq, profundidade + 1);
        imprimirArvore(raiz->dir, profundidade + 1);
    }
}

// Montar o dicionário de palavras
int alturaArvore(No *raiz) {
    int esq, dir;

    if (raiz == NULL)
        return -1;

    esq = alturaArvore(raiz->esq) + 1;
    dir = alturaArvore(raiz->dir) + 1;

    if (esq > dir) {
        return esq;
    } else {
        return dir;
    }
}

char **alocaDicionario(int colunas) {
    char **dicionario;

    dicionario = (char **)malloc(TAM * sizeof(char *));
    for (int i = 0; i < TAM; i++) {
        dicionario[i] = (char *)calloc(colunas, sizeof(char));
    }

    return dicionario;
}

void gerarDicionario(char **dicionario, No *raiz, char *caminho, int colunas) {
    char esquerda[colunas], direita[colunas];

    if (raiz->esq == NULL && raiz->dir == NULL) {
        strcpy(dicionario[raiz->caractere], caminho);
    } else {
        strcpy(esquerda, caminho);
        strcpy(direita, caminho);
        strcat(esquerda, "0");
        strcat(direita, "1");

        gerarDicionario(dicionario, raiz->esq, esquerda, colunas);
        gerarDicionario(dicionario, raiz->dir, direita, colunas);
    }
}

void imprimirDicionario(char **dicionario) {
    for (int i = 0; i < TAM; i++) {
        //Verifica se não é string vazia
        if (dicionario[i][0] != '\0'){
            printf("%d:  %s\n", i, dicionario[i]);
        }
    }
}

//Montar o texto codificado
int calcularTamanhoTexto(char **dicionario, unsigned char *texto){
    int i = 0, tam = 0;

    while(texto[i] != '\0'){
        tam = tam + strlen(dicionario[texto[i]]);
        i++;
    }
    return tam + 1;
}

char *codificar(char **dicionario, unsigned char *texto){
    int i = 0, tamanhoString = calcularTamanhoTexto(dicionario, texto);
    char *codigo = calloc(tamanhoString, sizeof(char));

    while(texto[i] != '\0'){
        strcat(codigo, dicionario[texto[i]]);
        i++;
    }

    return codigo;
}   

// Decodificar

char *decodificar(unsigned char texto[], No * raiz){
    int i = 0;
    No * aux = raiz;
    char temporario[2];
    char *decodificado = calloc(strlen(texto), sizeof(char));

    while(texto[i] != '\0'){
        if(texto[i] == '0'){
            aux = aux->esq;
        }else{
            aux = aux->dir;
        }

        if(aux->esq == NULL && aux->dir == NULL){
            //Preenche o vetor temporario pra adicionar no texto decodificado
            temporario[0] = aux->caractere;
            temporario[1] - '\0';
            strcat(decodificado, temporario);
            aux = raiz;
        }

        i++;
    }

    return decodificado;
}

//Compactar as strings
void compactar(unsigned char str[]){
    FILE *arquivo = fopen("compactado.wg", "wb");
    int i = 0, j = 7;
    unsigned char byte = 0, mascara;

    if(arquivo){
        while(str[i] != '\0'){
            mascara = 1;

            if(str[i] == '1'){
                mascara = mascara << j;
                byte = byte  | mascara;
            }

            j--;

            if(j < 0){ // Criamos um byte no arquivo
                fwrite(&byte, sizeof(unsigned char), 1, arquivo);
                byte = 0;
                j = 7;
            }
            i++;
        }

        if(j != 7){
            fwrite(&byte, sizeof(unsigned char), 1, arquivo);
        }
    }

    fclose(arquivo);
}

// Descompactar e ler com a árvore de ruffman

unsigned int verificaBitUm(unsigned char byte, int i){
    unsigned mascara = (1 << i);
    return byte & mascara;
}

void descompactar(No *raiz){
    FILE *arquivo = fopen("compactado.wg", "rb");
    No *aux = raiz;
    unsigned char byte;
    int i;

    if(arquivo){
        while(fread(&byte, sizeof(unsigned char), 1, arquivo)){
            for(i = 7; i >= 7; i--){
                if(verificaBitUm(byte, i)){
                    aux = aux->dir;
                }else{
                    aux = aux->esq;
                }   

                if(aux->dir == NULL && aux->esq == NULL){
                    printf("%c", aux->caractere);
                    aux = raiz;          
                }
            }
        }

        fclose(arquivo);
    }
}

int main() {
    unsigned char texto[] = "Vamos aprender a programar";
    unsigned int tabelaFrequencia[TAM];
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    No *arvore;
    int colunas;
    char **dicionario;
    char *codificado, *decodificado;

    // Inicializar e preencher a tabela de frequência
    inicializarTabela(tabelaFrequencia);
    preencherTabela(texto, tabelaFrequencia);
    imprimirTabela(tabelaFrequencia);

    // Criar e preencher a lista ordenada
    criarLista(lista);
    preencherLista(tabelaFrequencia, lista);
    imprimirLista(lista);

    // Gerar a árvore de Huffman e imprimi-la
    arvore = gerarArvoreHuffman(lista);
    imprimirArvore(arvore, 0);

    // Montar o dicionario
    colunas = alturaArvore(arvore) + 1;
    dicionario = alocaDicionario(colunas);
    gerarDicionario(dicionario, arvore, "", colunas);
    imprimirDicionario(dicionario);

    codificado = codificar(dicionario, texto);
    printf("texto codificado: %s\n", codificado);

    decodificado = decodificar(codificado, arvore);
    printf("texto decodificado: %s\n", decodificado);

    return 0;
}