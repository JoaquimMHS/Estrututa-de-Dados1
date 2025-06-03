#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No* prox;
}No;

No* criaNo(int valor){
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Alocação mal sucedida!\n");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}

No *incereOrde(No *lista, int valor){
    No *novo = criaNo(valor);
    No *aux = lista, *pred = NULL;
    if (lista == NULL) lista = novo;
    else {
        while (aux != NULL && valor > aux->chave){
            aux = aux->prox;
            pred = aux;
        }
        if(pred == NULL){
            lista = novo;
            novo->prox = aux; 
        } else {
            novo->prox = aux;
            pred->prox = novo;
        }
    }
    return novo;
}

No* fusao (No* lista1, No* lista2){
    No* aux1 = lista1;
    No* aux2 = lista2;
    No* aux3 = NULL;
    No* listaFusao = NULL;

    if (aux1 == NULL ) return aux2;
    if (aux2 == NULL ) return aux1;

    if(aux1->chave < aux2->chave){
        listaFusao = aux1;
        aux1 = aux1->prox;
    }else{
        listaFusao = aux2;
        aux2 = aux2->prox;
    }
    aux3 = listaFusao; 

    while(aux1 != NULL && aux2 != NULL){
        if(aux1->chave < aux2->chave){
            aux3->prox = aux1;
            aux1 = aux1->prox;
            aux3 = aux3->prox; 
        }else{
            aux3->prox = aux2;
            aux2 = aux2->prox;
            aux3 = aux3->prox; 
        }
    }
    if(aux1 != NULL){
        aux3->prox = aux1;    
    }else{
        aux3->prox = aux2;   
    }

    return listaFusao;  
}
