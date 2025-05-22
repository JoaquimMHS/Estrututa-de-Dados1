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
    No* aux = lista;
    No* pred = NULL;
    No* novo = criaNo(base, expoente);

    if(lista == NULL){
     lista = novo;
     return lista;
    } else{
        while(aux != NULL && expoente < aux->expoente){
            pred = aux;
            aux = aux->prox;

        }
        if(pred == NULL){
            novo->prox = aux;
            lista = novo;
        } else{
            novo->prox = aux;
            pred->prox =  novo;
        }
        }
        return lista;   
}

No* somaPolinomia(No* L1, No* L2){
    No* aux1 = L1;
    No* aux2 = L2;
    No* resultado = NULL;
    if(L1 == NULL){
        resultado = L2;
        return resultado;
    } 
    if(L2 == NULL){
        resultado = L1;
        return resultado;
    }
    while(aux1 != NULL || aux2 != NULL){
        if(aux1->expoente == aux2->expoente){
            int soma = aux1->base + aux2->base;
            resultado = insereDecrescente(resultado, soma, aux1->expoente);
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }else if (aux1->expoente > aux2->expoente && aux2 != NULL){
            resultado = insereDecrescente(resultado, aux1->base, aux1->expoente);
            aux1 = aux1->prox;
        }else if (aux2->expoente > aux1->expoente && aux1 != NULL){
            resultado = insereDecrescente(resultado, aux2->base, aux2->expoente);
            aux2 = aux2->prox;
        
        }   
    }
    return resultado;
}

void imprimeLista(No* lista){
    if(lista == NULL) return;
    else{
        printf("%dx^%d +", lista->base, lista->expoente);
        imprimeLista(lista->prox);
        printf("\n");
    }
}

int main(){
    No* lista1 = NULL;
    No* lista2 = NULL;
    No* lista3 = NULL;
    int qtL1, qtL2, base, expoente;

    printf("Digite a quantidade de elementos da lista1: \n");
    scanf("%d", &qtL1);

    printf("Digite a quantidade de elementos da lista2: \n");
    scanf("%d", &qtL2);

    printf("Preenchendo a lista1...\n");
    for(int i = 0; i < qtL1; i++){
        printf("Digite a base: \n");
        scanf("%d", &base);
        printf("Digite o expoente: \n");
        scanf("%d", &expoente);
        lista1 = insereDecrescente(lista1, base, expoente);
    }
    printf("Preenchendo a lista2...\n");
    for(int i = 0; i < qtL2; i++){
        printf("Digite a base: \n");
        scanf("%d", &base);
        printf("Digite o expoente: \n");
        scanf("%d", &expoente);
        lista2 = insereDecrescente(lista2, base, expoente);
    }

    lista3 =  somaPolinomia(lista1, lista2);
    imprimeLista(lista3);

    return 0;
}


