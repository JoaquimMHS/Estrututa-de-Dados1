#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
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

No *insereNoInicio(No* L, int valor){
    No *novo = criaNo(valor);

    novo->prox = L;
    L = novo;
    return L;

}

No *insereNoFim(No* L, int valor){
    No* novo = criaNo(valor);
    No* aux = L;
    if(L = NULL){
        L = novo;
    }
    while(aux != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return L;

}

void imprimeLista(No* L){
    No* aux = L;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
}

int contaAntecedente(No* L, int valor){
    No* aux = L;
    int cont = 0;
    if(L == NULL){ //Se a lista estiver vázia não tem valor à ser encontrado
        return 0;
    }else{
        while(aux != NULL){ //Precisamos percorrer toda a lista para tentar encontrar o valor
            if(aux->chave != valor){
                cont++;// Enquanto o valor não for encontradado cont++
                aux = aux->prox; //Se não for o valor correspodente vai para o próximo
            } else{
                break;
            }
        }
        if(aux == NULL){
            return 0; //Quer dizer que o valor não exite na lista, percorreu e não encontrou
        }
    }
    return cont;
}

void imprimeListaRecusiva(No* L){
    if(L == NULL){
        return;
    } else{
        printf("%d ", L->chave);
        imprimeLista(L->prox);
    }
}

int main()
{
    No *L = NULL;
    No *aux;
    int i, cont;


    for (i = 0; i < 10; i++)
    {
        L = insereNoInicio(L, i);
    }
    imprimeLista(L);

    for (i = 0; i < 10; i++)
    {
        L = insereNoFim(L, i);
    }
    
    imprimeListaRecusiva(L);

    cont = contaAntecedente(L, 5);
    printf("%d", cont);

    while (L != NULL)
    {
        aux = L;
        L = L->prox;
        free(aux);
    }
    free(L);
    return 0;
}