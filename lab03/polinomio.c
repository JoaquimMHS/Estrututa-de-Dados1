#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int base;
    int expoente;
    struct No *prox;
    
}No;

No* criaNo(int v_base, int v_expoente){
    No* novo = (No *)malloc(sizeof(No));
    if (novo == NULL){
        printf("ALocação mal sucedida!");
        exit(1);
    }
    novo->base = v_base;
    novo->expoente = v_expoente;
    novo->prox = NULL;

    return novo;
}

No *insereDecrescente(No *lista, int base, int expoente){
    
}


