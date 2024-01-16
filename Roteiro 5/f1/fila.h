#ifndef FILA_H
#define FILA_H

#define MAX 100

typedef struct{
    int qtd, ini, fim;
    int dados[MAX];
}Fila;

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
