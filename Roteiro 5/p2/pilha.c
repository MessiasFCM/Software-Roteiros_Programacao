#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Pilha* criaPilha() {
    Pilha* pi = (Pilha*)malloc(sizeof(Pilha));
    if (pi != NULL) {
        pi->qtd = 0;
        pi->topo = NULL;
    }
    return pi;
}

void destroiPilha(Pilha* pi) {
    if (pi != NULL) {
        while (pi->topo != NULL) {
            NO* aux = pi->topo;
            pi->topo = pi->topo->prox;
            free(aux);
        }
        free(pi);
    }
}

int tamanhoPilha(Pilha* pi) {
    if (pi == NULL)
        return -1;
    return pi->qtd;
}

int estaVazia(Pilha* pi) {
    if (pi == NULL)
        return -1;
    return (pi->topo == NULL);
}

int empilhar(Pilha* pi, int elem) {
    if (pi == NULL)
        return 0;

    NO* novo_no = (NO*)malloc(sizeof(NO));
    if (novo_no == NULL)
        return 0;

    novo_no->info = elem;
    novo_no->prox = pi->topo;
    pi->topo = novo_no;
    pi->qtd++;
    return 1;
}

int desempilhar(Pilha* pi) {
    if (pi == NULL || pi->topo == NULL)
        return 0;

    NO* aux = pi->topo;
    pi->topo = aux->prox;
    free(aux);
    pi->qtd--;
    return 1;
}

int verTopo(Pilha* pi, int* p) {
    if (pi == NULL || pi->topo == NULL)
        return 0;

    *p = pi->topo->info;
    return 1;
}

void imprime(Pilha* pi) {
    if (pi == NULL) return;

    NO* aux = pi->topo;
    printf("Elementos: ");
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}