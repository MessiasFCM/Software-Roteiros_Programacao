#ifndef PILHA_H
#define PILHA_H

#define MAX 100

typedef struct{
    int topo;
    int dados[MAX];
}Pilha;

Pilha* criaPilha();

void destroiPilha(Pilha *pi);

int tamanhoPilha(Pilha *pi);

int estaCheia(Pilha *pi);

int estaVazia(Pilha *pi);

int empilhar(Pilha* pi, int elem);

int desempilhar(Pilha* pi);

int verTopo(Pilha* pi, int* p);

void imprime(Pilha* pi);

#endif