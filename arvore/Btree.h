//header do Btreefuncoes.c

#ifndef BTREE_H
#define BTREE_H

#include <stdio.h>

//criando o struct da árvore

typedef struct {
    //definindo a estrutura do nó
    int chave;
    struct No *esq;
    struct No *dir;
}Arvore;

//listagem das funções

Arvore *criarNo(int chave);
Arvore *inserir(Arvore *raiz, int chave);
Arvore *buscar(Arvore *raiz, int chave);
Arvore *minimo(Arvore *raiz);
Arvore *remover(Arvore *raiz, int chave);
void preOrdem(Arvore *raiz);
void emOrdem(Arvore *raiz);
void posOrdem(Arvore *raiz);

#endif