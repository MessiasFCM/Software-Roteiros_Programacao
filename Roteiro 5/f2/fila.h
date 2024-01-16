#ifndef FILA_H
#define FILA_H

typedef struct NO {
    int info;
    struct NO* prox;
} NO;

typedef struct {
    int qtd;
    NO* ini;
    NO* fim;
} Fila;

Fila* criaFila();

void destroiFila(Fila *fi);

int tamanhoFila(Fila *fi);

int estaCheia(Fila *fi);

int estaVazia(Fila *fi);

int enfileirar(Fila* fi, int elem);

int desenfileirar(Fila* fi);

int verInicio(Fila* fi, int* p);

void imprime(Fila* fi);

#endif
