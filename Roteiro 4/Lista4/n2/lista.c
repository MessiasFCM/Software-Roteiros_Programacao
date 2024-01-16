#include "lista.h"
#include <stdio.h> 
#include <stdlib.h>

void inicializarLista(Lista* l) {
    l->cabeca = NULL;
    l->tamanho = 0;
}

int tamanhoLista(Lista* l) {
    return l->tamanho;
}

int procura(Lista* l, int elemento) {
    No* atual = l->cabeca;
    int indice = 0;
    while (atual != NULL) {
        if (atual->dado == elemento) {
            return indice;
        }
        atual = atual->proximo;
        indice++;
    }
    return -1; 
}

void inserirOrdenado(Lista* l, int elemento) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        exit(1);
    }
    novoNo->dado = elemento;
    novoNo->proximo = NULL;
    if (l->cabeca == NULL || l->cabeca->dado >= elemento) {
        novoNo->proximo = l->cabeca;
        l->cabeca = novoNo;
    } else {
        No* anterior = NULL;
        No* atual = l->cabeca;
        while (atual != NULL && atual->dado < elemento) {
            anterior = atual;
            atual = atual->proximo;
        }
        anterior->proximo = novoNo;
        novoNo->proximo = atual;
    }
    l->tamanho++;
}

void removerPrimeiraOcorrencia(Lista* l, int elemento) {
    No* anterior = NULL;
    No* atual = l->cabeca;

    while (atual != NULL && atual->dado != elemento) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            l->cabeca = atual->proximo;
        } else {
            anterior->proximo = atual->proximo;
        }
        free(atual);
        l->tamanho--;
    }
}

void imprimirLista(Lista* l) {
    No* atual = l->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}