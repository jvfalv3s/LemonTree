/*
incluir no
remorver no
buscar pre ordem
buscar em ordem
buscar pos ordem
*/

#include<stdio.h>
#include<stdlib.h>
#include "Btree.h"

//a struct se encontra no arquivo header Btree.h

//mostrando as funções

Arvore *criarNo(int chave);
Arvore *inserir(Arvore *raiz, int chave);
Arvore *buscar(Arvore *raiz, int chave);
Arvore *minimo(Arvore *raiz);
Arvore *remover(Arvore *raiz, int chave);
void preOrdem(Arvore *raiz);
void emOrdem(Arvore *raiz);
void posOrdem(Arvore *raiz);


//função para criar um novo nó

Arvore *criarNo(int chave){
    Arvore *novo = (Arvore*)malloc(sizeof(Arvore));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

//função para inserir um novo nó

Arvore *inserir(Arvore *raiz, int chave){
    if(raiz == NULL){
        return criarNo(chave);
    }
    if(chave < raiz->chave){
        raiz->esq = inserir(raiz->esq, chave);
    }else{
        raiz->dir = inserir(raiz->dir, chave);
    }
    return raiz;
}

//função para buscar um nó

Arvore *buscar(Arvore *raiz, int chave){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->chave == chave){
        return raiz;
    }
    if(chave < raiz->chave){
        return buscar(raiz->esq, chave);
    }else{
        return buscar(raiz->dir, chave);
    }
}

//função para buscar o nó com a menor chave

Arvore *minimo(Arvore *raiz){
    Arvore *atual = raiz;
    while(atual->esq != NULL){
        atual = atual->esq;
    }
    return atual;
}

//função para remover um nó

Arvore *remover(Arvore *raiz, int chave){
    if(raiz == NULL){
        return raiz;
    }
    if(chave < raiz->chave){
        raiz->esq = remover(raiz->esq, chave);
    }else if(chave > raiz->chave){
        raiz->dir = remover(raiz->dir, chave);
    }else{
        if(raiz->esq == NULL){
            Arvore *temp = raiz->dir;
            free(raiz);
            return temp;
        }else if(raiz->dir == NULL){
            Arvore *temp = raiz->esq;
            free(raiz);
            return temp;
        }
        Arvore *temp = minimo(raiz->dir);
        raiz->chave = temp->chave;
        raiz->dir = remover(raiz->dir, temp->chave);
    }
    return raiz;
}

//função para imprimir a arvore em pre ordem

void preOrdem(Arvore *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

//função para imprimir a arvore em ordem

void emOrdem(Arvore *raiz){
    if(raiz != NULL){
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}

//função para imprimir a arvore em pos ordem

void posOrdem(Arvore *raiz){
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        printf("%d ", raiz->chave);
    }
}