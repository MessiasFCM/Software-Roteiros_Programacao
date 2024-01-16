#ifndef PILHA_H
#define PILHA_H

typedef struct NO {
    int info;
    struct NO* prox;
} NO;

typedef struct {
    int qtd;
    NO* topo;
} Pilha;

Pilha* criaPilha();

void destroiPilha(Pilha* pi);

int tamanhoPilha(Pilha* pi);

int estaVazia(Pilha* pi);

int empilhar(Pilha* pi, int elem);

int desempilhar(Pilha* pi);

int verTopo(Pilha* pi, int* p);

void imprime(Pilha* pi);

#endif