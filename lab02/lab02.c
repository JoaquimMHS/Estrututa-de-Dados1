#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *prox;
} No;

No *criaNo(int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
    {
        printf("Alocacao mal sucedida!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
    return novo;
}

// Questão 03
No *insereNoInicio(No *L, int valor)
{
    No *novo = criaNo(valor);
    novo->prox = L;
    L = novo;
    return L;
}

No *insereNoFim(No *L, int valor)
{
    No *novo = criaNo(valor);
    No *aux = L;
    if (L == NULL)
        L = novo;
    else
    {
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return L;
}

int contaAntecedente(No *L, int num)
{
    No *aux = L;
    int cont = 0;
    if (L == NULL)
        return 0;
    else
    {
        while (aux != NULL)
        {
            if (aux->dado != num)
            {
                cont++;
                aux = aux->prox;
            }
            else
            {
                break;
            }
        }
        if (aux == NULL)
        {
            return 0;
        }
        return cont;
    }
}

void imprimeLista(No *L)
{
    No *aux = L;
    while (aux != NULL)
    {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
}

int main()
{
    No *L = NULL;
    No *aux;
    int i, cont;

    criaNo(10);
    for (i = 0; i < 10; i++)
    {
        L = insereNoInicio(L, i);
    }
    imprimeLista(L);

    for (i = 0; i < 10; i++)
    {
        L = insereNoFim(L, i);
    }
    imprimeLista(L);

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