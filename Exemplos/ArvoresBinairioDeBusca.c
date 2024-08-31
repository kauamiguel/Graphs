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
node *insert(node *tree, int info);
node *addLeft(node *tree, int info);
node *addRight(node *tree, int info);
node *setNodeLeft(node *tree, node *newNode);
node *setNodeRight(node *tree, node *newNode);
void freeTree(node *node);
void preOrdem(node *node);
void emOrdem(node *node);
void posOrdem(node *node);
node *search(node *tree, int info);

int main(){
    int vetor [12] = {50, 30, 70, 20, 40, 60, 80, 15, 25, 35, 45,36};
    node *tree = NULL;
    
    for(int i = 0; i < 12; i++){
        tree = insert(tree, vetor[i]);
    }
 
    emOrdem(tree);
}

node *search(node *tree, int info){
    if (tree->info == info){
        return tree;
    }

    if (tree->info < info){
        return search(left(tree), info);
    }else{
        return search(right(tree), info); 
    }
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

node *insert(node *tree, int info){
    if(tree == NULL){
        return maketree(info);
    }

    if(info < tree->info){
        setNodeLeft(tree, insert(left(tree), info));
    }else{
        setNodeRight(tree, insert(right(tree), info));
    }

    return tree;
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
