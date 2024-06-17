//criação do main e exposição do menu

#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"

int main(){
    Arvore *raiz = NULL;
    int opcao, chave;
    Arvore *aux;
    while(1){
        printf("1 - Inserir\n");
        printf("2 - Buscar\n");
        printf("3 - Remover\n");
        printf("4 - Listar em pré-ordem\n");
        printf("5 - Listar em ordem\n");
        printf("6 - Listar em pós-ordem\n");
        printf("7 - Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite a chave a ser inserida: ");
                scanf("%d", &chave);
                raiz = inserir(raiz, chave);
                break;
            case 2:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &chave);
                aux = buscar(raiz, chave);
                if(aux == NULL){
                    printf("Chave não encontrada\n");
                }else{
                    printf("Chave encontrada\n");
                }
                break;
            case 3:
                printf("Digite a chave a ser removida: ");
                scanf("%d", &chave);
                raiz = remover(raiz, chave);
                break;
            case 4:
                preOrdem(raiz);
                printf("\n");
                break;
            case 5:
                emOrdem(raiz);
                printf("\n");
                break;
            case 6:
                posOrdem(raiz);
                printf("\n");
                break;
            case 7:
                return 0;
            default:
                printf("Opção inválida\n");
        }
    }
    return 0;
}