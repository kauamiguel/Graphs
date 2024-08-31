#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype{
    int info;
    struct nodetype *father;
    struct nodetype *left;
    struct nodetype *right;
}node;

int test = 0;

//Operações básicas com árvores

node *maketree(int value);
int info(node *node);
node *left(node *node);
node *right(node *node);
node *father(node *node);
node *brother(node *node);
int isLeft(node *node);
int isRight(node *node);
node *addLeft(node *tree, int info);
node *addRight(node *tree, int info);
node *setNodeLeft(node *tree, node *newNode);
node *setNodeRight(node *tree, node *newNode);
void freeTree(node *node);
void preOrdem(node *node);
void emOrdem(node *node);
void posOrdem(node *node);

//Outras operações em árvores

int isLeaf(node *node);
node *root(node *node);
int level(node *node);
int depth(node *node);
int isStrictBinary(node *tree);
int isComplet(node *tree);
int lenght(node *tree);
int bigger(node *tree);
int sum(node *tree);
int max(int a, int b);

int main(){
    node *tree = maketree(14);
    addLeft(addLeft(tree,4), 3);
    addRight(left(tree), 10);
    addLeft(addRight(tree, 22), 18);
    addRight(right(tree), 25);
    emOrdem(tree);
}


int info(node *node){
    return node->info;
}

node *left(node *node){
    return node->left;
}

node *right(node *node){
    return node->right;
}

node *father(node *node){
    return node->father;
}

node *brother(node *node){
    if(isLeft(node)) return right(father(node));
    else return left(father(node));
}

int isLeft(node *node){

    if (father(node) == NULL) return 0;
    //Compara se o esquerdo do pai do nó é igual ao nó
    return left(father(node)) == node;
}

int isRight(node *node){
    if (father(node) == NULL) return 0;
    return right(father(node)) == node;
}

node *maketree(int value){
    node *nodeTree = (node *)malloc(sizeof(node));
    nodeTree->info = value;
    nodeTree->father = NULL;
    nodeTree->left = NULL;
    nodeTree->right = NULL;
    return nodeTree;
}

node *addLeft(node *tree, int info){
    return setNodeLeft(tree, maketree(info));
}

node *addRight(node *tree, int info){
    return setNodeRight(tree, maketree(info));
}

node *setNodeLeft(node *tree, node *newNode){
    tree->left = newNode;
    newNode->father = tree;
    return newNode;
}

node *setNodeRight(node *tree, node *newNode){
    tree->right = newNode;
    newNode->father = tree;
    return newNode;
}

void freeTree(node *node){
    if (node != NULL){
        freeTree(left(node));
        freeTree(right(node));
        free(node);
    }
}
 
void preOrdem(node *node){
    if(node != NULL){
        printf("[%d] ", node->info);
        preOrdem(left(node));
        preOrdem(right(node));
    }
}

void emOrdem(node *node){
     if(node != NULL){
        emOrdem(left(node));
        printf("[%d] ", node->info);
        emOrdem(right(node));
    }
}

void posOrdem(node *node){
    if(node != NULL){
        posOrdem(left(node));
        posOrdem(right(node));
        printf("[%d] ", node->info);
    }
}

int isLeaf(node *node){
    //Verifica se o nó não tem irmãos (definição de folha)
    return left(node) == NULL && right(node) == NULL;
}

//Dado um nó, qual a raiz desse nó
node *root(node *node){
    while(father(node) != NULL){
        node = father(node);
    }
    return node;
}

int level(node *node){
    int level = 0;

    //Caso não seja a raiz, retroecede até a raiz incrementando o valor de level
    while(father(node) != NULL){
        level++;
        node = node->father;
    }

    return level;
}


//Dado um nó, quantos elementos tem dali para baixo
int depth(node *node){
    //Se ele é folha não tem nenhum nó abaixo dele
    if(node == NULL || isLeaf(node)){
        return 0;
    }

    return max(depth(left(node)), depth(right(node))  + 1  );
}

//Maior valor entre dois números
int max(int a, int b){
    return a > b ? a : b;
}

//Verifica se o nó possui dois filhos ou nenhum
int isStrictBinary(node *tree){
    if(tree  == NULL){
        return 0;
    }else if(isLeaf(tree)){
        return 1;
    }
    return isStrictBinary(left(tree)) && isStrictBinary(right(tree));
}

int isComplet(node *tree);

int lenght(node *tree);

int bigger(node *tree){
    int m;
    
    if(tree == NULL){
        return 0;
    }
    // printf("\nvalor da stack atua;: \n%d", tree->info);
    m = max(bigger(left(tree)), bigger(right(tree)));
    return max(info(tree), m);
}

int sum(node *tree){

    if (tree == NULL){
        return 0;
    }

    return info(tree) + sum(left(tree)) + sum(right(tree));
}