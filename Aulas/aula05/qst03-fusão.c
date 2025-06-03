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
            pred = aux;
            aux = aux->prox;
        }
        if(pred == NULL){
            lista = novo;
            novo->prox = aux; 
        } else {
            novo->prox = aux;
            pred->prox = novo;
        }
    }
    return lista;
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

void imprimeLista(No* lista){
    if(lista == NULL) return;
    printf("%d ", lista->chave);
    imprimeLista(lista->prox);
}

int main(){
    No* lista1 = NULL;
    No* lista2 = NULL;
    No* listaFusao = NULL;
    int qnt, number;

    printf("Digite quantos elementos tem a lista 1: ");
    scanf("%d", &qnt);
    for(int i = 0; i < qnt; i++){
        printf("Digite o elemento : ");
        scanf("%d", &number);
        lista1 = incereOrde(lista1, number);
    }

    printf("Digite quantos elementos tem a lista 2: ");
    scanf("%d", &qnt);
    for(int i = 0; i < qnt; i++){
        printf("Digite o elmento : ");
        scanf("%d", &number);
        lista2 = incereOrde(lista2, number);
    }

    listaFusao =fusao(lista1, lista2);
    imprimeLista(listaFusao);

    return 0;
}
